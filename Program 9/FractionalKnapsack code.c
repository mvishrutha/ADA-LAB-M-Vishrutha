#include <stdio.h>

// Structure for items
struct Item {
    int weight;
    int profit;
    float ratio;
};

// Function to swap two items
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Sort items based on profit/weight ratio (Descending) - Bubble Sort
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j].ratio < arr[j+1].ratio) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(struct Item arr[], int n, int capacity) {
    float totalProfit = 0.0;

    for (int i = 0; i < n; i++) {
        if (capacity >= arr[i].weight) {
            // Take full item
            totalProfit += arr[i].profit;
            capacity -= arr[i].weight;
        } else {
            // Take fraction of item
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    // Input weights and profits
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i+1);
        scanf("%d %d", &arr[i].weight, &arr[i].profit);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    // Sort items by ratio
    sortItems(arr, n);

    float maxProfit = fractionalKnapsack(arr, n, capacity);

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
