#include <bits/stdc++.h> 
using namespace std; 

// Function to find all subsets of the given set.
// Any repeated subset is considered only once in the output.
vector<vector<int>> findPowerSet(vector<int>& nums) { 
    int bits = nums.size(); 
    unsigned int pow_set_size = pow(2, bits); 

    // Sort the array to handle duplicates easily
    sort(nums.begin(), nums.end()); 
    vector<vector<int>> ans; 
    vector<string> list; 

    // Iterate from 0 to 2^n - 1 to generate all subsets
    for (int counter = 0; counter < pow_set_size; counter++) { 
        vector<int> subset; 
        string temp = ""; 

        // Generate each subset based on the bits of 'counter'
        for (int j = 0; j < bits; j++) { 
            if (counter & (1 << j)) { 
                subset.push_back(nums[j]); 
                temp += to_string(nums[j]) + '$'; // Create a unique string for the subset
            } 
        } 

        // If this subset has not been added, add it to the result
        if (find(list.begin(), list.end(), temp) == list.end()) { 
            ans.push_back(subset); 
            list.push_back(temp); 
        } 
    } 

    return ans; 
} 

int main() { 
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the set: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> power_set = findPowerSet(arr); 

    cout << "Distinct subsets are:\n";
    for (int i = 0; i < power_set.size(); i++) { 
        cout << "{ ";
        for (int j = 0; j < power_set[i].size(); j++) 
            cout << power_set[i][j] << " "; 
        cout << "}\n"; 
    } 

    return 0; 
} 
