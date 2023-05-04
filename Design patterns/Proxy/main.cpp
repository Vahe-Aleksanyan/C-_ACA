//
// Created by Vahe Aleksanyan on 04.05.23.
//
#include "iostream"
class Subject {
public:
    virtual void Request() const = 0;
};

class RealSubject: public Subject {
public:
    void Request() const override {
        std::cout << "RealSubject: Handling request.\n";
    }
};

class Proxy : public Subject {
private:
    RealSubject * realSbj;
    bool checkAccess() const {
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }

    void LogAccess() const {
        std::cout << "Proxy: Logging the time of request.\n";
    }
public:
    Proxy(RealSubject *realSbj) : realSbj(new RealSubject(*realSbj)) {}
    ~Proxy() { delete realSbj;}

    void Request() const override {
        if(this->checkAccess()) {
            this->realSbj->Request();
            this->LogAccess();
        }
    }


};


void ClientCode(const Subject &subject) {
    // ...
    subject.Request();
    // ...
}

int main() {
    std::cout << "Client: Executing the client code with a real subject:\n";
    RealSubject *real_subject = new RealSubject;
    ClientCode(*real_subject);
    std::cout << "\n";
    std::cout << "Client: Executing the same client code with a proxy:\n";
    Proxy *proxy = new Proxy(real_subject);
    ClientCode(*proxy);

    delete real_subject;
    delete proxy;
    return 0;
}