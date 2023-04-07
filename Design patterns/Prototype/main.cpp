//
// Created by Vahe Aleksanyan on 07.04.23.
//Lets you copy existing objects without making your code dependent on
// their classes.

#include "iostream"
#include "unordered_map"

using namespace std;
enum Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype {
protected:
    string prototypeName;
    float prototypeField;
public:
    Prototype() {}
    Prototype(string prototypeName):prototypeName(prototypeName) {}

    virtual ~Prototype() {}
    virtual Prototype *clone() const = 0;
    virtual void method(float prototype_field) {
        this->prototypeField = prototype_field;
        std::cout << "Call Method from " << prototypeName << " with field : " << prototype_field << std::endl;
    }
};


class ConcretePrototype_1 : public Prototype {
private:
    float concretePrototypeFiled_1;
public:
    ConcretePrototype_1(string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), concretePrototypeFiled_1(concrete_prototype_field) {}

    Prototype *clone() const override {
        return new ConcretePrototype_1(*this);
    }
};

class ConcretePrototype_2 : public Prototype {
private:
    float concretePrototypeField_2;
public:
    ConcretePrototype_2(string prototype_name, float concrete_prototype_field) : Prototype(prototype_name), concretePrototypeField_2(concrete_prototype_field) {}
    Prototype *clone() const override {
        return new ConcretePrototype_2(*this);
    }
};

class PrototypeFactory {
private: std::unordered_map<Type, Prototype *, std::hash<int> > prototypes_;
public:
    PrototypeFactory(){
        prototypes_[Type::PROTOTYPE_1] = new ConcretePrototype_1("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = new ConcretePrototype_2("PROTOTYPE_2 ", 60.f);
    }

    ~PrototypeFactory() {
        delete prototypes_[Type::PROTOTYPE_1];
        delete prototypes_[Type::PROTOTYPE_2];
    }

    // here the magic happens
    Prototype *createPrototype(Type type) {
        return prototypes_[type]->clone();
    }
};


void client(PrototypeFactory & prototypeFactory) {
    std::cout << "Let's create a Prototype 1\n";

    Prototype *prototype = prototypeFactory.createPrototype(Type::PROTOTYPE_1);
    prototype->method(90);
    delete prototype;

    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";

    prototype = prototypeFactory.createPrototype(Type::PROTOTYPE_2);
    prototype->method(10);

    delete prototype;
}

int main() {
    PrototypeFactory *prototype_factory = new PrototypeFactory();
    client(*prototype_factory);
    delete prototype_factory;

    return 0;
}