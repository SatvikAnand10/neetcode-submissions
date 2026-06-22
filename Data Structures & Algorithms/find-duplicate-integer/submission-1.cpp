class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(auto a:nums){
            if(us.find(a)!=us.end()) return a;
            us.insert(a);
        }
        return -1;
    }
};
