class Solution {
public:
    vector<string> ans;

    void dfs(int n, string& s, int& open, int& close) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        // add '('
        if (open < n) {
            s += '(';
            open++;

            dfs(n, s, open, close);

            s.pop_back();
            open--;
        }

        // add ')'
        if (close < open) {
            s += ')';
            close++;

            dfs(n, s, open, close);

            s.pop_back();
            close--;
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        int open = 0;
        int close = 0;

        dfs(n, s, open, close);

        return ans;
    }
};