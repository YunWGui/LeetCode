/*
Title:
    25. Reverse Nodes in k-Group
    25. K 个一组翻转链表
Address: 
    https://leetcode-cn.com/problems/reverse-nodes-in-k-group/
*/

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法一：双端队列 + 递归
class Solution {
  public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if ( head == nullptr || head->next == nullptr || k == 1  )
            return head;
        
        deque<ListNode *> dq;
        while ( head && dq.size() < k ) {
            dq.push_back(head);
            head = head->next;
        }

        if ( dq.size() < k )
            return dq.front();
        else {
            ListNode *reversed = reverseKGroup(head, k);  // 递归
            head = dq.back();  dq.pop_back();
            ListNode *temp = head;
            
            while ( !dq.empty() ) {
                temp->next = dq.back();  dq.pop_back();
                temp = temp->next;
            }

            temp->next = reversed;
            
            return head;
        }
    }
};

// 方法二：
// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/814627/Faster-than-96.92-or-O(1)-Space-or-Iterative-Solution-with-helpful-comments.
class Solution {
  public:
    // Function to find the length of the list
    int length(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1)
            return head;

        int len = length(head); // Find the length of the list.
        int lim = len / k; // Finding the number of segments that need to be
                           // reversed. For e.g. when length is 5 and k = 2 the
                           // we need to reverse 2 segments i.e 5/2 segments.
        ListNode *res; // Stores the node to be returned.
        ListNode *currHead = head;
        for ( int i = 0; i < lim; i++ ) {  // Looping for the number of segments.
            // Initializing necessary variables to reverse the segment.
            ListNode *curr = currHead, *prev = NULL, *next; 

            int cnt = k;
            while ( cnt-- ) {  // Reversing k nodes.
                next = curr->next;
                curr->next = prev;
                
                prev = curr;
                curr = next;
            }
            
            if (i == 0) // Head of the first reversed segment is the answer. So storing it in res.
                res = prev;
            else {  // All the other reversed segments need to be attached to the previous reversed segment.
                head->next = prev;
                head = currHead;
            }
            
            currHead->next = curr; // Moving on to the next segment for reversal.
            currHead = curr;
        }

        return res;
    }
};

int main() 
{
    
    return 0; 
}