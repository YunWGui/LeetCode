/*
Title:
    459. Repeated Substring Pattern
    459. 重复的子字符串
Address: 
    https://leetcode-cn.com/problems/repeated-substring-pattern/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：
// https://leetcode-cn.com/problems/repeated-substring-pattern/solution/tu-jie-yi-xia-shuang-bei-zi-fu-chuan-de-jie-fa-by-/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return ( s + s ).find( s, 1 ) != s.size();
    }
};

int main()
{
    

    return 0;
}