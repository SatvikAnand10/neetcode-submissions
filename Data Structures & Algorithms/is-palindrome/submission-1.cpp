class Solution {
public:
    bool isPalindrome(string s) {
        int a=0;
        int b=s.size()-1;
        while(a<b){
            while(a<b && !isalnum(s[a])) a++;
            while(a<b && !isalnum(s[b])) b--;
            if(tolower(s[a])!=tolower(s[b])){
                return false;
            }
            a++;
            b--;
        }
        return true;
    }
};
