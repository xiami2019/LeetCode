class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        queuein.push(value);
    }
    
    int deleteHead() {
        if (queueout.empty()){
            if (queuein.empty()){
                return -1;
            }
            while (!queuein.empty()){
                queueout.push(queuein.top());
                queuein.pop();
            }
        }
        int result = queueout.top();
        queueout.pop();
        return result;
    }

private:
    stack<int> queueout, queuein;
};