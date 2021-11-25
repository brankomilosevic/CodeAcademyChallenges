/*
*** The Knapsack Problem ***

Imagine that you are a thief breaking into a house. 
There are so many valuables to steal, but you’re just one person who can only carry so much. 
Each item has a weight and value, and your goal is to maximize the total value of items while remaining within the weight limit of your knapsack. 

Create a knapsack() method that takes in:

    the total amount of weight you can carry
    an array of the weights of all of the items
    an array of the values of all of the items
    and returns the maximum value that you will be able to carry.

For example, 

#1
W = 10 units of weight. 
weights = [3, 6, 8]
values = [50, 60, 100]
result: 110

#2
W = 50
weights = { 10, 20, 30 }
values = { 60, 100, 120 }
result: 220

Your knapsack function should return 110 since you can carry the first and second items, whose values total 110. 
If you tried to carry the third item, which has the value of 100, you wouldn’t be able to fit anything else in the knapsack.

Solution #1
Pure recursion, not time optimized, candidate for dynamic

Solution #2
Recursion with memoization
*/

#include<stdio.h>

/*
// pure recursive 
int knapsack(int W, int *weights, int *values, int n)
{
    int res = 0;

    if (W == 0 || n == 0) return 0;

    if (weights[n-1] > W) 
    {
        return knapsack(W, weights, values, n-1);
    }
    else
    {
        int val_1 = values[n-1] + knapsack(W - weights[n-1], weights, values, n-1);
        int val_2 = knapsack(W, weights, values, n-1);
        return (val_1 > val_2) ? val_1 : val_2;
    }

    return res;
}
*/

// recursive with memoization
int knapsackRec(int W, int *weights, int *values, int i, int dp[i][W+1])
{
    if (i < 0) return 0;

    if (dp[i][W] != -1) return dp[i][W];

    if (weights[i] > W) 
    {
        dp[i][W] = knapsackRec(W, weights, values, i - 1, dp);
    }
    else
    {
        int val_1 = values[i] + knapsackRec(W - weights[i], weights, values, i - 1, dp);
        int val_2 = knapsackRec(W, weights, values, i - 1, dp);

        dp[i][W] = (val_1 > val_2) ? val_1 : val_2;  
    }
    return dp[i][W];

}

int knapsack(int W, int *weights, int *values, int n)
{
    int dp[n][W+1];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= W; ++j)
            dp[i][j] = -1;

    return knapsackRec(W, weights, values, n-1, dp);
}


int main(void)
{
    int weights[] = {3, 6, 8};
    int values[] = {50, 60, 100};
    int W = 10;

    // int weights[] = { 10, 20, 30 };
    // int values[] = { 60, 100, 120 };
    // int W = 50;

    int n = sizeof(weights) / sizeof(weights[0]);

    printf("\nKnapsack value: %d", knapsack(W, weights, values, n));

    return 0;
}