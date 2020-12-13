/*
Title:
    5625. Count of Matches in Tournament
    5625. 比赛中的配对次数
Address: 
    https://leetcode-cn.com/contest/weekly-contest-219/problems/count-of-matches-in-tournament/
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法一：
class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        
        while ( n > 1 ) {
            cnt += ( n >> 1 );
            
            n = ( n & 1 ) ? ( n >> 1 ) + 1: ( n >> 1 );
        }
        
        return cnt;
    }
};

int main()
{
    

    return 0;
}