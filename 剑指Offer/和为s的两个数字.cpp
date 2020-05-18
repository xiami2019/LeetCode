class Solution {
    //利用哈希以空间换时间
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s;
        vector<int> result;
        for (int i : nums){
            if (s.find(target - i) != s.end()){
                result.push_back(i);
                result.push_back(target - i);
                return result;
            }
            else{
                s.insert(i);
            }
        }

        return result;
    }
};

//考虑到是递增的序列，可以使用双指针法；
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int left = 0, right = nums.size() - 1;
        while (left < right){
            if (nums[left] + nums[right] > target){
                right--;
            }
            else if (nums[left] + nums[right] < target){
                left++;
            }
            else if (nums[left] + nums[right] == target){
                result.push_back(nums[left]);
                result.push_back(nums[right]);
                break;
            }
        }

        return result;
    }
};