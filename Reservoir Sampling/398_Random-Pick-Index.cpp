/*
Title:
    398. Random Pick Index
    398. 随机数索引
Address:
    https://leetcode-cn.com/problems/random-pick-index/
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_map>
using namespace std;

// 方法一：
class Solution {
public:
    unordered_map<int, vector<int>> hash;
    Solution(vector<int> &nums) { // 构造函数
        for (int i = 0; i < nums.size(); i++) {
            hash[nums[i]].push_back(i);
        }
    }

    int pick(int target) { 
        return hash[target][rand() % hash[target].size()]; 
    }
};


// 方法二：
// https://leetcode-cn.com/problems/random-pick-index/solution/xu-shui-chi-chou-yang-wen-ti-by-an-xin-9/
class Solution_2 {
private:
    vector<int> *pvec; // 指针，可使用「this 指针」代替
public:
    Solution_2(vector<int> &nums) { 
        pvec = &nums; 
    }

    int pick(int target) {
        int count = 0;
        int res = 0;
        for (int i = 0; i < (*pvec).size(); ++i) {
            if ((*pvec)[i] == target) {
                ++count;
                if (rand() % count == count - 1)
                    res = i;
            }
        }
        return res;
    }
};


int main() 
{ 
    return 0; 
}