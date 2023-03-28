//
// Created by Vahe Aleksanyan on 28.03.23.
//

#ifndef OPENADDRESING_DELETEDENTRY_H
#define OPENADDRESING_DELETEDENTRY_H

#include "HashEntry.h"

class DeletedEntry: public HashEntry {

private:

    static DeletedEntry *entry;

    DeletedEntry() :

            HashEntry(-1, -1) {

    }

public:

    static DeletedEntry *getUniqueDeletedEntry() {

        if (entry == nullptr)

            entry = new DeletedEntry();

        return entry;

    }

};



DeletedEntry *DeletedEntry::entry = nullptr;


#endif //OPENADDRESING_DELETEDENTRY_H
