/*
Title:
    15. 3Sum
    15. 三数之和
Address:
    https://leetcode-cn.com/problems/3sum/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printMatrix(vector<vector<int> > &matrix){
    for(int i=0; i<matrix.size(); i++){
        printf("{");
        for(int j=0; j< matrix[i].size(); j++) {
            printf("%3d ", matrix[i][j]) ;
        }
        printf("}\n");
    }
    cout << endl;
}

// 方法一：排序 + 双指针
/*
    时间复杂度：O( n^2 )
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        sort( nums.begin(), nums.end() );

        if ( nums.size() < 3 || nums.front() > 0 || nums.back() < 0 )
            return res;
        
        int len = nums.size();
        for ( int i = 0; i < len - 2; ++i ) {
            if ( 0 < i && nums[i] == nums[i - 1] )  // 跳过重复值
                continue;
            
            int left = i + 1, right = len - 1;
            while ( left < right ) {
                int sum = nums[i] + nums[left] + nums[right];

                if ( sum < 0 )
                    ++left;
                else if ( sum > 0 )
                    --right;
                else {  // sum == 0 
                    res.push_back( { nums[i], nums[left], nums[right] } );

                    while ( left < right && nums[left] == nums[left + 1] )  // 跳到「最后一个」重复值
                        ++left;
                    while ( left < right && nums[right] == nums[right - 1] )  // 跳到「最前一个」重复值
                        --right;
                    
                    ++left; --right;  // 跳到没有重复值的地方
                }
            }
        }

        return res;
    }
};

int main()
{
    // vector<int> nums1 {-1, 0, 1, 2, -1, -4};
    // vector<int> nums1 {-2, 0, 1, 1, 2};
    vector<int> nums1 {0, 0, 0};
    Solution solve;
    vector<vector<int>> result;

    result = solve.threeSum(nums1);

    printMatrix(result);


    // print(nums);


    return 0;
}
