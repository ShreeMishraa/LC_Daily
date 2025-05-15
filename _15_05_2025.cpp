//2900. Longest Unequal Adjacent Groups Subsequence I

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> result;

        result.push_back(words[0]);
        int lastGroup = groups[0];

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != lastGroup) {
                result.push_back(words[i]);
                lastGroup = groups[i];
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 0, 1, 1};

    vector<string> res = sol.getLongestSubsequence(words, groups);

    cout << "Longest alternating subsequence: ";
    for (const string& word : res) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
