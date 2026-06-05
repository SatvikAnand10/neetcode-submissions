class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        unordered_set<char> us(s.begin(), s.end());

        for (char a : us) {
            int count = 0;
            int l = 0;

            for (int r = 0; r < s.size(); r++) {
                if (s[r] == a) count++;

                while ((r - l + 1) - count > k) {
                    if (s[l] == a) count--;
                    l++;
                }

                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};