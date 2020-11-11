/*
Title:
    836. Rectangle Overlap
    836. 矩形重叠
Address:
    https://leetcode-cn.com/problems/rectangle-overlap/
*/

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/rectangle-overlap/solution/ju-xing-zhong-die-by-leetcode-solution/
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !( rec1[2] <= rec2[0]  // left
               || rec1[3] <= rec2[1]  // bottom
               || rec1[0] >= rec2[2]  // right
               || rec1[1] >= rec2[3]  // top
                );
    }
};

int main()
{
    

    return 0;
}