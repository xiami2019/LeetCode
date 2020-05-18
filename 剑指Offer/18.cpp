//回溯法
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        if (p.size() == 0){
            if (s.size() == 0) return true;
            else return false;
        }

        bool first_match = false;
        if (s.size() != 0 && (p[0] == s[0] || p[0] == '.')){
            first_match = true;
        }
        if (p.size() >= 2 && p[1] == '*'){
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        }
        else{
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

// 方法二：动态规划
// 想法：因为题目拥有最优子结构，一个自然的想法是将中间结果保存起来。我们可以通过用dp[i,j]表示pattern[i:]和pattern[j:]是否能匹配。
// 我们可以用更短的字符串匹配问题来表示原本的问题
// 算法：我们用[方法1]中同样的回溯方法，除此之外，因为函数match(text[i:], pattern[j:])只会被调用一次，我们用dp[i,j]来应对剩余相同
// 参数的函数调用，这帮助我们节省了字符串建立操作所需要的时间，也让我们可以将中间结果进行保存。

//动态规划法：
//自顶向下（递归）
int memo[10000][10000];
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        for (int i = 0; i < s.size() + 1; i++){
            for (int j = 0; j < p.size() + 1; j++){
                memo[i][j] = -1;
            }
        }
        int result = dp(0, 0, s, p);
        if (result == 1) return true;
        return false;
    }

    int dp(int i, int j, string s, string p)
    {
        int ans = 0;
        if (memo[i][j] == -1){
            if (j == p.size()){
                ans = i == s.size() ? 1 : 0;
            }
            else{
                bool first_match = false;
                if (i < s.size() && (p[j] == s[i] || p[j] == '.')){
                    first_match = true;
                }
                if (j + 1 < p.size() && p[j + 1] == '*'){
                    ans = (dp(i, j+2, s, p) || (first_match && dp(i + 1, j, s, p))) ? 1 : 0;
                }
                else{
                    ans = first_match && dp(i + 1, j + 1, s, p)? 1 : 0;
                }
            }
            memo[i][j] = ans;
        }
        return memo[i][j];
    }
};

//动态规划法：
//自底向上：
class Solution {
public:
    bool isMatch(string s, string p) 
    {
        bool dp[s.size() + 1][p.size() + 1];
        for (int i = 0; i < s.size() + 1; i++){
            for (int j = 0; j < p.size() + 1; j++){
                dp[i][j] = false;
            }
        }
        dp[s.size()][p.size()] = true;
        for (int i = s.size(); i > -1; i--){
            for (int j = p.size() - 1; j > -1; j--){
                bool first_match = (i < s.size() && (p[j] == s[i] || p[j] == '.'));
                if (j + 1 < p.size() && p[j + 1] == '*'){
                    dp[i][j] = dp[i][j + 2] || (first_match && dp[i+1][j]);
                } 
                else{
                    dp[i][j] = first_match && dp[i + 1][j + 1];
                    break;
                }
            }
        }
        return dp[0][0];
    }
};
