/*
哈希表+平衡二叉树
使用平衡二叉树的性质维护了时间的顺序
*/
// 缓存的数据结构
struct Node {
    int cnt; // 使用频率
    int time; // 最近一次使用时间
    int key, value; // kv键值对

    // 我们需要实现一个Node类的比较函数，将cnt作为第一关键字，time作为第二关键字
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }

    // Node构造函数
    Node (int _cnt, int _time, int _key, int _value): cnt(_cnt), time(_time), key(_key), value(_value){}
};

class LFUCache {
    // 缓存容量，时间戳；
    int capacity, time;
    unordered_map<int, Node> key_table; // 哈希表
    set<Node> S; // 平衡二叉树

public:
    LFUCache(int _capacity) {
        this->capacity = _capacity;
        this->time = 0;
        this->key_table.clear();
        this->S.clear();
    }

    int get(int key) {
        if (this->capacity == 0) return -1;
        auto it = key_table.find(key);
        // 如果哈希表中没有要查找的键值key，返回-1；
        if (it == key_table.end()) return -1;
        // 从哈希表中得到旧的缓存
        Node cache = it->second;
        S.erase(cache);
        // 将旧缓存更新
        cache.cnt += 1;
        cache.time = ++time;
        // 将缓存重新放入哈希表和平衡二叉树中
        S.insert(cache);
        it->second = cache;
        return cache.value;
    }

    void put(int key, int value) {
        if (this->capacity == 0) return;
        auto it = key_table.find(key);
        // 如果没有键值key
        if (it == key_table.end()) {
            // 到达缓存容量上限
            if (key_table.size() == this->capacity) {
                // 从哈希表和平衡二叉树中删除最近最少使用的缓存
                key_table.erase(S.begin()->key);
                S.erase(S.begin());
            }
            // 创建新的缓存
            Node cache = Node(1, ++time, key, value);
            // 将新缓存放入哈希表和平衡二叉树中
            key_table.insert(make_pair(key, cache));
            S.insert(cache);
        }
        else {
            // 如果存在键值key，则和get函数类似，只是需要改变value值
            Node cache = it->second;
            S.erase(cache);
            cache.cnt += 1;
            cache.time = ++time;
            cache.value = value; // 改变value的值
            S.insert(cache);
            it->second = cache;
        }
    }
};

/*
双哈希表法：一个freqTable, 一个keyTable
通过链表隐式地维护了使用时间；
*/
struct Node {
    int key, val, freq;
    Node (int _key, int _val, int _freq): key(_key), val(_val), freq(_freq) {}
};

class LFUCache {
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> keyTable;
    unordered_map<int, list<Node> > freqTable;
public:
    LFUCache(int _capacity) {
        this->minfreq = 0;
        this->capacity = _capacity;
        this->freqTable.clear();
        this->keyTable.clear();
    }

    int get(int key) {
        if (this->capacity == 0) return -1;
        auto it = this->keyTable.find(key);
        // 不存在该键值key
        if (it == this->keyTable.end()) return -1;
        // 存在该键值，访问该键值
        list<Node>::iterator node = it->second;
        // 记录值val和freq值
        int val = node->val, freq = node->freq;
        freqTable[freq].erase(node); // 从旧的频率链表里删除
        // 如果当前链表为空，需要在哈希表中删除，并且更新minFreq
        if (freqTable[freq].size() == 0) {
            freqTable.erase(freq);
            if (minfreq == freq) {
                minfreq += 1;
            }
        }
        // 插入到freq+1链表的表头
        freqTable[freq+1].push_front(Node(key, val, freq+1));
        keyTable[key] = freqTable[freq+1].begin();
        return val;
    }

    void put(int key, int value) {
        if (this->capacity == 0) return;
        auto it = keyTable.find(key);
        // 缓存中不存在key，直接进行插入即可
        if (it == keyTable.end()) {
            // 缓存已满，需要进行删除操作
            if (keyTable.size() == capacity) {
                // 通过minFreq拿到freqTable[minFreq]链表的末尾节点（最久未被使用的低频率节点）
                auto it2 = freqTable[minfreq].back();
                keyTable.erase(it2.key);
                freqTable[minfreq].pop_back();
                if (freqTable[minfreq].size() == 0) {
                    freqTable.erase(minfreq);
                }
            }
            freqTable[1].push_front(Node(key, value, 1));
            keyTable[key] = freqTable[1].begin();
            minfreq = 1;
        }
        else {
            // 与get操作基本一致，除了需要更新缓存的值
            list<Node>::iterator node = it->second;
            int freq = node->freq;
            freqTable[freq].erase(node);
            if (freqTable[freq].size() == 0) {
                freqTable.erase(freq);
                if (minfreq == freq) {
                    minfreq += 1;
                }
            }
            freqTable[freq+1].push_front(Node(key, value, freq+1));
            keyTable[key] = freqTable[freq+1].begin();
        }
    }
};