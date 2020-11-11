/*
Title:
    1353. Maximum Number of Events That Can Be Attended
    1353. 最多可以参加的会议数目
Address: 
    https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 方法一：优先级队列 / 贪心
// https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/solution/sao-miao-suan-fa-tan-xin-by-lucifer1004/
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        const int N = 1e5 + 1;
        vector<vector<int>> startTime( N );  // 记录会议的开始时间

        for ( int i = 0; i < (int)events.size(); ++i )
            startTime[events[i][0]].push_back( i );  

        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;  // 小根堆：记录所有当前可参加会议的结束时间

        for ( int i = 1; i < N; ++i ) {
            for ( int j : startTime[i] )  // 将当前时间点开始的会议的结束时间加入小根堆
                minHeap.push( events[j][1] );  
            
            while ( !minHeap.empty() && minHeap.top() < i )  // 将当前已经结束的会议移除出小根堆
                minHeap.pop();
            
            if ( !minHeap.empty() ) {  // 从剩余的会议中，选择一个结束时间最早的去参加
                minHeap.pop();
                ++ans;
            }
        }

        return ans;
    }
};

// 方法二：优先级队列 / 贪心
bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) 
        return a[0] < b[0];
    else  // a[0] == b[0]
        return a[1] < b[1];
}

class Solution_2 {
public:   
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), cmp);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> maxHeap;  // 大根堆
        
        int ans = 0;
        int j = 0;
    
        for (int i = 1; i <= 1e5; i ++) {  // 题目中给出的数据范围
            while (j < (int)events.size() && events[j][0] <= i) {
                maxHeap.push({events[j][1], events[j][0]});  // 结束时间，开始时间
                ++j;
            }
        
            while (maxHeap.size() && maxHeap.top().first < i) 
                maxHeap.pop();

            if (maxHeap.size() && maxHeap.top().second <= i) {
                ++ans;
                maxHeap.pop();
            }
        }

        return ans;
    }
};



int main()
{
    

    return 0;
}