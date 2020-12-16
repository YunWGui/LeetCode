/*
Title:
    1686. Stone Game VI
    1686. 石子游戏 VI
Address: 
    https://leetcode-cn.com/problems/stone-game-vi/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：贪心
// https://zxi.mytechroad.com/blog/greedy/leetcode-1686-stone-game-vi/
class Solution_2 {
  public:
    int stoneGameVI(vector<int> &A, vector<int> &B) {
        const int n = A.size();
        vector<pair<int, int>> s(n);

        for (int i = 0; i < n; ++i)
            s.emplace_back(A[i] + B[i], i);
        
        sort(rbegin(s), rend(s));
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int idx = s[i].second;
            ans += (i & 1 ? B[idx] : A[idx]) * (i & 1 ? -1 : 1);
        }
        
        return ans < 0 ? -1 : (ans > 0);
    }
};


// 方法一：贪心、博弈论
// AcWing 视频：https://www.acwing.com/video/2146/
// https://www.acwing.com/activity/content/code/content/637193/
struct Data {
    int x, y, z;
    bool operator< (const Data& t) const {
        return x < t.x;
    }
}c[100010];

class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n = a.size();
        for (int i = 0; i < n; i ++ )
            c[i] = {a[i] + b[i], a[i], b[i]};
        sort(c, c + n);
        int res = 0;
        for (int i = n - 1, j = 0; j < n; i --, j ++ ) {
            if (j % 2 == 0) res += c[i].y;
            else res -= c[i].z;
        }
        if (res > 0) return 1;
        if (!res) return 0;
        return -1;
    }
};



int main()
{
    

    return 0;
}