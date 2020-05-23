class CQueue:

    def __init__(self):
        self.s1 = []
        self.s2 = []

    def appendTail(self, value: int) -> None:
        self.s1.append(value)

    def deleteHead(self) -> int:
        if len(self.s2) != 0:
            temp = self.s2[len(self.s2) - 1]
            self.s2.pop()
            return temp
        else:
            if len(self.s1) == 0:
                return -1
            while len(self.s1) != 0:
                self.s2.append(self.s1[len(self.s1) - 1])
                self.s1.pop()
        temp = self.s2[len(self.s2) - 1]
        self.s2.pop()
        return temp

# Your CQueue object will be instantiated and called as such:
# obj = CQueue()
# obj.appendTail(value)
# param_2 = obj.deleteHead()