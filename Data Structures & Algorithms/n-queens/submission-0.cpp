class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }

        dfs(0,board,ans,n);
        return ans;
    }

    void dfs(int col,vector<string>& board,vector<vector<string>>& ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(safe(row,col,board,n)){
                board[row][col]='Q';
                dfs(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }

    bool safe(int r,int c,vector<string>& board,int n){
        int a=r;
        int b=c;
        //check diagonal
        while(a>=0 && b>=0){
            if(board[a][b]=='Q') return false;
            a--;
            b--;
        }

        a=r;
        b=c;
        //check row
        while(b>=0){
            if(board[a][b]=='Q') return false;
            b--;
        }

        a=r;
        b=c;
        //check diag
        while(a<n && b>=0){
            if(board[a][b]=='Q') return false;
            a++;
            b--;
        }   

        return true;
    }
};
