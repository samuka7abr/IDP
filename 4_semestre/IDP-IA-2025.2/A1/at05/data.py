import os
from pathlib import Path
from typing import Tuple

import numpy as np
from sklearn.model_selection import train_test_split

os.environ.setdefault("TF_CPP_MIN_LOG_LEVEL", "2")  # suprimir logs do TF

try:
    import tensorflow as tf
    from tensorflow.keras.models import Sequential
    from tensorflow.keras.layers import Dense
    from tensorflow.keras.optimizers import Adam
except Exception as exc:  # pragma: no cover
    raise SystemExit(
        "TensorFlow/Keras nao encontrado. Instale com: pip install tensorflow"
    ) from exc


def set_random_seeds(seed: int = 42) -> None:
    """Define sementes para reprodutibilidade."""
    np.random.seed(seed)
    tf.random.set_seed(seed)


def load_dataset(csv_path: Path) -> Tuple[np.ndarray, np.ndarray]:
    """Carrega o dataset Pima a partir de um CSV local.

    Retorna:
        X (float32): matriz (n_amostras, 8)
        y (float32): vetor (n_amostras,)
    """
    if not csv_path.exists():
        raise FileNotFoundError(f"CSV nao encontrado em: {csv_path}")

    data = np.loadtxt(str(csv_path), delimiter=",")
    X_data = data[:, 0:8].astype(np.float32)
    y_data = data[:, 8].astype(np.float32)
    return X_data, y_data


def split_data(
    X_data: np.ndarray,
    y_data: np.ndarray,
    test_size: float = 0.2,
    random_state: int = 42,
) -> Tuple[np.ndarray, np.ndarray, np.ndarray, np.ndarray]:
    """Divide em treino e teste, estratificando pela classe."""
    return train_test_split(
        X_data,
        y_data,
        test_size=test_size,
        random_state=random_state,
        stratify=y_data,
    )


def create_model(input_dim: int = 8, learning_rate: float = 1e-3) -> Sequential:
    """Cria e compila um MLP simples para classificacao binaria."""
    model = Sequential(name="pima_binary_mlp")
    model.add(Dense(16, activation="relu", input_shape=(input_dim,), name="dense_1"))
    model.add(Dense(8, activation="relu", name="dense_2"))
    model.add(Dense(1, activation="sigmoid", name="output"))

    model.compile(
        optimizer=Adam(learning_rate=learning_rate),
        loss="binary_crossentropy",
        metrics=["accuracy"],
    )
    return model


def train_model(
    model: Sequential,
    X_train: np.ndarray,
    y_train: np.ndarray,
    *,
    epochs: int = 50,
    batch_size: int = 32,
    validation_split: float = 0.2,
    verbose: int = 0,
):
    """Treina o modelo e retorna o historico."""
    history = model.fit(
        X_train,
        y_train,
        validation_split=validation_split,
        epochs=epochs,
        batch_size=batch_size,
        verbose=verbose,
    )
    return history


def evaluate_model(model: Sequential, X_test: np.ndarray, y_test: np.ndarray) -> Tuple[float, float]:
    """Avalia o modelo e retorna (loss, accuracy)."""
    loss, accuracy = model.evaluate(X_test, y_test, verbose=0)
    return float(loss), float(accuracy)


def predict_sample(model: Sequential, sample: np.ndarray) -> Tuple[float, int]:
    """Retorna (probabilidade, classe_predita) para um unico exemplo (1x8)."""
    sample = sample.astype(np.float32)
    proba = model.predict(sample, verbose=0)
    probability = float(proba[0][0])
    predicted_class = int((proba >= 0.5).astype(int)[0][0])
    return probability, predicted_class


def main() -> None:
    set_random_seeds(42)

    project_dir = Path(__file__).resolve().parent
    csv_path = project_dir / "pima-indians-diabetes.csv"

    X_data, y_data = load_dataset(csv_path)
    print(f"Dados: X={X_data.shape}, y={y_data.shape}")

    X_train, X_test, y_train, y_test = split_data(X_data, y_data)
    print(
        f"Split -> Treino: X={X_train.shape}, y={y_train.shape} | "
        f"Teste: X={X_test.shape}, y={y_test.shape}"
    )

    model = create_model(input_dim=X_train.shape[1], learning_rate=1e-3)

    _ = train_model(
        model,
        X_train,
        y_train,
        epochs=50,
        batch_size=32,
        validation_split=0.2,
        verbose=0,
    )
    print("Treinamento finalizado.")

    loss, acc = evaluate_model(model, X_test, y_test)
    print(f"Teste -> loss: {loss:.4f} | accuracy: {acc:.4f}")

    sample = np.array([[2, 148, 72, 35, 0, 33.6, 0.627, 25]], dtype=np.float32)
    prob, cls = predict_sample(model, sample)
    print(f"Exemplo -> prob: {prob:.4f} | classe: {cls} (0=nao,1=sim)")


if __name__ == "__main__":  # pragma: no cover
    main()


