#include <stdio.h>

#define MAX 20
#define LEFT 0
#define RIGHT 1

int findLargestMobile(int perm[], int dir[], int n) {
    int largestMobile = -1;
    int mobileIndex = -1;

    for (int i = 0; i < n; i++) {
        if (dir[i] == LEFT && i != 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > largestMobile) {
                largestMobile = perm[i];
                mobileIndex = i;
            }
        }

        if (dir[i] == RIGHT && i != n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > largestMobile) {
                largestMobile = perm[i];
                mobileIndex = i;
            }
        }
    }

    return mobileIndex;
}

void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i]);
    }
    printf("\n");
}

void johnsonTrotter(int n) {
    int perm[MAX], dir[MAX];

    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(perm, n);

    while (1) {
        int mobileIndex = findLargestMobile(perm, dir, n);

        if (mobileIndex == -1)
            break;

        int swapIndex;

        if (dir[mobileIndex] == LEFT)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;

        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;

        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;

        mobileIndex = swapIndex;

        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobileIndex]) {
                if (dir[i] == LEFT)
                    dir[i] = RIGHT;
                else
                    dir[i] = LEFT;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid input! Enter n between 1 and %d.\n", MAX);
        return 0;
    }

    printf("\nPermutations generated using Johnson Trotter Algorithm:\n");
    johnsonTrotter(n);

    return 0;
}
