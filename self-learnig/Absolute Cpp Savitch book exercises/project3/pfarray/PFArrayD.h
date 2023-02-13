//
// Created by Vahe Aleksanyan on 15.01.23.
//partially filled arrays of doubles.
//

#ifndef PROJECT3_PFARRAYD_H
#define PROJECT3_PFARRAYD_H


class PFArrayD {
public:
    PFArrayD();
    PFArrayD(int capacityValue);
    PFArrayD(const PFArrayD& pfaObject);

    void addElement(double element);

    bool full() const;

    int getCapacity() const;
    int getNumberUsed() const;

    void emptyArray();

    double& operator[] (int index);
    PFArrayD& operator=(const PFArrayD& rightSide);

    ~PFArrayD();
protected:
    double *a;
    int capacity;
    int used;
};


#endif //PROJECT3_PFARRAYD_H
