using PII = pair<int, int>;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);
        while (!stk.empty()){
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());

            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z){
                return true;
            }
            // 把X壶灌满；
            stk.emplace(x, remain_y);
            // 把Y壶灌满；
            stk.emplace(remain_x, y);
            // 把X壶倒空；
            stk.emplace(0, remain_y);
            // 把Y壶倒空；
            stk.emplace(remain_x, 0);
            // 把X壶的水灌进Y壶，直至灌满或倒空；
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把Y壶的水灌进X壶，直至灌满或倒空；
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};


//数学方法：求最大公约数（贝祖定理）
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x == 0 || y == 0) return z == 0 || x + y == z;
        return z % gcd(x, y) == 0;
    }
};