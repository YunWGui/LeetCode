/*******************************************************************************
 * Title:
 *     724. Find Pivot Index
 *     724. 寻找数组的中心索引
 * Address: 
 *     https://leetcode-cn.com/problems/find-pivot-index/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>  // accumulate
using namespace std;

// 方法一：
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if ( nums.empty() ) {
            return -1;
        }
        
        int n = nums.size();
        vector<int> leftSum( n ), rightSum( n );  // 以左、右两侧为起点的累加和
        
        leftSum[0] = nums[0];
        for ( int i = 1; i < n; ++i ) {
            leftSum[i] = leftSum[i - 1] + nums[i];
        }

        rightSum[n - 1] = nums[n - 1];
        for ( int i = n - 2; i >= 0; --i ) {
            rightSum[i] = rightSum[i + 1] + nums[i];
        }

        for ( int i = 0; i < n; ++i ) {
            if ( leftSum[i] == rightSum[i] ) {
                return i;
            }
        }
        
        return -1;
    }
};

// 方法二：方法一的改进
class Solution_2 {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate( nums.begin(), nums.end(), 0 );
        int leftSum = 0;  // 以左侧为起点的累加和
  
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            // sum - leftSum - nums[i] : 以右侧为起点的累加和
            if ( leftSum == sum - leftSum - nums[i] ) {  
                return i;
            }
            leftSum += nums[i];
        }

        return -1;
    }
};

// 方法三：方法二的改进
class Solution_3 {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate( nums.begin(), nums.end(), 0 );
        int leftSum = 0;

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            // 由 leftSum == sum - leftSum - nums[i] 演化而来，详见「方法二」
            if ( 2 * leftSum + nums[i] == sum ) {
                return i;
            }
            leftSum += nums[i];
        }
        
        return -1;
    }
};

int main()
{
    

    return 0;
}