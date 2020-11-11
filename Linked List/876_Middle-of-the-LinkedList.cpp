/*
Title:
    876. Middle of the Linked List
    876. 链表的中间结点
Address:
    https://leetcode-cn.com/problems/middle-of-the-linked-list/
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法三：快慢指针
class Solution_3 {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* solw = head;
        ListNode* fast = head;
        // fast 以 solw 的两倍速度前进
        while ( fast != nullptr && fast->next != nullptr ) {
            solw = solw->next;
            fast = fast->next->next;
        }

        return solw;
    }
};


// 方法一：
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* curNode = head;
        while ( curNode != nullptr ) {
            ++count;
            curNode = curNode->next;
        }

        int mid = ( count >> 1 ) + 1;
        curNode = head;
        for ( int i = 1; i < mid; ++i ) 
            curNode = curNode->next;    
        
        return curNode;
    }
};

// 方法二：空间换时间
class Solution_2 {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        ListNode* curNode = head;
        vector<ListNode*> vec;
        vec.push_back( nullptr );  

        while ( curNode != nullptr ) {
            ++count;
            vec.push_back( curNode );  // 从「下标」为 1 的位置开始插入
            curNode = curNode->next;
        }

        int mid = ( count>>1 ) + 1;
        
        return vec[mid];
    }
};


int main()
{
    

    return 0;
}