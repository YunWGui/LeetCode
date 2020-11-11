/*
Title:
    43. Multiply Strings
    43. 字符串相乘
Address: 
    https://leetcode-cn.com/problems/multiply-strings/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
// https://leetcode-cn.com/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/
class Solution {
public:
    string multiply(string num1, string num2) {
        if ( num1.empty() || num1[0] == '0' || num2.empty() || num2[0] == '0' )
            return "0";

        int n1 = num1.size(), n2 = num2.size();
        vector<int> ansArr( n1 + n2, 0 );

        for ( int i = n1 - 1; i >= 0; --i ) {
            int x = num1[i] - '0';
            for ( int j = n2 - 1; j >= 0; --j ) {
                int y = num2[j] - '0';
                ansArr[i + j + 1] += x * y;
            }
        }

        for ( int i = n1 + n2 - 1; i > 0; --i ) {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }

        string ans = "";
        
        int idx = ansArr[0] == 0 ? 1 : 0;
        for ( ; idx < n1 + n2; ++idx ) 
            ans.push_back( ansArr[idx] + '0' );

        return ans;
    }
};


int main()
{
    

    return 0;
}