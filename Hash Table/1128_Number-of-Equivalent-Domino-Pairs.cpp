/*******************************************************************************
 * Title:
 *     1128. Number of Equivalent Domino Pairs
 *     1128. 等价多米诺骨牌对的数量
 * Address: 
 *     https://leetcode-cn.com/problems/number-of-equivalent-domino-pairs/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int ans = 0;

        map<vector<int>, int> unique;

        for ( vector<int>& arr : dominoes ) {
            if ( arr[0] > arr[1] ) {
                swap( arr[0], arr[1] );
            }
            ++unique[arr];
        }

        for ( auto iter = unique.begin(); iter != unique.end(); ++iter ) {
            if ( iter->second >= 2 ) {  // C_n^2 = n * ( n - 1 ) / 2;
                ans += ( iter->second * ( iter->second - 1 ) ) >> 1;  // >> 1 : 位运算，更快些
            }
        }

        return ans;        
    }
};

// 方法二：哈希表
class Solution_2 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int nums[100];
        memset( nums, 0, sizeof( nums ) );

        int ans = 0;
        for ( auto& arr : dominoes ) {
            int val = arr[0] > arr[1] ? arr[0] * 10 + arr[1] : arr[1] * 10 + arr[0];
            ans += nums[val];
            ++nums[val];
        }

        return ans;
    }
};


int main()
{
    

    return 0;
}