class Solution {
public:
    vector<pair<int,int>> direc = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    bool dfs(int r, int c, vector<vector<char>>& board,
             string& word, int now) {

        // We matched the last character
        if (now == word.size() - 1)
            return true;

        // Mark current cell as visited
        char temp = board[r][c];
        board[r][c] = '#';

        for (auto a : direc) {
            int rn = r + a.first;
            int cn = c + a.second;

            // Check bounds + next character
            if (rn >= 0 && rn < board.size() &&
                cn >= 0 && cn < board[0].size() &&
                board[rn][cn] == word[now + 1]) {

                if (dfs(rn, cn, board, word, now + 1))
                    return true;
            }
        }

        // Backtrack: restore cell
        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(i, j, board, word, 0))
                        return true;
                }

            }
        }

        return false;
    }
};