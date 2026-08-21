class Twitter {
public:
    int time = 0;

    // follower -> set of people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        
    }

    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        // Max-heap: {time, tweetId}
        priority_queue<pair<int, int>> pq;

        // Add the user's own tweets
        for (auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // Add tweets from everyone they follow
        for (int followee : following[userId]) {
            for (auto tweet : tweets[followee]) {
                pq.push(tweet);
            }
        }

        // Get the 10 most recent tweets
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};