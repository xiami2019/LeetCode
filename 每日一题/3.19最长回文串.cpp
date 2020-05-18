class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> hashmap;
        int ans = 0;
        bool odd = true;
        for (char c: s){
            hashmap[c]++;
        }
        typedef map<char, int>::iterator iter;
        iter it = hashmap.begin();
        while (it != hashmap.end()){
            if (it->second % 2 == 0){
                ans += it->second;
            }
            else {
                ans += it->second - 1;
                if (odd){
                    ans += 1;
                    odd = false;
                }
            }
            it++;
        }
        return ans;
    }
};