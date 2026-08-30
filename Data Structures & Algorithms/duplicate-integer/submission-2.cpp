class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto a:nums){
            mp[a]++;
            if(mp[a]>1) return true;
        }
        return false;
    }
};