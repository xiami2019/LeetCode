#include <bits/stdc++.h>
// #include <unordered_map> 
using namespace std;

class Solution1 {
public:
/*
方法1：暴力法;直接遍历复杂度n方，遍历所有元素；
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};

class Solution2 {
public:
/*
方法2：使用哈希映射；以空间换时间；(用map容器实现)
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> temp;
        for(int i = 0; i < nums.size(); i++){
            if(temp.count(target - nums[i]) != 0){
                result.push_back(temp[target - nums[i]]);
                result.push_back(i);
                break;
            }
            else{
                temp[nums[i]] = i;
            }
        }
        return result;
    }
};

int main()
{
    Solution2 solu = Solution2();
    vector<int> a;
    int b[3] = {3, 2, 4};
    for(int i = 0; i < 3; i++){
        a.push_back(b[i]);
    }
    vector<int> result = solu.twoSum(a, 6);
    cout << result[0] << " " << result[1] << endl;
}