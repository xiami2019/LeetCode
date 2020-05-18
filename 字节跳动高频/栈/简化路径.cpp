class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        path = path.split('/')

        for item in path:
            if item == '..':
                