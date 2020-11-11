/*
Title:
    1002. Find Common Characters
    1002. 查找常用字符
Address: 
    https://leetcode-cn.com/problems/find-common-characters/
*/

#include <iostream>
#include <vector>
#include <algorithm>  // fill
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        const int num = 26;  // 小写英文字母的数量
        vector<int> minFreq( num, INT_MAX );  // 整个字符数组 A 中单词出现的最小频率
        vector<int> freq( num );  // 每个字符中，单词出现的最小频率

        for ( const string& word : A ) {
            fill( freq.begin(), freq.end(), 0 );

            for ( char ch : word ) 
                ++freq[ch - 'a'];
            
            for ( int i = 0; i < num; ++i ) 
                minFreq[i] = min( minFreq[i], freq[i] );
        }

        vector<string> ans;
        for ( int i = 0; i < num; ++i ) {
            for ( int j = 0; j < minFreq[i]; ++j ) {
                string str( 1, i + 'a' );
                ans.push_back( str );
            }
        }

        return ans;        
    }
};

int main()
{
    vector<string> str { "bella","label","roller" };
    Solution solve;
    vector<string> ans = solve.commonChars( str );

    for ( string& e : ans )
        cout << e << " ";
    cout << endl;
    

    return 0;
}