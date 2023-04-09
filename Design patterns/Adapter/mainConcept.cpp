//
// Created by Vahe Aleksanyan on 09.04.23.
//This example illustrates the structure of the Adapter design pattern. It focuses on answering these questions:
//
//What classes does it consist of?
//What roles do these classes play?
//In what way the elements of the pattern are related?
#include "iostream"


//  * The Target defines the domain-specific interface used by the client code.
class Target {
public:
    virtual ~ Target() = default; // A default constructor is a constructor that either has no parameters, or if it has parameters, all the parameters have default values

    virtual std::string request() const {
        return "Target: The default target's behavior.";
    }

};


//  The Adaptee needs some adaptation before the client code can use it.

class Adaptee {
public:
    std::string specialRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};


// The Adapter makes the Adaptee's interface compatible with the Target's interface.
class Adapter : public Target {
private:
    Adaptee *adaptee_;
public:
    Adapter(Adaptee *adaptee) :adaptee_(adaptee) {}
    std::string request() const override {
        std::string toReverse = this->adaptee_->specialRequest();
        std::reverse(toReverse.begin(), toReverse.end());
        return "Adapter: (TRANSLATED) " + toReverse;
    }
};

// The client code supports all classes that follow the Target interface.

void clientCode(const Target *target) {
    std::cout << target->request();
}

int main() {
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    clientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->specialRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter = new Adapter(adaptee);
    clientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}