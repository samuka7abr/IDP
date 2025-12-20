import os, numpy as np, pandas as pd, matplotlib.pyplot as plt

csv_path = "Titanic-Dataset.csv"
if not os.path.exists(csv_path):
    raise FileNotFoundError("csv path não encontrado")

df = pd.read_csv(csv_path)
df.columns = [c.strip().lower() for c in df.columns]
df = df.drop_duplicates()

req_cols = ["survived","pclass","age","sibsp","parch","fare","sex"]
for col in req_cols:
    if col not in df.columns:
        raise KeyError(f"Coluna ausente no CSV: {col}")

df = df[df["survived"].isin([0,1])]
df = df[df["pclass"].isin([1,2,3])]
df["is_female"] = (df["sex"]=="female").astype(int)
df["familysize"] = df["sibsp"] + df["parch"] + 1
df["is_alone"] = (df["familysize"]==1).astype(int)

os.makedirs("output", exist_ok=True)

plot_df = df.dropna(subset=["age","fare","pclass","survived"]).copy()
plt.figure(figsize=(7,5))
plt.scatter(plot_df["age"], plot_df["fare"], c=plot_df["survived"], alpha=0.6, edgecolors="none")
plt.xlabel("Age")
plt.ylabel("Fare")
plt.title("Age vs Fare (color = Survived)")
plt.tight_layout()
plt.savefig("output/age_fare.png")
plt.close()

pclass_jitter = plot_df["pclass"] + np.random.uniform(-0.12,0.12, size=len(plot_df))
plt.figure(figsize=(7,5))
plt.scatter(pclass_jitter, plot_df["fare"], c=plot_df["survived"], alpha=0.6, edgecolors="none")
plt.xlabel("Pclass (jittered)")
plt.ylabel("Fare")
plt.title("Pclass vs Fare (color = Survived)")
plt.tight_layout()
plt.savefig("output/pclass_fare.png")
plt.close()

plt.figure(figsize=(7,5))
plt.scatter(pclass_jitter, plot_df["age"], c=plot_df["survived"], alpha=0.6, edgecolors="none")
plt.xlabel("Pclass (jittered)")
plt.ylabel("Age")
plt.title("Pclass vs Age (color = Survived)")
plt.tight_layout()
plt.savefig("output/pclass_age.png")
plt.close()

num = df[["survived","pclass","age","sibsp","parch","fare","familysize","is_alone","is_female"]].dropna()
corr = num.corr(numeric_only=True, method="pearson")

plt.figure(figsize=(7.5,6.5))
im = plt.imshow(corr.values, vmin=-1, vmax=1, aspect="auto")
plt.colorbar(im, fraction=0.046, pad=0.04)
plt.xticks(range(len(corr.columns)), corr.columns, rotation=45, ha="right")
plt.yticks(range(len(corr.index)), corr.index)
for (i,j), val in np.ndenumerate(corr.values):
    plt.text(j, i, f"{val:.2f}", ha="center", va="center", fontsize=8)
plt.title("Correlation heatmap (Pearson)")
plt.tight_layout()
plt.savefig("output/heatmap.png")
plt.close()

summary = {
    "rows": len(df),
    "missing_age": int(df["age"].isna().sum()),
    "missing_fare": int(df["fare"].isna().sum()),
    "survival_rate": float(df["survived"].mean()),
    "corr_survived_fare": float(corr.loc["survived","fare"]),
    "corr_survived_pclass": float(corr.loc["survived","pclass"]),
    "corr_survived_is_female": float(corr.loc["survived","is_female"]),
    "corr_survived_is_alone": float(corr.loc["survived","is_alone"])
}
print(summary)
