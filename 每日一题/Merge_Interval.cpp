class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), less<vector<int> >());
        int pos = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[pos][1]) {
                intervals[pos][1] = max(intervals[pos][1], intervals[i][1]);
            }
            else {
                intervals[++pos] = intervals[i];
            }
        }
        intervals.resize(pos + 1);
        return intervals;
    }
};