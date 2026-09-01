class Solution {
public:
    bool dfs(int node,int parent,vector<int>& vis,vector<vector<int>>& adj){
        vis[node]=1;
        for(auto a:adj[node]){
            if(!vis[a]){
                if(dfs(a,node,vis,adj)==true) return true;
            }
            else if(a!=parent) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto a:edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }

        vector<int> vis(n,0);
        if(dfs(0,-1,vis,adj)==true) return false;

        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
