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
        set<int> scan;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            if ( scan.find( nums[i] ) != scan.end() )
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
