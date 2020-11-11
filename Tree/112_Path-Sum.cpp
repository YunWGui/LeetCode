/*
题目：
    112. Path Sum
    112. 路径总和
地址：
    https://leetcode-cn.com/problems/path-sum/
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


// 方法一：
class Solution_1 {
public:
    bool hasPathSum(TreeNode* root, int sum) {

        return dfs(root, sum, 0);
    }

    bool dfs(TreeNode* root, int sum, int curSum) {
        if ( root == nullptr )  // 当前节点为「空节点」
            return false;
    
        curSum += root->val;
        if ( !root->left && !root->right )  // 当前节点为「叶节点」
            return curSum == sum;

        return dfs(root->left, sum, curSum)
            || dfs(root->right, sum, curSum);
    }
};

// 方法二：
class Solution_2 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if ( root == nullptr )  // 空节点
            return false;
        if ( root->left == nullptr && root->right == nullptr && sum == (root->val))
            return true;

        return hasPathSum( root->left, sum - (root->val) )
            || hasPathSum( root->right, sum - (root->val) );
    }
};

// 方法三：
class Solution_3 {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> path;
        int curSum = 0;
        bool isSum = false;

        if ( root != nullptr )
            dfs(root, sum, path, curSum, isSum);

        return isSum;
    }

    void dfs(TreeNode* root, int sum, vector<int>& path, int curSum, bool& isSum) {
        curSum += root->val;
        path.push_back(root->val);

        bool isLeaf = (root->left == nullptr) && (root->right == nullptr);
        if ( curSum == sum && isLeaf )
            isSum = true;

        if ( root->left != nullptr )
            dfs(root->left, sum, path, curSum, isSum);
        if ( root->right != nullptr )
            dfs(root->right, sum, path, curSum, isSum);

        path.pop_back();
    }
};

int main()
{


    return 0;
}
