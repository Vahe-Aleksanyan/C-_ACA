//
// Created by Vahe Aleksanyan on 07.03.23.
//0. In every application there is a default thread which is main(), in side this we create other threads.
//1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
//   For example:
//   (a) The browser has multiple tabs that can be different threads.
//   (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//   (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)
//
//WAYS TO CREATE THREADS IN C++11
//1. Function Pointers
//2. Lambda Functions
//3. Functors
//4. Member Functions
//5. Static Member functions


#include "iostream"
#include "thread"
#include "chrono"
#include "algorithm"
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

ull oddSum;
ull evenSum;

void findEven(ull start, ull end) {
    for(ull i = start; i <= end; ++i) {
        if((i & 1) == 0) {
            evenSum += i;
        }
    }
}


void findOdd(ull start, ull end) {
    for(ull i = start; i <= end; ++i) {
        if((i & 1) == 1) {
            oddSum += i;
        }
    }
}
//
//int main() {
//    ull start = 0, end = 1900000000;
//
//    auto startTIme = high_resolution_clock::now();
//
//    // create the threads
//    std::thread t1(findEven, start, end);
//    std::thread t2(findOdd, start, end);
//
//
//    t1.join(); // we join threads to our main thread, main will wait until these threads are done
//    t2.join();
//
//
////    findOdd(start, end);
////    findEven(start, end);
//
//    auto endTIme = high_resolution_clock::now();
//
//    auto duration = duration_cast<microseconds>(endTIme - startTIme);
//    cout << "odd Sum : " << oddSum << endl;
//    cout << "even Sum :" << evenSum << endl;
//    cout << "seconds " << duration.count() / 1000000 << endl;
//
//    return 0;
//}