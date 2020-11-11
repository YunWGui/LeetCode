/*
Title:
    354. Russian Doll Envelopes
    354. 俄罗斯套娃信封问题
Address:
    https://leetcode-cn.com/problems/russian-doll-envelopes/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序 + 动态规划
bool cmp( const vector<int>& x, const vector<int>& y ) {
    if ( x[0] < y[0] )
        return true;
    else if ( x[0] == y[0] )
        return x[1] > y[1];

    return false;
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort( envelopes.begin(), envelopes.end(), cmp );

        vector<int> dp;
        for ( int i = 0; i < (int)envelopes.size(); ++i ) {
            int left = 0, right = dp.size();
            while ( left < right ) {
                int mid = left + ( ( right - left ) >> 1 );

                if ( dp[mid] < envelopes[i][1] )
                    left = mid + 1;
                else
                    right = mid;
            }

            if ( right >= (int)dp.size() )
                dp.push_back( envelopes[i][1] );
            else
                dp[right] = envelopes[i][1];
        }

        return dp.size();
    }
};

// 方法二：排序 + 动态规划
class Solution_2 {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if ( envelopes.empty() )
            return 0;

        sort( envelopes.begin(), envelopes.end(), cmp );

        int res = 1;
        vector<int> dp( envelopes.size(), 1 );
        for ( int i = 1; i < (int)envelopes.size(); ++i ) {
            for ( int j = 0; j < i; ++j ) {
                if ( envelopes[j][1] < envelopes[i][1] )
                    dp[i] = max( dp[i], dp[j] + 1 );
            }
            res = max( res, dp[i] );
        }

        return res;
    }
};


int main()
{


    return 0;
}
