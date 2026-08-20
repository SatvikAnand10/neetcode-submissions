class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<
    pair<int, vector<int>>,
    vector<pair<int, vector<int>>>,
    greater<pair<int, vector<int>>>
> pq;
        for(auto a:points){
            int x=a[0];
            int y=a[1];
            int z =x*x + y*y;
            pq.push({z,a});
        }
        while(k!=0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
