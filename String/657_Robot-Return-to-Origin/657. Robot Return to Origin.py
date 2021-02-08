"""
 * Title:
 *     657. Robot Return to Origin
 *     657. 机器人能否返回原点
 * Address:
 *     https://leetcode-cn.com/problems/robot-return-to-origin/
"""

# 方法二：
class Solution_2:
    def judgeCircle(self, moves: str) -> bool:
        x, y = 0, 0  # 坐标原点
        
        for ch in moves:
            if ch == 'R':
                x += 1
            elif ch == 'L':
                x -= 1
            elif ch == 'U':
                y += 1
            elif ch == 'D':
                y -= 1
            
        return x == 0 and y == 0

# 方法一：
class Solution:
    def judgeCircle(self, moves: str) -> bool:
        x, y = 0, 0  # 坐标原点
        dx = [1, -1, 0, 0]
        dy = [0, 0, 1, -1]

        hashMap = {'R': 0, 'L': 1, 'U': 2, 'D': 3 };

        for ch in moves:
            x += dx[hashMap[ch]]
            y += dy[hashMap[ch]]
        
        return x == 0 and y == 0    