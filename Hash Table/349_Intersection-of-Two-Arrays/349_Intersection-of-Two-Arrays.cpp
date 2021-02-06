/******************************************************************************
 * Title:
 *     349. Intersection of Two Arrays
 *     349. 两个数组的交集
 * Address:
 *     https://leetcode-cn.com/problems/intersection-of-two-arrays/
******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashSet1( nums1.begin(), nums1.end() );
        unordered_set<int> hashSet2( nums2.begin(), nums2.end() );

        vector<int> ans;
        for ( auto iter = hashSet1.begin(); iter != hashSet1.end(); ++iter ) {
            if ( hashSet2.count( *iter ) )
                ans.push_back( *iter );
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}