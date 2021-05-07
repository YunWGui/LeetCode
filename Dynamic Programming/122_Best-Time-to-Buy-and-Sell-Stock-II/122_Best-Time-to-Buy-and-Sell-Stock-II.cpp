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
// 由于交易次数不受限，所有上涨数值的和，即为最佳时机
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int total_gain = 0;

        for ( int i = 1; i < (int)prices.size(); ++i )
            if ( prices[i - 1] < prices[i] )
                total_gain += prices[i] - prices[i - 1];
        
        return total_gain;
    }
};

int main()
{
    

    return 0;
}

