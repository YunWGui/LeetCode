/*******************************************************************************
 * Title:
 *     448. Find All Numbers Disappeared in an Array
 *     448. 找到所有数组中消失的数字
 * Address:
 *     https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.push_back( 0 );

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            while ( nums[i] != i ) {
                if ( nums[i] == nums[nums[i]] )
                    break;
                
                swap( nums[i], nums[nums[i]] );
            }
        }

        vector<int> ans;
        for ( int i = 1; i < (int)nums.size(); ++i ) {
            if ( nums[i] != i )
                ans.push_back( i );
        }

        return ans;
    }
};


// 方法二：
// 参考：https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/solution/zhao-dao-suo-you-shu-zu-zhong-xiao-shi-d-mabl/
class Solution_2 {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        nums.push_back( 0 );

        int n = nums.size();

        for ( int& num : nums ) {
            // nums[num % n] += n;
            int x = num % n;
            nums[x] += n;
        }

        vector<int> ans;
        for ( int i = 0; i < n; ++i ) {
            if ( nums[i] < n )
                ans.push_back( i );
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}