/*
Title:
    215. Kth Largest Element in an Array
    215. 数组中的第K个最大元素
Address: 
    https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// 方法二：堆排序 - STL 容器
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        
        for ( int i = 0; i < (int)nums.size(); ++i )
            pq.push( nums[i] );
        
        for ( int i = 1; i < k; ++i ) {
            pq.pop();
        }

        return k > 0 ? pq.top() : -1;
    }
};


// 方法一：堆排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        for ( int i = n - 1; i >= 0; --i )
            heapify( nums, n, i );
        
        for ( int i = n - 1; i >= 0; --i ) {
            if ( k == 1 )
                return nums[0];
            
            --k;
            swap( nums[i], nums[0] );
            heapify( nums, i, 0 );
        }

        return -1; 
    }

    void heapify( vector<int>& nums, int n, int parent ) {
        int maxIndex = parent;
        int leftChild = parent * 2 + 1;
        int rightChild = parent * 2 + 2;

        if ( leftChild < n && nums[maxIndex] < nums[leftChild] )
            maxIndex = leftChild;
        
        if ( rightChild < n && nums[maxIndex] < nums[rightChild] )
            maxIndex = rightChild;

        if ( maxIndex != parent ) {
            swap( nums[maxIndex], nums[parent] );
            heapify( nums, n, maxIndex );
        }
    }
};

int main()
{
    

    return 0;
}