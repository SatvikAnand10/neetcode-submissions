class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevmax = nums[0];
        int prevmin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int currmax = max({nums[i], prevmax * nums[i], prevmin * nums[i]});
            int currmin = min({nums[i], prevmax * nums[i], prevmin * nums[i]});

            prevmax = currmax;
            prevmin = currmin;

            ans = max(ans, prevmax);
        }

        return ans;
    }
};