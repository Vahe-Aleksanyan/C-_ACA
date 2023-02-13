////
//// Created by Vahe Aleksanyan on 05.01.23.
////
//
//#include "Server.h"
//#include <iostream>
//using namespace std;
//class Server {
//public:
//    Server(char letterName);
//
//    static int getTurn();
//
//    void serveOne();
//
//    static bool stillOpen();
//
//private:
//    static int turn;
//    static int lastServed;
//    static bool nowOpen;
//    char name;
//};
//
//
//int main() {
//    Server s1('A'), s2('B');
//    int number, count;
//    do {
//        cout << "How many in your group? ";
//        cin >> number;
//        cout << "Your turns are: ";
//        for (count = 0; count < number; count++)
//            cout << Server::getTurn() << ' ';
//        cout << endl;
//        s1.serveOne();
//        s2.serveOne();
//    } while (Server::stillOpen());
//    cout << "Now closing service.\n";
//    return 0;
//}
//
//Server::Server(char letterName) : name(letterName){}
//
//int Server::getTurn() {  // Since getTurn is static, only static members can be referenced in here
//    turn++;
//    return turn;
//}
//
//bool Server::stillOpen() {
//    return nowOpen;
//}
//
//void Server::serveOne() {
//    if (nowOpen && lastServed < turn) {
//        lastServed++;
//        cout << "Server " << name
//                << " now serving " << lastServed << endl;
//    }
//
//    if (lastServed >= turn) //Everyone served
//        nowOpen = false;
//}