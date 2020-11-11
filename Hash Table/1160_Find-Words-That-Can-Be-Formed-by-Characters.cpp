/*
Title:
    1160. Find Words That Can Be Formed by Characters
    1160. 拼写单词
Address:
    https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


// 方法一：哈希表
class Solution_1 {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        vector<int> M( 26, 0 );

        for ( char ch: chars )
            ++M[ch - 'a'];
        
        for ( string& word: words ) {
            vector<int> Temp( 26, 0 );
            int i;
            for ( i = 0; i < word.size(); ++i ) 
                if ( ++Temp[word[i] - 'a'] > M[word[i] - 'a'] )
                    break;
            
            if ( i == word.size() )
                sum += word.size();            
        }

        return sum;
    }
};


// 方法二：
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        unordered_map<char, int> M, Temp;

        for ( size_t i = 0; i < chars.size(); ++i ) 
            ++M[chars[i]];
        
        for ( string word: words ) {
            int j;
            int len = word.length();
            Temp = M;
            for ( j = 0; j < len; ++j ) {
                if ( Temp.find(word[j]) != Temp.end() && Temp[word[j]] > 0 )
                    --Temp[word[j]];
                else
                    break;
            }
            if ( j == len )
                sum += len;
        }

        return sum;
    }
};

int main()
{
    

    return 0;
}