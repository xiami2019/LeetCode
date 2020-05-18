//思路1：模拟
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> line(num_people, 0);
        int index = 0;
        while (candies){
            line[index % num_people] += min(candies, index + 1);
            candies -= min(candies, index + 1);
            ++index;
        }
        return line;
    }
};