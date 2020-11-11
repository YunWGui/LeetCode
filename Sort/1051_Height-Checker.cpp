/*
Title:
    1051. Height Checker
    1051. 高度检查器
Address: 
    https://leetcode-cn.com/problems/height-checker/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序 - 计算有多少个数字改变了顺序
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        if ( heights.empty() )
            return 0;

        int cnt = 0;
        vector<int> arr( heights );
        sort( arr.begin(), arr.end() );

        for ( int i = 0; i < (int)heights.size(); ++i )
            if ( heights[i] != arr[i] )
                ++cnt;

        return cnt;
    }
};


int main()
{
    

    return 0;
}