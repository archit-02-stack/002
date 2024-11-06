#include <iostream>
#include <algorithm>

using namespace std;

struct Item {
    int value, weight;
};

int zeroOneKnapsack(int capacity, Item items[], int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;  
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    if (n <= 0) {
        cout << "The number of items must be greater than 0." << endl;
        return 1;
    }

    Item* items = new Item[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "The knapsack capacity must be greater than 0." << endl;
        delete[] items;
        return 1;
    }

    int maxValue = zeroOneKnapsack(capacity, items, n);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    delete[] items;

    return 0;
}

