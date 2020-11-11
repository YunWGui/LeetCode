/*
Title:
    486. Predict the Winner
    486. 预测赢家
Address: 
    https://leetcode-cn.com/problems/predict-the-winner/
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法二：动态规划
// https://leetcode-cn.com/problems/predict-the-winner/solution/yu-ce-ying-jia-by-leetcode-solution/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp( n );

        for (int i = 0; i < n; i++) 
            dp[i] = nums[i];
        
        for (int i = n - 2; i >= 0; i--) 
            for (int j = i + 1; j < n; j++) 
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        
        return dp[n - 1] >= 0;
    }
};



int main()
{
    

    return 0;
}