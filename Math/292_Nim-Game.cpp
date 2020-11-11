/*
Title:
    292. Nim Game
    292. Nim 游戏
Description:
    你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 
    拿掉最后一块石头的人就是获胜者。你作为先手。
    你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情
    况下赢得游戏。
Address: 
    https://leetcode-cn.com/problems/nim-game/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：取模
/* 思路：如果 n 能被 4 整除，则必输，其他情况必赢*/
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};


int main()
{
    

    return 0;
}