//
// Created by Vahe Aleksanyan on 09.03.23.
//
//Few points to remember about the lock_guard is as follows:
//0. It is very light weight wrapper for owning mutex on scoped basis.
//1. It acquires mutex lock the moment you create the object of lock_guard.
//2. It automatically removes the lock while goes out of scope.
//3. You can not explicitly unlock the lock_guard.
//4. You can not copy lock_guard.


#include "iostream"
#include "thread"
#include "mutex"
using namespace std;

std::mutex mut9;
int buffer9 = 0;

void task(const char* threadNumber, int loopFor) {
    std::lock_guard<mutex> lock(mut9);
    for(int i = 0; i < loopFor; ++i) {
        buffer9++;
        cout << threadNumber << buffer9 << endl;
    }
    // here it goes out of scope and removes the lock
}

//int main() {
//    thread t1(task, "T1 ", 10);
//    thread t2(task, "T2 ", 10);
//    t1.join();
//    t2.join();
//    return 0;
//}