/*
Title:
    470. Implement Rand10() Using Rand7()
    470. 用 Rand7() 实现 Rand10()
Address:
    https://leetcode-cn.com/problems/implement-rand10-using-rand7/
*/

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int rand7() {
        return 1 + rand() % 7;
    }

    int rand10() {
        int num = 0;
        do {
            num = ( rand7() - 1 ) * 7 + rand7() - 1;
        } while ( num >= 40 );

        return 1 + num % 10;
    }
};

int main()
{


    return 0;
}
