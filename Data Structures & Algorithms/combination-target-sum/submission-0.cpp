class Solution {
public:
    vector<vector<int>> ans;
    vector<int> subset;
    void backtracking(int i,vector<int>& nums,int target,vector<int>& subset){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(target<0 || i>=nums.size()) return;
        //case1
        subset.push_back(nums[i]);
        target-=nums[i];
        backtracking(i,nums,target,subset);
        //case2
        subset.pop_back();
        target+=nums[i];
        backtracking(i+1,nums,target,subset);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtracking(0,nums,target,subset);
        return ans;
    }
};
