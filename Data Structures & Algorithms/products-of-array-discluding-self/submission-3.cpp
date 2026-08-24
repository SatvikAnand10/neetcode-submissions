class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int zeros = 0;

        for (int a : nums) {
            if (a != 0) prod *= a;
            else zeros++;
        }

        vector<int> res(nums.size(), 0);

        
        if (zeros > 1) return res;

        
        if (zeros == 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    res[i] = prod;
                }
            }
            return res;
        }

        
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prod / nums[i];
        }

        return res;
    }
};