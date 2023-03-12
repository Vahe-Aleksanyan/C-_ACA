//
// Created by Vahe Aleksanyan on 09.03.23.
//1. The class unique_lock is a mutex ownership wrapper.
//2. It Allows:
//    a. Can Have Different Locking Strategies
//    b. time-constrained attempts at locking (try_lock_for, try_lock_until)
//    c. recursive locking
//    d. transfer of lock ownership (move not copy)
//    e. condition variables. (See this in coming videos)
//
//Locking Strategies
//   TYPE           EFFECTS(S)
//1. defer_lock  do not acquire ownership of the mutex.
//2. try_to_lock  try to acquire ownership of the mutex without blocking.
//3. adopt_lock  assume the calling thread already has ownership of the mutex.

#include "iostream"
#include "thread"
#include "mutex"
using namespace std;

std::mutex m10;
int buffer10 = 0;

// example 1

//void task10(const char* threadNumber, int loopFor) {
//    std::unique_lock<mutex> lock(m10); // unlock happens at the time of destructing the  unique_lock
//    for(int i = 0; i < loopFor; ++i) {
//        buffer10++;
//        cout << threadNumber << buffer10 << endl;
//    }
//}
//
//int main() {
//    thread t1(task10, "T1 ", 10);
//    thread t2(task10, "T2 ", 10);
//    t1.join();
//    t2.join();
//    return 0;
//}



// example 2

void task10(const char* threadNumber, int loopFor) {
    std::unique_lock<mutex> lock(m10, std::defer_lock);// Does not call lock on mutex m1, since used defer_lock

    // so we are owning mutex, but not lock yet, and we can do some other job here, then lock, which is flexibility


    lock.lock(); // But then we will have to explicitly tell to lock whenever we want to lock mutex m10
    for(int i = 0; i < loopFor; ++i) {
        buffer10++;
        cout << threadNumber << buffer10 << endl;
    }
}
//
//int main() {
//    thread t1(task10, "T1 ", 10);
//    thread t2(task10, "T2 ", 10);
//    t1.join();
//    t2.join();
//    return 0;
//}