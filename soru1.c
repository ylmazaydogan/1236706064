#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipleri
void insertionSort(int arr[], int n);
void selectionSort(int arr[], int n);

int main() {
    srand(time(NULL));

    // X dizisi oluştur
    int n = 500;
    int X[5];
    for (int i = 0; i < n; ++i) {
        X[i] = rand() % 1001; // 0-1000 arası rasgele tamsayılar
    }

    // Birleştirmeli Sıralama (Merge Sort)
    clock_t start_time = clock();
    // Merge Sort işlemleri burada gerçekleştirilir
    clock_t end_time = clock();
    double merge_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Seçmeli Sıralama (Selection Sort)
    start_time = clock();
    // Selection Sort işlemleri burada gerçekleştirilir
    clock_t end_time = clock();
    double selection_sort_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Birleştirmeli Sıralama süresi: %.6f saniye\n", merge_sort_time);
    printf("Seçmeli Sıralama süresi: %.6f saniye\n", selection_sort_time);

    return 0;
}

void insertionSort(int arr[], int n) {
    // Insertion Sort işlemleri burada gerçekleştirilir
}

void selectionSort(int arr[], int n) {
    // Selection Sort işlemleri burada gerçekleştirilir
}
