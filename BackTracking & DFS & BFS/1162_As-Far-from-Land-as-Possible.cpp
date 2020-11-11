/*
Title:
    1162. As Far from Land as Possible
    1162. 地图分析
Address:
    https://leetcode-cn.com/problems/as-far-from-land-as-possible/
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 方法二：BFS + queue
/*
思路：
    1. 通过遍历，找到所有陆地
    2. 判断是否是「全陆地」或「全海洋」
    3. 使用 BFS
    4. 直接修改原数组
*/
class Solution_2 {
public:    
    int maxDistance(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> Q;

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(grid[i][j] == 1)  //所有陆地入队列
                    Q.push(make_pair(i,j));

        if(Q.size() == 0 || Q.size() == rows*cols)  //全陆地、全海洋
            return -1;

        int ans = -1;
        vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};  //四个方向
        while(!Q.empty()){
            int size = Q.size();
            ans++;
            for(int i = 0; i < size; i++){
                int x = Q.front().first;
                int y = Q.front().second;
                Q.pop();
                for(int j = 0; j < 4; j++){
                    int dx = x + dirs[j][0];
                    int dy = y + dirs[j][1];
                    if(dx >= 0 && dx < rows && dy >= 0 && dy < cols && grid[dx][dy] == 0){
                        grid[dx][dy] = 1;  //标记为陆地，表示vsited，省内存
                        Q.push(make_pair(dx, dy));
                    }
                }
            }
        }
        
        return ans;
    }
};


// 方法一：广度优先搜索
// https://leetcode-cn.com/problems/as-far-from-land-as-possible/solution/lu-di-bu-duan-chang-da-zhi-dao-fu-gai-zheng-ge-di-/
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows, cols;
        rows = cols = grid.size();
        
        int landNums = 0;  // 「陆地」区域的个数
        int seaNums = 0;  // 标记「海洋」区域的个数
        int count_turn = 0;  // 标记距离「陆地」地域最远的「海洋」区域
        
        for ( int i = 0; i < rows; ++i ) 
            for ( int j = 0; j < cols; ++j ) 
                if ( grid[i][j] == 1 )
                    ++landNums;
                
        seaNums = rows * cols - landNums;
        if ( landNums == 0 || seaNums == 0 )  // 如果地图上只有陆地(seaNums = 0)或只有海洋(landNums = 0)
            return -1;  // 则，返回 -1

        while ( seaNums != 0 ) {
            ++count_turn;
            for ( int i = 0; i < rows; ++i ) {
                for ( int j = 0; j < cols; ++j ) {
                    if ( grid[i][j] == count_turn ) {
                        if ( i > 0 && grid[i-1][j] == 0 ) {  // 上
                            grid[i-1][j] = count_turn + 1;
                            --seaNums;
                        }                        
                        if ( i < rows - 1 && grid[i+1][j] == 0 ) {  // 下
                            grid[i+1][j] = count_turn + 1;
                            --seaNums;
                        }
                        if ( j > 0 && grid[i][j-1] == 0 ) {  // 左
                            grid[i][j-1] = count_turn + 1;
                            --seaNums;
                        }
                        if ( j < cols - 1 && grid[i][j+1] == 0 ) {  // 右
                            grid[i][j+1] = count_turn + 1;
                            --seaNums;
                        }
                    }
                }
            }
        }
        
        return count_turn;       
    }
};


int main()
{
    

    return 0;
}