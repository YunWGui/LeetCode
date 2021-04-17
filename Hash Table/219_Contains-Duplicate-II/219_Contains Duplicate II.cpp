/*******************************************************************************
 * Title:
 *     219. Contains Duplicate II
 *     219. 存在重复元素 II
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate-ii/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> record;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            if ( record.find( nums[i] ) != record.end() )
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
