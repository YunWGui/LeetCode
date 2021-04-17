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

        set<long> record;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            auto pos = record.lower_bound( (long)nums[i] - t );
            if ( pos != record.end() && *pos <= (long)nums[i] + t )
                return true;
                
            record.insert( nums[i] );    
            if ( record.size() > k )
                record.erase( nums[i - k] );
        }

        return false;
    }
};





int main()
{
    

    return 0;
}