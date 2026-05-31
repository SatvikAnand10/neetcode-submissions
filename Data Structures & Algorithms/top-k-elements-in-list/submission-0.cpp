class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for(auto a:nums){
            count[a]++;
        }
        for(auto a:count){
            freq[a.second].push_back(a.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--) {

    for(int num : freq[i]) {

        ans.push_back(num);

        if(ans.size() == k)
            return ans;
    }
}
        return ans;
    }
};
