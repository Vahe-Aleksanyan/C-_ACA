//
// Created by Vahe Aleksanyan on 07.03.23.
//JOIN NOTES
//0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
//1. Double join will result into program termination.
//2. If needed we should check thread is joinable before joining. ( using joinable() function)
//
//DETACH NOTES
//0. This is used to detach newly created thread from the parent thread.
//1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and
//   double detach() will result into program termination.
//2. If we have detached thread and main function is returning then the detached thread execution is suspended.
//
//NOTES:
//Either join() or detach() should be called on thread object, otherwise during thread object�s destructor it will
//terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.


#include "iostream"
#include "thread"
#include "chrono"
using namespace std;

void run(int count) {
    while (count --> 0)
        cout << "cpp hello" << endl;
//    std::this_thread::sleep_for(chrono::seconds(5)); // just makes it sleep, main thinks it is doing some job
    cout << "finish thread ";
}

//int main() {
//    std::thread t1(run, 10);
//    cout << "main()" << endl;
//
//    // good practise to check joinable, otherwise double joining will terminate program
////    if(t1.joinable()) {
////        t1.join(); // we tell the main to wait until t1 is done
////    }
//
//if(t1.joinable())
//    t1.detach();
//
//
//    cout << "main() after" << endl;
//    // here we make sllep the main thread, so the os can start the thread t1,
//    // otherwise the thread will not start, since os is not so fast and the program will execute return statement below.
//    std::this_thread::sleep_for(chrono::seconds(5));
//
//    return 0;
//}