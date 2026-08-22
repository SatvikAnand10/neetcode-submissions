class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;

        for(auto a:strs){
            vector<int>hash(26,0);
            for(auto b:a){
                hash[b-'a']++;
            }

            string s="";
            for(auto c:hash){
                s+=to_string(c);
                s+=',';
            }
            mpp[s].push_back(a);
        }
        vector<vector<string>>ans;
        for(auto p:mpp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
