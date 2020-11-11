/*
Title:
    645. Set Mismatch
    645. 错误的集合
Description:
    The set S originally contains numbers from 1 to n. But unfortunately, due to 
    the data error, one of the numbers in the set got duplicated to another number 
    in the set, which results in repetition of one number and loss of another number.

    Given an array nums representing the data status of this set after the error. 
    Your task is to firstly find the number occurs twice and then find the number 
    that is missing. Return them in the form of an array.

    Example 1:
    Input: nums = [1,2,2,4]
    Output: [2,3]

Note:
    The given array size will in the range [2, 1000 0].
    The given array's numbers won't have any order.
Address:
    https://leetcode-cn.com/problems/set-mismatch/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：就地修改
// 参考：https://mp.weixin.qq.com/s/o3GQ4fXjPkS04Sr9uPH8ZQ
class Solution_2 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        int dup = -1;
        for ( size_t i = 0; i < len; ++i ) {
            int index = abs( nums[i] ) - 1;
            if ( nums[index] < 0 )
                dup = abs( nums[i] );
            else
                nums[index] *= -1;
        }

        int missing = -1;
        for ( size_t i = 0; i < len; ++i ) {
            if ( nums[i] > 0 )
                missing = i + 1;
        }

        return { dup, missing };
    }
};


// 方法一：蛮力法，哈希麦
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        if ( nums.empty() )
            return vector<int> { };
        
        vector<int> res(2, 0);
        vector<int> vec( nums.size()+1, 0 );

        for ( size_t i = 0; i < nums.size(); ++i ) 
            vec[ nums[i] ] += 1;
        
        for ( size_t j = 1; j < vec.size(); ++j ) {
            if ( vec[j] == 2 )
                res[0] = j;
            if ( vec[j] == 0 )
                res[1] = j;                
        }

        return res;
    }
};

int main()
{
    

    return 0;
}