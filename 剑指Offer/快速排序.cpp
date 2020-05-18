/*
Partition的两种写法
*/
// 1.两头夹逼法
int Partition1(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= pivot){
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot){
            low++;
        }
        arr[high] = arr[low];
    }
}

// 2.单头替换法
int Partition2(vector<int> &arr, int low, int high)
{
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

//快排主程序
void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int middle = Partition(arr, low, high);
        quicksort(arr, low, middle - 1);
        quicksort(arr, middle + 1, high);
    }
}