/*
Title:
    24. Swap Nodes in Pairs
    24. 两两交换链表中的节点
Address:
    https://leetcode-cn.com/problems/swap-nodes-in-pairs/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 方法三：递归
class Solution_3 {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* cur = head;
        ListNode* nxt = cur->next;

        cur->next = swapPairs(nxt->next);
        nxt->next = cur;

        return nxt;
    }
};

// 方法一：作图解答
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;

        ListNode* dummy = new ListNode( -1 );  // 哨兵节点
        dummy->next = head;

        ListNode* pre = dummy, *cur = head, *nxt = cur->next;

        while ( nxt != nullptr ) {
            cur->next = nxt->next;
            nxt->next = cur;
            pre->next = nxt;

            // 指针右移
            pre = cur;
            cur = cur->next;

            if ( cur == nullptr )
                break;
            else
                nxt = cur->next;
        }

        return dummy->next;
    }
};

// 方法二
class Solution_2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;

        ListNode* pre = nullptr;
        ListNode* newHead = nullptr;  // 翻转后链表的头节点
        for ( ListNode* cur = head; cur && cur->next; cur = cur->next ) {
            ListNode* nxt = cur->next;

            cur->next = nxt->next;
            nxt->next = cur;

            if ( pre )
                pre->next = nxt;

            pre = cur;

            if ( cur == head )
                newHead = nxt;
        }

        return newHead;
    }
};


int main()
{


    return 0;
}
