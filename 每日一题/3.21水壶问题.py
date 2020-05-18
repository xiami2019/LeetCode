class Solution:
    def canMeasureWater(self, x: int, y: int, z: int) -> bool:
        stack = [(0, 0)]
        self.seen = set()
        while stack:
            remain_x, remain_y = stack.pop()
            if remain_x == z or remain_y == z or remain_x + remain_y == z:
                return True
            if (remain_x, remain_y) in self.seen:
                continue
            self.seen.add((remain_x, remain_y))
            # 把X壶灌满；
            stack.append((x, remain_y))
            # 把Y壶灌满;
            stack.append((remain_x, y))
            # 把X壶倒空；
            stack.append((0, remain_y))
            # 把Y壶倒空；
            stack.append((remain_x, 0))
            # 把X壶的水灌进Y壶，直至灌满或倒空；
            stack.append((remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y)))
            # 把Y壶的水倒进X壶，直至灌满或倒空；
            stack.append((remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x)))
        return False