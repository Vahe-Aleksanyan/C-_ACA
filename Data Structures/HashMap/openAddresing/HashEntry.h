//
// Created by Vahe Aleksanyan on 28.03.23.
//

#ifndef OPENADDRESING_HASHENTRY_H
#define OPENADDRESING_HASHENTRY_H

class HashEntry {

private:
    int key;
    int value;
public:

    HashEntry(int key, int value) {
        this->key = key;
        this->value = value;
    }

    int getKey() {
        return key;
    }

    int getValue() {
        return value;
    }

    void setValue(int value) {
        this->value = value;
    }
};


#endif //OPENADDRESING_HASHENTRY_H
