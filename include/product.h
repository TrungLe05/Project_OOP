#ifndef PRODUCT_H
#define PRODUCT_H
#include<iostream>
#include<string>
using namespace std;


class PRODUCT{
    private:
        string idProduct;
        string nameProduct;
        bool statusProduct;
    public:
        PRODUCT();
        PRODUCT(string idProduct, string nameProduct, bool statusProdct);
        string getIdproduct()const;
        string getNameProduct()const;
        bool getStatusProduct();
        void setIdProduct(string idProduct);
        void setNameProduct(string nameProduct);
        void setStatusProduct(bool statusProduct);
        void displayProduct() const;
        ~PRODUCT();
};

#endif