/*******************************************************************************
 * Title:
 *     888. Fair Candy Swap
 *     888. 公平的糖果棒交换
 * Address: 
 *     https://leetcode-cn.com/problems/fair-candy-swap/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
#include <set>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;

        long sumA = accumulate( A.begin(), A.end(), 0 );
        long sumB = accumulate( B.begin(), B.end(), 0 );
        int b = ( sumB - sumA ) / 2;  // y = x + b;

        set<int> hashSet( B.begin(), B.end() );

        for ( int a : A ) {
            if ( hashSet.count( a + b ) ) {
                ans.push_back( a );
                ans.push_back( a + b );

                break;
            }
        }

        return ans;
    }
};


int main()
{
    

    return 0;
}