'''
正则表达式匹配：
方法1：回溯
想法：如果没有星号（正则表达式中的*），问题会很简单——我们只需要从左到右检查匹配串s是否能匹配模式串p的每一个字符
当模式串中有星号时，我们需要检查匹配串s中的不同后缀，以判断它们是否能匹配模式串剩余的部分。一个直观的解法就是用
回溯的方法来体现这种关系。
算法：如果没有星号，我们的代码会像这样：
'''
def match(text, pattern):
    if not pattern: 
        return not text
    first_match = bool(text) and pattern[0] in {text[0], '.'}
    return first_match and match(text[1:], pattern[1:])
'''
如果模式串中有星号，它会出现在第二个位置，即pattern[1]. 这种情况下，我们可以直接忽略模式串中这一部分，或者删除匹配串
第一个字符，前提是它能够匹配模式串当前位置字符，即pattern[0]。如果两种操作中有任何一种使得剩下的字符串能匹配，那么初
始时，匹配串和模式串就可以被匹配。
'''
def isMatch(self, text, pattern):
    if not pattern:
        return not text
    
    first_match = bool(text) and pattern[0] in {text[0], '.'}

    if len(pattern) >= 2 and pattern[1] == '*': #使用或逻辑完成了回溯的操作;
        return self.isMatch(text, pattern[2:]) or 
        first_match and self.isMatch(text[1:], pattern)
    else:
        return first_match and self.isMatch(text[1:], pattern[1:])

'''
方法二：动态规划
想法：因为题目拥有最优子结构，一个自然的想法是将中间结果保存起来。我们可以通过用dp[i,j]表示pattern[i:]和pattern[j:]是否能匹配。
我们可以用更短的字符串匹配问题来表示原本的问题
算法：我们用[方法1]中同样的回溯方法，除此之外，因为函数match(text[i:], pattern[j:])只会被调用一次，我们用dp[i,j]来应对剩余相同
参数的函数调用，这帮助我们节省了字符串建立操作所需要的时间，也让我们可以将中间结果进行保存。
'''
#自顶向下的方法：使用递归的方法；
def isMatch(self, text, pattern):
    memo = {}
    def dp(i, j):
        if (i, j) not in memo:
            if j == len(pattern):
                ans = i == len(text)
            else:
                first_match = i < len(text) and pattern[j] in {text[i], '.'}
                if j + 1 < len(pattern) and pattern[j+1] == '*':
                    ans = dp(i, j+2) or first_match and dp(i+1, j)
                else:
                    ans = first_match and dp(i+1, j+1)
            memo[i, j] = ans
        return memo[i,j]
    return dp(0, 0)

#自底向上的方法：不用递归的方法；
def isMatch(self, text, pattern):
    dp = [[False] * (len(pattern) + 1) for _ in range(len(text) + 1)]

    dp[-1][-1] = True
    for i in range(len(text), -1, -1):
        for j in range(len(pattern) - 1, -1, -1):
            first_match = i < len(text) and pattern[j] in {text[i], '.'}
            if j+1 < len(pattern) and pattern[j+1] == '*':
                dp[i][j] = dp[i][j+2] or first_match and dp[i+1][j]
            else:
                dp[i][j] = first_match and dp[i+1][j+1]
    return dp[0][0]

#自顶向下因为子问题还没有处理，所以通常要是用递归的方法；
#自底向上优先开始处理子问题，所以不用使用递归；