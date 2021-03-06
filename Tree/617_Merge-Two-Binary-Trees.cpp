/*
Title:
    617. Merge Two Binary Trees
    617. 合并二叉树
Address: 
    https://leetcode-cn.com/problems/merge-two-binary-trees/
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


// 方法一：dfs
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if ( t1 == nullptr )
            return t2;
        if ( t2 == nullptr )
            return t1;
        
        TreeNode* curNode = new TreeNode( t1->val + t2->val );

        curNode->left = mergeTrees( t1->left, t2->left );
        curNode->right = mergeTrees( t1->right, t2->right );

        return curNode;
    }
};

int main()
{
    

    return 0;
}