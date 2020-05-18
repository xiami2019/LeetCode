class Solution {
    //法1，逆向双指针
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int index = 0;
        int lenA = A.size();
        for (int i = 0; i < n; i++){
            while (index < m && A[index] <= B[i]){
                index++;
            }
            for (int j = lenA- 1; j > index; j--){
                A[j] = A[j - 1];
            }
            A[index++] = B[i];
            m++;
        }
    }
};

class Solution {
    //法2，归并
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> ans;
        int indexA = 0, indexB = 0;
        while (indexA < m || indexB < n){
            if (indexA >= m || (indexB < n && A[indexA] > B[indexB])){
                ans.push_back(B[indexB++]);
            }
            else{
                ans.push_back(A[indexA++]);
            }
        }
        A.clear();
        A = ans;
    }
};
