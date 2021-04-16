/*******************************************************************************
 * Title:
 *     220. Contains Duplicate III
 *     220. 存在重复元素 III
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate-iii/
 ******************************************************************************/


#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 方法一：
// 对于「重复」数字。如果挨得近，在insert前就满足true条件；如果距离远，则不能同时进行循环。
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if ( k < 0 || t < 0 || nums.size() < 2 )
            return false;

        set<long> scan;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            auto pos = scan.lower_bound( (long)nums[i] - t );
            if ( pos != scan.end() && *pos <= (long)nums[i] + t )
                return true;
            scan.insert( nums[i] );    
            if ( scan.size() > k )
                scan.erase( nums[i - k] );
        }

        return false;
    }
};





int main()
{
    

    return 0;
}