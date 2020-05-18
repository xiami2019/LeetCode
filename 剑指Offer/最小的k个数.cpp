//法1：直接排序，然后返回前k个元素；O(nlogn)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort(arr.rbegin(), arr.rend());
        vector<int> ans(arr.begin(), arr.begin() + k);
        return ans;
    }
};

// 法2维护一个最小堆，然后取前k个；O(nlogn)
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k);
        int arrLen = arr.size();
        this->buildHeap(arr, arrLen);
        for (int i = 0; i < k; i++){
            ans[i] = arr[0];
            arr[0] = arr[--arrLen];
            heapify(arr, arrLen);
        }
        return ans;
    }

    void buildHeap(vector<int> &arr, int heapSize)
    {
        // 采用自底向上堆化
        // 建堆
        for (int i = 1; i < heapSize; i++){
            int j = i;
            while((j + 1) / 2 >= 1 && arr[j] < arr[(j + 1) / 2 - 1]){
                int temp = arr[j];
                arr[j] = arr[(j + 1) / 2 - 1];
                arr[(j + 1) / 2 - 1] = temp;
                j = (j + 1) / 2 - 1;
            }
        }
    }

    void heapify(vector<int> &arr, int heapSize)
    {
        int index = 0;
        while (1){
            int minPos = index;
            if ((index + 1) * 2 - 1 < heapSize && arr[index] > arr[(index + 1) * 2 - 1]){
                minPos = (index + 1) * 2 - 1;
            }
            if ((index + 1) * 2 < heapSize && arr[minPos] > arr[(index + 1) * 2]){
                minPos = (index + 1) * 2;
            }
            if (minPos == index){
                break;
            }
            int temp = arr[index];
            arr[index] = arr[minPos];
            arr[minPos] = temp;
            index = minPos;
        }
    }
};

// 法三：维护一个k个元素的最大堆，每遇到一个新元素进行比较，比最大的小就替换掉进入最大堆里：
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (k == 0) return vector<int> ();
        vector<int> ans(arr.begin(), arr.begin() + k);
        this->buildHeap(ans, k);
        int arrLen = arr.size();
        for (int i = k; i < arrLen; i++){
            if (arr[i] < ans[0]){
                ans[0] = arr[i];
                heapify(ans, k);
            }
        }
        return ans;
    }

    void buildHeap(vector<int> &arr, int heapSize)
    {
        // 采用自底向上堆化
        // 建堆
        for (int i = 1; i < heapSize; i++){
            int j = i;
            while((j + 1) / 2 >= 1 && arr[j] > arr[(j + 1) / 2 - 1]) {
                swap(arr[j], arr[(j + 1) / 2 - 1]);
                j = (j + 1) / 2 - 1;
            }
        }
    }

    void heapify(vector<int> &arr, int heapSize)
    {
        int index = 0;
        while (1){
            int maxPos = index;
            if ((index + 1) * 2 - 1 < heapSize && arr[index] < arr[(index + 1) * 2 - 1]){
                maxPos = (index + 1) * 2 - 1;
            }
            if ((index + 1) * 2 < heapSize && arr[maxPos] < arr[(index + 1) * 2]){
                maxPos = (index + 1) * 2;
            }
            if (maxPos == index){
                break;
            }
            swap(arr[index], arr[maxPos]);
            index = maxPos;
        }
    }
};

// 法四 使用快排的partition；
/*
时间复杂度为O(n)
*/
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans(k);
        if (arr.empty() || 0 == k) return ans;
        int start = 0, end = arr.size() - 1;
        int index = myPartition(arr, start, end);
        while (index != k - 1){
            if (index > k - 1){
                end = index - 1;
                index = myPartition(arr, start, end);
            }
            else{
                start = index + 1;
                index = myPartition(arr, start, end);
            }
        }
        for (int i = 0; i < k; i++){
            ans[i] = arr[i];
        }

        return ans;
    }

    int myPartition(vector<int> &arr, int low, int high){
        int pivot = arr[high];
        int location = low - 1;
        for (int i = low; i < high; i++){
            if (arr[i] < pivot){
                swap(arr[i], arr[++location]);
            }
        }
        swap(arr[high], arr[++location]);
        return location;
    }
};