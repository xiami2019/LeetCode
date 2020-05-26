class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        if len(pushed) == 0 and len(popped) == 0:
            return True
        if len(pushed) == 0 or len(popped) == 0:
            return False

        s = []
        index = 0
        for item in pushed:
            s.append(item)
            while len(s) > 0 and s[-1] == popped[index]:
                s.pop()
                index += 1
        
        return index == len(popped)