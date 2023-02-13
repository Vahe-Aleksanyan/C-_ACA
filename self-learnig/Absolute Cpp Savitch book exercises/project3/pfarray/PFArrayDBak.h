//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_PFARRAYDBAK_H
#define PROJECT3_PFARRAYDBAK_H
#include "PFArrayD.h"

class PFArrayDBak: public PFArrayD {
public:
    PFArrayDBak();
    PFArrayDBak(int capacityValue);
    PFArrayDBak(const PFArrayDBak& Object);

    void backup();
    void restore();

    PFArrayDBak& operator =(const PFArrayDBak& rightSide);

    ~PFArrayDBak();
private:
    double *b;
    int usedB;
};



#endif //PROJECT3_PFARRAYDBAK_H
