/*
题目：
    103. Binary Tree Zigzag Level Order traversal
    103. 二叉树的锯齿形层次遍历
地址：
    https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
*/


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        bool left_to_right = true;

        if ( root )
            Q.push(root);

        while ( !Q.empty() ) {
            vector<int> level;
            for ( int i = Q.size(); i > 0; --i ) {
                TreeNode* cur = Q.front(); Q.pop();
                level.push_back(cur->val);

                if ( cur->left )
                    Q.push(cur->left);
                if ( cur->right )
                    Q.push(cur->right);
            }

            if ( !left_to_right )
                reverse(level.begin(), level.end());

            left_to_right = !left_to_right;
            res.push_back(level);
        }
        return res;
    }
};


int main()
{


    return 0;
}
