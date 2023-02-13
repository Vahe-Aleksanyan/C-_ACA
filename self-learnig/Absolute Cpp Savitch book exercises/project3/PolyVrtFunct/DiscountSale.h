//
// Created by Vahe Aleksanyan on 15.01.23.
//

#ifndef PROJECT3_DISCOUNTSALE_H
#define PROJECT3_DISCOUNTSALE_H

#include "Sale.h"

namespace SavitchSale {
    class DiscountSale : public Sale {
    public:
        DiscountSale( );
        DiscountSale(double thePrice, double theDiscount);


        double getDiscount( ) const;
        void setDiscount(double newDiscount);
        virtual double bill( ) const override; // note that this is a virtual funciton defined in the class Sale, if not specified here it will be automatically be virtual

    private:
        double discount;
    };
}


#endif //PROJECT3_DISCOUNTSALE_H
