/*******************************************************************************
 * Title:
 *     179. Largest Number
 *     179. 最大数
 * Address:
 *     https://leetcode-cn.com/problems/largest-number/
 * Tips:
 *     与《剑指offer - 45.把数组排成最小的数》类似
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort( nums.begin(), nums.end(), []( const int& x, const int& y ) {
            return to_string( x ) + to_string( y ) > to_string( y ) + to_string( x );
        });

        if ( nums[0] == 0 )  // nums数组最大的数为 0，表明整个数组均为 0
            return "0";

        string ans;
        for ( const int& num : nums )
            ans += to_string( num );
        
        return ans;
    }
};

// 方法二：
class Solution_2 {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> cpy;
        for ( int num : nums )
            cpy.push_back( to_string( num ) );
        
        sort( cpy.begin(), cpy.end(), []( const string& a, const string& b ) {
            return a + b > b + a;
        });

        string ans;
        for ( string& str : cpy )
            ans += str;
        
        return ans[0] == '0' ? "0" : ans;
    }
};

int main()
{
    

    return 0;
}