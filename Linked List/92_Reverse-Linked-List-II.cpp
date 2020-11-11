/*
Title:
    92. Reverse Linked List II
    92. 反转链表 II
Description:
    Reverse a linked list from position m to n. Do it in one-pass.
    Note: 1 ≤ m ≤ n ≤ length of list.
Address:
    https://leetcode-cn.com/problems/reverse-linked-list-ii/
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( NULL ) { }
};

// 方法二：迭代
class Solution_2 {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if ( head == nullptr || head->next == nullptr )  // 链表为空、或只有一个节点
            return head;

        ListNode* dummy = new ListNode( -1 );  // 虚拟头结点：为了得到反转原起点的前一个结点，以便连接反转的新起点
        dummy->next = head;
        head = dummy;

        for ( int i = 0; i < m - 1; ++i )
            head = head->next;  // 用 head 表示反转原起点的前一个结点

        ListNode* newTail = head->next;
        ListNode* prevNode = head->next;
        ListNode* curNode = prevNode->next;
        ListNode* nextNode = nullptr;

        for ( int i = 0; i < n - m; ++i ) {
            nextNode = curNode->next;

            curNode->next = prevNode;

            prevNode = curNode;
            curNode = nextNode;
        }  // 反转完成后，新起点 prevNode，新终点 newTail

        newTail->next = curNode;  // 将新终点与后面的链表连接
        head->next = prevNode;  // 将反转原起点的前一个结点连接到反转后的新起点

        return dummy->next;
    }
};


// 方法一：递归
// https://leetcode-cn.com/problems/reverse-linked-list-ii/solution/bu-bu-chai-jie-ru-he-di-gui-di-fan-zhuan-lian-biao/
class Solution {
public:
    ListNode* nextNode;

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if ( m == 1 )
            return reverseN( head, n );

        head->next = reverseBetween( head->next, m - 1, n - 1 );

        return head;
    }

    ListNode* reverseN( ListNode* head, int n ) {
        if ( n == 1 ) {
            nextNode = head->next;
            return head;
        }

        ListNode* last = reverseN( head->next, n - 1 );
        head->next->next = head;
        head->next = nextNode;

        return last;
    }
};

int main()
{


    return 0;
}
