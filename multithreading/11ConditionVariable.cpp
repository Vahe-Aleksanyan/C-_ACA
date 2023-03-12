//
// Created by Vahe Aleksanyan on 09.03.23.
//1. Condition variables allow us to synchronise threads via notifications.
//   a. notify_one();
//   b. notify_all();
//2. You need mutex to use condition variable
//3. Condition variable is used to synchronise two or more threads.
//4. Best use case of condition variable is Producer/Consumer problem.
//5. Condition variables can be used for two purposes:
//    a. Notify other threads
//    b. Wait for some condition



#include "iostream"
#include "thread"
#include "mutex"
#include "condition_variable"
using namespace std;

std::condition_variable cv;
std::mutex m11;

long balance = 0;

void addMoney(int money) {
    std::lock_guard<mutex> lg(m11); // immediately lock the mutex to do its job
    balance += money;
    cout << "Amount Added Current Balance: " << balance << endl;
    cv.notify_one(); // so we notify other threds that here something is done and if they were waiting to this, they can do their job
}

void withrowMoney(int money) {
    std::unique_lock<mutex> ul(m11); // locks
    cv.wait(ul, [] {return (balance != 0) ? true : false;}); // waits this condition to fulfil by other threads, and when notified it continues
    if(balance >= money) { // further checking for self
        balance -= money;
        cout << "Amount Deducted: " << money << endl;
    } else {
        cout << "Amount can`t be duducted, current Balance is less than " << money << endl;
    }

    cout << "Current Balance is " << balance << endl;
}

//int main() {
//    std::thread t1(withrowMoney, 500);
//    std::thread t2(addMoney, 500);
//    t1.join();
//    t2.join();
//    return 0;
//}