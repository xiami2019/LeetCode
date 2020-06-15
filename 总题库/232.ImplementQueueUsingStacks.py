class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.popStack = []
        self.pushStack = []


    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.pushStack.append(x)


    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not self.popStack:
            while not self.pushStack:
                self.popStack.append(self.pushStack[-1])
                self.pushStack.pop()
        top = self.popStack[0]
        self.popStack.pop(0)
        return top


    def peek(self) -> int:
        """
        Get the front element.
        """
        if not self.popStack:
            while not self.pushStack:
                self.popStack.append(self.pushStack[-1])
                self.pushStack.pop()
        top = self.popStack[0]
        return top


    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return self.popStack or self.popStack



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()