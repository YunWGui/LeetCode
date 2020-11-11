/*
Title:
    455. Assign Cookies
    455. 分发饼干
Address:
    https://leetcode-cn.com/problems/assign-cookies/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序 + 自后向前比较
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort( g.begin(), g.end() );
        sort( s.begin(), s.end() );

        int cnt = 0;
        int lenG = g.size() - 1, lenS = s.size() - 1;
        while ( 0 <= lenG && 0 <= lenS ) {
            if ( s[lenS] >= g[lenG] ) {  // 满足条件
                ++cnt;
                --lenS; --lenG;
            }
            else
                --lenG;
        }

        return cnt;
    }
};

int main()
{


    return 0;
}
