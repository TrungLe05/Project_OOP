#include"menuItem.h"


MENUITEM::MENUITEM(){
    priceForSizeM = 0.0;
    priceForSizeL = 0.0;
    isBestSeller = false;
}

MENUITEM::MENUITEM(PRODUCT product, double priceForSizeM, double priceForSizeL, bool isBestSeller){
    this->product = product;
    this->priceForSizeM = priceForSizeM;
    this->priceForSizeL = priceForSizeL;
    this->isBestSeller = isBestSeller = false;
}

double MENUITEM::getPriceForSizeM(){
    return priceForSizeM;
}
double MENUITEM::getPriceForSizeL(){
    return priceForSizeL;
}
bool MENUITEM::getIsBestSeller(){
    return isBestSeller;
}
string MENUITEM::getIdProduct(){
    return product.getIdproduct();
}
string MENUITEM::getNameProduct(){
    return product.getNameProduct();
}
const PRODUCT& MENUITEM::getProduct(){
    return product;
}
void MENUITEM::setPriceForSizeM(double priceForSizeM){
    this->priceForSizeM = priceForSizeM;
}
void MENUITEM::setPriceForSizeL(double priceForSizeL){
    this->priceForSizeL = priceForSizeL;
}
void MENUITEM::setIsBestSeller(bool isBestSeller){
    this->isBestSeller = isBestSeller;
}
void MENUITEM::displayMenuItems() const {
    // Decorative header for the menu item table
    cout << "\n+================== MENU ITEM ==================+\n";

    product.displayProduct(); 

    cout << "+-----------------------------------------------+\n";
    cout << "|     Size     |       Price                    |\n";
    cout << "+-----------------------------------------------+\n";
    cout << "|     M        | " << setw(10) << fixed << setprecision(0) << priceForSizeM << " d                   |\n";
    cout << "|     L        | " << setw(10) << fixed << setprecision(0) << priceForSizeL << " d                   |\n";

    if (isBestSeller) {
        cout << "|              BESTSELLER ITEM               |\n";
        cout << "+-----------------------------------------------+\n";
    }

    cout << "+===============================================+\n\n";
}

bool MENUITEM::getSizeMorSizeL()const{
    return this->MorL;
}
MENUITEM::~ MENUITEM(){}
