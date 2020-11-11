/*
题目：
    107. Binary Tree Level Order Traversal II
    107. 二叉树的层次遍历 II
地址：
    https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){ }
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> Q;
        stack<vector<int>> stk;

        if ( root )
            Q.push(root);

        while ( !Q.empty() ) {
            vector<int> level;
            for ( size_t i = Q.size(); i > 0; --i ) {
                TreeNode* cur = Q.front(); Q.pop();

                level.push_back(cur->val);

                if ( cur->left )
                    Q.push(cur->left);
                if ( cur->right )
                    Q.push(cur->right);
            }

            stk.push(level);
        }

        while ( !stk.empty() ) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};

class Solution_2 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<vector<int>> stk;
        queue<TreeNode*> Q;
        vector<int> level;

        if ( root != nullptr )  // 根节点非空
            Q.push(root);

        int currentLevel = 1;  // 当前层中还没有打印的节点数
        int nextLevel = 0;  // 下一层节点的数目

        while ( !Q.empty() ) {  // 队列非空
            TreeNode* x = Q.front();
            Q.pop();
            level.push_back(x->val);
            --currentLevel;

            if ( x->left ) {  // 当前节点存在左节点
                Q.push(x->left);
                ++nextLevel;
            }
            if ( x->right ) {  // 当前节点存在右节点
                Q.push(x->right);
                ++nextLevel;
            }

            if ( currentLevel == 0 ) {
                stk.push(level);
                level.clear();  // vector 置空
                currentLevel = nextLevel;
                nextLevel = 0;
            }
        }

        while ( !stk.empty() ) {
            res.push_back(stk.top());
            stk.pop();
        }

        return res;
    }
};


int main()
{


    return 0;
}
