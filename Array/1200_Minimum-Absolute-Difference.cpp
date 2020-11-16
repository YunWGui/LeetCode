/*
Title:
    1200. Minimum Absolute Difference
    1200. 最小绝对差
Address: 
    https://leetcode-cn.com/problems/minimum-absolute-difference/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：
class Solution_2 {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        
        sort( arr.begin(), arr.end() );

        int minDelta = 1e7;  // 最大差值

        for ( int i = 1; i < (int)arr.size(); ++i ) {
            int delta = arr[i] - arr[i - 1];

            if ( delta < minDelta ) {
                minDelta = delta;
                ans = { { arr[i - 1], arr[i] } };  // 覆盖之前的值
            }
            else if ( delta == minDelta ) 
                ans.push_back( { arr[i - 1], arr[i] } );
        }
        
        return ans;
    }
};

// 方法一：直觉
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort( arr.begin(), arr.end() );

        vector<int> temp( arr.size() - 1 );

        for ( int i = 1; i < (int)arr.size(); ++i ) 
            temp[i - 1] = arr[i] - arr[i - 1];
        
        int minDelta = *min_element( temp.begin(), temp.end() );

        vector<vector<int>> ans;

        for ( int i = 0; i < (int)temp.size(); ++i ) 
            if ( temp[i] == minDelta )
                ans.push_back( { arr[i], arr[i + 1] } );

        return ans;
    }
};


int main()
{
    

    return 0;
}