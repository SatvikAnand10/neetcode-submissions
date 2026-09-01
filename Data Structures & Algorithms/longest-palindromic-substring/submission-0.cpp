class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string st="";
        int len=0;
        for(int i=0;i<s.size();i++){
            int l=i,r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    st=s.substr(l,len);
                }
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1>len){
                    len=r-l+1;
                    st=s.substr(l,len);
                }
                l--;
                r++;
            }
        }
        return st;
    }
};
