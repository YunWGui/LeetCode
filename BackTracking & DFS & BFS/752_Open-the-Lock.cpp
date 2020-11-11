/*
Title:
    752. Open the Lock
    752. 打开转盘锁
Address:
    https://leetcode-cn.com/problems/open-the-lock/
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

// 方法一: BFS - 广度优先搜索 —— 超时
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        set<string> deads;  // 记录需要跳过的死亡密码
        for ( string& s : deadends )
            deads.insert( s );
        
        // 记录已经穷举过的密码，防止走回头路
        set<string> visited;
        queue<string> Q;

        // 从起点开始启动广度优先搜索
        int step = 0;
        Q.push( "0000" );
        visited.insert( "0000" );

        while ( !Q.empty() ) {
            int sz = Q.size();
            // 将当前队列中的所有节点向周围扩散
            for ( int i = 0; i < sz; ++i ) {
                string cur = Q.front();
                Q.pop();

                // 判断是否到达终点
                if ( deads.count( cur ) )
                    continue;
                if ( cur == target )
                    return step;
                
                // 将一个节点的未遍历相邻节点加入队列
                for ( int j = 0; j < 4; ++j ) {
                    string up = plusOne( cur, j );
                    if ( !visited.count( up ) ) {
                        Q.push( up );
                        visited.insert( up );
                    }
                    string down = minusOne( cur, j );
                    if ( !visited.count( down ) ) {
                        Q.push( down );
                        visited.insert( down );
                    }
                }
            }
            // 在这里增加步数
            ++step;
        }
        // 如果穷举完都没有找到目标密码，那就是找不到了。
        return -1;
    }
    // 将 s[i] 向上拔动一次
    string plusOne( string s, int j ) {
        // string s = s;
        if ( s[j] == '9' )
            s[j] = '0';
        else
            s[j] += 1;
        
        return s;
    }
    // 将 s[i] 向下拔动一闪
    string minusOne( string s, int j ) {
        if ( s[j] == '0' )
            s[j] = '9';
        else 
            s[j] -= 1;
        
        return s;
    }
};


// 方法二：双向 BFS -> 多源 ：Error
class Solution_2 {
public:
    int openLock(vector<string>& deadends, string target) {
        
        set<string> deads;  // 记录需要跳过的死亡密码
        for ( string& s : deadends )
            deads.insert( s );
        
        // 记录已经穷举过的密码，防止走回头路
        set<string> visited;
        set<string> Q1;
        set<string> Q2;

        // 从起点开始启动广度优先搜索
        int step = 0;
        Q1.insert( "0000" );
        Q2.insert( target );

        while ( !Q1.empty() && Q2.empty() ) {
            set<string> temp;
            // 将 Q1 中的所有节点向周围扩散
            for ( string cur : Q1 ) {
                // 判断是否到达终点
                if ( deads.count( cur ) )
                    continue;
                if ( Q2.count( cur ) )
                    return step;
                visited.insert( cur );

                // 将一个节点的未遍历相信节点加入集合
                for ( int j = 0; j < 4; ++j ) {
                    string up = plusOne( cur, j );
                    if ( !visited.count( up ) )
                        temp.insert( up );
                    
                    string down = minusOne( cur, j );
                    if ( !visited.count( down ) )
                        temp.insert( down );
                }
            }
            // 在这里增加步数
            ++step;
            // temp 相当于 Q1
            // 这里交换 Q1、Q2，下一轮 while 就是扩散 Q2
            Q1 = Q2;
            Q2 = temp;
        }
        // 如果穷举完都没有找到目标密码，那就是找不到了。
        return -1;
    }
    // 将 s[i] 向上拔动一次
    string plusOne( string s, int j ) {
        // string s = s;
        if ( s[j] == '9' )
            s[j] = '0';
        else
            s[j] += 1;
        
        return s;
    }
    // 将 s[i] 向下拔动一闪
    string minusOne( string s, int j ) {
        if ( s[j] == '0' )
            s[j] = '9';
        else 
            s[j] -= 1;
        
        return s;
    }
};

int main()
{
    

    return 0;
}