/*
Title:
    17. Letter Combinations of a Phone Number
    17. 电话号码的字母组合
Address: 
    https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;


// 方法一：回溯法
/*
时间复杂度：O(3^m X 4^n)，其中 m 是输入中对应 3 个字母的数字个数（包括数字 2、3、
            4、5、6、8），n 是输入中对应 4 个字母的数字个数（包括数字 7、9），m+n 
            是输入数字的总个数。当输入包含 m 个对应 3 个字母的数字和 n 个对应 4个字
            母的数字时，不同的字母组合一共有 3^m X 4^n 种，需要遍历每一种字母组合。
空间复杂度：O(m+n)，其中 m 是输入中对应 3 个字母的数字个数，n 是输入中对应 4 个字母
            的数字个数，m+n 是输入数字的总个数。除了返回值以外，空间复杂度主要取决
            于哈希表以及回溯过程中的递归调用层数，哈希表的大小与输入无关，可以看成
            常数，递归调用层数最大为 m+n。
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if ( digits.empty() )
            return ans;
        
        unordered_map<char, string> phoneMap {
            { '2', "abc" },
            { '3', "def" },
            { '4', "ghi" },
            { '5', "jkl" },
            { '6', "mno" },
            { '7', "pqrs" },
            { '8', "tuv" },
            { '9', "wxyz" }
        };

        string str;

        backTrack( digits, phoneMap, 0, str, ans );

        return ans;
    }

    void backTrack( string& digits, unordered_map<char, string>& phoneMap, int idx, string& str, vector<string>& ans ) {
        if ( idx == (int)digits.size() ) {
            ans.push_back( str );
            return;
        }
        
        char digit = digits[idx];
        string& word = phoneMap[digit];

        for ( char& ch : word ) {
            str.push_back( ch );
            backTrack( digits, phoneMap, idx + 1, str, ans );
            str.pop_back();
        }
    }
};

int main()
{
    

    return 0;
}