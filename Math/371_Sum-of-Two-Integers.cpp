/*
Title:
    371. Sum of Two Integers
    371. 两整数之和
Description:
    不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。
Address:
    https://leetcode-cn.com/problems/sum-of-two-integers/
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
题解：https://leetcode-cn.com/problems/sum-of-two-integers/solution/wei-yun-suan-xiang-jie-yi-ji-zai-python-zhong-xu-y/
    a ^ b : 无进位加法，可以得到两数相加不进位的加法结果
    ( a & b ) << 1 : 可以得到两数相加产生的进位
*/

// 方法四：迭代
class Solution_4 {
public:
    int getSum(int a, int b) {
        while ( b != 0 ) {
            int temp = a ^ b;
            b = (unsigned int)( a & b ) << 1;
            a = temp;
        }

        return a;
    }
};

// 方法二：递归
class Solution_2 {
public:
    int add(int a, int b) {
        int carry = (unsigned int)( a & b ) << 1;
        int sum = ( a ^ b );

        if (carry != 0) {
            return add(carry, sum);  // 递归调用
        }

        return sum;
    }
};


// 方法三：迭代
class Solution_3 {
public:
    int add(int a, int b) {
        int sum, carry;
        do {
            sum = a ^ b;
            carry = (unsigned int)( a & b ) << 1;
            a = sum;
            b = carry;
        } while ( b != 0 );

        return a;
    }
};


// 方法一：容器
class Solution {
public:
    int add(int a, int b) {
        vector<int> v{ a, b };

        return accumulate( v.begin(), v.end(), 0 );
    }
};


int main()
{
    int a = 2, b = 3;
    Solution_3 solve;
    cout << solve.add(a, b) << endl;

    return 0;
}
