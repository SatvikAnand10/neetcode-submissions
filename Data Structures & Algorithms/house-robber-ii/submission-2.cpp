class Solution {
public:
    int robRange(vector<int>& nums, int l, int r) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = l; i <= r; i++) {
            int take = nums[i] + prev2;
            int skip = prev1;

            int curr = max(take, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        int excludeLast = robRange(nums, 0, n - 2);
        int excludeFirst = robRange(nums, 1, n - 1);

        return max(excludeLast, excludeFirst);
    }
};