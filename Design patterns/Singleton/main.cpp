//
// Created by Vahe Aleksanyan on 07.04.23.
//
#include "iostream"
#include "thread"
using namespace std;

class Singleton {

private:
    static Singleton * pinstance_;
    static std::mutex mutex_;
    // always make the constructor private
protected:
    Singleton(const std::string value) :value_(value) {}
    ~Singleton() {}
    std::string value_;
public:
    // just clonable
    Singleton(Singleton & other) = delete;
    // also assignable
    void operator=(const Singleton &) = delete;

    static Singleton *getInstance(const std::string & value);

    void SomeBusinessLogic()
    {
        // ...
    }

    std::string value() const{
        return value_;
    }
};


Singleton* Singleton::pinstance_= nullptr;
std::mutex Singleton::mutex_;


// Static methods should be defined outside the class.
Singleton *Singleton::getInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (pinstance_ == nullptr)
    {
        pinstance_ = new Singleton(value);
    }
    return pinstance_;
}



void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::getInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main()
{
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
              "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
              "RESULT:\n";
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}