import os
import json
import joblib
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.impute import SimpleImputer
from sklearn.preprocessing import StandardScaler
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import Pipeline
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, roc_auc_score, confusion_matrix, classification_report, roc_curve, precision_recall_curve, average_precision_score
from sklearn.linear_model import LogisticRegression
from sklearn.ensemble import RandomForestClassifier

xlsx_path = "Diabetes_Dataset_Missing_Data.xlsx"
out_dir = Path("output")
out_dir.mkdir(parents=True, exist_ok=True)

df = pd.read_excel(xlsx_path)
df.columns = [c.strip().lower() for c in df.columns]

expected = ['pregnancies','glucose','bloodpressure','skinthickness','insulin','bmi','familyhistorydiabetes','age','outcome']
missing_cols = [c for c in expected if c not in df.columns]
if missing_cols:
    raise ValueError(f"Colunas ausentes no XLSX: {missing_cols}")

df[expected] = df[expected].apply(pd.to_numeric, errors='coerce')

zeros_as_nan = ['glucose','bloodpressure','skinthickness','insulin','bmi']
for c in zeros_as_nan:
    df.loc[df[c] == 0, c] = np.nan

num_cols = ['pregnancies','glucose','bloodpressure','skinthickness','insulin','bmi','familyhistorydiabetes','age']
target_col = 'outcome'
X = df[num_cols].copy()
y = df[target_col].copy().astype(int)

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.25, random_state=42, stratify=y)

preprocess = ColumnTransformer([
    ("num", Pipeline([("imputer", SimpleImputer(strategy="median")), ("scaler", StandardScaler())]), num_cols)
])

models = {
    "logreg": {
        "pipeline": Pipeline([("preprocess", preprocess), ("clf", LogisticRegression(max_iter=1000, class_weight="balanced", solver="lbfgs"))]),
        "param_grid": {"clf__C": [0.1, 1, 10]}
    },
    "rf": {
        "pipeline": Pipeline([("preprocess", preprocess), ("clf", RandomForestClassifier(class_weight="balanced", random_state=42))]),
        "param_grid": {"clf__n_estimators": [100, 200, 300], "clf__max_depth": [None, 10, 20]}
    }
}

rows = []
best = {"name": None, "estimator": None, "f1": -1.0, "best_params": None}

for name, spec in models.items():
    gs = GridSearchCV(spec["pipeline"], spec["param_grid"], scoring="f1", cv=5, n_jobs=-1)
    gs.fit(X_train, y_train)
    y_pred = gs.predict(X_test)
    y_proba = gs.predict_proba(X_test)[:,1] if hasattr(gs.best_estimator_.named_steps["clf"], "predict_proba") else None
    acc = accuracy_score(y_test, y_pred)
    prec = precision_score(y_test, y_pred, zero_division=0)
    rec = recall_score(y_test, y_pred, zero_division=0)
    f1 = f1_score(y_test, y_pred, zero_division=0)
    auc = roc_auc_score(y_test, y_proba) if y_proba is not None else np.nan
    rows.append({"model": name, "best_params": json.dumps(gs.best_params_), "accuracy": acc, "precision": prec, "recall": rec, "f1": f1, "roc_auc": auc})
    if f1 > best["f1"]:
        best["name"] = name
        best["estimator"] = gs.best_estimator_
        best["f1"] = f1
        best["best_params"] = gs.best_params_

summary = pd.DataFrame(rows).sort_values("f1", ascending=False)
summary.to_csv(out_dir / "models_summary.csv", index=False)

joblib.dump(best["estimator"], out_dir / "best_model.joblib")

y_pred = best["estimator"].predict(X_test)
y_proba = best["estimator"].predict_proba(X_test)[:,1] if hasattr(best["estimator"].named_steps["clf"], "predict_proba") else None
report_txt = classification_report(y_test, y_pred, zero_division=0)
with open(out_dir / "classification_report.txt", "w") as f:
    f.write(report_txt)

cm = confusion_matrix(y_test, y_pred)
fig = plt.figure()
plt.imshow(cm, aspect="auto")
plt.title("Confusion Matrix")
plt.xlabel("Predicted")
plt.ylabel("True")
for i in range(cm.shape[0]):
    for j in range(cm.shape[1]):
        plt.text(j, i, cm[i, j], ha="center", va="center")
plt.tight_layout()
plt.savefig(out_dir / "confusion_matrix.png")
plt.close(fig)

if y_proba is not None:
    fpr, tpr, thr = roc_curve(y_test, y_proba)
    ap = average_precision_score(y_test, y_proba)
    pr_x, pr_y, _ = precision_recall_curve(y_test, y_proba)
    fig = plt.figure()
    plt.plot(fpr, tpr)
    plt.plot([0,1],[0,1],"--")
    plt.title("ROC Curve")
    plt.xlabel("FPR")
    plt.ylabel("TPR")
    plt.tight_layout()
    plt.savefig(out_dir / "roc_curve.png")
    plt.close(fig)
    fig = plt.figure()
    plt.plot(pr_x, pr_y)
    plt.title(f"Precision-Recall Curve (AP={ap:.3f})")
    plt.xlabel("Recall")
    plt.ylabel("Precision")
    plt.tight_layout()
    plt.savefig(out_dir / "pr_curve.png")
    plt.close(fig)

if best["name"] == "rf":
    rf = best["estimator"].named_steps["clf"]
    imp = pd.DataFrame({"feature": num_cols, "importance": rf.feature_importances_}).sort_values("importance", ascending=False)
    imp.to_csv(out_dir / "feature_importances_randomforest.csv", index=False)
else:
    logreg = best["estimator"].named_steps["clf"]
    pre = best["estimator"].named_steps["preprocess"]
    f_names = pre.get_feature_names_out().tolist()
    coef = pd.DataFrame({"feature": f_names, "coefficient": logreg.coef_.ravel()}).sort_values("coefficient", key=lambda s: s.abs(), ascending=False)
    coef.to_csv(out_dir / "coefficients_logreg.csv", index=False)

corr = df[num_cols + [target_col]].corr(numeric_only=True)
fig = plt.figure(figsize=(6,4))
plt.imshow(corr.values, aspect="auto")
plt.xticks(range(len(corr.columns)), corr.columns, rotation=90n)
plt.yticks(range(len(corr.index)), corr.index)
plt.title("Correlation Heatmap")
plt.colorbar()
plt.tight_layout()
plt.savefig(out_dir / "correlation_heatmap.png")
plt.close(fig)