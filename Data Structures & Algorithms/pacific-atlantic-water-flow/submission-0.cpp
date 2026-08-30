class Solution {
public:
    vector<pair<int,int>> direc = {
        {0,1}, {1,0}, {0,-1}, {-1,0}
    };

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacv(row, vector<bool>(col, false));
        vector<vector<bool>> atlv(row, vector<bool>(col, false));

        queue<pair<int,int>> pac;
        queue<pair<int,int>> atl;

        // Left + Right
        for(int r = 0; r < row; r++){
            pac.push({r,0});
            pacv[r][0] = true;

            atl.push({r,col-1});
            atlv[r][col-1] = true;
        }

        // Top + Bottom
        for(int c = 0; c < col; c++){
            pac.push({0,c});
            pacv[0][c] = true;

            atl.push({row-1,c});
            atlv[row-1][c] = true;
        }

        bfs(heights, pac, pacv);
        bfs(heights, atl, atlv);

        vector<vector<int>> ans;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(pacv[i][j] && atlv[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<int>>& heights,
             queue<pair<int,int>> q,
             vector<vector<bool>>& visit){

        while(!q.empty()){
            auto a = q.front();
            q.pop();

            int r = a.first;
            int c = a.second;

            for(auto d : direc){
                int rnew = r + d.first;
                int cnew = c + d.second;

                if(rnew >= 0 && rnew < heights.size() &&
                   cnew >= 0 && cnew < heights[0].size() &&
                   !visit[rnew][cnew] &&
                   heights[rnew][cnew] >= heights[r][c]){

                    visit[rnew][cnew] = true;
                    q.push({rnew,cnew});
                }
            }
        }
    }
};