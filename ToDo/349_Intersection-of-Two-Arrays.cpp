/*
Title:
    349. Intersection of Two Arrays
    349. 两个数组的交集
Description:
    给定两个数组，编写一个函数来计算它们的交集
Address: 
    https://leetcode-cn.com/problems/intersection-of-two-arrays/
*/


#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> arr1( nums1.begin(), nums1.end() );
        unordered_set<int> arr2( nums2.begin(), nums2.end() );

        vector<int> ans;

        for ( auto iter = arr1.begin(); iter != arr1.end(); ++iter ) {
            if ( arr2.find( *iter ) != arr2.end() ) 
                ans.push_back( *iter );
        }

        return ans;
    }
};

int main()
{
    

    return 0;
}