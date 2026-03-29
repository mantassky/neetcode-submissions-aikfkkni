class Twitter {
public:
    struct Tweet {
        int tweetId;
        int time;
        Tweet(int tweetId, int time) : tweetId(tweetId), time(time) {};
    };

    struct Compare {
        bool operator()(Tweet& a, Tweet& b) {
            return a.time < b.time;
        }
    };

    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<Tweet>> tweets; //user to tweet
    int time;

    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        Tweet* tweet = new Tweet(tweetId, time);
        time++;
        tweets[userId].push_back(*tweet);
    }
    
    vector<int> getNewsFeed(int userId) {
        unordered_set<int> followees = follows[userId];
        followees.insert(userId);
        priority_queue<Tweet, vector<Tweet>, Compare> recents;

        for (int fId: followees)
            for (Tweet tweet: tweets[fId])
                recents.push(tweet);
        
        vector<int> res;
        while (!recents.empty() && res.size() != 10) {
            res.push_back(recents.top().tweetId);
            recents.pop();
        }

        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
