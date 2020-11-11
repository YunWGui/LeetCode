/*
Title:
    662. Maximum Width of Binary Tree
    662. 二叉树最大宽度
Address: 
    https://leetcode-cn.com/problems/maximum-width-of-binary-tree/
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode ( int x ): val( x ), left( NULL ), right( NULL ) {  }
};

// 方法一：层次遍历
// https://leetcode-cn.com/problems/maximum-width-of-binary-tree/solution/ceng-xu-bian-li-dui-lie-cun-chu-mei-ge-jie-dian-de/
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) 
            return 0;

        int ans = 1;
        queue<pair<TreeNode*, unsigned long long>> Q;
        Q.push({root, 1});
        
        while (!Q.empty()) {
            ans = max(int(Q.back().second - Q.front().second + 1), ans);

            for ( int i = Q.size(); i > 0; --i ) {
                TreeNode* cur = Q.front().first;
                unsigned long long pos = Q.front().second;  Q.pop();

                if (cur->left) 
                    Q.push({cur->left, 2 * pos});

                if (cur->right)
                    Q.push({cur->right, 2 * pos + 1});
            }
        }

        return ans;
    }
};


int main()
{
    

    return 0;
}