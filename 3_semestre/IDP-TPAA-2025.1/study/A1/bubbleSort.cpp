#include <iostream>
#include <vector>

void bubbleSort(std::vector<int>& v) {
    int n = v.size();
    int troca = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {  
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
                troca = true; 
            }
        }
    if(troca == false){ // um bubble sort esperto adiciona esse break para evitar percorrer o array desnecessáriamente 
        break;
    }
    }
}

int main() {
    std::vector<int> v = {5, 1, 4, 2, 8};

    bubbleSort(v);

    for (auto i : v)
        std::cout << i << " ";  
    std::cout << std::endl;

    return 0;
}
