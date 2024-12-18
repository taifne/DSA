#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentPermutation;
        vector<bool> used(nums.size(), false); 
        
        backtrack(nums, currentPermutation, used, result);
        
        return result;
    }

private:
    void backtrack(vector<int>& nums, vector<int>& currentPermutation, vector<bool>& used, vector<vector<int>>& result) {
     
        if (currentPermutation.size() == nums.size()) {
            result.push_back(currentPermutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
           
            if (used[i]) continue;
            currentPermutation.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, currentPermutation, used, result);
            currentPermutation.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = solution.permute(nums);

    cout << "All permutations of the array are: \n";
    for (auto& permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
