// 1. 利用构造函数求解 （使用的是循环的思路）
/*
设置一个类的静态变量，然后在构造函数里面计数，开一个数组相当于进行了循环调用
*/
class Temp {
public:
    Temp() {
        ++n;
        sum += n;
    }

    static void reset() {
        n = 0;
        sum = 0;
    }

    static int getSum() {
        return sum;
    }

private: 
    static int n;
    static int sum;
};

int Temp::n = 0;
int Temp::sum = 0;

class Solution {
public:
    int sumNums(int n) {
        Temp::reset();
        Temp temps[n];
        return Temp::getSum();
    }
};

// 2. 利用虚函数求解 (递归的思路)
/*
如果不能在一个函数中判断是不是应该终止递归（要用到if函数），那么不妨定义两个函数，一个函数充当递归函数的角色，
另一个函数处理终止递归的情况，我们需要做的就是在这两个函数里二选一。二选一使用布尔变量来实现，值为true(1)的
时候调用第一个函数，值为false(0)的时候调用第二个函数。如果对n连续做两次反运算，即!!n，那么非零的n转换为true，
0转换为false。这里使用虚函数的多态性来实现函数的选择。
*/
class A;
A *Array[2]; // 两个不同的函数使用多态性来实现

// 基类Sum函数用来终止递归
class A {
public:
    virtual int Sum(int n) {
        return 0;
    }
};

// 派生类Sum函数用来处理递归
class B: public A {
public:
    virtual int Sum(int n) {
        // 非零的数转化为True，0转换为false；
        return Array[!!n]->Sum(n - 1) + n;
    }
};

class Solution {
public:
    int sumNums(int n) {
        A a;
        B b;
        Array[0] = &a; // 存储基类
        Array[1] = &b; // 存储派生类

        int value = Array[1]->Sum(n);
        return value;
    }
};

// 3. 使用函数指针来求解 (递归的思路)
/*
在纯C语言的编程环境中，不能使用虚函数，此时可以用函数指针来模拟；
*/
typedef int(*fun)(int);

class Solution {
public:
    static int sumNums(int n) {
        static fun f[2] = {sumNums0, sumNums};
        return n + f[!!n](n - 1);
    }

    static int sumNums0(int n) {
        return 0;
    }
};