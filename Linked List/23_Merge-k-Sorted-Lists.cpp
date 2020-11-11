/*
Title:
    23. Merge k Sorted Lists
    23. 合并 K 个排序链表
Address:
    https://leetcode-cn.com/problems/merge-k-sorted-lists/
*/

// https://leetcode.com/problems/merge-k-sorted-lists/discuss/785936/C%2B%2B-oror-3-Approaches-oror-Easy-to-understand

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 方法一：优先级队列
/* 时间复杂度：O( n logk ), 空间复杂度：O( k ) */
class Solution {
public:
    struct cmp {
        bool operator() ( ListNode* a, ListNode* b ) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if ( lists.empty() )
            return nullptr;

        priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;  // 小根堆

        for ( ListNode* cur : lists ) 
            if ( cur != nullptr )
                minHeap.push( cur );
            
        ListNode dummy( -1 );        
        ListNode* cur = &dummy;

        while ( !minHeap.empty() ) {
            ListNode* temp = minHeap.top();  minHeap.pop();
            cur->next = temp;
            cur = temp;

            if ( temp->next )
                minHeap.push( temp->next );
        }

        return dummy.next;
    }
};


// 方法二：优先级队列
static auto lambda = [](ListNode* x, ListNode* y) {
    return (x != nullptr && y == nullptr) || (x != nullptr && y != nullptr && x->val > y->val); };

class Solution_2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(lambda)> minHeap(lambda, move(lists));
        ListNode* begin = nullptr;
        ListNode* curr = nullptr;

        while ( !minHeap.empty() ) {
            auto temp = minHeap.top();  minHeap.pop();
          
            if (temp != nullptr) {
                if (begin == nullptr) {
                    begin = temp;
                    curr = temp;
                } else {
                    curr->next = temp;
                    curr = curr->next;
                }
                if (temp->next != nullptr) {
                    minHeap.push(temp->next);
                }
            }
        }
        return begin;
    }
}; 



int main()
{


    return 0;
}
