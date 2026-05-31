class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<string, unordered_set<char>> boxes;

        for(int r = 0; r < 9; r++) {

            for(int c = 0; c < 9; c++) {

                if(board[r][c] == '.')
                    continue;

                char val = board[r][c];

                string boxKey =
                    to_string(r/3) + "," + to_string(c/3);

                if(rows[r].count(val) ||
                   cols[c].count(val) ||
                   boxes[boxKey].count(val))
                {
                    return false;
                }

                rows[r].insert(val);
                cols[c].insert(val);
                boxes[boxKey].insert(val);
            }
        }

        return true;
    }
};