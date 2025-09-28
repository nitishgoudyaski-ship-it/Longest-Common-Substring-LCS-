#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

// Function to compute Longest Common Substring(s)
void longestCommonSubstring(const string &s1, const string &s2) {
    int m = s1.size();
    int n = s2.size();

    // DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;

    // Store all substrings with max length
    set<string> substrings;

    // Fill DP table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    substrings.clear(); // reset because we found a longer substring
                    substrings.insert(s1.substr(i - maxLen, maxLen));
                } else if (dp[i][j] == maxLen && maxLen > 0) {
                    substrings.insert(s1.substr(i - maxLen, maxLen));
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // Print DP Table
    cout << "\nDP Lookup Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // Print results
    cout << "\nLongest Common Substring length: " << maxLen << endl;
    cout << "Substring(s): ";
    for (auto &sub : substrings) {
        cout << sub << " ";
    }
    cout << endl;
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    // Ensure both strings have same length (assignment assumption)
    if (s1.length() != s2.length()) {
        cout << "Error: Strings must be of the same length for this assignment.\n";
        return 1;
    }

    cout << "\nString 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    longestCommonSubstring(s1, s2);

    return 0;
}
