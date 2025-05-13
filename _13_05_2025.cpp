//3335. Total Characters in String After Transformations I (med)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int totalLengthAfterTransformations(string s, int t) {
    // dp[c][i] = length of transforming character 'a'+c for i steps
    vector<vector<int>> dp(26, vector<int>(t + 1, 0));

    // Base case: at t = 0, length is 1 for each character
    for (int c = 0; c < 26; ++c) {
        dp[c][0] = 1;
    }

    // Build DP table
    for (int i = 1; i <= t; ++i) {
        for (int c = 0; c < 26; ++c) {
            if (c == 25) {
                // 'z' becomes "ab"
                dp[c][i] = (dp[0][i - 1] + dp[1][i - 1]) % MOD;
            } else {
                // other characters become next character
                dp[c][i] = dp[c + 1][i - 1];
            }
        }
    }

    // Calculate final result
    long long result = 0;
    for (char ch : s) {
        int idx = ch - 'a';
        result = (result + dp[idx][t]) % MOD;
    }

    return static_cast<int>(result);
}

int main() {
    // Example usage:
    string s1 = "abcyy";
    int t1 = 2;
    cout << totalLengthAfterTransformations(s1, t1) << endl;  // Output: 7

    string s2 = "azbk";
    int t2 = 1;
    cout << totalLengthAfterTransformations(s2, t2) << endl;  // Output: 5

    return 0;
}
