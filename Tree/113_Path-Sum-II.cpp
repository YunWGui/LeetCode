/*
题目：
    113. Path Sum II
    113. 路径总和 II
描述：
    给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
    说明: 叶子节点是指没有子节点的节点。

    示例:
    给定如下二叉树，以及目标和 sum = 22，
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
    返回:
        [
            [5,4,11,2],
            [5,8,4,5]
        ]

地址：
    https://leetcode-cn.com/problems/path-sum-ii/
*/


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int curSum = 0;

        if ( root != nullptr )
            backTrack(root, sum, path, curSum, res);

        return res;
    }

    void backTrack(TreeNode* root, int sum, vector<int>& path, int curSum, vector<vector<int>>& res) {
        curSum += root->val;
        
        path.push_back(root->val);  // 加入

        if ( root->left == nullptr && root->right == nullptr && curSum == sum )
            res.push_back(path);

        if ( root->left != nullptr )
            backTrack(root->left, sum, path, curSum, res);
        if ( root->right != nullptr )
            backTrack(root->right, sum, path, curSum, res);

        path.pop_back();  // 弹出
    }
};

int main()
{


    return 0;
}
