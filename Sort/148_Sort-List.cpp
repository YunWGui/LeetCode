/*
Title:
    148. Sort List
    148. 排序链表
Description:
    在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
Address:
    https://leetcode-cn.com/problems/sort-list/
*/

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( NULL ) { }
};


// 方法二：归并排序
class Solution_2 {
public:
    ListNode* sortList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* slow = head, *fast = head->next;  // 快慢指针
        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;

        ListNode* l1 = sortList( head );
        ListNode* l2 = sortList( head2 );

        return mergeTwoList( l1, l2 );
    }

    ListNode* mergeTwoList( ListNode* l1, ListNode* l2 ) {
        if ( l1 == nullptr )
            return l2;
        if ( l2 == nullptr )
            return l1;
        
        ListNode* res = nullptr;

        if ( l1->val <= l2->val ) {
            res = l1;
            res->next = mergeTwoList( l1->next, l2 );
        }
        else {
            res = l2;
            res->next = mergeTwoList( l1, l2->next );
        }

        return res;
    }
};


// 方法三：快速排序
// https://leetcode.com/problems/sort-list/discuss/803260/C%2B%2B-Quick-Sort-Commented
class Solution_3 {
public:
    ListNode* sortList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* tail = head;

        while ( tail->next )
            tail = tail->next;
        
        quickSort( head, tail );

        return head;
    }

    void quickSort( ListNode* head, ListNode* tail ) {
        if ( head == tail || head == nullptr || tail == nullptr )
            return;
        
        ListNode* mid = partition( head, tail );

        quickSort( head, mid );
        quickSort( mid->next, tail );
    }

    ListNode* partition( ListNode* left, ListNode* right ) {
        if ( left == right || left == nullptr || right == nullptr )
            return nullptr;
        
        ListNode* pivot = left;
        ListNode* ptr = left;

        left = left->next;

        while ( left != right->next ) {
            if ( left->val < pivot->val ) {
                ptr = ptr->next;
                int temp = left->val;
                left->val = ptr->val;
                ptr->val = temp;
            }

            left = left->next;
        }

        int temp = ptr->val;
        ptr->val = pivot->val;
        pivot->val = temp;

        return ptr;
    }
};

// 方法一：冒泡排序
/* 
    时间复杂度：O( n^2 )
    空间复杂度：O( 1 )
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr ) 
            return head;
        
        ListNode* cur = head;
        ListNode* nxt = nullptr;

        while ( cur != nullptr ) {
            nxt = cur->next;
            while ( nxt != nullptr ) {
                if ( cur->val > nxt->val ) {
                    int tmp = nxt->val;
                    nxt->val = cur->val;
                    cur->val = tmp;
                }
                nxt = nxt->next;
            }
            cur = cur->next;
        }

        return head;
    }
};

int main()
{
    

    return 0;
}