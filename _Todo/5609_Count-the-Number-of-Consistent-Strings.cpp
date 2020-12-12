/*
Title:
    5609. Count the Number of Consistent Strings
    5609. 统计一致字符串的数目
Address: 
    https://leetcode-cn.com/contest/biweekly-contest-41/problems/count-the-number-of-consistent-strings/
*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;


// 方法一：
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = words.size();
        
        for ( string str : words ) {
            for ( char ch : str )
                if ( allowed.find( ch ) == string::npos ) {
                    --cnt;
                    break;
                }
        }
        
        return cnt;
    }
};

int main()
{
    

    return 0;
}