//
// Created by Vahe Aleksanyan on 09.03.23.
//Deadlock is a situation where a set of processes are blocked because each process is holding a resource and waiting
// for another resource acquired by some other process.


#include "iostream"
#include "thread"
#include "mutex"
#include "condition_variable"
using namespace std;

//int main() {
//    std::mutex m1;
//    std::mutex m2;
//
//    std::thread t1([&m1, &m2] {
//        cout << "geting m1 " << endl;
//        m1.lock();
//
//        std::this_thread::sleep_for(std::chrono::microseconds(10));
//        cout << "getting m2";
//        m2.lock();
//    });
//
//    std::thread t2([&m1, &m2] {
//        cout << "geting m2 " << endl;
//        m2.lock();
//        std::this_thread::sleep_for(std::chrono::microseconds(10));
//        cout << "getting m1";
//        m1.lock();
//    });
//
//    return 0;
//}