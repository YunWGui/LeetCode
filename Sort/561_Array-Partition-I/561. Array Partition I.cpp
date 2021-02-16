/*******************************************************************************
 * Title:
 *     561. Array Partition I
 *     561. 数组拆分 I
 * Address:
 *     https://leetcode-cn.com/problems/array-partition-i/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort( nums.begin(), nums.end() );

        int sum = 0;
        for ( int i = 0; i < (int)nums.size(); i += 2 ) 
            sum += nums[i];
        
        return sum;
    }
};


int main()
{
    

    return 0;
}