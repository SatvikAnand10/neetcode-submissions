class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ans = 0;
        int freq[26] = {0};

        // Count frequencies
        for (char task : tasks) {
            freq[task - 'A']++;
        }

        // Max-heap of frequencies
        priority_queue<int> pq;

        for (int a : freq) {
            if (a > 0) {
                pq.push(a);
            }
        }

        while (!pq.empty()) {
            vector<int> temp;
            int cycle = 0;

            // Process at most n + 1 tasks
            for (int i = 0; i <= n; i++) {
                if (!pq.empty()) {
                    int a = pq.top();
                    pq.pop();

                    a--;
                    cycle++;

                    // Task still has occurrences remaining
                    if (a > 0) {
                        temp.push_back(a);
                    }
                }
            }

            // Put unfinished tasks back
            for (int a : temp) {
                pq.push(a);
            }

            // If tasks remain, cooldown/idles may be needed
            if (!pq.empty()) {
                ans += n + 1;
            } 
            // Last round: don't count unnecessary idle cycles
            else {
                ans += cycle;
            }
        }

        return ans;
    }
};