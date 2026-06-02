#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array around a pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at correct position
        int pi = partition(arr, low, high);

        // Recursively sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Main program to test the Quick Sort and measure time
    int main()
{
    int n, i;
    int arr[100000];
    clock_t start, end;
    double time_ms;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    /* Generate random array */
    for (i = 0; i < n; i++)
        arr[i] = rand() % 100;

    printf("\nUnsorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    start = clock();

quickSort(arr,0,n-1);

end = clock();

time_ms = (((double)(end-start))/CLOCKS_PER_SEC) * 1000;

printf("\n\nSorted array:\n");
for(i=0;i<n;i++)
    printf("%d ",arr[i]);

printf("\n\nTime Taken= %f milliseconds\n",time_ms);

    return 0;
}
