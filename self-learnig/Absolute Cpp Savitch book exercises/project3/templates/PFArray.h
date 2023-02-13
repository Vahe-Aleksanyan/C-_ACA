//
// Created by Vahe Aleksanyan on 16.01.23.
//

#ifndef PROJECT3_PFARRAY_H
#define PROJECT3_PFARRAY_H

namespace PFArraySavitch {
    template <class T>
    class PFArray {
    public:
        PFArray();
        PFArray(int capacityValue);
        PFArray(const PFArray<T>& pfaObject);

        void addElement(const T& element);
        bool full() const;

        int getCapacity() const;
        int getNumberUsed() const;

        void emptyArray();

        T& operator[] (int index);
        PFArray<T>& operator =(const PFArray<T>& rightSide);

        virtual ~PFArray();
    private:
        T *a;
        int capacity;
        int used;
    };
}


#endif //PROJECT3_PFARRAY_H
