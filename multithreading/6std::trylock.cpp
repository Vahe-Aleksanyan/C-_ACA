//
// Created by Vahe Aleksanyan on 08.03.23.
//
//Few things to remember about the try_lock is as follows:
//0. std::try_lock() tries to lock all the mutex passed in it one by one in given order.
//1. On success this function returns -1 otherwise it will return 0-based mutex index number which it could not lock.
//2. If it fails to lock any of the mutex then it will release all the mutex it locked before.
//3. If a call to try_lock results in an exception, unlock is called for any locked objects before re-throwing.
//

#include "mutex"
#include "iostream"
#include "thread"
#include "chrono"
using namespace std;
int x = 0, y = 0;

std::mutex m1, m2;

void doSomeWork_1_Second(int sec) { std::this_thread::sleep_for(std::chrono::seconds(sec));}

void increaseXY(int& XorY, std::mutex& m, const char* desc) {
    for(int i= 0; i < 5; ++i)  {
        m.lock();
        ++XorY;
        cout << desc << XorY << '\n';
        m.unlock();
        doSomeWork_1_Second(1); // since this sleeps, consume will take place
    }
}


void consumeXY () {
    int useCount = 5;
    int XplusY = 0;
    while (1) {
        int lockResult = std::try_lock(m1, m2);
        if(lockResult == -1) { // success
            if(x != 0 && y != 0) {
                --useCount;
                XplusY += x + y;
                x = 0;
                y = 0;
                cout << "XplusY " << XplusY << '\n';
            }
            m1.unlock();
            m2.unlock();
            if(useCount == 0) break;
        }
    }
}

//int main() {
//    std::thread t1(increaseXY, std::ref(x), std::ref(m1), "x ");
//    std::thread t2(increaseXY, std::ref(y), std::ref(m2), "y ");
//    std::thread t3(consumeXY);
//
//    t1.join();
//    t2.join();
//    t3.join();
//
//    return 0;
//}