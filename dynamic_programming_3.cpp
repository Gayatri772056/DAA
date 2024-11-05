/*Implement Check if it is possible to transform one string to
another.
Statement Given two strings s1 and s2 (all letters in uppercase).
Check if it is possible to convert s1 to s2 by performing following
operations.
1. Make some lowercase letters uppercase.
2. Delete all the lowercase letters.
Input: s1 = daBcd s2 = ABC Output: yes
Input: s1 = argaju s2 = RAJ Output: yes
*/
// C++ program to check if a string can
// be converted to another string by
// performing operations
#include <bits/stdc++.h>
using namespace std;

// function to check if a string can be
// converted to another string by
// performing the following operations
bool canConvert(string source, string target)
{
    // Get lengths of the source and target strings
    int sourceLen = source.length();
    int targetLen = target.length();

    // dp[i][j] will be true if it's possible to convert the first i characters
    // of source to the first j characters of target
    bool dp[sourceLen + 1][targetLen + 1];

    // Initialize dp table with false
    for (int i = 0; i <= sourceLen; i++) {
        for (int j = 0; j <= targetLen; j++) {
            dp[i][j] = false;
        }
    }

    // Base case: Both strings are empty at the start
    dp[0][0] = true;

    // Traverse through each character of source and target
    for (int i = 0; i < source.length(); i++) {
        for (int j = 0; j <= target.length(); j++) {

            // If it's possible to convert the first i characters of source to
            // the first j characters of target
            if (dp[i][j]) {

                // If the current character of source (uppercased) matches the
                // current character of target, move to the next character in both strings
                if (j < target.length() && toupper(source[i]) == target[j])
                    dp[i + 1][j + 1] = true;

                // If the current character of source is lowercase, we can delete it
                if (!isupper(source[i]))
                    dp[i + 1][j] = true;
            }
        }
    }

    // Return whether it's possible to convert all characters of source to target
    return (dp[sourceLen][targetLen]);
}

// driver code
int main()
{
    string source = "daBcd";
    string target = "ABC";

    if (canConvert(source, target))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
