/*
并发问题来自并发计算的场景，该场景下，程序在多线程（或多进程）中同时执行。
同时进行并不是完全指进程或线程再不同的物理CPU上独立运行，更多情况下，是在一个物理
CPU上交替执行多个线程或进程。并发既可在线程中，也可在进程中。

并发任务主要为多任务情况设计。但如果应用不当，可能会引发一些漏洞。按照情况不同，可以分为三种：

竞态条件：由于多进程之间的竞争执行，导致程序未按照期望的顺序输出。
死锁：并发程序等待一些必要资源，导致没有程序可以执行。
资源不足：进程被永久剥夺了运行所需的资源。

无竞争并发：
并发问题有一个共同特征：多个线程/进程之间共享一些资源。由于无法消除资源共享的约束，防止并发问题就变成了
共享资源的协调问题。

如果可以确保程序中关键部分代码的独占性，就可以防止程序进入不一致的状态。

竞争条件的解决方案为：需要某些关键部分代码具有排他性，即在给定的时间内，只有一个线程可以进入关键部分代码。

可以将这种机制看做限制关键部分代码访问的锁。
在该机制下，一旦一个线程进入关键部分，它就可以阻止其他线程进入该关键部分。

如果该线程未被授权进入关键代码，可以认为该线程被阻塞或进入睡眠状态。

总之，为了防止出现并发生竞争状态，需要一种具有两种功能的机制：1）关键部分的访问控制；2）通知阻塞线程；

使用synchronization
思路：
题目要求按顺序依次执行三个方法，且每个方法都在单独的线程中运行。为了保证线程的执行顺序，
可以在方法之间创建一些依赖关系，即第二个方法必须在第一个方法之后执行，第三个方法必须在
第二个方法之后执行。

依赖关系可以通过并发机制实现。使用一个共享变量firstJobDone协调第一个方法与第二个方法的
执行顺序，使用另一个共享变量secondJobDone协调第二个方法与第三个方法的执行顺序。

算法：
首先初始化共享变量firstJobDone和secondJobDone，初始值表示所有方法未执行。

方法first()没有依赖关系，可以直接执行。在方法最后更新变量firstJobDone表示该方法完成。

方法second()中，检查firstJobDone的状态。如果未更新则进入等待状态，否则执行方法second()。
在方法末尾，更新变量secondJobDone表示方法second()执行完成。

方法third()中，检查secondJobDone的状态。与方法second()类似，执行third()之前，需要先等待secondJobDone的状态。
*/
#include <semaphore.h>

class Foo {
protected:
    sem_t firstJobDone;
    sem_t secondJobDone;
public:
    Foo() {
        sem_init(&firstJobDone, 0, 0);
        sem_init(&secondJobDone, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstJobDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondJobDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};