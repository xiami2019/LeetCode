class Solution:
    def simplifyPath(self, path: str) -> str:
        allNames = path.split('/')
        s = []
        for name in allNames:
            if name == '' or name == '.':
                continue
            if name == '..':
                if s:
                    s.pop()
                continue
            s.append(name)
        return '/' + '/'.join(s)