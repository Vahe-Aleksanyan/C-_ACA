//
// Created by Vahe Aleksanyan on 11.03.23.
//NOTES:
// 1. It runs a function asynchronously (potentially in a new thread) and returns a std: :future that
//will hold the result.
// 2. There are three launch policies for creating task:
//7
//a. std: :launch: :async
//§ //
//b. std: :launch: : deffered
//9
//c. std:: launch: :async | std: : launch: :async
//10
//11 // HOW IT WORKS:
//12
// 1. It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
//13 // 2. Then passes the std::promise object to thread function and returns the associated std::future object.
//14 // 3. When our passed argument function exits then its value will be set in this promise object,
//15 // so eventually return value will be available in std::future object.
//16
//17 // SIDE NOTES:
//18
// 1. We can send functor and lambda function as callback to std: :async, it will work the same.


#include "iostream"
#include "thread"
#include "chrono"
#include "algorithm"
#include "future"
using namespace std;
using namespace std::chrono;
typedef long int ull;

ull findOdd(ull start, ull end) {
    ull oddSum = 0;
    cout << "Thread id " << std::this_thread::get_id() << endl;
    for (ull i = start; i <= end; ++i) {
        if(i & 1) {
            oddSum += i;
        }
    }
    return oddSum; // here we can do return as we are using std::async
}

//int main() {
//    ull start = 0, end = 1900000000;
//
//    cout << "Thread id " << std::this_thread::get_id() << endl;
//    cout << "Thread created if policy is std::launch::async" << endl;
//    // in case of option differed, program will start with the same thread to deal with the function when get() is called
//    // if used option async, program will create a new thread and start the job immediately
//    std::future<ull> oddSum = std::async(std::launch::async, findOdd, start, end);
//
//    cout << "waiting for the result" << endl;
//    cout << "oddSum " << oddSum.get() << endl;
//
//    cout << "Completed" << endl;
//    return 0;
//}