// 滑动窗口
/*
在滑动窗口类型的问题中都会有两个指针。一个用于延伸现有窗口的right指针，
和一个用于收缩窗口的left指针。在任意时刻，只有一个指针运动，而另一个保持静止。

在本题中，我们通过移动right指针不断扩张窗口。当窗口包含全部所需的字符后，如果能
收缩，我们就收缩窗口直到得到最小窗口。

答案就是最小的可行窗口。
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }
        map<char, int> dictT;
        for (int i = 0; i < t.length(); i++) {
            dictT[t[i]]++;
        }
        // number of unique characters in t, which need to be present in the desired window.
        int required = dictT.size();

        int left = 0, right = 0;
        // formed is used to keep track of how many unique characters in t are present in the current window in its desired frequency
        int formed = 0;
        map<char, int> windowCounts;

        // ans list of the form (window length, left, right)
        int ans[3] = {-1, 0, 0};

        while (right < s.length()) {
            windowCounts[s[right]]++;

            if (dictT.count(s[right]) && windowCounts[s[right]] == dictT[s[right]]) {
                formed++;
            }

            // Try and contract the window till the point where it ceases to be "desirable".
            while (left <= right && formed == required) {
                // Save the smallest window until now.
                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                windowCounts[s[left]]--;
                if (dictT.count(s[left]) && windowCounts[s[left]] < dictT[s[left]]) {
                    formed--;
                }
                left++;
            }
            // Keep expanding the window once we are done contracting.
            right++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};

// 优化滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() == 0 || t.length() == 0) {
            return "";
        }

        map<char, int> dictT;
        for (int i = 0; i < t.length(); ++i) {
            dictT[t[i]]++;
        }
        int required = dictT.size();
        vector<pair<int, char>> filteredS;

        for (int i = 0; i < s.length(); i++) {
            if (dictT.count(s[i])) {
                filteredS.emplace_back(make_pair(i, s[i]));
            }
        }

        int left = 0, right = 0, formed = 0;
        map<char, int> windowCounts;
        int ans[3] = {-1, 0, 0};

        while (right < filteredS.size()) {
            char c = filteredS[right].second;
            windowCounts[c]++;

            if (dictT.count(c) && windowCounts[c] == dictT[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = filteredS[left].second;

                int end = filteredS[right].first;
                int start = filteredS[left].first;
                if (ans[0] == -1 || end - start + 1 < ans[0]) {
                    ans[0] = end - start + 1;
                    ans[1] = start;
                    ans[2] = end;
                }

                windowCounts[c]--;
                if (dictT.count(c) && windowCounts[c] < dictT[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return ans[0] == -1 ? "" : s.substr(ans[1], ans[0]);
    }
};