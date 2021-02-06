/*******************************************************************************
 * Title:
 *     1423. Maximum Points You Can Obtain from Cards
 *     1423. 可获得的最大点数
 * Address: 
 *     https://leetcode-cn.com/problems/maximum-points-you-can-obtain-from-cards/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 方法一：滑动窗口
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxPoints = accumulate( cardPoints.begin(), cardPoints.begin() + k, 0 );
        int sumPoints = maxPoints;

        // [1, 2, 3, 4, 5, 6, 1], k = 3
        //  <--i           <--j  # i, j 移动方向
        
        int i = k - 1, j = cardPoints.size() - 1;
        while ( i >= 0 ) {
            sumPoints = sumPoints - cardPoints[i--] + cardPoints[j--];
            maxPoints = max( maxPoints, sumPoints );
        }

        return maxPoints;
    }
};


int main()
{
    

    return 0;
}