class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> s(nums.begin(), nums.end());

        for (auto a : nums) {
            if (s.find(a - 1) == s.end()) {
                
                int curr = a;
                int longest = 1;

                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    longest++;
                }

                ans = max(ans, longest);
            }
        }

        return ans;
    }
};