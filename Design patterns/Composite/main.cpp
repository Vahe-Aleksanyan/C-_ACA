//
// Created by Vahe Aleksanyan on 09.04.23.
//

// The base Component class declares common operations for both simple and
// * complex objects of a composition.
#include "iostream"
#include "list"
class Component {
protected:
    Component *parent;
public:
    virtual ~Component(){}
    void setParent(Component *parent) {
        this->parent = parent;
    }
    Component *getParent() const {
        return this->parent;
    }

    virtual void add(Component *component) {}
    virtual void remove(Component *component) {}
    virtual bool isComposite() const {
        return false;
    }
    virtual std::string operation() const = 0;
};

//  * The Leaf class represents the end objects of a composition. A leaf can't have
// * any children.
// *
// * Usually, it's the Leaf objects that do the actual work, whereas Composite
// * objects only delegate to their sub-components.

class Leaf :public Component {
public:
    std::string operation() const override{
        return "Leaf";
    }
};

//  * The Composite class represents the complex components that may have children.
// * Usually, the Composite objects delegate the actual work to their children and
// * then "sum-up" the result.

class Composite : public Component {
protected:
    std::list<Component *> children;
public:
    void add(Component * comp) override {
        this->children.push_back(comp);
        comp->setParent(this);
    }
    void remove(Component *component) override {
        children.remove(component);
        component->setParent(nullptr);
    }

    bool isComposite() const override {
        return true;
};

    std::string operation() const override {
        std::string result;
        for (const Component *c : children) {
            if (c == children.back()) {
                result += c->operation();
            } else {
                result += c->operation() + "+";
            }
        }
        return "Branch(" + result + ")";
    }
};


//* The client code works with all of the components via the base interface.
void clientCode(Component *component) {
    std::cout << "RESULT: " << component->operation();
}

void ClientCode2(Component *component1, Component *component2) {
    if (component1->isComposite()) {
        component1->add(component2);
    }
    std::cout << "RESULT: " << component1->operation();
}

int main() {
    Component *simple = new Leaf;
    std::cout << "Client: I've got a simple component:\n";
    clientCode(simple);
    std::cout << "\n\n";

    Component *tree = new Composite;
    Component *branch1 = new Composite;

    Component *leaf_1 = new Leaf;
    Component *leaf_2 = new Leaf;
    Component *leaf_3 = new Leaf;
    branch1->add(leaf_1);
    branch1->add(leaf_2);
    Component *branch2 = new Composite;
    branch2->add(leaf_3);
    tree->add(branch1);
    tree->add(branch2);
    std::cout << "Client: Now I've got a composite tree:\n";
    clientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    ClientCode2(tree, simple);
    std::cout << "\n";

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    return 0;
}