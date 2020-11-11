/*
Title:
    134. Gas Station
    134. 加油站
Address: 
    https://leetcode-cn.com/problems/gas-station/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
// https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int curGas = 0;  // 当前剩余油量
        int minGas = INT_MAX;  // 行驶过程中油箱中测量的最小值
        int Idx = 0;  // 加油站编号

        for ( int i = 0; i < len; ++i ) {
            curGas += gas[i] - cost[i];
            if ( curGas < minGas ) {
                minGas = curGas;
                Idx = i;
            }
        }

        return curGas < 0 ? -1 : ( Idx + 1 ) % len;
    }
};

// 方法二：贪心法
// https://leetcode-cn.com/problems/gas-station/solution/tan-xin-suan-fa-qian-zhui-he-by-antione/
class Solution_2 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int curGas = 0;  // 当前剩余油量
        int minGas = INT_MAX;  // 行驶过程中油箱中测量的最小值
        
        for ( int i = 0; i < len; ++i ) {
            curGas += gas[i] - cost[i];
            if ( curGas < minGas )
                minGas = curGas;
        }

        if ( curGas < 0 )  // 加油站提供的油量总和小于花费总和，不能绕环路行驶一周
            return -1;

        if ( minGas >= 0 )  // 行驶过程中，油箱始终不为空，则可以从 0 出发环绕一周
            return 0;
        
        // minGas < 0，逆向遍历，找到将 minGas 补充到 >= 0 的点，就是能够环绕一周的起点，
        // 因为此时从该的起点出发，绕环路行驶的整个过程中 minGas >= 0，即油箱都不为空
        for ( int i = len - 1; i >= 0; --i ) {
            int diff = gas[i] - cost[i];
            minGas += diff;

            if ( minGas >= 0 )
                return i;
        }

        return -1;
    }
};

int main()
{
    

    return 0;
}