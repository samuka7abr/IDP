# 📚 Questões da Revisão

---

## ✅ Função de McCarthy

Implementada de forma otimizada, transformando uma função recursiva em uma estrutura condicional simples (constante):

```c
int main(){
    int v;
    if(v < 100){
        puts("91");
    }else{
        printf("%d\n", v - 10);
    }
    return 0;
}
```

---

## ✅ Carcereiro Binário

Utiliza operadores bitwise para verificar o estado de uma lâmpada com base na posição do bit. Otimização: não precisa usar `& 1`.

```c
int main(){
    unsigned long long n;
    int q, v;
    scanf("%llu %d", &n, &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &v);
        printf("%s", (n >> v) ? "acesa\n" : "apagada\n");
    }
    return 0;
}
```

---

## ✅ Batalha Naval Numérica

### 🔹 Solução 1: busca binária por linha e depois por coluna

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, v;
    cin >> n >> m >> q;

    vector<vector<int>> valores(n, vector<int>(m));
    vector<int> primeiraColuna(n);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v;
            valores[i][j] = v;
            if(j == 0)
                primeiraColuna[i] = v;
        }
    }

    while(q--){
        cin >> v;
        auto it = upper_bound(primeiraColuna.begin(), primeiraColuna.end(), v);
        if(it == primeiraColuna.begin()){
            cout << "-1 -1\n";
            continue;
        }
        int linha = int(it - primeiraColuna.begin()) - 1;
        if(valores[linha][m-1] < v){
            cout << "-1 -1\n";
            continue;
        }
        auto jt = lower_bound(valores[linha].begin(), valores[linha].end(), v);
        if(jt != valores[linha].end() && *jt == v){
            int col = int(jt - valores[linha].begin());
            cout << (linha + 1) << " " << (col + 1) << "\n";
        } else {
            cout << "-1 -1\n";
        }
    }

    return 0;
}
```

### 🔹 Solução 2: vetor plano + `lower_bound` com comparador

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, q, v;
    cin >> n >> m >> q;

    vector<pair<int, pair<int,int>>> flat;
    flat.reserve((size_t)n * m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> v;
            flat.emplace_back(v, make_pair(i, j));
        }
    }

    auto comp = [](const pair<int,pair<int,int>> &a, const int &b){
        return a.first < b;
    };

    while(q--){
        cin >> v;
        auto it = lower_bound(flat.begin(), flat.end(), v, comp);
        if(it == flat.end() || it->first != v){
            cout << "-1 -1\n";
        } else {
            cout << (it->second.first + 1)
                 << " "
                 << (it->second.second + 1)
                 << "\n";
        }
    }

    return 0;
}
```

---

## ✅ Função 

Busca a menor solução `x` tal que `A * x + B * sin(x) >= C`, usando busca binária com `double`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C;
    cin >> A >> B >> C;

    double lo = 0.0, hi = 1e9, mid;
    double tol = 1e-9;

    while(hi - lo > tol){
        mid = (lo + hi) / 2.0;
        double valor = A * mid + B * sin(mid);
        if(valor < C){
            lo = mid;
        }else{
            hi = mid;
        }
    }

    cout << fixed << setprecision(4) << hi << endl;
    return 0;
}
```

---

## ✅ Prateleiras 

Ordenação por tamanho dos títulos e ordem lexicográfica (alfabética). Uso de lambda com `auto`.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    vector<string> livros(N);
    for(int i = 0; i < N; i++){
        cin >> livros[i];
    }

    sort(livros.begin(), livros.end(), [](auto &a, auto &b){
        return a.size() == b.size() ? a < b : a.size() < b.size();
    });

    for(const auto &titulo : livros)
        cout << titulo << "\n";

    return 0;
}
```cd