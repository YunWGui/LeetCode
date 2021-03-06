/*
Title:
    119. Pascal's Triangle II
    119. 杨辉三角 II
Address:
    https://leetcode-cn.com/problems/pascals-triangle-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一: 动态规划
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kRows( rowIndex + 1 );  // 第 k 行的 vector 大小为 rowIndex + 1
        // 利用前一行求后一行, 第 k 行要循环 k 遍
        for ( int i = 0; i <= rowIndex; ++i ) {
            kRows[i] = 1;  // 行末尾为 1

            for ( int j = i; j > 1; --j ) {  // 从后往前更新
                kRows[j - 1] = kRows[j - 2] + kRows[j - 1];
            }
        }

        return kRows;
    }
};

// 方法二：线性递推
// 参考：https://leetcode-cn.com/problems/pascals-triangle-ii/solution/yang-hui-san-jiao-ii-by-leetcode-solutio-shuk/
class Solution_2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> kRows( rowIndex + 1 );

        kRows[0] = 1;
        for ( int i = 1; i <= rowIndex; ++i ) {
            kRows[i] = 1LL * kRows[i - 1] * ( rowIndex - i + 1 ) / i;  // 1LL -> 防溢出
        }
        
        return kRows;
    }
};




int main()
{


    return 0;
}
