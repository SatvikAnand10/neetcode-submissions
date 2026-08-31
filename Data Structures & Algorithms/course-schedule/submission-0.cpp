class Solution {
public:
    bool dfs(int course, vector<vector<int>>& adj,
             vector<int>& vis, vector<int>& pathvis) {

        vis[course] = 1;
        pathvis[course] = 1;

        for (auto next : adj[course]) {

            if (!vis[next]) {
                if (dfs(next, adj, vis, pathvis))
                    return true;
            }
            else if (pathvis[next]) {
                return true;   // cycle
            }
        }

        pathvis[course] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);

        // [a,b] means b -> a
        for (auto p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathvis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathvis))
                    return false;
            }
        }

        return true;
    }
};