//
// Created by Vahe Aleksanyan on 03.05.23.
//
#include "iostream"
class subSystem1 {
public :
    std::string operation1() {
        return "doing something in FIRST system";
}
    std::string OperationN() const {
        return "Subsystem1: Go!\n";
    }

};


// Some facades can work with multiple subsystems at the same time.
class subSystem2 {
public:
    std::string operation1() const {
        return "Subsystem2: Get ready!\n";
    }

    std::string operationZ() const {
        return "Subsystem2: Fire!\n";
    }
};

class Facade {
protected:
    subSystem1 * subSystem_1 = nullptr;
    subSystem2 * subSystem_2 = nullptr;
public:
    Facade(
            subSystem1 *subsystem1 = nullptr,
            subSystem2 *subsystem2 = nullptr) {
        this->subSystem_1 = subsystem1 ?: new subSystem1;
        this->subSystem_2 = subsystem2 ?: new subSystem2;
    }

    ~Facade() {
        delete subSystem_1;
        delete subSystem_2;
    }

    std::string Operation() {
        std::string result = "Facade initializes subsystems:\n";
        result += this->subSystem_1->operation1();
        result += this->subSystem_2->operation1();
        result += "Facade orders subsystems to perform the action:\n";
        result += this->subSystem_1->OperationN();
        result += this->subSystem_2->operationZ();
        return result;
    }
};

void slientCode(Facade *facade) {

    std::cout << facade->Operation();
}

int main() {
    subSystem1 *sub1 = new subSystem1();
    subSystem2 *sub2 = new subSystem2();
    Facade * fc = new Facade(sub1, sub2);
    slientCode(fc);
}

