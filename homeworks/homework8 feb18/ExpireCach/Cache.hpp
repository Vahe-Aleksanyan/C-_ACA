#pragma once
#include <iostream>
#include <shared_mutex>
#include <unordered_map>
#include <thread>
#include <optional>
#include <chrono>

using namespace std;
template<typename T1, typename T2>
class Cache {
public:

    // simple constructor
    Cache() :
            alive(true),
            workerThread([this]() {
                while (alive) {
                    doStaff();
                    this_thread::sleep_for(1ms);
                }
            }) {}
// destructor
    ~Cache() {
        d1.clear();
        d2.clear();
        alive = false;
        workerThread.join();
    }


    // public method to insert pairs
    void insert(T1 key, T2 value) {
        if (!d1.contains(key) && !d2.contains(key)) {
            unique_lock l(lock);
            d1[key] = value;
        }
    }

    // public method to find the value with given key
    optional<T2> search(T1 key) {
        shared_lock l(lock);
        if (d1.contains(key)) {
            return d1[key];
        }
        if (d2.contains(key)) {
            return d2[key];
        }
        return optional<T2>();
    }

private:

    // private util method
    void doStaff() {
        unique_lock l(lock);
        if (d1.size() >= 100) {
            d2.clear();
            d2 = d1;
            d1.clear();
        }
    }

private:
    unordered_map<T1, T2> d1;
    unordered_map<T1, T2> d2;
    thread workerThread;
    bool alive;
    shared_mutex lock;
};


