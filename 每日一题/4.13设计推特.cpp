/*
方法一：哈希表+链表：
根据题意可知，对于每个推特用户，我们需要存储他关注的用户ID，以及自己发的推文ID的集合，
为了使每个操作的复杂度尽可能的低，我们需要根据操作来决定存储这些信息的数据结构。注意，
由于题目中没有说明用户的Id是否连续，所以我们需要一个以用户Id为索引的哈希表来存储用户
的信息。

对于关注和取关操作，我们只需要用一个哈希表存储，即可实现插入和删除的时间复杂度为O（1）。

对于发布和getNews操作，由于getNews要知道此用户关注的人和用户自己发出的最近十条推文，
因此可以考虑对每个用户用链表存储发送的推文。每次创建推文的时候我们在链表头插入，这样能
保证链表里存储的推文的时间是从最近到最久的。对于getNews操作，要做的就是合并K个排序链表。
*/

class Twitter {

    struct Node {
        // 哈希表存储关注人的Id
        unordered_set<int> followee;
        // 用链表存储tweetId
        list<int> tweet;
    };

    // getNewsFeed检索的推文的上限以及tweetId的时间戳
    int recentMax, time;
    // tweetId对应发送的时间
    unordered_map<int, int> tweetTime;
    // 每个用户存储的信息
    unordered_map<int, Node> user;

public:
    /** Initialize your data structure here. */
    Twitter() {
        this->time = 0;
        this->recentMax = 10;
        user.clear();
    }
    
    // 对一个用户的信息进行初始化，在map容器中存入这个索引
    void init(int userId) {
        this->user[userId].followee.clear();
        this->user[userId].tweet.clear();
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) { 
        // 是一个新的用户，进行初始化
        if (this->user.find(userId) == this->user.end()) {
            this->init(userId);
        }

        // 达到条数限制，剔除链表末尾元素（list的底层是一个双向链表）
        if (this->user[userId].tweet.size() == this->recentMax) {
            this->user[userId].tweet.pop_back();
        }

        this->user[userId].tweet.push_front(tweetId);
        this->tweetTime[tweetId] = ++time;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for (list<int>::iterator it = this->user[userId].tweet.begin(); it != this->user[userId].tweet.end(); it++) {
            ans.emplace_back(*it);
        }
        for (int followeeId : this->user[userId].followee) {
            if (followeeId == userId) continue;
            vector<int> res;
            list<int>::iterator it = this->user[followeeId].tweet.begin();
            int i = 0;
            // 线性归并（就是一个一个归并）
            while (i < (int)ans.size() && it != this->user[followeeId].tweet.end()) {
                if (this->tweetTime[(*it)] > this->tweetTime[ans[i]]) {
                    res.emplace_back(*it);
                    it++;
                }
                else {
                    res.emplace_back(ans[i]);
                    i++;
                }
                // 已经找到这两个链表合起来后最近的recentMax条推特
                if ((int)res.size() == recentMax) break;
            }
            for (; i < (int)ans.size() && (int)res.size() < recentMax; i++) res.emplace_back(ans[i]);
            for (; it != this->user[followeeId].tweet.end() && (int)res.size() < recentMax; it++) res.emplace_back(*it);
            ans.assign(res.begin(), res.end());
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (this->user.find(followerId) == this->user.end()) {
            this->init(followerId);
        }
        if (this->user.find(followeeId) == this->user.end()) {
            this->init(followeeId);
        }
        // 插入到关注列表中
        this->user[followerId].followee.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        this->user[followerId].followee.erase(followeeId);
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