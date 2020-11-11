/*
Title:
    61. Rotate List
    61. 旋转链表
Description:
    给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
Address:
    https://leetcode-cn.com/problems/rotate-list/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if ( !head || !head->next )
            return nullptr;

        int len = 0;
        ListNode* curNode = head, *preNode = head, *res;
        
        while ( curNode ) {  // 获取链表长度
            ++len;
            curNode = curNode->next;
        }

        k %= len;
        if ( k == 0 )
            return head;

        curNode = head;
        while ( k-- )  // curNode 先后移 k 步 
            curNode = curNode->next;

        while ( curNode->next ) {  // preNode 和 curNode 同时后移，直到 curNode->next == nullptr 为止
            curNode = curNode->next;
            preNode = preNode->next;
        }  // 此时 preNode->next 就是倒数第 k 个元素
        
        res = preNode->next;
        preNode->next = nullptr;
        curNode->next = head;

        return res; 
    }
};

int main()
{
    

    return 0;
}