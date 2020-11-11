/*
Title:
    925. Long Pressed Name
    925. 长按键入
Address: 
    https://leetcode-cn.com/problems/long-pressed-name/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法一：双指针
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;

        while ( j < typed.size() ) {
            if ( i < name.size() && name[i] == typed[j] ) {
                ++i;
                ++j;
            }
            else if ( j > 0 && typed[j] == typed[j - 1] )
                ++j;
            else 
                return false;
        }

        return i == name.size();
    }
};

int main()
{
    

    return 0;
}