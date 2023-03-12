cmake_minimum_required(VERSION 3.24)
project(Threads)

set(CMAKE_CXX_STANDARD 20)

add_executable(Threads
        1basicThreads.cpp 3TypesOfThreads.cpp 2joinAndDetach.cpp 4mutex.cpp 5MutextryLock.cpp 6std::trylock.cpp 7TimedMutex.cpp 8recursiveMutex.cpp 9lockGuard.cpp 10uniqueLock.cpp 11ConditionVariable.cpp 12deadLock.cpp 13std::lock.cpp 15PromiseFuture.cpp 16std::async.cpp 17producerConsumer.cpp concurency/BusyWait.hpp concurency/thread_pull.h concurency/thread_pull.cpp concurency/Primes.hpp concurency/main.cpp concurency/ExpirationCache.hpp concurency/ExpirationCache.cpp concurency/CheckSleep.cpp 18printProblem.cpp)
