/**
 * Title:
 *     290. Word Pattern
 *     290. 单词规律
 * Address: 
 *     https://leetcode-cn.com/problems/word-pattern/
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>  // istringstream
#include <unordered_map>
using namespace std;

/**
 * C++ 拆分字符串为单词的五种方法
 * https://blog.csdn.net/baidu_38492549/article/details/111405543
 */

// 方法一：
class Solution {
public:
    bool wordPattern(string pattern, string s) {        
        // 将字符串拆分为单词
        istringstream input( s );
        vector<string> vec;
        string temp;
        while ( input >> temp )
            vec.push_back( temp );
        
        if ( pattern.size() != vec.size() )
            return false;
        
        unordered_map<char,string> hash;

        for ( int i = 0; i < (int)pattern.size(); ++i ) {
            if ( hash.count( pattern[i] ) == 1 ) {  // 当 hash 中存在对应的 key
                if ( hash[pattern[i]] != vec[i] )
                    return false;
            }
            else {  // hash 中不存在对应的 key
                for ( auto iter : hash )  // 遍历 hash，判断是否有 value == vec[i]
                    if ( iter.second == vec[i] )
                        return false;
                hash[pattern[i]] = vec[i];
            }    
        }

        return true;
    }
};

int main()
{
    

    return 0;
}