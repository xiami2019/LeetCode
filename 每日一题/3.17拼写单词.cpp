class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> alphabet;
        int ans = 0;
        for (char c: chars){
            alphabet[c]++;
        }
        for (string str: words){
            map<char, int> temp(alphabet);
            bool flag = true;
            for (char c: str){
                if (temp.find(c) == temp.end() || temp[c] == 0){
                    flag = false;
                    break;
                }
                else {
                    temp[c]--;
                }
            }
            if (flag){
                ans += str.length();
            }
        }
        return ans;
    }
};