#include <bits/stdc++.h>
using namespace std;

//采用归并的方法直接将两个数组合并;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        double result = 0;
        vector<int> combine;
        int index_1 = 0, index_2 = 0;
        while(index_1 < m || index_2 < n){
            if(index_1 == m){
                combine.push_back(nums2[index_2]);
                index_2++;
            }
            else if(index_2 == n){
                combine.push_back(nums1[index_1]);
                index_1++;
            }
            else if(nums1[index_1] <= nums2[index_2]){
                combine.push_back(nums1[index_1]);
                index_1++;
            }
            else{
                combine.push_back(nums2[index_2]);
                index_2++;
            }
        }
        if((m + n) % 2 == 0){
            result = (combine[(m + n) / 2 - 1] + combine[(m + n) / 2]) / 2.0;
        }
        else{
            result = combine[(m + n) / 2];
        }
        return result;
    }
};

//递归法二分查找;
/*
将一个集合划分为两个长度相等的子集，其中一个子集的元素总是大于另一个子集中的元素;
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n){ //to ensure m <= n
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax){
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums2[j-1] > nums1[i]){
                iMin = i + 1; //i is too small;
            }
            else if (i > iMin && nums1[i-1] > nums2[j]){
                iMax = i - 1; //i is too big;
            }
            else{//i is perfect
                int maxLeft = 0;
                if (i == 0){
                    maxLeft = nums2[j-1];
                }
                else if (j == 0){
                    maxLeft = nums1[i-1];
                }
                else{
                    maxLeft = max(nums1[i-1], nums2[j-1]);
                }
                if ((m + n) % 2 == 1){
                    return maxLeft;
                }
                int minRight = 0;
                if (i == m){
                    minRight = nums2[j];
                }
                else if (j == n){
                    minRight = nums1[i];
                }
                else{
                    minRight = min(nums2[j], nums1[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

int main()
{

}