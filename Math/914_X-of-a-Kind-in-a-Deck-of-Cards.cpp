/*
Title:
    914. X of a Kind in a Deck of Cards
    914. 卡牌分组
Address:
    https://leetcode-cn.com/problems/x-of-a-kind-in-a-deck-of-cards/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法二：
class Solution_2 {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if ( deck.size() <= 1 )
            return false;
        
        unordered_map<int, int> UM;

        for ( int num : deck )
            ++UM[num];
        
        int gcd = UM[deck[0]];

        for ( auto iter = UM.begin(); iter != UM.end(); ++iter ) {
            gcd = getGCD( gcd, iter->second );

            if ( gcd < 2 )
                return false;
        }

        return true;
    }

    int getGCD( int a, int b ) {
        return a % b == 0 ? b : getGCD( b, a % b );
    }
};


// 方法一：最大公约数
class Solution {
private:
    int counts[10000];  // counts 必须在 private 域
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        
        for(int card : deck) {
            counts[card]++;
        }
        int gcd = counts[deck[0]];  // 公约数
        for(int cnt : counts) {
            if(cnt != 0) {
                gcd = getGCD(gcd, cnt);
                if(gcd < 2) {
                    return false;
                }
            }
        }
        return true;
    }

    int getGCD(int a, int b) {
        return a % b == 0 ? b : getGCD(b, a % b);
    }
};

int main()
{
    

    return 0;
}