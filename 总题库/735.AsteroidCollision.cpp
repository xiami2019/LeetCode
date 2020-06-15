class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> collision; // 用来保存正数，每次遇到负数时就和栈顶元素进行比较，开始撞击；
        for (int i : asteroids) {
            if (i > 0 || collision.empty()) {
                collision.push_back(i);
            }
            else {
                while (!collision.empty() && collision.back() > 0 && abs(i) > collision.back()) {
                    collision.pop_back();
                }
                if (collision.empty() || collision.back() < 0) { // 此时说明碰撞成功，负元素入栈，否则说明碰撞失败，负元素被忽略；
                    collision.push_back(i);
                }
                if (!collision.empty() && collision.back() == abs(i)) { // 星球相等时，同时💥；
                    collision.pop_back();
                }
            }
        }
        return collision;
    }
};

// [5, 10, -5]
// [8, -8]
// [10, 2, -5]
// [-2, -1, 1, 2]