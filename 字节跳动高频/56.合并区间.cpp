class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int numbers[10000] = {0};
        int intervalsLen = intervals.size();
        vector<vector<int> > ans;
        if (intervalsLen == 0) return ans;

        for (int i = 0; i < intervalsLen; i++) {
            if (intervals[i][0] == intervals[i][1] && numbers[intervals[i][1]] == 0) {
                numbers[intervals[i][1]] = -1;
                continue;
            }
            for (int j = intervals[i][0]; j < intervals[i][1]; j++) {
                numbers[j] = 1;
            }
        }
        
        bool start = false;
        vector<int> temp(2);
        for (int i = 0; i < 10000; i++) {
            if (numbers[i] == 1 && start == false) {
                temp[0] = i;
                start = true;
            }
            else if ((numbers[i] == 0 || numbers[i] == -1) && start == true) {
                temp[1] = i;
                start = false;
                ans.emplace_back(temp);
            }
            else if (numbers[i] == -1 && start == false) {
                temp[0] = i;
                temp[1] = i;
                ans.emplace_back(temp);
            }
        }
        return ans;
    }
};

/*
法二：排序+双指针原地修改
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), less<vector<int> >());
        int pos = 0; // 用来标记合并后的集合个数；
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[pos][1] >= intervals[i][0]) {
                // 有重叠
                intervals[pos][1] = max(intervals[pos][1], intervals[i][1]);
            }
            else {
                intervals[++pos] = intervals[i];
            }
        }
        intervals.resize(pos+1);
        return intervals;
    }
};