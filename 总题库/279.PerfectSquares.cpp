// 贪心枚举（从小到大枚举组成的个数）
class Solution {
    vector<int> squareNums;
public:
    bool isDividedBy(int n, int count) {
        if (count == 1) {
            auto it = find(squareNums.begin(), squareNums.end(), n);
            return !(it == squareNums.end());
        }
        for (int square : squareNums) {
            if (square > n) break;
            if (isDividedBy(n - square, count - 1)) {
                return true;
            }
        }
        return false;
    }

    int numSquares(int n) {
        for (int i = 1; i <= sqrt(n); ++i) {
            squareNums.push_back(i * i);
        }
        for (int i = 1; i <= n; ++i) {
            if (isDividedBy(n, i)) return i;
        }
        return n;
    }
};

// 贪心加BFS
class Solution {
    vector<int> squareNums;
public:
    int numSquares(int n) {
        for (int i = 1; i <= sqrt(n); ++i) {
            squareNums.push_back(i * i);
        }
        queue<int> q;
        q.push(n);
        int level = 0;

        while (q.size()) {
            level += 1;
            queue<int> nextQueue;
            set<int> helper; // reduce the redundancy
            while (q.size()) {
                remainder = q.front();
                q.pop()
                for (int square : squareNums) {
                    if (remainder == square) return level; // find the node
                    if (remainder < square) break;
                    nextQueue.push(remainder - square);
                }
            }
            q = nextQueue;
            nextQueue.clear();
        }

        return level;
    }
};

// 换一种层序遍历方法再试一遍