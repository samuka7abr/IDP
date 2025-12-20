samuelabrao@SamuelDeb:~/VSCODE/Slides-Template$ cat SLIDES.md 

## Objetivo

- **Treinar** uma rede neural simples (MLP com Keras) para **classificação binária** de diabetes usando o dataset Pima Indians.

## Dataset

- **Fonte**: `at05/pima-indians-diabetes.csv`
- **Formato**: 768 amostras, 8 atributos de entrada e 1 alvo binário.
- **Entrada**: vetor em \(\mathbb{R}^8\) por amostra.

## Pipeline de Treinamento

1. Carregar e preparar os dados (X, y)
2. Dividir em treino e teste (estratificado)
3. Definir arquitetura da rede
4. Compilar e treinar o modelo
5. Avaliar desempenho no conjunto de teste

### 1) Carregamento e Preparação dos Dados

```python
from pathlib import Path
import numpy as np

def load_dataset(csv_path: Path):
    data = np.loadtxt(str(csv_path), delimiter=",")
    X_data = data[:, 0:8].astype(np.float32)
    y_data = data[:, 8].astype(np.float32)
    return X_data, y_data

csv_path = Path(__file__).resolve().parent / "pima-indians-diabetes.csv"
X_data, y_data = load_dataset(csv_path)
print(f"Dados: X={X_data.shape}, y={y_data.shape}")
```

### 2) Divisão Treino/Teste (estratificada)

```python
from sklearn.model_selection import train_test_split

X_train, X_test, y_train, y_test = train_test_split(
    X_data, y_data, test_size=0.2, random_state=42, stratify=y_data
)
print(
    f"Treino: X={X_train.shape}, y={y_train.shape} | "
    f"Teste: X={X_test.shape}, y={y_test.shape}"
)
```

### 3) Arquitetura do Modelo (MLP)

```python
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense
from tensorflow.keras.optimizers import Adam

def create_model(input_dim: int = 8, learning_rate: float = 1e-3) -> Sequential:
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

model = create_model(input_dim=X_train.shape[1], learning_rate=1e-3)
```

### 4) Treinamento

```python
def train_model(model, X_train, y_train, *, epochs: int = 50, batch_size: int = 32):
    history = model.fit(
        X_train,
        y_train,
        validation_split=0.2,
        epochs=epochs,
        batch_size=batch_size,
        verbose=0,
    )
    return history

_ = train_model(model, X_train, y_train, epochs=50, batch_size=32)
print("Treinamento finalizado.")
```

### 5) Avaliação no Conjunto de Teste

```python
loss, acc = model.evaluate(X_test, y_test, verbose=0)
print(f"Teste -> loss: {loss:.4f} | accuracy: {acc:.4f}")
```

### (Opcional) Predição de Exemplo Pós-Treino

```python
sample = np.array([[2, 148, 72, 35, 0, 33.6, 0.627, 25]], dtype=np.float32)
proba = model.predict(sample, verbose=0)
pred = int((proba >= 0.5).astype(int)[0][0])
print(f"Prob.: {float(proba[0][0]):.4f} | Classe (0/1): {pred}")
```


## Resultados (Execução Real)

- **Dados (shapes)**: X=(768, 8), y=(768,)
- **Split treino/teste**: Treino X=(614, 8), y=(614,) | Teste X=(154, 8), y=(154,)
- **Métricas de teste**: loss=0.6372, accuracy=0.6948
- **Predição de exemplo**: prob=0.3015, classe=0 (0=nao,1=sim)

```text
Dados: X=(768, 8), y=(768,)
Split -> Treino: X=(614, 8), y=(614,) | Teste: X=(154, 8), y=(154,)
Treinamento finalizado.
Teste -> loss: 0.6372 | accuracy: 0.6948
Exemplo -> prob: 0.3015 | classe: 0 (0=nao,1=sim)
```

