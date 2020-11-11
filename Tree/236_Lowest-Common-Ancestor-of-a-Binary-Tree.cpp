/*
Title:
    236. Lowest Common Ancestor of a Binary Tree
    236. 二叉树的最近公共祖先
Address: 
    https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode ( int x ): val( x ), left( NULL ), right( NULL ) {  }
};

// 方法一：递归
// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/mian-shi-ti-68-ii-er-cha-shu-de-zui-jin-gong-gon-7/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root == nullptr || root == p || root == q )
            return root;
        
        TreeNode* leftNode = lowestCommonAncestor( root->left, p, q );
        TreeNode* rightNode = lowestCommonAncestor( root->right, p, q );

        if ( leftNode == nullptr )
            return rightNode;
        if ( rightNode == nullptr )
            return leftNode;
        
        return root;
    }
};

int main()
{
    

    return 0;
}