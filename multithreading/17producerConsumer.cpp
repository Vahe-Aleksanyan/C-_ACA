//
// Created by Vahe Aleksanyan on 11.03.23.
//Producer Consumer OR Bounded Buffer Problem
//
//THE PROBLEM STATEMENT:
// 1. Producer will produce and consumer will consume with synchronisation of a common buffer.
// 2. Until producer thread produces any data consumer thread can't consume.
// 3. Threads will use condition_variable to notify each other.
// 4. We need mutex if we use condition_variable because CV waits on mutex.
// 5. This is one of the example of producer consumer there are many.
//
//PRODUCER thread steps:
// 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
// 2. check if buffer is full and if it is full then unlock mutex and sleep, if not then go ahead and produce.
// 3. insert item in buffer.
// 4. unlock mutex.
// 5. notify consumer.
//
//CONSUMER thread steps:
// 1. lock mutex, if success then go ahead otherwise wait for mutex to get free.
// 2. check if buffer is empty and if it is, then unlock the mutex and sleep, if not then go ahead and consume.
// 3. consume item from buffer.
// 4. unlock mutex.
// 5. notify producer.
//
//IMP:
// Producer and Consumer have to notify each other upon completion of their job.


#include "iostream"
#include "thread"
#include <deque>
using namespace std;
using namespace std::chrono;
typedef long int ull;

std::mutex mu;
std::condition_variable cond;
deque<int> bufferPC;
const unsigned int maxBufferSize = 50;

void producer(int val) {
    while(val) {
        std::unique_lock<std::mutex> locker(mu); // here we lock the mutex
        cond.wait(locker, []() {return bufferPC.size() < maxBufferSize;}); // this is condition for producer
        bufferPC.push_back(val); // do the job
        cout << "produced " << val << endl;
        val--;
        locker.unlock(); // release mutex
        cond.notify_one(); // notify to the consumer

        // after notifying, we don't have guarantee that the consumer will be able to start,
        // and maybe the producer loop will continue
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> locker(mu); // try to lock the mutex
        cond.wait(locker, []() {return bufferPC.size() > 0;}); // consumer condition
        int val = bufferPC.back(); // do the job
        bufferPC.pop_back();
        cout << "Consumed " << val << endl;
        locker.unlock(); // release mutex
        cond.notify_one(); // notify producer that this is done
    }
}

//int main() {
//    std::thread t1(producer, 100);
//    std::thread t2(consumer);
//
//    t1.join();
//    t2.join();
//    return 0;
//}
