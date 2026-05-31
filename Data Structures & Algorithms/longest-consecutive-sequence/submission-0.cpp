class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        us.insert(nums.begin(),nums.end());
        int ans=0;
        for(auto a:nums){
            int streak=0;
            int curr=a;
            while(us.find(curr)!=us.end()){
                streak++;
                curr++;
            }
            ans=max(ans,streak);
        }
        return ans;
    }
};
