/*Implement a problem of activity selection problem with K
persons.
Statement: Given two arrays S[] and E[] of size N denoting
starting and closing time of the shops and an integer
value K denoting the number of people, the task is to find out the
maximum number of shops they can visit in total if they visit each
shop optimally based on the following conditions:
 A shop can be visited by only one person
 A person cannot visit another shop if its timing collide with it
Input: S[] = {1, 8, 3, 2, 6}, E[] = {5, 10, 6, 5, 9}, K = 2
Output: 4
Input: S[] = {1, 2, 3}, E[] = {3, 4, 5}, K = 2
Output: 3
*/




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold shop timings
struct Shop {
    int start, end;
};

// Comparator function to sort shops based on their ending time
bool compare(Shop a, Shop b) {
    return a.end < b.end;
}

// Function to find the maximum number of shops that can be visited by K persons
int maxShopsVisited(vector<int>& S, vector<int>& E, int K) {
    int N = S.size();
    vector<Shop> shops(N);

    // Store the start and end times in the Shop structure
    for (int i = 0; i < N; ++i) {
        shops[i] = {S[i], E[i]};
    }

    // Sort the shops based on their end times
    sort(shops.begin(), shops.end(), compare);

    vector<int> persons(K, 0);
    int count = 0;

    // Assign shops to persons optimally
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            if (persons[j] <= shops[i].start) {
                persons[j] = shops[i].end;
                count++;
                break;
            }
        }
    }

    return count;
}

int main() {
    int N, K;
    
    // Input the number of shops
    cout << "Enter the number of shops: ";
    cin >> N;
    
    vector<int> S(N), E(N);
    
    // Input start times
    cout << "Enter the start times of the shops: ";
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    // Input end times
    cout << "Enter the end times of the shops: ";
    for (int i = 0; i < N; ++i) {
        cin >> E[i];
    }
    
    // Input the number of persons
    cout << "Enter the number of persons: ";
    cin >> K;

    // Calculate and output the maximum number of shops that can be visited
    cout << "Maximum shops visited: " << maxShopsVisited(S, E, K) << endl;

    return 0;
}
