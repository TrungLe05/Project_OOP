#include"product.h"


PRODUCT::PRODUCT(){
    idProduct = " ";
    nameProduct = " ";
    statusProduct = true;
}

PRODUCT::PRODUCT(string idProduct, string nameProduct, bool statusProdct){
    this->idProduct = idProduct;
    this->nameProduct = nameProduct;
    this->statusProduct = statusProduct = true;
}

string PRODUCT::getIdproduct()const{
    return idProduct;
}
string PRODUCT::getNameProduct()const{
    return nameProduct;
}
bool PRODUCT::getStatusProduct(){
    return statusProduct;
}
void PRODUCT::setIdProduct(string idProduct){
    this->idProduct = idProduct;
}
void PRODUCT::setNameProduct(string nameProduct){
    this->nameProduct = nameProduct;
}
void PRODUCT::setStatusProduct(bool statusProduct){
    this->statusProduct = statusProduct;
}
void PRODUCT::displayProduct() const{
    cout << "| ID:\t\t Name:\t\t Status:  \t|" << endl;
    cout << "| " << idProduct << "\t\t " << nameProduct << "\t " << (statusProduct == 1 ? "In Stock" : "Out of Stock") << "  \t|" << endl;
    // phần status 1: có nghĩa là còn hàng và 0: có nghĩa là hết hàng
}


PRODUCT::~PRODUCT(){}
