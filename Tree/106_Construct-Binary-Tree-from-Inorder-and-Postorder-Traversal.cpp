/*
Title:
    106. Construct Binary Tree from Inorder and Postorder Traversal
    106. 从中序与后序遍历序列构造二叉树
Address:
    https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
*/

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法二：哈希表
class Solution_2 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash;  // 用 hash 记录某个节点在中序遍历数组中的索引
      
        for ( int i = 0; i < inorder.size(); ++i )
            hash[inorder[i]] = i;  // hash[value, index]
        
        int n = postorder.size();
        
        return helper(n, postorder, n-1, inorder, 0, hash);
    }

    TreeNode* helper(int n, vector<int>& postorder, int post_last,
                     vector<int>& inorder, int in_start, unordered_map<int, int>& hash) {
        if ( n == 0 )
            return nullptr;

        int val = postorder[post_last];
        int i = hash[val] - in_start;  // i 代表左子树有多少个节点
        
        TreeNode* curNode = new TreeNode(val);

        curNode->left = helper(i, postorder, post_last - n + i, inorder, in_start, hash);
        curNode->right = helper(n-i-1, postorder, post_last-1, inorder, in_start+i+1, hash);

        return curNode;
    }
};

// 方法一：递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if ( inorder.size() == 0 || postorder.size() == 0 )
            return nullptr;

        TreeNode* root = new TreeNode(postorder.back());

        vector<int> in_left, in_right;  // 中序遍历左侧，右侧
        vector<int> post_left, post_right;  // 后序遍历左侧、右侧

        size_t count_left = 0;
        for (size_t i = 0; i < inorder.size(); ++i) {
            if (inorder[i] == postorder.back())
                break;
            ++count_left;
        }
        // 拆分「后序」遍历
        for (size_t i = 0; i < postorder.size() - 1; ++i ) {
            if (i < count_left)
                post_left.push_back(postorder[i]);
            else
                post_right.push_back(postorder[i]);
        }
        // 拆分「中序」遍历
        for (size_t i = 0; i < inorder.size(); ++i) {
            if (i < count_left)
                in_left.push_back(inorder[i]);
            else if (count_left < i)
                in_right.push_back(inorder[i]);
        }
        // 递归
        root->left = buildTree(in_left, post_left);
        root->right = buildTree(in_right, post_right);

        return root;
    }

    // 用「后序遍历」的方式打印二叉树
    void PrintBinaryTreePostOrder (TreeNode* root){
        if (root == NULL)
            return;
        // postOrder
        PrintBinaryTreePostOrder(root->left);
        PrintBinaryTreePostOrder(root->right);
        cout << root->val << " ";
    }
};


int main ()
{
    Solution savle;
    vector<int> in { 9, 3, 15, 20, 7 };
    vector<int> post { 9, 15, 7, 20, 3 };



    TreeNode* root = savle.buildTree(in, post);

    savle.PrintBinaryTreePostOrder(root);
    cout << endl;

    return 0;
}
