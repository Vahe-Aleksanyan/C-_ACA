//
// Created by Vahe Aleksanyan on 28.03.23.
//

#ifndef OPENADDRESING_HASHMAP_H
#define OPENADDRESING_HASHMAP_H


#include "HashEntry.h"
#include "DeletedEntry.h"

const int TABLE_SIZE = 128;


class HashMap {

private:

    HashEntry **table;

public:

    HashMap() {

        table = new HashEntry *[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++)

            table[i] = nullptr;

    }


    int get(int key) {

        int hash = (key % TABLE_SIZE);

        int initialHash = -1;

        while (hash != initialHash && (table[hash]

                                       == DeletedEntry::getUniqueDeletedEntry() || table[hash] != nullptr

                                                                                   && table[hash]->getKey() != key)) {

            if (initialHash == -1)

                initialHash = hash;

            hash = (hash + 1) % TABLE_SIZE;

        }

        if (table[hash] == nullptr || hash == initialHash)

            return -1;

        else

            return table[hash]->getValue();

    }


    void put(int key, int value) {

        int hash = (key % TABLE_SIZE);

        int initialHash = -1;

        int indexOfDeletedEntry = -1;

        while (hash != initialHash && (table[hash]

                                       == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL

                                                                                   && table[hash]->getKey() != key)) {

            if (initialHash == -1)

                initialHash = hash;

            if (table[hash] == DeletedEntry::getUniqueDeletedEntry())

                indexOfDeletedEntry = hash;

            hash = (hash + 1) % TABLE_SIZE;

        }

        if ((table[hash] == nullptr || hash == initialHash) && indexOfDeletedEntry

                                                               != -1)

            table[indexOfDeletedEntry] = new HashEntry(key, value);

        else if (initialHash != hash)

            if (table[hash] != DeletedEntry::getUniqueDeletedEntry()

                && table[hash] != nullptr && table[hash]->getKey() == key)

                table[hash]->setValue(value);

            else

                table[hash] = new HashEntry(key, value);

    }


    void remove(int key) {

        int hash = (key % TABLE_SIZE);

        int initialHash = -1;

        while (hash != initialHash && (table[hash]

                                       == DeletedEntry::getUniqueDeletedEntry() || table[hash] != NULL

                                                                                   && table[hash]->getKey() != key)) {

            if (initialHash == -1)

                initialHash = hash;

            hash = (hash + 1) % TABLE_SIZE;

        }

        if (hash != initialHash && table[hash] != nullptr) {

            delete table[hash];

            table[hash] = DeletedEntry::getUniqueDeletedEntry();

        }

    }


    ~HashMap() {

        for (int i = 0; i < TABLE_SIZE; i++)

            if (table[i] != nullptr && table[i]

                                       != DeletedEntry::getUniqueDeletedEntry())

                delete table[i];

        delete[] table;

    }

};

#endif //OPENADDRESING_HASHMAP_H
