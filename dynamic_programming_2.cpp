#include <iostream>
#include <cstring> // For memset

using namespace std;

// Function to determine if there is a subset with the given sum
bool isSubsetSum(int arr[], int n, int sum) {
    bool prev[sum + 1];
    bool curr[sum + 1];
    
    // Initialize the array for sum = 0
    memset(prev, false, sizeof(prev));
    prev[0] = true; // Base case: sum 0 is always possible with an empty subset

    for (int i = 1; i <= n; i++) {
        memset(curr, false, sizeof(curr)); // Reset curr for the current i
        for (int j = 0; j <= sum; j++) {
        .
        
                curr[j] = prev[j];
            else
                curr[j] = (prev[j] || prev[j - arr[i - 1]]);
        }
        // Copy current state to previous state
        memcpy(prev, curr, sizeof(prev));
    }
    return prev[sum];
}

int main() {
    int n, sum;
    cout << "Enter the total number of elements in the set: ";
    cin >> n;

    int* arr = new int[n]; // Dynamically allocate memory for array
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the sum to find: ";
    cin >> sum;

    if (isSubsetSum(arr, n, sum)) {
        cout << "True";
    } else {
        cout << "False";
    }

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}

