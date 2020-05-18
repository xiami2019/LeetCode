/*
用BFS搜
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        queue<pair<int, int> > bfs;
        bfs.push(make_pair(0, 0));
        int reached[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                reached[i][j] = 0;
            }
        }
        int addition_x[] = {0, 0, -1, 1};
        int addition_y[] = {1, -1, 0, 0};
        int countCell = 0;
        while (!bfs.empty()){
            int currentX = bfs.front().first, currentY = bfs.front().second;
            bfs.pop();
            if (reached[currentX][currentY] == 0){
                reached[currentX][currentY] = 1;
                countCell++;
                // cout << countCell << endl;
            }
            else if (reached[currentX][currentY] == 1){
                continue;
            }
            for (int i = 0; i < 4; i++){
                int newX = currentX + addition_x[i], newY = currentY + addition_y[i];
                if (newX < 0 || newX >= m || newY < 0 || newY >= n || reached[newX][newY] == 1){
                    continue;
                }
                else{
                    int digitSum = 0, tempX = newX, tempY = newY;
                    for (; newX; digitSum += newX % 10, newX /= 10);
                    for (; newY; digitSum += newY % 10, newY /= 10);
                    if (digitSum <= k) bfs.push(make_pair(tempX, tempY));
                }
            }
        }
        return countCell;
    }
};

int main()
{
    Solution solu;
    cout << solu.movingCount(36, 11, 15) << endl;
    
}