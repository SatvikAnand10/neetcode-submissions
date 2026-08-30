class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        
        vector<int> sa(26,0);
        vector<int> ta(26,0);

        for(int i=0;i<s.size();i++){
            sa[s[i]-'a']++;
            ta[t[i]-'a']++;
        }

        for(int i=0;i<26;i++){
            if(sa[i]!=ta[i]) return false;
        }
        return true;
    }
};
