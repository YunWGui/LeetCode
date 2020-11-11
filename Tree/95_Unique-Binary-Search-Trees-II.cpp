/*
Title:
    95. Unique Binary Search Trees II
    95. 不同的二叉搜索树 II
Address: 
    https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if ( n == 0 )
            return {};
        
        return helper( 1, n );
    }

    vector<TreeNode*> helper( int start, int end ) {
        if ( start > end ) 
            return { nullptr };
        
        vector<TreeNode*> res;
        for ( int i = start; i <= end; ++i ) {
            vector<TreeNode*> leftTree = helper( start, i - 1 );
            vector<TreeNode*> rightTree = helper( i + 1, end );
            
            for ( TreeNode* a : leftTree ) {
                for ( TreeNode* b : rightTree ) {
                    TreeNode* curNode = new TreeNode( i );
                    curNode->left = a;
                    curNode->right = b;
                    res.push_back( curNode );
                }
            }
        }

        return res;
    }
};

int main()
{
    

    return 0;
}