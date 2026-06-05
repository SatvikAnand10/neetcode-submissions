class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> us;
        int l=0;
        int r=0;
        int ans=0;
        while(r<s.size()){
            if(us.contains(s[r])){
                us.erase(s[l]);
                l++;
            }
            else{
                us.insert(s[r]);
                ans=max(ans,r-l+1);
                r++;                
            }            
        }
        return ans;
    }
};