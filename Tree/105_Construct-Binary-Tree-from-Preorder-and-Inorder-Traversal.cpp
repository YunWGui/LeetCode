/*
题目：
    105. Construct Binary Tree from Preorder and Inorder Traversal
    105. 从前序与中序遍历序列构造二叉树
地址：
    https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
备注：
    同《剑指offer》第7题-重建二叉树，P62
    https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if ( preorder.empty() || inorder.empty() )
            return nullptr;

        int idx = 0;  // preorder 的下标索引

        return dfs( preorder, inorder, 0, preorder.size() - 1, idx );
    }

    TreeNode* dfs( vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx ) {
        int pivot = 0;
        while ( pivot <= right ) {
            if ( inorder[pivot] == preorder[idx] )
                break;
            ++pivot;
        }

        TreeNode* curNode = new TreeNode( preorder[idx] );
        if ( left <= pivot - 1 ) {
            ++idx;
            curNode->left = dfs( preorder, inorder, left, pivot - 1, idx );
        }

        if ( pivot + 1 <= right ) {
            ++idx;
            curNode->right = dfs( preorder, inorder, pivot + 1, right, idx );
        }

        return curNode;
    }
};

int main()
{
    

    return 0;
}