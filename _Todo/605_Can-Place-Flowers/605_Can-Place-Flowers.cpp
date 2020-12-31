/*******************************************************************************
 * Title:
 *     605. Can Place Flowers
 *     605. 种花问题
 * Address: 
 *     https://leetcode-cn.com/problems/can-place-flowers/
 ******************************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：模拟
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ans = 0;
        int cnt = 0;
        
        int left = 0;
        while ( left < flowerbed.size() ) {
            cnt = 0;
            if ( flowerbed[left] == 0 ) {
                if ( left == 0 )
                    ++cnt;
                
                ++left;
                while ( left < flowerbed.size() && flowerbed[left] == 0 ) {
                    ++cnt;                   
                    ++left;
                }

                if ( left < flowerbed.size() )  // 即： flowerbed[left] == 1
                    --cnt;
                if ( cnt > 0 )
                    ans += ( cnt - 1 ) / 2 + 1;
            }
            ++left;
        }

        return ans >= n;
    }
};

int main()
{
    

    return 0;
}