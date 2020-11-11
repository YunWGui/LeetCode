/**
 * Title:
 *      542. 01 Matrix
 *      542. 01 矩阵
 * Description:
 *      给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 *      两个相邻元素间的距离为 1 。
 * Address:
 *      https://leetcode-cn.com/problems/01-matrix/
 */


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法一：广度优先搜索
class Solution {
  public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<pair<int, int>> around = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // 运动范围
        vector<vector<int>> res(rows, vector<int>(cols, INT_MAX));
        queue<pair<int, int>> Q;
        
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    res[row][col] = 0;
                    Q.push({row, col});
                }
            }
        }
        // 广度优先搜索
        while (!Q.empty()) {
            auto temp = Q.front();
            Q.pop();
            for (int row = 0; row < 4; row++) {
                int x = temp.first + around[row].first;
                int y = temp.second + around[row].second;
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    if (res[x][y] > res[temp.first][temp.second] + 1) {
                        res[x][y] = res[temp.first][temp.second] + 1;
                        Q.push({x, y});
                    }
                }
            }
        }
        return res;
    }
};


int main()
{
    

    return 0;
}