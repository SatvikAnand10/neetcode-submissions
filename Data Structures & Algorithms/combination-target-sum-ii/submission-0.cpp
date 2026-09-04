class Solution {
public:
    vector<vector<int>> ans;
    void backtracking(int i,vector<int>& candidates,int target,vector<int>& subset){
        if(target==0){
            ans.push_back(subset);
            return;
        }
        if(i>=candidates.size() || target<0) return;

        //case1
        subset.push_back(candidates[i]);
        backtracking(i+1,candidates,target-candidates[i],subset);
        subset.pop_back();
        
        //case2
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        backtracking(i+1,candidates,target,subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        backtracking(0,candidates,target,subset);
        return ans;
    }
};
