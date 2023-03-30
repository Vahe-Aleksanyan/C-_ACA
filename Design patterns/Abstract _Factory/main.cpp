//
// Created by Vahe Aleksanyan on 28.03.23.
//
#include "iostream"


/**
 * Each distinct product of a product family should have a base interface. All
 * variants of the product must implement this interface.
 */
class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual std::string UsefulFunctionA() const = 0; // will not modify the code inside class
};

/**
 * Concrete Products are created by corresponding Concrete Factories based on family.
 */
 class ConcreteProductA1 : public AbstractProductA {
 public:
     std::string UsefulFunctionA() const override {
         return "The output of the product A1.";
     }
 };

 class ConcreteProductA2 : public AbstractProductA {
     std::string UsefulFunctionA() const override {
         return "The result of the product A2.";
     }
 };


/**
* Here's the the base interface of another product. All products can interact
* with each other, but proper interaction is possible only between products of
* the same concrete variant.
*/
class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};


class ConcreteProductB2 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }

    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};



/**
 * The Abstract Factory interface declares a set of methods that return
 * different abstract products. These products are called a family and are
 * related by a high-level theme or concept. Products of one family are usually
 * able to collaborate among themselves. A family of products may have several
 * variants, but the products of one variant are incompatible with products of
 * another.
 */
class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

/**
 * Concrete Factories produce a family of products that belong to a single
 * variant. The factory guarantees that resulting products are compatible. Note
 * that signatures of the Concrete Factory's methods return an abstract product,
 * while inside the method a concrete product is instantiated.
 */
class ConcreteFactory1: public AbstractFactory {
public:
    AbstractProductA *CreateProductA () const override {
        return new ConcreteProductA1;
    }

    AbstractProductB *CreateProductB () const override {
        return new ConcreteProductB1;
    }
};

/**
 * Each Concrete Factory has a corresponding product variant.
 */
class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB2();
    }
};


void client(const AbstractFactory & factory) {
    const AbstractProductA * prA = factory.CreateProductA();
    const AbstractProductB * prB = factory.CreateProductB();
    std::cout << prA->UsefulFunctionA();
    delete prA;
    delete prB;
}

int main() {
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    client(*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    client(*f2);
    delete f2;
    return 0;
}