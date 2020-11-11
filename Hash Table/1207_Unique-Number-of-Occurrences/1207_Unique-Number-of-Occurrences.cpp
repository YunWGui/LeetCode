/*
Title:
    1207. Unique Number of Occurrences
    1207. 独一无二的出现次数
Address: 
    https://leetcode-cn.com/problems/unique-number-of-occurrences/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 方法一：
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hashMap;
        unordered_set<int> hashSet;

        for ( int num : arr )
            ++hashMap[num];
        
        for ( auto iter : hashMap ) {
            if ( hashSet.count( iter.second ) )
            // if ( hashSet.find( iter.second ) != hashSet.end() )
                return false;
            
            hashSet.insert( iter.second );
        }

        return true;
    }
};


int main()
{
    

    return 0;
}