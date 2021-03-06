/*
Title:
    994. Rotting Oranges
    994. 腐烂的橘子
Address:
    https://leetcode-cn.com/problems/rotting-oranges/ 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法一：广度优先搜索
class Solution {
public:
    int orangesRotting (vector<vector<int> >& grid) {
        int dirs[4][2] = { { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int> > Q;
        int count = 0;
        int time = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    count++;
                else if (grid[i][j] == 2)
                    Q.push({ i, j });
            }
        if (count == 0)
            return 0;

        while (!Q.empty()) {
            time++;
            for (int j = Q.size(); j > 0; j--) {
                auto cur = Q.front();
                Q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = cur.first + dirs[k][0];
                    int y = cur.second + dirs[k][1];
                    if (x < 0 || x > rows - 1 || y < 0 || y > cols - 1 || grid[x][y] == 0)
                        continue;
                    if (grid[x][y] == 1) {
                        count--;
                        grid[x][y] = 2;
                        Q.push({ x, y });
                    }
                }
                if (count == 0)
                    return time;
            }
        }

        return -1;
    }
};

int main()
{


    return 0;
}
