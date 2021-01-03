/*******************************************************************************
 * Title:
 *     605. Can Place Flowers
 *     605. 种花问题
 * Address: 
 *     https://leetcode-cn.com/problems/can-place-flowers/
 ******************************************************************************/


// 方法一：模拟
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int ans = 0;
        int cnt = 0;

        int left = 0;
        while ( left < flowerbed.length ) {
            cnt = 0;
            if ( flowerbed[left] == 0 ) {
                if ( left == 0 ) {
                    ++cnt;
                }

                ++left;
                while ( left < flowerbed.length && flowerbed[left] == 0 ) {
                    ++cnt;
                    ++left;
                }

                if ( left < flowerbed.length ) {
                    --cnt;
                }

                if ( cnt > 0 ) {
                    ans += ( cnt - 1 ) / 2 + 1;
                }
            }
            ++left;
        }

        return ans >= n;
    }

    public static void main( String[] args ) {
        int[] arr = { 1, 0, 0, 0, 1 };
        int n = 1;
        
        Solution solve = new Solution();

        boolean ans = solve.canPlaceFlowers( arr, n );
        
        System.out.println( ans );
    }
}