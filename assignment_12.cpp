#include <iostream>
using namespace std;

// Function to find the subsets of the given array
void generateSubsets(int elements[], int size)
{
    // Loop through all possible subsets using bit manipulation
    for (int subsetMask = 0; subsetMask < (1 << size); subsetMask++) {

        // Loop through all elements of the input array
        for (int i = 0; i < size; i++) {

            // Check if the ith bit is set in the current subset
            if ((subsetMask & (1 << i)) != 0) {

                // If the ith bit is set, add the ith element to the subset
                cout << elements[i] << " ";
            }
        }

        cout << endl;
    }
}

// Driver Code
int main()
{
    int arr[] = { 1, 2, 3 };
    int n = sizeof(arr)/sizeof(arr[0]);
    generateSubsets(arr, n);
}
