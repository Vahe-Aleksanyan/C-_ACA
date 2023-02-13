////
//// Created by Vahe Aleksanyan on 16.01.23.
////
//#include <string>
//#include <iostream>
//
//using std::string;
//using std::cout;
//using std::endl;
//
//class Pet {
//public:
//    string name;
//    virtual void print() const;
//};
//
//class Dog: public Pet {
//public:
//    string breed;
//    virtual void print() const;
//};
//
//int main() {
//    Dog vdog;
//    Pet vpet;
//
//    vdog.name = "Tiny";
//    vdog.breed = "Great Dane";
//
//    vpet = vdog; // here occurs slicing problem, child`s field breed is lost
//
//    cout << "The slicing problem: " << endl;
//    vpet.print();
//
//    cout << "Note that it was print from Pet that was invoked." << endl;
//
//    cout << "The slicing problem defeated: " << endl;
//    Pet *ppet; // use pointers - dynamic variable
//    Dog *pdog;
//
//    pdog = new Dog;
//    pdog->name = "Tiny";  // The Arrow(->) operator exists to access the members of the structure or the unions using pointers.
//    pdog->breed = "Great Dane";
//
//    ppet = pdog;
//    // virtual
//    ppet->print();
//    pdog->print();
//
//    //The following, which accesses member variables directly
//    //rather than via virtual functions, would produce an error:
//    //cout << "name: " << ppet->name << " breed: "
//    // << ppet->breed << endl;
//    //It generates an error message saying
//    //class Pet has no member named breed.
//
//    return 0;
//}
//
//void Dog::print() const {
//    cout << "name: " << name << endl;
//    cout << "breed: " << breed << endl;
//}
//
//void Pet::print() const {
//    cout << "name: " << name << endl;
//}
