//
// Created by Vahe Aleksanyan on 07.03.23.
//
// if we create multiple threads at the same time there is no guarantee which one will start first

#include "iostream"
#include "thread"

using namespace std;


// ---------------------------------------
// function pointer
//void fun(int x) {
//    while(x --> 0) {
//        cout << x << endl;
//    }
//}

//int main() {
//    std::thread t1(fun, 11);
//    std::thread t2(fun, 10);
//
//    t1.join();
//    t2.join();
//    return 0;
//}



// ---------------------------------------


// Lambda Expression

//int main() {
//
//
//    std::thread t([](int x) {
//        while (x-- > 0) {
//            cout << x << endl;
//        }
//    }, 10);
//    t.join();
//    return 0;
//}

// ---------------------------------------

// Functor - function object


//class Base {
//public :
//    void operator()(int x) {
//        while (x --> 0) {
//            cout << x << endl;
//        }
//    }
//};
//
//int main() {
//    std::thread t((Base()), 10);
//    t.join();
//    return 0;
//}

// ---------------------------------------

// Non-static member function

//class Base {
//public:
//    void run(int x) {
//        while (x --> 0) {
//            cout << x << endl;
//        }
//    }
//};
//
//int main() {
//    Base b;
//    std::thread t(&Base::run, &b,  10);
//    t.join();
//    return 0;
//}


// ---------------------------------------

// static member function

class Base {
public :
    static void run(int x) {
        while (x --> 0) {
            cout << x << endl;
        }
}
};

//int main() {
//    std::thread t(&Base::run, 10);
//    t.join();
//
//    return 0;
//}