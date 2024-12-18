#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
      
        result.push_back(current);
        
      
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]); 
            backtrack(nums, result, current, i + 1);  
            current.pop_back();  
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        
        backtrack(nums, result, current, 0);
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    
    vector<vector<int>> result = solution.subsets(nums);
    
    // Output the result
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
