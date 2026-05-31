class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> wally;
        for(auto s:strs){
            string sorted=s;
            sort(sorted.begin(),sorted.end());
            wally[sorted].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto pair : wally){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
