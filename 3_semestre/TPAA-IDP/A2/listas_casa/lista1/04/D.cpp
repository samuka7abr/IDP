#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node{
    int chave;
    Node* esq;
    Node* dir;
    Node(int item){
        chave = item;
        esq = NULL;
        dir = NULL;
    }
};

Node* inserir(Node* node, int chave){
    if(node == NULL){
        return new Node(chave);
    }

    if(node->chave == chave){
        return node;
    }

    if(node->chave < chave){
        node->dir = inserir(node->dir, chave);
    }else{
        node->esq = inserir(node->esq, chave);
    }

    return node;
}

void emOrdem(Node* node){
    if(node == nullptr){
        return;
    }

    emOrdem(node->esq);
    cout << node->chave << " ";
    emOrdem(node->dir);
}


void preOrdem(Node* node){
    if(node == nullptr){
        return;
    }
    
    cout << node->chave << " ";
    preOrdem(node->esq);
    preOrdem(node->dir);
}

void posOrdem(Node* node){

    if(node == nullptr){
        return;
    }

    posOrdem(node->esq);
    posOrdem(node->dir);
    cout << node->chave << " ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    Node* raiz = nullptr;

    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        raiz = inserir(raiz, x);
    }

    cout << "In.: ";
    emOrdem(raiz);
    cout << endl;

    cout << "Pre: ";
    preOrdem(raiz);
    cout << endl;

    cout << "Pos: ";
    posOrdem(raiz);
    cout << endl;

    return 0;
}
