//
// Created by Vahe Aleksanyan on 09.04.23.
//

// In C++ the Adapter pattern can be implemented using multiple inheritance.
#include "iostream"

class Target {
public:
    virtual ~Target() = default;

    virtual std::string request() const {
        return "Target: The default target's behavior.";
    }
};

class Adaptee {
public:
    std::string specificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// The Adapter makes the Adaptee's interface compatible with the Target's interface using multiple inheritance.

class Adapter : public Target, public Adaptee {
public:
    Adapter() {}

    std::string request() const override {
        std::string to_reverse = specificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    };
};


void ClientCode(const Target *target) {
    std::cout << target->request();
}

int main() {
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target *target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee *adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->specificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter *adapter = new Adapter;
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

    return 0;
}