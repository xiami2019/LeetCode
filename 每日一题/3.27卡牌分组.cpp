/*
法一：暴力
*/

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() == 0) return false;
        int minCounts = 0;
        map<int, int> cardsNumber;
        for (int card : deck){
            cardsNumber[card]++;
        }
        vector<int> temp(cardsNumber.size());
        int index = 0;
        for (auto iter = cardsNumber.begin(); iter != cardsNumber.end(); index++, iter++){
            temp[index] = iter->second;
        }
        int tempLen = temp.size();
        int lessEle = INT_MAX;
        for (int i = 0; i < tempLen; i++){
            if (temp[i] < lessEle){
                lessEle = temp[i];
            }
        }
        
        if (lessEle < 2){
            return false;
        }
        for (int j = 2; j <= lessEle; j++){
            if (lessEle % j != 0){
                continue;
            }
            bool flag = true;
            for (int i = 1; i < tempLen; i++){
                if (temp[i] % j != 0){
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        
        return false;
    }
};

/*
求所有counts的最大公约数
*/
class Solution {
    int cnt[10000];
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        for (auto x: deck) cnt[x]++;
        int g = -1;
        for (int i = 0; i < 10000; ++i){
            if(cnt[i]) {
                if (~g){
                    g = gcd(g, cnt[i]);
                }
                else g = cnt[i];
            }
        }
        return g >= 2 ? true : false;
    }
};