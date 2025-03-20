#include <stdio.h>
#include <stdlib.h>

int knapsack(int weights[], int values[], int n, int W) {
    int i, w;
    int **K = (int **)malloc((n+1)*sizeof(int *));
    for(i = 0; i <= n; i++)
        K[i] = (int *)malloc((W+1)*sizeof(int));

    for(i = 0; i <= n; i++) {
        for(w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                K[i][w] = 0;
            else if(weights[i-1] <= w)
                K[i][w] = (values[i-1] + K[i-1][w-weights[i-1]] > K[i-1][w]) ?
                          values[i-1] + K[i-1][w-weights[i-1]] : K[i-1][w];
            else
                K[i][w] = K[i-1][w];
        }
    }
    int result = K[n][W];
    for(i = 0; i <= n; i++)
        free(K[i]);
    free(K);
    return result;
}

int main() {
    int weights[] = {1, 3, 4, 5};
    int values[] = {1, 4, 5, 7};
    int n = sizeof(values)/sizeof(values[0]);
    int W = 7;
    printf("Maximum value in knapsack = %d\n", knapsack(weights, values, n, W));
    return 0;
}
