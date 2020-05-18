// 使用hashmap根据two-sum问题进行优化；
// 超时；
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int numsLen = nums.size();
        int preElement; // 用来跳过相同的元素；
        sort(nums.begin(), nums.end()); // 对原数组排序，可以跳过相同的元素；
        vector<vector<int> > ans;

        if (nums.size() == 0){
            return ans; //处理特殊情况；
        }

        set<vector<int> > ansList;
        preElement = nums[0];
        for (int i = 0; i < numsLen - 2; i++){
            if (nums[i] == preElement && i != 0){
                continue;
            }
            preElement = nums[i];
            set<int> twoNums;
            for (int j = i + 1; j < numsLen; j++){
                vector<int> tempAns({nums[i]});
                if (twoNums.find(-nums[i] - nums[j]) == twoNums.end()){
                    twoNums.insert(nums[j]);
                }
                else{
                    tempAns.push_back(nums[j]);
                    tempAns.push_back(-nums[i] - nums[j]);

                    sort(tempAns.begin(), tempAns.end());
                    if (ansList.find(tempAns) == ansList.end()){
                        ans.push_back(tempAns);
                        ansList.insert(tempAns);
                    }
                }
            }
        }
        return ans;
    }
};

/*
双指针法：
先选定一个数，再在它后面的部分中选择剩下的两个数；
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        int len = nums.size();
        sort(nums.begin(), nums.end()); // 先排序，因此就可以使用双指针法
        for (int i = 0; i < len - 2; i++){
            if (i == 0 || (i > 0 && nums[i] != nums[i-1])) { //相同的数直接跳过
                int p1 = i + 1, p2 = len - 1; //使用双指针指向两个边界
                while (p1 < p2){
                    if (nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    }
                    else if (nums[p1] + nums[p2] == -nums[i]){
                        if (p1 == i+1){
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            ans.push_back(vtemp);
                        }
                        else if (nums[p1] != nums[p1 - 1]){ // 去重，相同的数只留一个；
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            ans.push_back(vtemp);
                        }
                        p1++,p2--;
                    }
                    else{
                        p2--;
                    }
                }
            }
        }
        return ans;
    }
};