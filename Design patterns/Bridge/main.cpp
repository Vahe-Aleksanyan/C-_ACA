//
// Created by Vahe Aleksanyan on 09.04.23.
//
#include "iostream"
class Implementation {
public:
    virtual ~ Implementation() {}
    virtual std::string operationImplementation() const = 0;
};

//  Each Concrete Implementation corresponds to a specific platform and implements the Implementation interface using that platform's API.

class ConcreteImplementationA : public Implementation {
public:
    std::string operationImplementation() const override {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};

class ConcreteImplementationB : public Implementation {
public:
    std::string operationImplementation() const override {
        return "ConcreteImplementationB: Here's the result on the platform B.\n";
    }
};

// * The Abstraction defines the interface for the "control" part of the two class
// * hierarchies. It maintains a reference to an object of the Implementation
// * hierarchy and delegates all the real work to this object.

class Abstraction {
protected:
    Implementation * anImplementation;
public:
    Abstraction(Implementation *impl) : anImplementation(impl) {}
    virtual ~Abstraction(){}

    virtual std::string operation() const {
        return "Abstraction: Base operation with:\n" + this->anImplementation->operationImplementation();
    }
};

// we can extend the Abstraction without changing the Implementation classes.
class ExtendedAbstraction : public Abstraction {
public:
    ExtendedAbstraction(Implementation* implementation) : Abstraction(implementation) {
    }
    std::string operation() const override {
        return "ExtendedAbstraction: Extended operation with:\n" +
               this->anImplementation->operationImplementation();
    }
};

// * Except for the initialization phase, where an Abstraction object gets linked
// * with a specific Implementation object, the client code should only depend on
// * the Abstraction class. This way the client code can support any abstraction-
// * implementation combination.
void clientCode(const Abstraction& abstraction) {
    std::cout << abstraction.operation();
}

int main() {
    Implementation* implementation = new ConcreteImplementationA;
    Abstraction* abstraction = new Abstraction(implementation);
    clientCode(*abstraction);
    std::cout << std::endl;
    delete implementation;
    delete abstraction;

    implementation = new ConcreteImplementationB;
    abstraction = new ExtendedAbstraction(implementation);
    clientCode(*abstraction);

    delete implementation;
    delete abstraction;

    return 0;
}