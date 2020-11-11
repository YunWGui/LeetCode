/*
Title:
    82. Remove Duplicates from Sorted List II
    82. 删除排序链表中的重复元素 II
Description:
    给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

    示例 1:
        输入: 1->2->3->3->4->4->5
        输出: 1->2->5
    示例 2:
        输入: 1->1->1->2->3
        输出: 2->3
Address: 
    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode( int x ) : val( x ), next( nullptr ) {  }
};


// 方法一：递归
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/javadi-gui-0ms-by-maplestore/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        if ( head->val == head->next->val ) {
            while ( head && head->next && head->val == head->next->val )
                head = head->next;
            return deleteDuplicates( head->next );
        }
        else {
            head->next = deleteDuplicates( head->next );
            return head;
        }
    }
};

// 方法二：迭代
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/zi-jie-ti-ku-82-zhong-deng-shan-chu-pai-xu-lian-bi/
class Solution_2 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;
        
        ListNode* dummy = new ListNode( -1 );
        dummy->next = head;
        ListNode* prev = dummy;

        while ( prev && prev->next ) {
            ListNode* cur = prev->next;
            if ( cur->next == nullptr || cur->val != cur->next->val )  // 如果curr到最后一位或者当前curr所指元素没有重复值
                prev = cur;  // 即：prev = prev->next;
            else {  // cur->val == cur->next->val
                while ( cur->next != nullptr && cur->val == cur->next->val )
                    cur = cur->next;
                prev->next = cur->next;  // prev->next 跳过中间所有的重复元素
            }
        }
        
        return dummy->next;
    }
};

int main()
{
    

    return 0;
}