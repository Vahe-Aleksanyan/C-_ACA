//
// Created by Vahe Aleksanyan on 16.01.23.
//

#ifndef PROJECT3_PFARRAYBAK_H
#define PROJECT3_PFARRAYBAK_H

#include "PFArray.h"

namespace PFArraySavitch {
    template <class T>
    class PFArrayBak: public PFArray<T> {
    public:
        PFArrayBak();
        PFArrayBak(int capacityValue);
        PFArrayBak(const PFArrayBak<T>& Object);

        void backup();
        void restore();

        PFArrayBak<T>& operator =(const PFArrayBak<T>& rightSide);
        virtual ~PFArrayBak();
    private:
        T *b;
        int usedB;
    };
}

#endif //PROJECT3_PFARRAYBAK_H
