class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> subset;
        sort(nums.begin(),nums.end());
        bfs(0,nums,ans,subset);
        return ans;
    }

    void bfs(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& subset){
        if(i==nums.size()){
            ans.push_back(subset);
            return;
        }

        //case1 take it
        subset.push_back(nums[i]);
        bfs(i+1,nums,ans,subset);
        subset.pop_back();

        //case2 dont take it
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        bfs(i+1,nums,ans,subset);
    }
};
