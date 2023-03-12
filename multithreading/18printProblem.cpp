//
// Created by Vahe Aleksanyan on 11.03.23.
//how to call one thread from another thread in sequence.
//User will give input that how many threads should created
// and how many characters should be printed using each thread, and what is the string from which characters should be printed.


#include <iostream>
#include <string>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <thread>
#include <chrono>

using namespace std;

class MyPrinter {
private:
    string str;
    int char_count;
    int thread_count;
    vector<thread> threads; // here we keep our threads
    vector<std::thread::id> thread_ids;  // here we keep human-readable ids
    int thread_id;
    int allowed_thread;
    mutex mutex_lock;
    condition_variable cv;
    int next_char; // to keep track of character id

public:
    MyPrinter(string s, int c_count, int t_count) { // constructor
        str = s;
        char_count = c_count;
        thread_count = t_count;
        thread_id = 0;
        next_char = 0;
        allowed_thread = 0;
    }

    int getCurrentThreadId (const std::thread::id& id) { // given thread, returns human-readable id
        int thread_id = 0;
        for(auto& e : thread_ids) {
            if(e == id) return thread_id;
            thread_id++;
        }
        return -1;
    }


    // create threads with given count, and add in the container by moving, -- combine all code
    void run() {
        for (int i = 0; i < thread_count; i++) {
            thread t(&MyPrinter::print_thread, this);
            cout << "Thread " << t.get_id() <<  " is " << i << endl;
            thread_ids.push_back(t.get_id());
            threads.push_back(move(t));
        }
        for (int i = 0; i < thread_count; i++){
            threads[i].join();
        }
    }

    // This function won't allow printing until all the threads are started.
    void waitForAllThreadInit() {
        while(1) {
            if(thread_count == thread_ids.size()) return;
        }
    }


    void print_thread() {
        while(1) {
            waitForAllThreadInit(); // initialize all threads
            std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // just for making printing slow
            unique_lock<mutex> lock(mutex_lock); // lock th mutex
            cv.wait(lock, [this] { return std::this_thread::get_id() == thread_ids[allowed_thread]; }); // condition variable that links all threads
            print_chars(); // when condition variable is reached and the right thread is reached
            allowed_thread+=1; // change the thread
            if(allowed_thread == thread_count) allowed_thread = 0;
            if(next_char >= str.length()) next_char -= str.length();
            lock.unlock();
            cv.notify_all();
        }
    }

    // logic for pointing chunks of chars and moving cursor
    void print_chars() {
        cout << "ThreadId " << getCurrentThreadId(std::this_thread::get_id()) << " : ";
        int printcount = 0;
        for(int i = next_char; i < str.length() && printcount < char_count; i++){
            cout << str[i];
            printcount++;
        }
        if(printcount < char_count) {
            for(int i = 0; i < char_count - printcount; i++) {
                cout << str[i];
            }
        }
        next_char = next_char + char_count;
        cout << endl;
    }
};

int main(int argc, char *argv[]) {


    // give limit for starting chunks of chars
    if (argc != 4) {
        cout << "Please provide 3 arguments - a string, char count & thread count" << endl;
        return 1;
    }


    string str = argv[1];
    int char_count = atoi(argv[2]); // converts the string argument str to an integer
    int thread_count = atoi(argv[3]); // converts the string argument str to an integer

    MyPrinter p(str, char_count, thread_count);
    p.run();

    return 0;
}