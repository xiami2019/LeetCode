/*
哈希表加双向链表
*/

class LRUCache {
    int cap; // 容量
    // 双向链表，储存(key, value)键值对；
    list<pair<int, int> > cache;
    // 哈希表：key映射到（key，value）在cache中的位置；
    unordered_map<int, list<pair<int, int> >::iterator > hashmap;
public:
    LRUCache(int capacity) {
        // 设定容量
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = hashmap.find(key); //it是一个迭代器；
        // 访问的key不存在
        if (it == hashmap.end()) return -1;
        // key存在，把（k,v）换到队头（使用先删除再插入的方式）
        pair<int, int> kv = *hashmap[key];
        cache.erase(hashmap[key]);
        cache.push_front(kv);
        // 更新（key，value）在cache中的位置；
        hashmap[key] = cache.begin();
        return kv.second; // 返回value值；
    }
    
    void put(int key, int value) {
        // 要首先判断key是否已经存在
        auto it = hashmap.find(key);
        if (it == hashmap.end()){
            // 当前key在cache中不存在，需要进行插入
            // 判断cache是否已满
            if (cache.size() == this->cap) {
                // cache已满，删除尾部的键值对腾位置
                // cache和map中的数据都要删除
                // 删除cache末尾的键值对
                auto lastPair = cache.back();
                int lastKey = lastPair.first;
                hashmap.erase(lastKey);
                cache.pop_back();
            }
            // cache没满，可以直接添加
            cache.push_front(make_pair(key, value));
           hashmap[key] = cache.begin();
        }
        else {
            // key存在，更改value并换到队头
            cache.erase(hashmap[key]);
            cache.push_front(make_pair(key, value));
            hashmap[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */