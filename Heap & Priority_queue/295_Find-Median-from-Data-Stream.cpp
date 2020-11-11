/*
Title:
    295. Find Median from Data Stream
    295. 数据流的中位数
Address:
    https://leetcode-cn.com/problems/find-median-from-data-stream/
*/

#include <iostream>
#include <vector>
#include <queue>  // priority_queue
#include <functional>  // greater
using namespace std;


// 方法二：堆
// https://leetcode-cn.com/problems/find-median-from-data-stream/solution/shu-ju-liu-de-zhong-wei-shu-by-leetcode/
class MedianFinder_2 {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num) {
        maxHeap.push( num );
        minHeap.push( maxHeap.top() );

        maxHeap.pop();

        if ( maxHeap.size() < minHeap.size() ) {  
            maxHeap.push( minHeap.top() );
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if ( ( maxHeap.size() + minHeap.size() ) % 2 == 1 ) 
            return maxHeap.top();
        else
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
    }
};


// 方法一：堆
class MedianFinder {
public:
    priority_queue<int> maxHeap;  // 最大堆
    priority_queue<int, vector<int>, greater<int>> minHeap;  // 最小堆

    void addNum(int num) {
        maxHeap.push( num );

        if ( !minHeap.empty() && maxHeap.top() > minHeap.top() ) {
            int maxNum = maxHeap.top(), minNum = minHeap.top();
            maxHeap.pop(); minHeap.pop();
            
            maxHeap.push( minNum ); minHeap.push( maxNum );
        }

        if ( maxHeap.size() > minHeap.size() + 1 ) {
            minHeap.push( maxHeap.top() );
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        if ( ( maxHeap.size() + minHeap.size() ) % 2 == 1 ) 
            return maxHeap.top();
        else 
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
    }
};

int main()
{
    
    
    return 0;
}