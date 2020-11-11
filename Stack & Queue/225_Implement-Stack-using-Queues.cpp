/*
Title:
    225. Implement Stack using Queues
    225. 用队列实现栈
Address:
    https://leetcode-cn.com/problems/implement-stack-using-queues/
*/


#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// 方法一: 普通队列
class MyStack {
private:
    queue<int> Q;
public:
    /** Initialize your data structure here. */
    MyStack() {   }
    
    /** Push element x onto stack. */
    void push(int x) {
        Q.push( x );
        for ( int i = 0; i < Q.size()-1; ++i ) {  // 对「队列」内的元素，「就地」翻转
            Q.push( Q.front() );
            Q.pop();
        }       
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = Q.front();
        Q.pop();

        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

// 方法二：使用「双端队列」
class MyStack_2 {
private:
    deque<int> DQ;  // 双端队列
public:
    /** Initialize your data structure here. */
    MyStack_2() {  }
    
    /** Push element x onto stack. */
    void push(int x) {
        DQ.push_back( x );
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = DQ.back();
        DQ.pop_back();
        
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return DQ.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return DQ.empty();
    }
};

int main()
{
    

    return 0;
}