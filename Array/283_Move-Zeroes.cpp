/*
Title:
    283. Move Zeroes
    283. 移动零
Address: 
    https://leetcode-cn.com/problems/move-zeroes/
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for ( int i = 0; i < (int)nums.size(); ++i ) {
            if ( nums[i] != 0 ) {
                swap( nums[i], nums[idx++] );
            }
        }
    }
};

int main()
{
    

    return 0;
}