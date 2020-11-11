/*
Title:
    461. Hamming Distance
    461. 汉明距离
Address: 
    https://leetcode-cn.com/problems/hamming-distance/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        while ( x > 0 || y > 0 ) {
            if ( ( x & 1 ) != ( y & 1 ) )  // 各自判断「奇偶性」，只有 [0, 1], [1, 0] 两种情况才不相等
                ++count;
            
            x >>= 1;
            y >>= 1;
        }

        return count;
    }
};

// 方法二：
class Solution_2 {
  public:
    int hammingDistance(int x, int y) {
        int n = x ^ y, count = 0;
       
        while ( n ) {
            n &= ( n - 1 );
            count++;
        }

        return count;
    }
};

int main()
{
    

    return 0;
}