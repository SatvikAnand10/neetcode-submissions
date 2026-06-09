class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" &&
                tokens[i] != "-" &&
                tokens[i] != "*" &&
                tokens[i] != "/"){
                    st.push(stoi(tokens[i]));
                }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c;
                if(tokens[i]=="+") c=b+a;
                else if(tokens[i]=="*") c=a*b;
                else if(tokens[i]=="-") c=b-a;
                else {c=b/a;}

                st.push(c);
            }
        }
        return st.top();
    }
};