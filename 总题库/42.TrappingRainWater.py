class Solution:
    def trap(self, height: List[int]) -> int:
        walls = []
        totalRain = 0
        tempRain = 0
        walls.append(0)
        for i in range(1, len(height)):
            if height[i] >= height[walls[-1]]:
                totalRain += tempRain
                tempRain = 0
                walls.pop()
                walls.append(i)
            else:
                tempRain += height[walls[-1]] - height[i]

        walls = [len(height) - 1]
        tempRain = 0
        for i in range(len(height) - 2, -1, -1):
            if height[i] > height[walls[-1]]:
                totalRain += tempRain
                tempRain = 0
                walls.pop()
                walls.append(i)
            else:
                tempRain += height[walls[-1]] - height[i]
        return totalRain
