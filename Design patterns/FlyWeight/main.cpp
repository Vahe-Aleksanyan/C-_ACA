//
// Created by Vahe Aleksanyan on 03.05.23.
//
#include "iostream"
#include <unordered_map>
#include <initializer_list>
#include <vector>

struct SharedState {
    std::string brand;
    std::string model;
    std::string color;
    SharedState(const std::string &brand, const std::string &model, const std::string &color)
            : brand(brand), model(model), color(color)
    {
    }

    friend std::ostream &operator<<(std::ostream &os, const SharedState &ss) {
        return os << "[ " << ss.brand << " , " << ss.model << " , " << ss.color << " ]";
    }
};

struct UniqueState {
    std::string owner;
    std::string plates;
    UniqueState(const std::string &owner, const std::string &plates)
            : owner(owner), plates(plates) {}

            friend std::ostream &operator << (std::ostream &os, const UniqueState &us) {
                return os << "[ " << us.owner << " , " << us.plates << " ]";
    }
};


// * The Flyweight stores a common portion of the state (also called intrinsic
// * state) that belongs to multiple real business entities. The Flyweight accepts
// * the rest of the state (extrinsic state, unique for each entity) via its
// * method parameters.
class Flyweight {
private:
    SharedState *st;

public:
    Flyweight(const SharedState* st): st(new SharedState(*st)) {}

    Flyweight(const Flyweight  &other) : st(new SharedState(*other.st)) {}
    ~Flyweight() {
        delete st;
    }

    SharedState *shared_state() const
    {
        return st;
    }
    void Operation(const UniqueState &unique_state) const
    {
        std::cout << "Flyweight: Displaying shared (" << *st << ") and unique (" << unique_state << ") state.\n";
    }
};


//  * The Flyweight Factory creates and manages the Flyweight objects. It ensures
// * that flyweights are shared correctly. When the client requests a flyweight,
// * the factory either returns an existing instance or creates a new one, if it
// * doesn't exist yet.

class FlyWeightFactory {
private:
    std::unordered_map<std::string, Flyweight> flyweights_;
    std::string getKey(const SharedState &ss ) const {
        return ss.brand + "_" + ss.model + "_" + ss.color;
    }
public:
    FlyWeightFactory(std::initializer_list<SharedState> share_states)
    {
        for (const SharedState &ss : share_states)
        {
            this->flyweights_.insert(std::make_pair(std::string(this->getKey(ss)), Flyweight(&ss)));

        }
    }
//    Returns an existing Flyweight with a given state or creates a new one.
    Flyweight GetFlyweight(const SharedState &shared_state)
    {
        std::string key = this->getKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
            this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
        }
        else
        {
            std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return this->flyweights_.at(key);
    }

    void ListFlyweights() const
    {
        size_t count = this->flyweights_.size();
        std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
        for (std::pair<std::string, Flyweight> pair : this->flyweights_)
        {
            std::cout << pair.first << "\n";
        }
    }
};

void AddCarToPoliceDatabase(
        FlyWeightFactory &ff, const std::string &plates, const std::string &owner,
        const std::string &brand, const std::string &model, const std::string &color)
{
    std::cout << "\nClient: Adding a car to database.\n";
    const Flyweight &flyweight = ff.GetFlyweight({brand, model, color});
    // The client code either stores or calculates extrinsic state and passes it
    // to the flyweight's methods.
    flyweight.Operation({owner, plates});
}


int main()
{
    FlyWeightFactory *factory = new FlyWeightFactory({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
    factory->ListFlyweights();

    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "James Doe",
                           "BMW",
                           "M5",
                           "red");

    AddCarToPoliceDatabase(*factory,
                           "CL234IR",
                           "James Doe",
                           "BMW",
                           "X1",
                           "red");
    factory->ListFlyweights();
    delete factory;

    return 0;
}