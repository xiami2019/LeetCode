class CQueue {
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (!s2.empty()) {
            int temp = s2.top();
            s2.pop();
            return temp;
        }
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        int temp = s2.top();
        s2.pop();
        return temp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */