/*
Title;
    26. Remove Duplicates from Sorted Array
    26. 删除排序数组的重复项
Address:
    https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        
        if(nums.empty())
            return 0;
            
        for(size_t i = 0; i < nums.size(); i++){
            if(nums[i] != nums[k])
                nums[++k] = nums[i];
        }

        return ++k;
    }
};

// 方法二：借鉴 InsertionSort
class Solution_2 {
public:
    int removeDuplicates(vector<int>& nums){
        int i = 0, j = 1;
        int len = nums.size();
        
        if(0 == len)
            return 0;

        while(j < len){
            if(nums[i] == nums[j])
                j++;
            else
                nums[++i] = nums[j++];
        }
        return ++i;
    }
};

// 方法三：双指针
class Solution_3 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if ( n == 0 || n == 1 )
            return n;
        
        int left = 0, right = 1;

        while ( right < n ) {
            while ( right < n && nums[left] == nums[right] )
                ++right;
            
            if ( right >= n )
                break;
            
            nums[++left] = nums[right];
            ++right;
        }

        nums.resize( left + 1 );

        return left + 1;
    }
};

int main()
{
    vector<int> arr {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    Solution solve;
    cout << solve.removeDuplicates(arr) << endl;

    

    return 0;
}
