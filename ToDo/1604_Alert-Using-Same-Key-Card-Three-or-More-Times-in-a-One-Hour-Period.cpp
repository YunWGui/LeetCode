/*
Title:
    1604. Alert Using Same Key-Card Three or More Times in a One Hour Period
    1604. 警告一小时内使用相同员工卡大于等于三次的人
Address: 
    https://leetcode-cn.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 方法一：哈希表
// https://zxi.mytechroad.com/blog/hashtable/leetcode-1604-alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/
/* 时间复杂度：O( nlogn ), 空间复杂度：O( n ) */
class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> res;

        if ( keyName.empty() || keyTime.empty() ) 
            return res;
        
        unordered_map<string, vector<int>> UM;
        for ( size_t i = 0; i < keyTime.size(); ++i ) {
            const int hour = stoi( keyTime[i].substr(0, 2) );
            const int minute = stoi( keyTime[i].substr( 3 ) );
            
            UM[keyName[i]].push_back( hour * 60 + minute );
        }

        for ( auto& [name, times] : UM ) {
            sort( times.begin(), times.end() );

            for ( size_t i = 2; i < times.size(); ++i ) {
                if ( times[i] - times[i - 2] <= 60 ) {
                    res.push_back( name );
                    break;
                }
            }
        }

        sort( res.begin(), res.end() );

        return res;
    }
};

int main()
{
    

    return 0;
}