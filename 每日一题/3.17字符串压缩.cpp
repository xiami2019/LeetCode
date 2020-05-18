class Solution {
public:
    string compressString(string S) {
        int strLength = S.length();
        if (0 == strLength) return S;
        string result = "";
        char temp = S[0];
        result += temp;
        int times = 1;
        for (int i = 1; i < strLength; i++){
            if (S[i] == temp){
                times++;
                if (i == strLength - 1){
                    result += to_string(times);
                }
            }
            if (S[i] != temp){
                result += to_string(times);
                temp = S[i];
                result += S[i];
                times = 1;
                if (i == strLength - 1){
                    result += '1';
                }
            }
        }
        if (result.length() >= strLength){
            return S;
        }
        return result;
    }
};