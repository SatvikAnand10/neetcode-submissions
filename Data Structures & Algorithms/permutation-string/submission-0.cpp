class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> one;
        unordered_map<char,int> two;

        for(auto a:s1){
            one[a]++;
        }
        int l=0;
        for(int r=s1.size()-1;r<s2.size();r++){
            for(int j=l;j<=r;j++){
            two[s2[j]]++;
            }
            if(one==two) return true;
            two.clear();
            l++;
        }
        return false;
    }
};