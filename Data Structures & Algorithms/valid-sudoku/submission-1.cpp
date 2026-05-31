class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<char>> col;
        unordered_map<int,unordered_set<char>> row;
        unordered_map<string,unordered_set<char>> box;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char val=board[i][j];
                if(val=='.') continue;
                string str=to_string(i/3)+","+to_string(j/3);
                if(row[i].count(val)||col[j].count(val)||box[str].count(val)){
                    return false;
                }
                col[j].insert(val);
                row[i].insert(val);
                box[str].insert(val);
            }
        }
        return true;
    }
};
