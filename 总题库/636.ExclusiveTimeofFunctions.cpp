/*
我们可以使用栈来模拟函数的调用，即在遇到一条包含 start 的日志时，我们将对应的函数 id 入栈；在遇到一条包含 end 的日志时，
我们将对应的函数 id 出栈。在每一个时刻，栈中的所有函数均为被调用的函数，而栈顶的函数为正在执行的函数。

在每条日志的时间戳后，栈顶的函数会独占执行，直到下一条日志的时间戳，因此我们可以根据相邻两条日志的时间戳差值，来计算函数的
独占时间。我们依次遍历所有的日志，对于第 i 条日志，如果它包含 start，那么栈顶函数从其时间戳 time[i] 开始运行，
即 prev = time[i]；如果它包含 end，那么栈顶函数从其时间戳 time[i] 的下一个时间开始运行，即 prev = time[i] + 1。
对于第 i + 1 条日志，如果它包含 start，那么在时间戳 time[i + 1] 时，有新的函数被调用，因此原来的栈顶函数的独占时间
为 time[i + 1] - prev；如果它包含 end，那么在时间戳 time[i + 1] 时，原来的栈顶函数执行结束，
独占时间为 time[i + 1] - prev + 1。在这之后，我们更新 prev 并遍历第 i + 2 条日志。
在遍历结束后，我们就可以得到所有函数的独占时间。

*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n); // save the results;
        int preTimeStamp = 0; // previous time stamp;
        stack<int> s; // save all started threads, the thread on the top of the stack ocuppy the CPU now.
        for (int i = 0; i < logs.size(); ++i) {
            // process every logs, split the string, and get the id, time stamp, and the action.
            size_t pos1 = logs[i].find_first_of(':');
            size_t pos2 = logs[i].find_last_of(':');
            int id = stoi(logs[i].substr(0, pos1));
            int timeStamp = stoi(logs[i].substr(pos2 + 1, logs[i].size() - 1 - pos2));
            string action = logs[i].substr(pos1 + 1, pos2 - pos1 - 1);

            // when starts a thread, put its id into the stack and calculate run time of the current thread.
            if (action == "start") {
                if(!s.empty()) {
                    res[s.top()] += timeStamp - preTimeStamp;
                }
                preTimeStamp = timeStamp;
                s.push(id);
            }
            else {
                // when ends a thread, pop it from the stack and calculate run time of the current thread.
                res[s.top()] += timeStamp - preTimeStamp + 1;
                s.pop();
                preTimeStamp = timeStamp + 1;
            }
        }

        return res;
    }
};