/*******************************************************************************
 * Title:
 *     485. Max Consecutive Ones
 *     485. 最大连续1的个数
 * Address:
 *     https://leetcode-cn.com/problems/max-consecutive-ones/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, ans = 0;

        for ( int& element : nums ) {
            if ( element == 1 )
                ++cnt;
            else {  // element == 0
                ans = max( ans, cnt );
                cnt = 0;
            }
        }

        ans = max( ans, cnt );

        return ans;
    }
};

// 方法二：
class Solution_2 {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        else if ( nums.size() == 1 )
            return nums[0];
        
        int ans = nums[0];
        for ( int i = 1; i < (int)nums.size(); ++i ) {
            if ( nums[i] == 1 )
                nums[i] += nums[i - 1];

           ans = max( ans, nums[i] ); 
        }

        return ans;
    }
};


int main()
{
    

    return 0;
}