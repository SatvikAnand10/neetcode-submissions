class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            unordered_map<char, int> freq;
            int maxf = 0;

            for (int j = i; j < s.size(); j++) {
                freq[s[j]]++;

                maxf = max(maxf, freq[s[j]]);

                int len = j - i + 1;

                if (len - maxf <= k) {
                    ans = max(ans, len);
                }
            }
        }

        return ans;
    }
};