/******************************************************************************
 * Title:
 *     49. Group Anagrams
 *     49. 字母异位词分组
 * Address:
 *     https://leetcode-cn.com/problems/group-anagrams/
******************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 方法一：排序
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> record;
        string key = "";

        for ( const string& str : strs ) {
            key = str;
            sort( key.begin(), key.end() );
            record[key].push_back( str );
        }

        vector<vector<string>> ans;
        for ( auto iter : record )
            ans.push_back( iter.second );
        
        return ans;
    }
};

int main()
{
    

    return 0;
}