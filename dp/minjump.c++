#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= i + nums[i] && j < n; ++j) {
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }

        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Minimum jumps: " << solution.jump(nums) << endl;
    return 0;
}
