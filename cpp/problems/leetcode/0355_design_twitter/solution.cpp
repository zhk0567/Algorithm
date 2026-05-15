// LeetCode 355: Design Twitter
#include <alg_std.hpp>
#include <cassert>
using namespace std;

class Twitter {
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

public:
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        unordered_set<int> users = follows[userId];
        users.insert(userId);
        priority_queue<tuple<int, int, int>> pq;
        for (int u : users) {
            if (!tweets[u].empty()) {
                int idx = (int)tweets[u].size() - 1;
                pq.push({tweets[u][idx].first, u, idx});
            }
        }
        vector<int> res;
        while (!pq.empty() && (int)res.size() < 10) {
            auto [t, u, idx] = pq.top();
            pq.pop();
            res.push_back(tweets[u][idx].second);
            if (idx > 0) pq.push({tweets[u][idx - 1].first, u, idx - 1});
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) follows[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

int main() {
    Twitter tw;
    tw.postTweet(1, 5);
    assert(tw.getNewsFeed(1) == vector<int>({5}));
    tw.postTweet(1, 3);
    assert(tw.getNewsFeed(1) == vector<int>({3, 5}));
    tw.follow(1, 2);
    tw.postTweet(2, 6);
    assert(tw.getNewsFeed(1) == vector<int>({6, 3, 5}));
    tw.unfollow(1, 2);
    assert(tw.getNewsFeed(1) == vector<int>({3, 5}));
    cout << "0355 OK" << endl;
    return 0;
}
