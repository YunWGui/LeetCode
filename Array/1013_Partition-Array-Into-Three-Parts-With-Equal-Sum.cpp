/*
Title:
    1013. Partition Array Into Three Parts With Equal Sum
    1013. 将数组分成和相等的三个部分
Address:
    https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：基于方法一的变形
class Solution_2 {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sumVal { 0 };

        for ( int x: A )
            sumVal += x;
        
        if ( sumVal % 3 != 0 )  // sumVal 不能被 3 整除
            return false;

        int res = sumVal / 3;
        int count { 0 };
        sumVal = 0;

        for ( int i = 0; i < A.size(); ++i ) {
            sumVal += A[i];
            if ( sumVal == res ) {
                ++count;
                sumVal = 0;  // 置 0
                if ( 2 == count && i != A.size()-1 )
                    return true;
            }
        }
                
        return false;
    }
};

// 方法一：
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        if ( A.empty() )
            return false;

        int sumVal { 0 };
        for ( int x: A )
            sumVal += x;
        
        int res = sumVal / 3;
        int count { 0 };
        sumVal = 0;
        
        for ( int i = 0; i < A.size(); ++i ) {
            sumVal += A[i];
            if ( sumVal == res ) {
                ++count;
                sumVal = 0;
            }
        }
        // 考虑 [10, -10, 10, -10, 10, -10, 10, -10] 这样的极端情况
        if ( 3 == count || ( 0 == res && count >= 3 ) )
            return true;
        
        return false;
    }
};

int main()
{
    

    return 0;
}