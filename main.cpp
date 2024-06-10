#include <iostream>
#include <cstdlib> // para srand() e rand()
#include <ctime>   // para time()

using namespace std;

long int leituraCount = 0; // Contador de leituras
long int escritaCount = 0; // Contador de escritas

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

void resetCounters() {
    leituraCount = 0;
    escritaCount = 0;
}

int main() {
    int tamanhos[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    int numTamanhos = sizeof(tamanhos) / sizeof(tamanhos[0]);

    cout << "TAMANHO_DO_VETOR BubbleSort InsertionSort SelectionSort" << endl;

    for (int i = 0; i < numTamanhos; i++) {
        int tam = tamanhos[i];
        int *vetorteste = new int[tam];

        gerarVetor(vetorteste, tam, "aleatorio");

        // Ordenação com BubbleSort
        resetCounters();
        bubbleSort(vetorteste, tam);
        long int bubbleSortLeiturasEscritas = leituraCount + escritaCount;

        gerarVetor(vetorteste, tam, "aleatorio");

        // Ordenação com InsertionSort
        resetCounters();
        insertionSort(vetorteste, tam);
        long int insertionSortLeiturasEscritas = leituraCount + escritaCount;

        gerarVetor(vetorteste, tam, "aleatorio");

        // Ordenação com SelectionSort
        resetCounters();
        selectionSort(vetorteste, tam);
        long int selectionSortLeiturasEscritas = leituraCount + escritaCount;

        cout << tam << " " << bubbleSortLeiturasEscritas << " " << insertionSortLeiturasEscritas << " " << selectionSortLeiturasEscritas << endl;

        delete[] vetorteste;
    }

    std::cout << "Fim do codigo!" << std::endl;
    return 0;
}
