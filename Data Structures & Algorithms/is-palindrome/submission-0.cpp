class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for(auto a:s){
            if(isalnum(a)){
                st+=tolower(a);
            }
        }
        string orignal=st;
        string reversed(orignal.rbegin(),orignal.rend());
        if(orignal==reversed){
            return true;
        }
        return false;
    }
};
