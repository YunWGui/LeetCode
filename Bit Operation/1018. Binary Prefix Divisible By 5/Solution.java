/*******************************************************************************
 * Title:
 *     1018. Binary Prefix Divisible By 5
 *     1018. 可被 5 整除的二进制前缀
 * Address: 
 *     https://leetcode-cn.com/problems/binary-prefix-divisible-by-5/
 ******************************************************************************/

class Solution {
    public List<Boolean> prefixesDivBy5(int[] A) {
        List<Boolean> list = new ArrayList<Boolean>();
        int number = 0;
        int n = A.length;

        for ( int i = 0; i < n; ++i ) {
            number = ( number * 2 + A[i] ) % 5;
            list.add( number == 0 );
        }

        return list;
    }
}