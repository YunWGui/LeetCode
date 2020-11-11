/*
Title:
    122. Best Time to Buy and Sell Stock II
    122. 买卖股票的最佳时机 II
Address: 
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;

        for ( int i = 1; i < (int)prices.size(); ++i ) 
            ans += max( 0, prices[i] - prices[i - 1] );
        
        return ans;
    }
};

int main()
{
    

    return 0;
}

