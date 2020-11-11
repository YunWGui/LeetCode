/*
Title:
    945. Minimum Increment to Make Array Unique
    945. 使数组唯一的最小增量
Address:
    https://leetcode-cn.com/problems/minimum-increment-to-make-array-unique/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        sort( A.begin(), A.end() );

        int cnt = 0;
        for ( int i = 1; i < (int)A.size(); ++i ) {
            if ( A[i - 1] >= A[i] ) {
                cnt += A[i - 1] - A[i] + 1;
                A[i] = A[i - 1] + 1;
            }
        }

        return cnt;
    }
};


int main()
{
    

    return 0;
}