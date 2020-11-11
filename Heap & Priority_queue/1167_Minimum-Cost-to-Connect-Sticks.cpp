/*
Title:
    1167. Minimum Cost to Connect Sticks
    1167. 连接棒材的最低费用
Description:
    为了装修新房，你需要加工一些长度为正整数的棒材 sticks。

    如果要将长度分别为 X 和 Y 的两根棒材连接在一起，你需要支付 X + Y 的费用。 
    由于施工需要，你必须将所有棒材连接成一根。

    返回你把所有棒材 sticks 连成一根所需要的最低费用。注意你可以任意选择棒材连接的顺序。

    示例 1：
    输入：sticks = [2,4,3]
    输出：14
    解释：先将 2 和 3 连接成 5，花费 5；再将 5 和 4 连接成 9；总花费为 14。

    示例 2：
    输入：sticks = [1,8,3,5]
    输出：30
    提示：

    1 <= sticks.length <= 10^4
    1 <= sticks[i] <= 10^4

Address:
    https://leetcode-cn.com/problems/minimum-cost-to-connect-sticks/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 方法一：最小堆
/* 时间复杂度：O(nlongn)  空间复杂度：O(n) 
思路：
    哈夫曼树权值求和
    根据贪心的思想，应该把最长的棒子留到最后再合并，每次应该把当前最短的两根棒子合在一起。
    所以是一个动态找最小值的过程，用优先级队列解题。
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for ( int num : sticks )
            minHeap.push( num );
        
        int res = 0;
        while ( minHeap.size() > 1 ) {
            int x = minHeap.top();  minHeap.pop();
            int y = minHeap.top();  minHeap.pop();
            
            res += x + y;
            minHeap.push( x + y );
        }

        return res;
    }
};



int main()
{
    vector<int> nums{ 1, 8, 3, 5 };
    Solution solve;

    cout << solve.connectSticks( nums ) << endl;
    
    return 0;
}