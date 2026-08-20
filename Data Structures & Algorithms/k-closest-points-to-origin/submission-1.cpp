class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> pq;

        for (auto a : points) {
            pq.push({a[0]*a[0] + a[1]*a[1], a});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while (pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};