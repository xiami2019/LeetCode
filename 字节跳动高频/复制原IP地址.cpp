/*
对IP合法性要求：
1. ip格式每个部分占8位，最大不超过255；
2. 每段位数在1-3之间（在取前面段的时候要判断剩余位数是否能满足后面）；
3. 一共4段代表树最多有四层；
4. 当每段长度>1时，第一位不能是'0'；
*/
class Solution {
    vector<string> ans;
    int n;
    // 分层DFS
    void dfs(int start, int depth, string path, string s) {
        /*
        start: 当前开始位置；
        depth: 当前选出了几个段；
        path：传递的路径（一般字符串问题都将路径作为传递，可以解决回溯弹出问题）；
        s：待分割的字符串；
        */
       if (depth == 4) {
           path.pop_back(); // 除去传递参数时最后一次多加的'.'
           ans.emplace_back(path);
           return;
       }

       // endMin表示最短可以在哪里结束，endMax表示最长可以在哪里结束
       // 3 - depth表示剩余的IP段个数。（eg.当depth=0，现在正在处理第一段，还剩三段）
       // n - (3 - depth) * 3表示剩余的ip段如果都是3位数，当前ip段的结束位置（取不到）
       // start + 1也是因为取不到
       int endMin = max(start + 1, n - (3 - depth) * 3);
       int endMax = min(start + 3, n - (3 - depth));

       for (int end = endMin; end <= endMax; end++) {
           string split = s.substr(start, end - start); // end - start 表示截取长度
           int splitLen = split.size();
           if (splitLen > 1 && split[0] == '0') {
               break;
           }
           if (stoi(split) <= 255) {
               dfs(end, depth+1, path + (split + '.'), s);
           }
       }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        this->n = s.size();
        this->dfs(0, 0, "", s);
        return ans;
    }
};