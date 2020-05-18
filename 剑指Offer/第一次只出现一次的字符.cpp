class Solution {
public:
    char firstUniqChar(string s) {
        if (s == ""){
            return ' ';
        }

        int alphabet[128] = {0};
        for (char c : s){
            alphabet[c]++;
        }

        for (char c : s){
            if (alphabet[c] == 1){
                return c;
            }
        }

        return ' ';
    }
};