class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    void backtracking(vector<int>& nums, int i,
                      vector<int>& subset) {

        if (i >= nums.size()) {
            ans.push_back(subset);
            return;
        }

        // Case 1: take nums[i]
        subset.push_back(nums[i]);
        backtracking(nums, i + 1, subset);

        // Case 2: don't take nums[i]
        subset.pop_back();
        backtracking(nums, i + 1, subset);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0, subset);
        return ans;
    }
};