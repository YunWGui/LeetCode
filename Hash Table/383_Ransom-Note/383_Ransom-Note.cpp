/******************************************************************************
 * Title:
 *     383. Ransom Note
 *     383. 赎金信
 * Address:
 *     https://leetcode-cn.com/problems/ransom-note/
******************************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>  // 即：string.h，引入 memset
using namespace std;

// 方法二：哈希表
class Solution_2 {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26];
        memset( record, 0, sizeof(record) );

        for ( char& ch : magazine )
            ++record[ch - 'a'];
        
        for ( char& ch : ransomNote ) {
            --record[ch - 'a'];
            if ( record[ch - 'a'] < 0 )
                return false;
        }

        return true;
    }
};

// 方法一：哈希表
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if ( ransomNote.empty() )
            return true;
        else if ( magazine.empty() )  // 此时 ransomNote 非空
            return false;
        
        unordered_map<char, int> hashMap;
        for ( char ch : magazine ) 
            ++hashMap[ch];
        
        for ( char ch : ransomNote ) {
            if ( hashMap[ch] != 0 )
                --hashMap[ch];
            else 
                return false;
        }

        return true;
    }
};


int main()
{
    

    return 0;
}