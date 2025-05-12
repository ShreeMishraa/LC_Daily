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