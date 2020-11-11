/*
Title:
    9. Palindrome Number
    9. 回文数
Description:
    Determine whether an integer is a palindrome. An integer is a palindrome when
    it reads the same backward as forward.
Address:
    https://leetcode-cn.com/problems/palindrome-number/
*/ 

#include <iostream>
#include <string>
using namespace std;


// 方法三：
class Solution_3 {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        
        int help = 1;  // 辅助数字
        while ( x / help >= 10 )  // 防止 help 溢出
            help *= 10;
        
        while ( x != 0 ) {
            if ( x / help != x % 10 )  // x / hellp : 最高位，x % 10 : 最低位
                return false;
            
            x = ( x % help ) / 10;  // 除去「最高位」和「最低位」之后的值
            help /= 100;  // 保持 help 与 x 的位数相同
        }

        return true;
    }
};


// 方法一：字符串 + 双指针
class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;

        string str = to_string( x );
        
        int left = 0, right = str.size() - 1;
        while ( left < right ) {
            if ( str[left] == str[right] ) {
                ++left;
                --right;
            }
            else 
                return false;
        }

        return true;
    }
};

// 方法二：旋转数字后与原数字比较
class Solution_2 {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;
        
        int temp = x;
        long rotateNum = 0;  // 避免溢出：如 x = 2147483647
        while ( temp > 0 ) {
            rotateNum = rotateNum * 10 + temp % 10;
            temp /= 10;
        }

        return x == rotateNum;
    }
};


int main()
{
    

    return 0;
}