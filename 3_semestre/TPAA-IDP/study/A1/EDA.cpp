#include <bits/stdc++.h>
using namespace std;

/*
 * == PRINCIPAIS ESTRUTURAS DE DADOS em C++ ==
 * Complexidades típicas e operações mais usadas.
 */

// ————————————————————————————————————————————————
// VECTOR<T>
// ————————————————————————————————————————————————
// Acesso aleatório contíguo.
// - at(i)             : O(1) com verificação de faixa
// - operator[](i)     : O(1)
// - front(), back()   : O(1)
// - empty(), size()   : O(1)
// - capacity(), reserve(n), shrink_to_fit()
//                     : O(1)/O(N)
// - clear()           : O(N)
// - push_back(x)      : O(1) amortizado
// - emplace_back(args): O(1) amortizado
// - pop_back()        : O(1)
// - insert(pos, x)    : O(N)
// - emplace(pos,args) : O(N)
// - erase(pos)        : O(N)
// - resize(n)         : O(N)

void demoVector() {
    vector<int> v;        // inicia vazio
    v.reserve(10);        // aloca espaço para 10 elementos

    // inserções no final
    v.push_back(1);
    v.emplace_back(2);
    v.push_back(3);

    // inserção no meio (idx=1)
    v.insert(v.begin()+1, 42);

    // acesso
    cout << "v[1]=" << v[1] << ", front=" << v.front()
         << ", back=" << v.back() << "\n";

    // remoções
    v.erase(v.begin()+2);
    v.pop_back();

    // capacidade e limpeza
    cout << "size=" << v.size()
         << ", cap=" << v.capacity() << "\n";
    v.clear();
}

// ————————————————————————————————————————————————
// LIST<T> (lista duplamente encadeada)
// ————————————————————————————————————————————————
// - push_front/back, pop_front/back: O(1)
// - insert(it,x), emplace(it,args): O(1)
// - erase(it): O(1)
// - remove(val), unique(), splice(): O(N)
// - front(), back(), empty(), size(): O(1)

void demoList() {
    list<int> L;
    L.push_back(10);
    L.push_front(5);
    auto it = L.begin(); ++it;
    L.emplace(it, 7);
    cout << "List: ";
    for (int x : L) cout << x << " ";
    cout << "\n";
}

// ————————————————————————————————————————————————
// STACK<T> (adaptador de contêiner)
// ————————————————————————————————————————————————
// LIFO: push, pop, top, empty, size — todos O(1)

void demoStack() {
    stack<int> st;  // por padrão usa deque
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Stack topo->base: ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}

// ————————————————————————————————————————————————
// QUEUE<T> (adaptador de contêiner)
// ————————————————————————————————————————————————
// FIFO: push, pop, front, back, empty, size — todos O(1)

void demoQueue() {
    queue<char> q;  // por padrão usa deque
    q.push('X');
    q.push('Y');
    q.push('Z');
    cout << "Queue front->back: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";
}

// ————————————————————————————————————————————————
// MAIN
// ————————————————————————————————————————————————
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "--- VECTOR ---\n";    demoVector();
    cout << "--- LIST ---\n";      demoList();
    cout << "--- STACK ---\n";     demoStack();
    cout << "--- QUEUE ---\n";     demoQueue();

    return 0;
}
