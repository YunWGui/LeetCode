/*
Title:
    692. Top K Frequent Words
    692. 前K个高频单词
Address: 
    https://leetcode-cn.com/problems/top-k-frequent-words/
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 方法一：哈希表
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> hashMap;
        
        if ( words.empty() )
            return {};
        
        for ( string str : words )
            ++hashMap[str];
        
        vector<pair<string, int>> vec;

        for ( auto iter : hashMap )
            vec.push_back( iter );
        
        sort( vec.begin(), vec.end(), cmp );

        vector<string> ans;

        for ( int i = 0; i < k; ++i ) 
            ans.push_back( vec[i].first );

        return ans;
    }

    static bool cmp( pair<string, int>& a, pair<string, int>& b ) {
        if ( a.second > b.second )
            return true;
        else if ( a.second == b.second )
            return a.first < b.first;
        else
            return false;
    }
};


// 方法二：哈希表
class Solution_2 {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> M;

        for ( string& str : words ) 
            ++M[str];
        
        multimap<int, string, greater<int>> multiM;

        for ( auto& iter : M )
            multiM.insert( make_pair( iter.second, iter.first ) );

        vector<string> res;

        for ( auto& iter : multiM ) {
            if ( (int)res.size() < k )
                res.push_back( iter.second );
            else
                break;
        }

        return res;
    }
};

int main()
{
    

    return 0;
}