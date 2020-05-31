class MedianFinder {
private:
    // 最终的中位数结果是最小堆的堆顶数加上最大堆的堆顶数；
    multiset<int, less<int> > minHeap; // 存放后半部分数的最小堆；
    multiset<int, greater<int> > maxHeap; // 存放前半部分数的最大堆；
    int counts; // 统计总数，奇数时插入前半部分，偶数时插入后半部分；

public:
    /** initialize your data structure here. */
    MedianFinder() {
        this->minHeap.clear();
        this->maxHeap.clear();
        this->counts = 0;
    }
    
    void addNum(int num) {
        if (this->counts & 1) {
            // 插入前半部分的最大堆
            auto iter = this->minHeap.begin();
            if (num > *iter) {
                this->minHeap.insert(num);
                iter = this->minHeap.begin();
                this->maxHeap.insert(*iter);
                this->minHeap.erase(iter);
            }
            else {
                this->maxHeap.insert(num);
            }
        }
        else {
            // 插入后半部分的最小堆；
            if (this->maxHeap.empty()) {
                this->minHeap.insert(num);
            }
            else {
                auto iter = this->maxHeap.begin();
                if (num < *iter) {
                    this->maxHeap.insert(num);
                    iter = this->maxHeap.begin();
                    this->minHeap.insert(*iter);
                    this->maxHeap.erase(iter);
                }
                else {
                    this->minHeap.insert(num);
                }
            }
        }
        this->counts++;
    }
    
    double findMedian() {
        if (this->counts == 0) return 0.0;
        if (this->maxHeap.empty() || (this->counts & 1)) {
            auto iter = this->minHeap.begin();
            return *iter * 1.0;
        }
        if ((this->counts & 1) == 0) {
            auto iter1 = this->minHeap.begin();
            auto iter2 = this->maxHeap.begin();
            return (*iter1 + *iter2) / 2.0;
        }
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */