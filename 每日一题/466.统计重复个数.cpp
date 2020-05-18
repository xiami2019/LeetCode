/*
方法一：找出循环节
*/
class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0) {
            return 0;
        }

        int s1cnt = 0, index = 0, s2cnt = 0;
        /*
        recall是我们用来找循环节的变量，它是一个哈希映射
        我们如何找循环节？假设我们遍历了s1cnt个s1，此时匹配到了第s2cnt个s2中的第index个字符
        如果我们之前遍历了s1cnt'个s1时，匹配到的是第s2cnt'个s2中同样的第index个字符，那么就有循环节了
        我们用（s1cnt'，s2cnt'，index）和（s1cnt，s2cnt，index）表示两次包含相同index的匹配结果
        那么哈希映射中的键就是index，值就是（s1cnt'，s2cnt'）这个二元组
        循环节就是：
        -前s1cnt'个s1包含了s2cnt'个s2；
        -以后的每（s1cnt - s1cnt'）个s1包含了（s2cnt-s2cnt'）个s2
        那么还会剩下（n1 - s1cnt）% （s1cnt - s1cnt'）个s1，我们对这些与s2进行暴力匹配
        注意s2要从第index个字符开始匹配
        */
       unordered_map<int, pair<int, int>> recall;
       pair<int, int> preLoop, inLoop;
       while (true) {
           // 我们遍历一个s1，看看能不能找不到循环节
           ++s1cnt;
           for (char ch: s1) {
               if (ch == s2[index]) {
                   index += 1;
                   if (index == s2.size()) {
                       ++s2cnt;
                       index = 0;
                   }
               }
           }
           // 没有找到循环节，所有的s1就用完了
           if (s1cnt == n1) {
               return s2cnt / n2;
           }
           // 出现了之前的index，表示找到了循环节
           if (recall.count(index)) {
               auto [s1cntPrime, s2cntPrime] = recall[index];
               // 前s1cnt'个s1包含了s2cnt'个s2
               preLoop = {s1cntPrime, s2cntPrime};
               // 以后的每（s1cnt - s2cnt'）个s1包含了（s2cnt - s2cnt'）个s2
               inLoop = {s1cnt - s1cntPrime, s2cnt - s2cntPrime};
               break;
           }
           else {
               recall[index] = {s1cnt, s2cnt};
           }
        }
        // ans存储的S1包含的s2数量，考虑到之前的preLoop和inLoop
        int ans = preLoop.second + (n1 - preLoop.first) / inLoop.first * inLoop.second;
        // S1的末尾还剩下一些s1（数量不足以构成循环节），我们暴力进行匹配
        int rest = (n1 - preLoop.first) % inLoop.first;
        for (int i = 0; i < rest; i++) {
            for (char ch : s1) {
                if (ch == s2[index]) {
                    index++;
                    if (index == s2.size()) {
                        ans++;
                        index = 0;
                    }
                }
            }
        }
        // S1包含ans个s2，那么久包含ans / n2个S2；
        return ans / n2;
    }
};