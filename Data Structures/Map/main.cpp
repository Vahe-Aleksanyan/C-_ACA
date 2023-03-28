#include "mapWIthAVL.h"
#include <iostream>
using namespace std;

int main()
{
    Map map;

    map[333] = 322;
    map[33] = 53;
    map[3] = -927;

    map.insert(-4,45);
    map.insert(0,2);


    cout<<"Value at key 42 before updating = "
        <<map[42]<<endl;
    cout<<"Value at key -2 before updating = "
        <<map[-2]<<endl;
    cout<<"Value at key 12 before updating = "
        <<map[12]<<endl;

// update
    map[33] = -32;

    // Updating value at key -2
    map.insert(-4,8);

    // Updating value at key 12
    map.update(3,444);

    // accessing elements
    cout <<map[33]<<endl;
    cout <<map[-4]<<endl;
    cout <<map[3]<<endl;

    return 0;
}
