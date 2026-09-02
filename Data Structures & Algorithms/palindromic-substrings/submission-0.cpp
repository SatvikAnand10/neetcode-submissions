class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n==1) return 1;
        int total=0;

        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                total++;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                total++;
                l--;
                r++;
            }
        }
        return total;
    }
};
