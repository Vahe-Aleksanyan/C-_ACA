//
// Created by Vahe Aleksanyan on 01.04.23.
//

//Use the Builder pattern to get rid of a “telescoping constructor”.

// Use the Builder pattern when you want your code to be able to create
// different representations of some product (for example, stone and wooden houses)

// Use the Builder to construct Composite trees or other complex objects.

#include "iostream"
#include <vector>
//using namespace std;

class Product1{
public:
    std::vector<std::string> parts_;
    void listParts()const{
        std::cout << "Product parts: ";
        for (size_t i=0;i<parts_.size();i++){
            if(parts_[i]== parts_.back()){
                std::cout << parts_[i];
            }else{
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

/**
 * The Builder interface specifies methods for creating the different parts of
 * the Product objects.
 */


class Builder {
public:
    virtual ~ Builder() {}
    virtual void producePartA() const = 0;
    virtual void producePartB() const = 0;
    virtual void producePartC() const = 0;
};


/**
 * The Concrete Builder classes follow the Builder interface and provide
 * specific implementations of the building steps. Your program may have several
 * variations of Builders, implemented differently.
 */


class concreteBuilder1: public Builder {
private:
    Product1* product;
public:
    concreteBuilder1() {
        this->reset();
    }
    ~concreteBuilder1() {
        delete product;
    }

    void reset() {
        this->product = new Product1();
    }

    void producePartA() const override {
        this->product->parts_.push_back("part A1");
    }

    void producePartB()const override{
        this->product->parts_.push_back("Part B1");
    }

    void producePartC()const override{
        this->product->parts_.push_back("Part C1");
    }

    Product1* getProduct() {
        Product1* result = this->product;
        this->reset();
        return result;
    }
};

/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration.
 * */

class Director {
private:
    Builder* builder;
public:
    void setBuilder(Builder* builder) {
        this->builder = builder;
    }

    void buildMinimalViableProduct(){
        this->builder->producePartA();
    }

    void buildFullProduct() {
        this->builder->producePartA();
        this->builder->producePartB();
        this->builder->producePartC();
    }
};

/**
 * The client code creates a builder object, passes it to the director and then
 * initiates the construction process. The end result is retrieved from the
 * builder object.
 */

void clientCode(Director& director) {
    concreteBuilder1* builder = new concreteBuilder1();
    director.setBuilder(builder);
    std::cout << "just created ordinary product\n";
    director.buildMinimalViableProduct();

    Product1* p = builder->getProduct();
    p->listParts();
    delete p;

    std::cout << "creating full product\n";
    director.buildFullProduct();

    p = builder->getProduct();
    p->listParts();
    delete p;

    delete builder;
}

int main() {
    Director* director = new Director();
    clientCode(*director);
    delete director;
    return 0;
}