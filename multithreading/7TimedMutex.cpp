//
// Created by Vahe Aleksanyan on 08.03.23.
//0. std::timed_mutex is blocked till timeout_time or the lock is acquired and returns true if success
//   otherwise false.
//1. Member Function:
//   a. lock
//   b. try_lock
//   c. try_lock_for    ---\ These two functions makes it different from mutex.
//   d. try_lock_until  ---/
//   e. unlock
//
//EXAMPLE: try_lock_for();
//Waits until specified timeout_duration has elapsed or the lock is acquired, whichever comes first.
//On successful lock acquisition returns true, otherwise returns false.


#include "iostream"
#include "mutex"
#include "thread"
#include "chrono"
using namespace std;
int counter7 = 0;
std::timed_mutex timeMut;
void increment(int i) {
    if(timeMut.try_lock_for(std::chrono::seconds(1))) { // try to change numbers and see other scenarios
        ++counter7;
        std::this_thread::sleep_for (std::chrono::seconds(2));
        cout << "Thread " << i << " Entered" << endl;
        timeMut.unlock();
    } else {
        cout << "Thread " << i << " Could not Enter" << endl;
    }
}

//int main() {
//    std::thread t1(increment, 1);
//    std::thread t2(increment, 2);
//
//    t1.join();
//    t2.join();
//
//    cout << counter7 << endl;
//    return 0;
//}

// expected output - assume t1 executes at first, it locks the mutex, then sleeps for 2 second, at the same time t2, which can only wait for 1 second, coulnd not wait for 2 second and execute else command,
//Thread 2 Could not Enter
//        Thread 1 Entered
//1
