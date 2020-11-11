/*
Title:
    260. Single Number III
    260. 只出现一次的数字 III
Description:
    给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
    找出只出现一次的那两个元素。
Address: 
    https://leetcode-cn.com/problems/single-number-iii/
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// 方法一：哈希表
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;
        vector<int> res;

        if ( nums.size()  < 2 )
            return res;

        for ( int num : nums )
            ++M[num];

        for ( auto iter = M.begin(); iter != M.end(); ++iter )
            if ( iter->second == 1 )
                res.emplace_back( iter->first );
        
        return res;
    }
};


int main()
{
    

    return 0;
}