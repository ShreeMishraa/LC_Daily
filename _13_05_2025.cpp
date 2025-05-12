//Problem Summary: 2094. Finding 3-Digit Even Numbers
/*You are given an array of digits (0–9), possibly with duplicates.
Your task is to find all unique 3-digit even numbers that can be formed by using exactly 3 digits from the array (in any order), such that:
No leading zero (e.g., 012 is invalid).
Last digit must be even (i.e., 0, 2, 4, 6, 8).
Each digit used only as many times as it appears in the array.
Return: A sorted list of valid numbers (no duplicates).*/

#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int d : digits) count[d]++;  // Count frequency of each digit

        set<int> result;

        // Generate all 3-digit numbers from 100 to 998 (step by 2 to ensure even numbers)
        for (int num = 100; num <= 999; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> tempCount = count;
            if (--tempCount[a] >= 0 &&
                --tempCount[b] >= 0 &&
                --tempCount[c] >= 0) {
                result.insert(num);
            }
        }

        return vector<int>(result.begin(), result.end());
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> digits = {2, 1, 3, 0};
    vector<int> evenNumbers = solution.findEvenNumbers(digits);
    
    // Output the result
    for (int num : evenNumbers) {
        cout << num << " ";
    }
    return 0;
}