#include <stdlib.h>

int* sortArray(int* nums, int numsSize, int* returnSize) {
    int offset = 50000;
    int range = 100001;

    int *count = calloc(range, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        count[nums[i] + offset]++;
    }

    int k = 0;

    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            nums[k++] = i - offset;
            count[i]--;
        }
    }

    free(count);

    *returnSize = numsSize;
    return nums;
}
