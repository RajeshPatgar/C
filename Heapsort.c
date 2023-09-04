#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int a[], int n, int i) {
    int temp;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    int i, temp;
    
    // Build a max heap
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    // Extract elements one by one
    for (i = n - 1; i >= 0; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        heapify(a, i, 0);
    }
}

int main() {
    int n, i, a[100];
    clock_t end, start;
    double clk;

    printf("Enter the number of resumes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
        a[i] = rand() % 100;

    printf("Candidates ranks\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    start = clock();
    heapSort(a, n);
    end = clock();

    printf("\nSorted Candidates ranks\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    clk = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nRuntime is %f sec", clk);

    return 0;
}
