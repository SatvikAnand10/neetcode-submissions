class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> treasure;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==0) treasure.push({i,j});
            }
        }
        while(!treasure.empty()){
            auto curr=treasure.front();treasure.pop();
            int r=curr.first;
            int c=curr.second;
            for(auto a:directions){
                int rn=r+a.first;
                int cn=c+a.second;
                if(rn>=0 && rn<row && cn>=0 && cn<col && grid[rn][cn]==2147483647){
                    grid[rn][cn]=grid[r][c]+1;
                    treasure.push({rn,cn});
                }
            }
        }
    }
};
