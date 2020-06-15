class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }

        int minLength = INT_MAX;
        for (string s : strs) {
            minLength = min(minLength, (int)s.size());
        }
        int low = 0, high = minLength;
        while (low < high) {
            int mid = (high - low + 1) / 2 + low;
            if (isCommonPrefix(strs, mid)) {
                low = mid;
            }
            else {
                high = mid - 1;
            }
        }
        return strs[0].substr(0, low);
    }

    bool isCommonPrefix(const vector<string>& strs, int length) {
        string str0 = strs[0].substr(0, length);
        int counts = strs.size();
        for (int i = 1; i < counts; ++i) {
            string str = strs[i];
            for (int j = 0; j < length; ++j) {
                if (str0[j] != str[j]) {
                    return false;
                }
            }
        }
        return true;
    }
};