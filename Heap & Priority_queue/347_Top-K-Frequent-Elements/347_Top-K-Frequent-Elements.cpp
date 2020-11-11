/*
Title:
    347. Top K Frequent Elements
    347. 前 K 个高频元素
Address: 
    https://leetcode-cn.com/problems/top-k-frequent-elements/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

// 方法二：哈希表 + 最小堆
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        if ( (int)nums.size() < k )
            return res;

        unordered_map<int, int> hashMap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for ( int num : nums ) {
            ++hashMap[num];
        }

        for ( auto iter = hashMap.begin(); iter != hashMap.end(); ++iter ) {
            if ( minHeap.size() == k ) {
                if ( minHeap.top().first < iter->second ) {
                    minHeap.pop();
                    minHeap.push( { iter->second, iter->first } );
                }
            }
            else {
                minHeap.push( { iter->second, iter->first } );
            }
        }

        while ( !minHeap.empty() ) {
            res.push_back( minHeap.top().second );
            minHeap.pop();
        }

        reverse( res.begin(), res.end() );

        return res;
    }
};

// 方法一：哈希表 + 最大堆
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;

        if ( (int)nums.size() < k )
            return res;

        unordered_map<int, int> hashMap;
        priority_queue<pair<int, int>> maxHeap;

        for ( int num : nums ) {
            ++hashMap[num];
        }

        for ( auto iter = hashMap.begin(); iter != hashMap.end(); ++iter ) {
            maxHeap.push( { iter->second, iter->first } );
        }

        while ( k > 0 ) {
            --k;                
            res.push_back( maxHeap.top().second );
            maxHeap.pop();
        }    

        return res;
    }
};

int main()
{
    

    return 0;
}