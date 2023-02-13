//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_SALE_H
#define PROJECT3_SALE_H


namespace SavitchSale {
    class Sale {
    public:
        Sale();
        Sale(double thePrice);

        double getPrice() const;
        void setPrice(double newPrice);

        virtual double bill() const; // notice here virtual function!!!
        double savings(const Sale& other) const;
    private:
        double price;
    };

    bool operator < (const Sale& first, const Sale& second);
}


#endif //PROJECT3_SALE_H
