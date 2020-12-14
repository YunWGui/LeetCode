/*
Title:
    1684. Count the Number of Consistent Strings
    1684. 统计一致字符串的数目
Address: 
    https://leetcode-cn.com/problems/count-the-number-of-consistent-strings/
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


// 方法一：模拟
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = words.size();
        
        for ( string& str : words ) {
            for ( char ch : str )
                if ( allowed.find( ch ) == string::npos ) {
                    --cnt;
                    break;
                }
        }
        
        return cnt;
    }
};

// 方法二：哈希表
class Solution_2 {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = words.size();
        unordered_set<char> st;

        for ( char& ch : allowed )
            st.insert( ch );
        
        for ( string& str : words ) {
            for ( char ch : str ) {
                if ( st.find( ch ) == st.end() ) {
                    --cnt;
                    break;
                }
            }
        }

        return cnt;
    }
};

int main()
{
    

    return 0;
}