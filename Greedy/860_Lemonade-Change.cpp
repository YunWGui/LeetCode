/*
Title:
    860. Lemonade Change
    860. 柠檬水找零
Address: 
    https://leetcode-cn.com/problems/lemonade-change/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if ( bills.empty() )
            return true;

        int five = 0, ten = 0;

        for ( int num : bills ) {
            if ( num == 5 )
                ++five;
            else if ( num == 10 )
                if ( five != 0 ) {
                    --five;
                    ++ten;
                }                   
                else 
                    return false;
            else {  // num == 20
                if ( ten == 0 ) {
                    if ( five >= 3 ) {
                        five -= 3;
                    }
                    else
                        return false;
                }
                else {  // ten != 0
                    if ( five >= 1 ) {
                        --ten;
                        --five;
                    }
                    else 
                        return false;
                }
            }
        }

        return true;
    }
};

int main()
{
    

    return 0;
}