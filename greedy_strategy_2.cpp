//Greedy Strategy-2
/*Implement a problem of maximize Profit by trading stocks
based on given rate per day.
Statement: Given an array arr[] of N positive integers which
denotes the cost of selling and buying a stock on each of
the N days. The task is to find the maximum profit that can be
earned by buying a stock on or selling all previously bought stocks
on a particular day.
Input: arr[] = {2, 3, 5} Output: 5
Input: arr[] = {8, 5, 1} Output: 0
*/
#include <iostream>
using namespace std;

// Function to find the maximum profit
int calculateMaxProfit(int* priceList, int numDays) {
    int totalProfit = 0;
    int currentIndex = numDays - 1;

    // Start from the last day
    while (currentIndex > 0) {
        int previousIndex = currentIndex - 1;

        // Traverse and keep adding the profit until a day with a higher price than currentIndex is found
        while (previousIndex >= 0 && (priceList[currentIndex] > priceList[previousIndex])) {
            totalProfit += (priceList[currentIndex] - priceList[previousIndex]);
            previousIndex--;
        }

        // Set this day as currentIndex with the maximum cost of stock currently
        currentIndex = previousIndex;
    }

    // Return the total profit
    return totalProfit;
}

// Driver Code
int main() {
    int numDays;
    cout << "Enter the number of days: ";
    cin >> numDays;

    int priceList[numDays];
    cout << "Enter the prices for each day: ";
    for (int i = 0; i < numDays; i++) {
        cin >> priceList[i];
    }

    // Function Call
    int maxProfit = calculateMaxProfit(priceList, numDays);
    cout << "Maximum profit that can be earned: " << maxProfit << endl;

    return 0;
}
