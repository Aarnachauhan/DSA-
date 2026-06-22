lc 355


class Twitter {
        int timer;
        unordered_map<int,unordered_set<int>> followmap;
        unordered_map<int,vector<pair<int,int>>> tweetmap;

public:
   
    Twitter() {
        timer=0;
    }
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({timer++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> ans;

       followmap[userId].insert(userId);
       priority_queue<vector<int>> pq;

       for(auto followee: followmap[userId]){
        auto &tweets=tweetmap[followee];
        if(!tweets.empty()){
            int ind=tweets.size()-1;

            pq.push({
                tweets[ind].first,
                tweets[ind].second,
                followee,
                ind
            });
        }
       } 

       while(!pq.empty() && ans.size() < 10) {

            auto curr = pq.top();
            pq.pop();

            int tweetId = curr[1];
            int user = curr[2];
            int ind = curr[3];

            ans.push_back(tweetId);

            if(ind > 0) {

                ind--;

                pq.push({
                    tweetmap[user][ind].first,
                    tweetmap[user][ind].second,
                    user,
                    ind
                });
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followmap[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
