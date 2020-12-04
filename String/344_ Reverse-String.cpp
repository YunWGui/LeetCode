/*
Title:
    344. 反转字符串
    344. Reverse String
Address: 
    https://leetcode-cn.com/problems/reverse-string/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：位运算
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while ( left < right ) {
            s[left] ^= s[right];
            s[right] ^= s[left];
            s[left] ^= s[right];

            ++left; --right;
        }
    }
};


// 方法二：常规方法
class Solution_2 {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size() - 1;

        while ( left < right ) {
            swap( s[left++], s[right--] );
        }
    }
};

int main()
{
    

    return 0;
}