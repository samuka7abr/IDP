#include <bits/stdc++.h>
using namespace std;

/*
    Criação e inicialização
        - unordered_set<T> guarda elementos únicos de tipo T.
        - unordered_map<Key,Value> guarda pares chave–valor.
    > Ambos podem ser inicializados via lista de inicializadores ou vazios, e aceitam parâmetros opcionais para customizar 
    > função de hash, comparador de igualdade e alocador.

    Inserção
        - insert(x) tenta inserir o elemento (ou par) e retorna um pair<iterator,bool> onde bool indica se a inserção realmente ocorreu.
        - emplace(...) constrói o elemento in-place, evitando cópias em alguns casos.
    
    Remoção e busca
        - erase(key) remove por chave.
        - count(key) informa se existe (0 ou 1 em unordered_set, número de elementos iguais em unordered_multiset).
        - find(key) retorna um iterador para o elemento, ou end() se não existir.

    Estado da tabela
        - size() dá o número de elementos armazenados.
        - bucket_count() informa quantos “slots” (buckets) a tabela tem.
        - bucket(key) diz em qual bucket uma chave está.
        - bucket_size(i) diz quantos elementos existem no bucket de índice i.
*/

int main(){
    // 1) Cria um unordered_set com alguns valores repetidos:
    //    duplicatas (7,7,7) são ignoradas, sobra {27, 21, 7, 12, 33}
    unordered_set<int> us {27, 21, 7, 12, 7, 7, 33};

    // 2) size() retorna quantos elementos únicos há:
    cout << us.size() << endl;
    // Saída: 5

    // 3) tenta inserir 7 de novo:
    auto r1 = us.insert(7);
    if(r1.second)
        cout << *r1.first << endl;
    else
        cout << "nao" << endl;
    // r1.second == false, pois 7 já estava lá
    // Saída: nao

    // 4) insere 8:
    auto r2 = us.insert(8);
    if(r2.second)
        cout << *r2.first << endl;
    // Saída: 8

    // 5) remove o elemento 12:
    us.erase(12);
    // agora us == {27, 21, 7, 33, 8}

    // 6) imprime todo o conjunto:
    for(auto x: us)
        cout << x << ' ';
    cout << '\n';
    // Saída (ordem arbitrária, ex.):
    // 33 7 8 27 21 

    // 7) quantos buckets a tabela está usando:
    cout << us.bucket_count() << '\n';
    // Saída (por exemplo): 8

    // 8) para cada elemento, mostra em qual bucket caiu:
    for(auto x: us)
        cout << us.bucket(x) << ' ';
    cout << "\n\n";
    // Saída (exemplo):
    // 5 2 3 0 6

    // ————————————————————————————————————————————————

    // 9) unordered_map<String,Double> inicializado com 3 entradas
    unordered_map<string,double> um {
        {"Maria", 1.68},
        {"Lucas", 1.59},
        {"Pedro", 1.74}
    };

    // 10) tamanho atual:
    cout << um.size() << '\n';
    // Saída: 3

    // 11) adiciona um par novo:
    um.insert({"Carlos", 1.78});

    // 12) agora têm 4 entradas:
    cout << um.bucket_count() << '\n';
    // Saída (por exemplo): 11

    // 13) imprime todas as chaves e valores (ordem arbitrária):
    for(auto &p: um)
        cout << p.first << ' ' << p.second << '\n';
    // Saída (exemplo):
    // Lucas 1.59
    // Pedro 1.74
    // Carlos 1.78
    // Maria 1.68

    // 14) para cada bucket, quantos elementos ele contém:
    for(size_t i = 0; i < um.bucket_count(); ++i)
        cout << i << ' ' << um.bucket_size(i) << '\n';
    // Saída (exemplo):
    // 0 1
    // 1 0
    // 2 0
    // 3 1
    // 4 0
    // 5 1
    // 6 0
    // 7 0
    // 8 0
    // 9 1
    // 10 0

    return 0;
}
