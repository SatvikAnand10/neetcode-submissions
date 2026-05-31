class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto str:strs){
            int a=str.size();
            string c=to_string(a);
            s+=c+"#"+str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int len=stoi(s.substr(i,j-i));
            string a=s.substr(j+1,len);
            ans.push_back(a);
            i = j + 1 + len;
        }
        return ans;
    }
};
