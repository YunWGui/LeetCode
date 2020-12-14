/*
Title:
    1688. Count of Matches in Tournament
    1688. 比赛中的配对次数
Address: 
    https://leetcode-cn.com/problems/count-of-matches-in-tournament/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：
/*
    思路：每场比赛会淘汰一支队伍，最终只有一支队伍胜出，即要淘汰 N - 1 支队伍，因此
          需要 N - 1 场比赛
*/
class Solution_2 {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};

// 方法一：模拟
class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        
        while ( n > 1 ) {
            cnt += ( n >> 1 );
            
            // n = ( n & 1 ) ? ( n >> 1 ) + 1: ( n >> 1 );
            n = n / 2 + n % 2;
        }
        
        return cnt;
    }
};

int main()
{
    

    return 0;
}