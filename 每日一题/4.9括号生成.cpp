/*
暴力法：生成由“(”和“)”字符构成的全部序列，然后检查每一个是否有效即可。
为了生成所有序列，我们可以使用递归。长度为n的序列就是在长度为n-1的序列前加一个“（”或“）”。
*/
class Solution {
    // 用来检查一个排列是否符合要求
    bool valid (const string & str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            }
            else {
                --balance;
                if (balance < 0) {
                    return false;
                }
            }
        }
        return balance == 0;
    }

    // 用来生成所有排列，使用回溯法
    void generateAll (string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generateAll(current, n, result);
        current.pop_back();
        current += ')';
        generateAll(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generateAll(current, n*2, result);
        return result;
    }
};

/*
方法二：回溯法
对于方法一：我们可以只在序列仍然保持有效时才添加“（”和“）”，而不是像方法一一样每次都添加，
可以通过跟踪到目前为止放置的左括号和右括号的数目来做到这一点。
如果左括号数量不大于n，可以放一个左括号。如果右括号数量小于左括号的数量，可以放一个右括号。
*/
class Solution {
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        // open标记左括号的个数，close标记右括号的个数
        if (cur.size() == n*2) { // cur已经是一个符合要求的排列
            ans.push_back(cur);
            return;
        }
        
        if (open < n) { // open标记左括号的个数，如果左括号的个数小于n，可以添加一个左括号
            cur.push_back('(');
            backtrack(ans, cur, open+1, close, n);
            cur.pop_back();
        }
        
        if (close < open) { // 如果右括号的个数小于左括号的个数，则可以添加右括号
            cur.push_back(')');
            backtrack(ans, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
};

/*
方法三：按括号序列的长度递归
任何一个括号序列都一定是由（开头，并且第一个（一定有一个唯一与之对应的）。这样一来，每一个括号序列可以用（a）b来表示，
其中a与b分别是一个合法的括号序列（可以为空）。

那么，要生成所有长度为2*n的括号序列，我们定义一个函数generate(n)来返回所有可能的括号序列。那么在函数generate(n)的过程中：
1. 我们需要枚举与第一个（对应的）的位置：2*i+1；
2. 递归调用generate(i)即可计算a的所有可能性；
3. 递归调用generate(n - i - 1)即可计算b的所有可能性；
4. 遍历a与b的所有可能性并拼接，即可得到所有长度为2*n的括号序列。
为了节省计算时间，我们在每次generate(i)函数返回之前，把返回值存储起来，下次再调用generate(i)时可以直接返回，不需要再递归计算；

*/
class Solution {
    // sharedPtr是智能指针
    shared_ptr<vector<string> > cache[100] = {NULL};
public:
    shared_ptr<vector<string> > generate(int n) {
        if (cache[n] != NULL) { // 已经保存有缓存的情况
            return cache[n];
        }
        if (n == 0) {
            cache[0] = shared_ptr<vector<string> >(new vector<string>{""});
        }
        else {
            auto result = shared_ptr<vector<string> >(new vector<string>);
            for (int i = 0; i != n; i++) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts) {
                    for (const string& right : *rights) {
                        result->push_back("(" + left + ")" + right);
                    }
                }
            }
            cache[n] = result;
        }
        return cache[n];
    }

    vector<string> generateParenthesis(int n) {
        return *generate(n);
    }
};