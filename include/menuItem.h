#ifndef MENUITEM_H
#define MENUITEM_H
#include"product.h"
#include <iomanip>
#include<iostream>
using namespace std;

class MENUITEM{
    private:
        PRODUCT product;
        double priceForSizeM;
        double priceForSizeL;
        bool isBestSeller;
        bool MorL;
    public:
        MENUITEM();
        MENUITEM(PRODUCT product, double priceForSizeM, double priceForSizeL, bool isBestSeller);
        double getPriceForSizeM();
        double getPriceForSizeL();
        bool getIsBestSeller();
        string getIdProduct();
        string getNameProduct();
        const PRODUCT& getProduct();
        void setPriceForSizeM(double priceForSizeM);
        void setPriceForSizeL(double priceForSizeL);
        void setIsBestSeller(bool isBestSeller);
        void displayMenuItems()const;
        bool getSizeMorSizeL()const;
        ~ MENUITEM();
};

#endif