class Solution {
public:
    vector<int> ans;
    bool dfs(int i,vector<int>& vis,vector<int>& pathvis,vector<vector<int>>& adj){
        vis[i]=1;
        pathvis[i]=1;

        for(auto a:adj[i]){
            if(!vis[a]){
                if(dfs(a,vis,pathvis,adj)) return true;
            }
            else if(pathvis[a]){
                return true;
            }
        }
        pathvis[i]=0;
        ans.push_back(i);
        return false;
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        for(auto a:prerequisites){
            adj[a[1]].push_back(a[0]);
        }

        vector<int> vis(numCourses,0);
        vector<int> pathvis(numCourses,0);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathvis,adj)){
                    return {}; 
                }
            }
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};
