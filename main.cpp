#include <iostream>

// Função para trocar dois elementos
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para particionar o array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Escolhe o último elemento como pivô
    int i = (low - 1); // Índice do menor elemento

    for (int j = low; j < high; j++) {
        // Se o elemento atual é menor ou igual ao pivô
        if (arr[j] <= pivot) {
            i++; // Incrementa o índice do menor elemento
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Particiona o array
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
    int size = sizeof(v) / sizeof(v[0]);

    std::cout << "Array original: ";
    printArray(v, size);

    quickSort(v, 0, size - 1);

    std::cout << "Array ordenado: ";
    printArray(v, size);

    return 0;
}
