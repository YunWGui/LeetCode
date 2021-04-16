/*******************************************************************************
 * Title:
 *     217. Contains Duplicate
 *     217. 存在重复元素
 * Address:
 *     https://leetcode-cn.com/problems/contains-duplicate/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for ( int num : nums )
            s.insert( num );

        return s.size() != nums.size();
    }
};

// 方法二：排序
class Solution_2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort( nums.begin(), nums.end() );
        
        for ( int i = 1; i < (int)nums.size(); ++i )
            if ( nums[i - 1] == nums[i] )
                return true;
        
        return false;
    }   
};

int main()
{
    

    return 0;
}