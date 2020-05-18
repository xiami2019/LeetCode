class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        this->toppoints = -1;
        this->minnumber = INT_MAX;
        this->stacksize = 100;
        this->numbers = new int[this->stacksize];
    }
    
    void push(int x) {
        if (this->toppoints >= this->stacksize - 1){
            int* newnumbers = new int[2 * this->stacksize];
            for (int i = 0; i < this->stacksize; i++){
                newnumbers[i] = numbers[i];
            }
            this->stacksize *= 2;
            delete[] this->numbers;
            this->numbers = newnumbers;
        }

        this->numbers[++this->toppoints] = x;
        this->minnumber = this->minnumber < x ? this->minnumber : x;
    }
    
    void pop() {
        if (this->minnumber == numbers[this->toppoints]){
            this->minnumber = this->numbers[0];
            for (int i = 1; i < this->toppoints; i++){
                if (this->numbers[i] < this->minnumber){
                    this->minnumber = this->numbers[i];
                }
            }
        }
        this->toppoints--;
        if(this->toppoints == -1){
            this->minnumber = INT_MAX;
        }
    }
    
    int top() {
        return this->numbers[this->toppoints];
    }
    
    int min() {
        return this->minnumber;
    }

private:
    int* numbers;
    int toppoints;
    int minnumber;
    int stacksize;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */


/*
剑指Offer解法
使用辅助栈解决
*/
class MinStack {
    stack<int> numbers;
    stack<int> minNumbers;
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        this->numbers.push(x);
        if (this->minNumbers.size() == 0) this->minNumbers.push(x);
        else {
            if (x < this->minNumbers.top()) this->minNumbers.push(x);
            else this->minNumbers.push(this->minNumbers.top());
        }
    }
    
    void pop() {
        this->numbers.pop();
        this->minNumbers.pop();
    }
    
    int top() {
        return this->numbers.top();
    }
    
    int min() {
        return this->minNumbers.top();
    }
};
