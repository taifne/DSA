#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> dp(n, 1);  

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());  
    }
};

int main() {
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of longest increasing subsequence: " << solution.lengthOfLIS(nums) << endl;
    return 0;
}
