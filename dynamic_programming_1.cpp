/*Implement Coin Change problem.
Statement Given an integer array of coins[ ] of size N representing
different types of currency and an integer sum, The task is to find
the number of ways to make sum by using different combinations
from coins[].
Note: Assume that you have an infinite supply of each type of
coin.
Input: sum = 4, coins[] = {1,2,3}, Output: 4
Input: sum = 10, coins[] = {2, 5, 3, 6} Output: 5      */
#include <iostream>
#include <cstring>
using namespace std;

// This code counts the number of ways to make a given sum with a set of coins
int countWaysToMakeSum(int denominations[], int numCoins, int targetSum)
{
    // dp[i] will store the number of ways to make sum i
    int dp[targetSum + 1];

    // Initialize all dp values as 0
    memset(dp, 0, sizeof(dp));

    // Base case: There is 1 way to make sum 0 (by choosing no coins)
    dp[0] = 1;

    // Process each coin one by one
    for (int i = 0; i < numCoins; i++)
        for (int j = denominations[i]; j <= targetSum; j++)
            dp[j] += dp[j - denominations[i]];
    
    return dp[targetSum];
}

// Driver Code
int main()
{
    int denominations[] = { 1, 2, 3 };
    int numCoins = sizeof(denominations) / sizeof(denominations[0]);
    int targetSum = 5;
    
    cout << countWaysToMakeSum(denominations, numCoins, targetSum);
    return 0;
}
