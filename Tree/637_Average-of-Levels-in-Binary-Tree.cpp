/*
Title:
    637. Average of Levels in Binary Tree
    637. 二叉树的层平均值
Address: 
    https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/
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
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};

// 方法一：层次遍历
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if ( root == nullptr )
            return res;

        queue<TreeNode*> Q;
        Q.push( root );

        while ( !Q.empty() ) {
            vector<int> level;
            for ( int i = Q.size(); i > 0; --i ) {
                TreeNode* cur = Q.front();  Q.pop();
                level.push_back( cur->val );

                if ( cur->left )  Q.push( cur->left );
                if ( cur->right )  Q.push( cur->right );
            }

            res.push_back( accumu( level ) );
        }

        return res;
    }

    double accumu( vector<int> level ) {
        double sum = 0.0;
        for ( int e : level )
            sum += e;
        
        return sum / (int)level.size();
    }
};

int main()
{
    

    return 0;
}