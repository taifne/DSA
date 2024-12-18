#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void backtrack(int open, int close, int n, string current, vector<string>& result) {
    
        if (current.size() == 2 * n) {
            result.push_back(current);
            return;
        }


        if (open < n) {
            backtrack(open + 1, close, n, current + "(", result);
        }

        if (close < open) {
            backtrack(open, close + 1, n, current + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(0, 0, n, "", result); 
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);
    
 
    for (const string& combination : result) {
        cout << combination << endl;
    }

    return 0;
}
