/*
Title:
    1130. Minimum Cost Tree From Leaf Values
    1130. 叶值的最小代价生成树
Description:
    给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
        - 每个节点都有 0 个或是 2 个子节点。
        - 数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。
        - 每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
    在所有这样的二叉树中，返回每个「非叶节点」的值的最小可能总和。
    这个和的值是一个 32 位整数。
Address: 
    https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values/
*/

// https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values/solution/xiang-xi-jie-shi-dong-tai-gui-hua-dan-diao-zhan-ji/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：栈 - 用 vector 模拟「栈」
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        vector<int> stack { INT_MAX };

        for ( int num : arr ) {
            while ( stack.back() <= num ) {
                int mid = stack.back();
                stack.pop_back();
                res += mid * min( stack.back(), num );
            }
            stack.push_back( num );
        }

        for ( int i = 2; i < (int)stack.size(); ++i ) {
            res += stack[i] * stack[i - 1];
        }

        return res;
    }
};

int main()
{
    

    return 0;
}