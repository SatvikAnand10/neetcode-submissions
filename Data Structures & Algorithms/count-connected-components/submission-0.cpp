class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto a:adj[node]){
            if(!vis[a]) dfs(a,vis,adj);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};
