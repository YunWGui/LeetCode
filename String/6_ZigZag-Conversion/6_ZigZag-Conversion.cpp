/*******************************************************************************
 * Title:
 *     6. ZigZag Conversion
 *     6. Z 字形变换
 * Address: 
 *     https://leetcode-cn.com/problems/zigzag-conversion/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <cmath>  // ceil
#include <cctype>  // isalpha
using namespace std;

// 方法二：
// https://leetcode-cn.com/problems/zigzag-conversion/solution/zzi-xing-bian-huan-by-jyd/
class Solution_2 {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1 || numRows >= (int)s.length() )
            return s;

        vector<string> strs( numRows );
        int row = 0, flag = 0;

        for ( char ch : s ) {
            strs[row].push_back( ch );

            if ( row == 0 )
                flag = 1;
            else if ( row == numRows - 1 )
                flag = -1;
            
            row += flag;
        }

        string ans;
        for ( string str : strs )
            ans += str;
        
        return ans;
    }
};

// 方法一：暴力法 - 模拟
class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();

        if (numRows == 1 || numRows >= len)
            return s;

        int numCols = ceil(1.0 * (numRows - 1) * len / (2 * numRows - 2));
        vector<vector<char>> matrix(numRows, vector<char>(numCols, 0));

        int idx = 0;
        int row = 0, col = 0;
        while (idx < len) {
            if (col % (numRows - 1) == 0) {
                for (row = 0; row < numRows; ++row) {
                    if ( idx >= len )
                        break;
                    matrix[row][col] = s[idx++];
                }
                ++col;
                --row;
            }
            else {
                matrix[--row][col++] = s[idx++];
            }
        }

        string str;
        for (int row = 0; row < numRows; ++row) {
            for (int col = 0; col < numCols; ++col) {
                char ch = matrix[row][col];
                if (isalpha(ch) || ch == ',' || ch == '.')
                    str.push_back(ch);
            }
        }

        return str;
    }
};



int main()
{
    

    return 0;
}