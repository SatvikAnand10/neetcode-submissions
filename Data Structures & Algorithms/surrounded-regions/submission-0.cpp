class Solution {
public:
    vector<pair<int,int>> direc = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            if(board[i][0]=='O') dfs(board,i,0);
            if(board[i][col-1]=='O') dfs(board,i,col-1);
        }
        for(int i=0;i<col;i++){
            if(board[0][i]=='O') dfs(board,0,i);
            if(board[row-1][i]=='O') dfs(board,row-1,i);
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='S') board[i][j]='O';
                else{board[i][j]='X';}
            }
        }
    }

    void dfs(vector<vector<char>>& board,int r,int c){
        board[r][c]='S';
        for(auto a:direc){
            int nr=r+a.first;
            int nc=c+a.second;
            if(nr>=0 && nr<board.size() && nc>=0 && nc<board[0].size() && board[nr][nc]=='O'){
                dfs(board,nr,nc);
            }
        }
    }
};
