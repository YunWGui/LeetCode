/*
Title:
    543. Diameter of Binary Tree
    543. 二叉树的直径
Description:
    Given a binary tree, you need to compute the length of the diameter of the tree. 
    The diameter of a binary tree is the length of the longest path between any 
    two nodes in a tree. This path may or may not pass through the root.

    Example:
    Given a binary tree
             1
            / \
           2   3
          / \     
         4   5    
    Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: 
    The length of path between two nodes is represented by the number of edges between them.
Address:
    https://leetcode-cn.com/problems/diameter-of-binary-tree/
*/

#include <iostream>
#include <algorithm>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// 方法一：DFS，深度优先搜索
/*
解析：
    最大直径不一定经过二叉树原来的根节点，而是要以每个节点为根节点，计算最大直径（左子
树高度 + 右子树高度）。
    所以我们需要一个函数 depth 来计算某个节点的左子树和右子树的高度。
    再定义一个变量 distance 来保存二叉树的直径。
    每次获得左子树和右子树的高度之后，比较 distance 和 left + right 的大小，更新 count。
    此题与 LeetCode-563 二叉树的坡度 类似。
*/
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if ( root == nullptr )
            return 0;
        
        int distance = 0;  // 保存最大直径
        depth( root, distance );

        return distance;
    }

    int depth( TreeNode* root, int& distance ) {
        if ( root == nullptr )
            return 0;
        
        int leftDist = depth( root->left, distance );  // 左子树的高度
        int rightDist = depth( root->right, distance );  // 右子树的高度
        // 每次获得左子树和右子树的高度之后，比较 distance 和 left + right 的大小，更新 distance
        distance = max( distance, leftDist + rightDist );

        return max( leftDist, rightDist ) + 1;  // 求左右子树的高度
    }
};

int main()
{
    TreeNode* root = new TreeNode( 1 );
    root->left = new TreeNode( 2 );
    root->right = new TreeNode( 3 );
    root->left->left = new TreeNode( 4 );
    root->left->right = new TreeNode( 5 );

    Solution solve;

    cout << solve.diameterOfBinaryTree( root ) << endl;
    

    return 0;
}