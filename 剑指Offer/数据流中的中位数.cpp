/*
用multiset加上仿函数greater<int>和less<int>来模拟最大堆和最小堆；
*/

class MedianFinder {
private:
    multiset<int, less<int> > minHeap;
    multiset<int, greater<int> > maxHeap;
    int counts;

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
        if (this->minHeap.empty()) {
            auto iter = this->maxHeap.begin();
            return *iter * 1.0;
        }
        if (this->maxHeap.empty() || (this->counts & 1)) {
            auto iter = this->minHeap.begin();
            return *iter * 1.0;
        }
        if ((this->counts & 1) == 0) {
            auto iter1 = this->minHeap.begin();
            auto iter2 = this->maxHeap.begin();
            return (*iter1 + *iter2) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */