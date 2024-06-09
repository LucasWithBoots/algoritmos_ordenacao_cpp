#include <iostream>
#include <cstdlib> // para srand() e rand()
#include <ctime>   // para time()

using namespace std;

int leituraCount = 0; // Contador de leituras
int escritaCount = 0; // Contador de escritas

void gerarVetor(int vetor[], int tamanho, string ordem) {
    if (ordem == "crescente") {
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = i + 1;
        }
    } else if (ordem == "decrescente") {
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = tamanho - i;
        }
    } else if (ordem == "aleatorio") {
        srand(time(0)); // Inicializa a semente com o tempo atual
        for (int i = 0; i < tamanho; ++i) {
            vetor[i] = rand() % tamanho + 1;
            for (int j = 0; j < i; ++j) {
                if (vetor[i] == vetor[j]) {
                    --i;
                    break;
                }
            }
        }
    }
}

// https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            leituraCount += 2; // Lendo arr[j] e arr[j + 1]
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                escritaCount += 2; // Escrevendo arr[j] e arr[j + 1]
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

// https://www.geeksforgeeks.org/insertion-sort/
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        leituraCount++; // Lendo arr[i]
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            leituraCount += 2; // Lendo arr[j] e key
            arr[j + 1] = arr[j];
            escritaCount++; // Escrevendo arr[j + 1]
            j = j - 1;
        }
        arr[j + 1] = key;
        escritaCount++; // Escrevendo arr[j + 1]
    }
}

// https://www.geeksforgeeks.org/selection-sort/
void selectionSort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        leituraCount++; // Lendo min_idx
        for (j = i + 1; j < n; j++) {
            leituraCount++; // Lendo arr[j]
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
                leituraCount++; // Lendo min_idx
            }
        }
        if (min_idx != i) {
            swap(arr[min_idx], arr[i]);
            escritaCount += 2; // Escrevendo arr[min_idx] e arr[i]
        }
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

int main() {
    int tam = 10;
    int vetorteste[tam];

    gerarVetor(vetorteste, tam, "aleatorio");

    cout << "Vetor original:" << endl;
    printArray(vetorteste, tam);

    cout << "\n" << endl;

    insertionSort(vetorteste, tam);

    cout << "Vetor modificado em ordem:" << endl;
    printArray(vetorteste, tam);

    cout << "\n\nTotal de leituras: " << leituraCount << endl;
    cout << "Total de escritas: " << escritaCount << endl;

    std::cout << "\nFim do codigo!" << std::endl;
    return 0;
}
