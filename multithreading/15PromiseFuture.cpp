//
// Created by Vahe Aleksanyan on 11.03.23.
//Basically std::promise is sent to the called thread and once the value is ready we set that value in promise object,
// now at calling thread side we get that value using std::future object which was created using std::promise object
// before sending it to the called thread. And this is how we receive value from one thread to another in synchronisation.


#include "iostream"
#include "thread"
#include "chrono"
#include "algorithm"
#include "future"
using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull> && oddSumPromise, ull start, ull end) {
    ull oddSum = 0;
    for(ull i = start; i <= end; ++i) {
        if( i & 1) {
            oddSum += i;
        }
    }
    oddSumPromise.set_value(oddSum);
}

//int main() {
//    ull start = 0, end = 1900000000;
//
//
//    // 1.create promise object - for source
//    // 2.send it inside thread
//    // 3. thread will pass some value to the promise
//    // 4. create future object based on the promise - for destination, which will be resolved later
//    // 5. when thread is dome, the future object will wait, and finally get the processed value
//    std::promise<ull> oddSum;
//    std::future<ull> oddFuture = oddSum.get_future();
//
//    cout << "Thread Created " << endl;
//    std::thread t1(findOdd, std::move(oddSum), start, end);
//
//    cout << "waiting for result " << endl;
//
//    cout << "oddSum : " << oddFuture.get() << endl;
//
//    cout << "Completed" << endl;
//
//    t1.join();
//    return 0;
//}