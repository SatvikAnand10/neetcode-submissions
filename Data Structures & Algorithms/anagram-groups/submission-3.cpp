class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        for(const auto& s:strs){
            vector <int> vec(26,0);
            for(auto q:s){
                vec[q-'a']++;
            }
            string key="";
            for(auto r:vec){
                key+= ","+ to_string(r);
            }
            um[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto& w:um){
            ans.push_back(w.second);
        }
        return ans;
    }
};
