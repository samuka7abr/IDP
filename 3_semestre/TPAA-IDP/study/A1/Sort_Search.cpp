// =============================
// BUSCA & ORDENAÇÃO em C++
// =============================

#include <bits/stdc++.h>
using namespace std;

// -------------------------------------------------------------
// 1) SORTING COM std::sort
// -------------------------------------------------------------

// 1.1) Ordenação crescente padrão
{
    vector<int> v = {4,1,3,2,5};
    sort(v.begin(), v.end());  // O(N log N)
    // v == {1,2,3,4,5}
}

// 1.2) Ordenação decrescente via lambda
{
    vector<int> v = {4,1,3,2,5};
    sort(v.begin(), v.end(),
         [](int a,int b){ return a > b; }
    );  // compara invertido
    // v == {5,4,3,2,1}
}

// 1.3) Ordenação usando função externa
bool cmpDesc(int a,int b){ return a > b; }
{
    vector<int> v = {4,1,3,2,5};
    sort(v.begin(), v.end(), cmpDesc);
    // v == {5,4,3,2,1}
}

// 1.4) Ordenando vector<vector<int>> por dois critérios
{
    vector<vector<int>> mat = {{1,5},{1,3},{2,4},{2,2}};
    sort(mat.begin(), mat.end(),
         [](auto &A, auto &B){
            if (A[0] != B[0]) 
                return A[0] < B[0];  // primeiro campo
            return A[1] < B[1];      // em empate, segundo
         }
    );
    // mat == {{1,3},{1,5},{2,2},{2,4}}
}

// -------------------------------------------------------------
// 2) BUSCA SEQUENCIAL
// -------------------------------------------------------------
{
    vector<int> v = {4,1,3,2,5};
    int key = 3;
    // find percorre linearmente
    auto it = find(v.begin(), v.end(), key);
    if (it != v.end()) {
        size_t pos = it - v.begin();  // índice onde encontrou
        // pos == 2
    }
    else {
        // não encontrado
    }
}

// -------------------------------------------------------------
// 3) BUSCA BINÁRIA e UTILITÁRIOS (vetor ordenado!)
// -------------------------------------------------------------
{
    vector<int> v = {1,2,3,4,5,5,6};
    int x = 5;

    // 3.1) binary_search: retorna bool
    bool found = binary_search(v.begin(), v.end(), x);
    // found == true

    // 3.2) lower_bound: primeiro >= x
    auto lb = lower_bound(v.begin(), v.end(), x);
    // *lb == 5, pos = 4 (primeira ocorrência)

    // 3.3) upper_bound: primeiro > x
    auto ub = upper_bound(v.begin(), v.end(), x);
    // *ub == 6, pos = 6

    // 3.4) contar ocorrências de x
    size_t count = ub - lb;  // 2 vezes o valor 5 aparece
}

// -------------------------------------------------------------
// RESUMO COMPLEXIDADES
// -------------------------------------------------------------
// sort, stable_sort : O(N log N)
// find              : O(N)
// binary_search     : O(log N)
// lower_bound       : O(log N)
// upper_bound       : O(log N)