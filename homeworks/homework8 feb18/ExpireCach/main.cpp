#include <iostream>
#include "Cache.hpp"

using namespace std;

int main() {
    Cache<int, int> cache;
    int x = 10;
    int y = 4;
    cache.insert(x, 40);
    cache.insert(y, 23);
    if (cache.search(x).has_value()) {
        cout << cache.search(x).value() << endl;
    }
    if (cache.search(y).has_value()) {
        cout << cache.search(y).value() << endl;
    }
    for (int i = 0; i < 1000; i++) {
        cache.insert(i, i * i);
    }

    for (int i = 1000; i < 100000; i++) {
        cache.insert(i, i * i);
    }
    if (cache.search(y).has_value()) {
        cout << cache.search(y).value() << endl;
    } else {
        cout << "Not found!" << endl;
    }
    if (cache.search(100000).has_value()) {
        cout << cache.search(y).value() << endl;
    } else {
        cout << "Not found!" << endl;
    }

    return 0;
}
