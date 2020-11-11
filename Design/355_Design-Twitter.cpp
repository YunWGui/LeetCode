/*
Title:
    355_Design-Twitter.cpp
    355. 设计推特
Address:
    https://leetcode-cn.com/problems/design-twitter/
*/

#include <iostream>
#include <unordered_map>
#include <set>
#include <stack>
#include <vector>
using namespace std;


// 方法一：哈希表 + 栈
// https://leetcode-cn.com/problems/design-twitter/solution/c-ha-xi-biao-she-ji-tui-te-tui-te-zhan-de-chang-gu/
class Twitter {
private:
    /* 2 个哈希表 */
    unordered_map<int, set<int>> userId2Follow;
    unordered_map<int, stack<pair<int, int>>> userId2Tweet;
    int counter;  // 计数器
public:
    Twitter() {
        counter = 0;  // 计数器初始化
    }

    void postTweet( int userId, int tweetId ) {
        /* 添加推特，记得 counter++ */
        userId2Tweet[userId].push( { tweetId, counter++ } );
    }

    vector<int> getNewsFeed( int userId ) {
        vector<int> res;
        /* 加入 userId 本身的推特栈 */
        vector<stack<pair<int, int>>> temp = { userId2Tweet[userId] };

        for ( set<int>::iterator iter = userId2Follow[userId].begin(); iter != userId2Follow[userId].end(); ++iter ) {
            /* 注意用户关注其本身的操作！这里要将这种情况排除 */
            if ( *iter != userId ) {
                /* 将 userId 所关注的其他用户的推特栈加入 temp */
                temp.push_back( userId2Tweet[*iter] );
            }
        }

        for ( int i = 0; i < 10; ++i ) {
            /* 记录最大值和索引 */
            int maxIndex, maxVal = -1;
            for ( int j = 0; j < temp.size(); ++j ) {
                if ( !temp[j].empty() && temp[j].top().second > maxVal ) {
                    maxVal = temp[j].top().second;  // 保存最大值
                    maxIndex = j;  // 保存索引
                }
            }

            if ( maxVal == -1 )
                break;  // 所有栈都为空
            res.push_back( temp[maxIndex].top().first );  // 将推荐 id 加入 res
            temp[maxIndex].top();
        }

        return res;
    }

    void follow( int followerId, int followeeId ) {
        userId2Follow[followerId].insert( followeeId );  // 关注
    }

    void unfollow( int followerId, int followeeId ) {
        userId2Follow[followerId].erase( followeeId );  // 取关
    }
};

int main()
{
    

    return 0;
}