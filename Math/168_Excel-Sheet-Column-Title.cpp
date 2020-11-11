/*
Title:
    168. Excel Sheet Column Title
    168. Excel表列名称
Address: 
    https://leetcode-cn.com/problems/excel-sheet-column-title/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while ( n ) {
            --n;
            str += ( 'A' + n % 26 );
            n = n / 26;
        }

        reverse( str.begin(), str.end() );

        return str;
    }
};

int main()
{
    

    return 0;
}