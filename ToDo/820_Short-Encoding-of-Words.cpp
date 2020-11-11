/*
Title:
    820. Short Encoding of Words
    820. 单词的压缩编码
Address:
    https://leetcode-cn.com/problems/short-encoding-of-words/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：宝典树
// https://leetcode-cn.com/problems/short-encoding-of-words/solution/shou-si-zi-dian-shu-trie-shu-c-by-time-limit/
struct Node {
    Node* next[26];  // 指针域。当前结点的边，指向对应的子节点
    bool flag;  // 标记字段。如果为 true，说明该树记录了一个由根节点到当前结点的路径组成的字符串。反之，则不存在。
    Node() {
        for ( int i = 0; i < 26; ++i ) 
            next[i] = nullptr;
        flag = false;
    }
};

const int MAXN = 2000*7 + 1;
Node pool[MAXN];  // 定义一个结点池，结合 placement new 实现内存复用
class Solution {
    int poolPtr;
    inline Node* getNodePtr() {
        return new ( &pool[poolPtr++]) Node();
    }
    // root: 当前子树根节点，str: 待插入的字符，str[pos]: 等待插入的字符串
    void Insert( Node* root, const string& str, int pos ) {
        if ( pos < 0 ) {
            root->flag = true;  // 记录有 str 至此结束了
            return;
        }            
        
        int ind = str[pos] - 'a';  // 计算 str[pos] 对应的子结点的下标
        if ( root->next[ind] == nullptr )
            root->next[ind] = getNodePtr();  // 记录 str 在 pos 处的字符
        Insert( root->next[ind], str, pos - 1 );  // pos + 1 等价于将已插入的字符删除了
    }
    int Count( Node* root, int edgeCnt ) {
        bool isLeaf = true;
        int sum = 0;
        for ( int i = 0; i < 26; ++i ) {
            if ( root->next[i] != nullptr ) {
                isLeaf = false;
                sum += Count( root->next[i], edgeCnt + 1 );
            }
        }
        if ( isLeaf )
            return edgeCnt + 1;  // 1 是 '#' 的长度
        
        return sum;
    }
public:
    int minimumLengthEncoding( vector<string>& words ) {
        poolPtr = 0;
        auto root = getNodePtr();
        for ( auto iter = words.cbegin(); iter != words.cend(); ++iter ) {
            Insert( root, *iter, int( iter->size() - 1 ) );
        }

        return Count( root, 0 );
    }
};


int main()
{
    

    return 0;
}