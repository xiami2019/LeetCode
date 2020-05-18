class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path = path.split('/')

        for item in path:
            if item == '..':
                if stack:
                    # Python中的list可以模拟栈操作
                    stack.pop()
            elif item and item != '.':
                stack.append(item)
        return '/' + '/'.join(stack)