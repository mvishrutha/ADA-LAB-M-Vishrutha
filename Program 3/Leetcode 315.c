#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair* arr, int left, int mid, int right,
           int* counts, Pair* temp) {

    int i = left;
    int j = mid + 1;
    int k = left;

    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            temp[k++] = arr[j++];
            rightCount++;
        } else {
            counts[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        counts[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(Pair* arr, int left, int right,
               int* counts, Pair* temp) {

    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, counts, temp);
    mergeSort(arr, mid + 1, right, counts, temp);

    merge(arr, left, mid, right, counts, temp);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* counts = calloc(numsSize, sizeof(int));

    Pair* arr = malloc(numsSize * sizeof(Pair));
    Pair* temp = malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, counts, temp);

    free(arr);
    free(temp);

    return counts;
}
