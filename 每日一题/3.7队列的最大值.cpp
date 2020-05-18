//循环数组实现队列

class MaxQueue {
public:
    MaxQueue() {
        this->queueSize = 100;
        this->numbers = new int[this->queueSize];
        this->maxNumber = INT_MIN, this->head = 0, this->tail = 1;
    }

    bool empty() {
        if ((this->head + 1) % this->queueSize == this->tail){
            return true;
        }
        else{
            return false;
        }
    }

    bool full() {
        if (this->head == this->tail){
            return true;
        }
        else{
            return false;
        }
    }
    
    int max_value() {
        if (this->empty()){
            this->maxNumber = -1;
        }

        return this->maxNumber;
    }

    void push_back(int value) {

        if (this->full()){
            int* temp = new int[2 * this->queueSize];
            int index = 1;
            this->head = (this->head + 1) % this->queueSize;
            while(this->head != this->tail){
                temp[index++] = this->numbers[this->head];
                this->head = (this->head + 1) % this->queueSize;
            }
            delete[] this->numbers;
            this->numbers = temp;
            this->head = 0, this->tail = index;
            this->queueSize *= 2;
        }

        this->numbers[this->tail] = value;
        this->tail = (this->tail + 1) % this->queueSize;
        this->maxNumber = max(this->maxNumber, value);
    }
    
    int pop_front() {
        if (this->empty()){
            this->maxNumber = -1;
            return -1;
        }

        this->head = (this->head + 1) % this->queueSize;
        int result = this->numbers[this->head];

        if (result == this->maxNumber){
            this->maxNumber = INT_MIN;
            int temp = (this->head + 1) % this->queueSize;
            while (temp != this->tail){
                this->maxNumber = max(this->maxNumber, this->numbers[temp]);
                temp = (temp + 1) % this->queueSize;
            }
        }
        
        return result;
    }

private:
    int* numbers;
    int queueSize;
    int head, tail;
    int maxNumber;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */


//双栈实现队列
class MaxQueue {
public:
    MaxQueue() {
        this->maxNumber = INT_MIN;
    }

    bool empty(){
        if (this->outStack.empty() && this->inStack.empty()){
            return true;
        }
        return false;
    }
    
    int max_value() {
        if (this->empty()){
            this->maxNumber = -1;
        }
        return this->maxNumber;
    }
    
    void push_back(int value) {
        this->maxNumber = max(this->maxNumber, value);
        this->inStack.push(value);
    }
    
    int pop_front() {
        if (this->empty()){
            return -1;
        }

        if (this->outStack.empty()){
            while (!this->inStack.empty()){
                this->outStack.push(this->inStack.top());
                this->inStack.pop();
            }
        }

        int result = this->outStack.top();
        this->outStack.pop();

        if (this->maxNumber == result){
            this->maxNumber = INT_MIN;
            stack<int> temp;
            while (!this->outStack.empty()){
                this->maxNumber = max(this->maxNumber, this->outStack.top());
                temp.push(this->outStack.top());
                this->outStack.pop();
            }
            while (!temp.empty()){
                this->outStack.push(temp.top());
                temp.pop();
            }
            while (!this->inStack.empty()){
                this->maxNumber = max(this->maxNumber, this->inStack.top());
                temp.push(this->inStack.top());
                this->inStack.pop();
            }
            while (!temp.empty()){
                this->inStack.push(temp.top());
                temp.pop();
            }
        }
        return result;
    }

private:
    stack<int> outStack, inStack;
    int maxNumber;
};

//链表实现队列
struct Node
{
    int val;
    Node* next;
    Node(int a): val(a),next(NULL) {}
};


class MaxQueue {
public:
    MaxQueue() {
        this->front = NULL, this->back = NULL;
        this->maxNumber = INT_MIN;
    }

    bool empty(){
        if (this->front == NULL && this->back == NULL) return true;
        else return false;
    }
    
    int max_value() {
        if (this->empty()){
            this->maxNumber = -1;
        }
        return this->maxNumber;
    }
    
    void push_back(int value) {
        if (this->empty()){
            this->back = new Node(value);
            this->front = this->back;
        }
        else{
            this->back->next = new Node(value);
            this->back = this->back->next;
        }
        
        this->maxNumber = max(this->maxNumber, value);
    }
    
    int pop_front() {
        if (this->empty()){
            return -1;
        }

        int result = this->front->val;
        if (this->front == this->back){
            delete this->front;
            this->front = this->back = NULL;
            this->maxNumber = INT_MIN;
        }
        else{
            Node* temp = this->front;
            this->front = this->front->next;
            delete temp;
            temp = this->front;

            if (this->maxNumber == result){
                this->maxNumber = INT_MIN;
                while (temp != NULL){
                    this->maxNumber = max(this->maxNumber, temp->val);
                    temp = temp->next;
                }
            }
        }
        return result;
    }

private:
    Node* front;
    Node* back;
    int maxNumber;
};