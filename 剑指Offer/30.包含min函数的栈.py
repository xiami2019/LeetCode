class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s = []
        self.minValues = []

    def push(self, x: int) -> None:
        self.s.append(x)
        if len(self.minValues) == 0 or x < self.minValues[len(self.minValues) - 1]:
            self.minValues.append(x)
        else:
            self.minValues.append(self.minValues[len(self.minValues) - 1])

    def pop(self) -> None:
        self.s.pop()
        self.minValues.pop()

    def top(self) -> int:
        return self.s[len(self.s) - 1]

    def min(self) -> int:
        return self.minValues[len(self.minValues) - 1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.min()