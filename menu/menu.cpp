#include"menu.h"


MENU::MENU(){
}
// khởi tạo một menu có sẵn
void MENU::initialMenuList(){
    menuList.push_back(MENUITEM(PRODUCT("001", "Espresso", true), 30000, 35000, false));
    menuList.push_back(MENUITEM(PRODUCT("002", "Latte Coffee", true), 40000, 45000, true));
    menuList.push_back(MENUITEM(PRODUCT("003", "Cappuccino", true), 45000, 50000, false));
    menuList.push_back(MENUITEM(PRODUCT("004", "Tra sua socola", true), 50000, 55000, true));
    menuList.push_back(MENUITEM(PRODUCT("005", "Tra sua dao", true), 35000, 40000, true));
    menuList.push_back(MENUITEM(PRODUCT("006", "Tra dao cam xa", true), 30000, 35000, false));
    menuList.push_back(MENUITEM(PRODUCT("007", "Matcha nong", true), 40000, 45000, true));
    menuList.push_back(MENUITEM(PRODUCT("008", "Nuoc cam", true), 30000, 35000, false));
    menuList.push_back(MENUITEM(PRODUCT("009", "Ep dua hau", true), 30000, 35000, false));
    menuList.push_back(MENUITEM(PRODUCT("010", "Sinh to xoai", true), 35000, 40000, true));
    menuList.push_back(MENUITEM(PRODUCT("011", "banh sung bo", true), 20000, 25000, false));
    menuList.push_back(MENUITEM(PRODUCT("012", "Banh mouse", true), 30000, 35000, true));
    menuList.push_back(MENUITEM(PRODUCT("013", "banh tiramisu", true), 40000, 45000, true));
    menuList.push_back(MENUITEM(PRODUCT("014", "Dua luoi", true), 25000, 30000, false));
    menuList.push_back(MENUITEM(PRODUCT("015", "Ga vien chien", true), 30000, 35000, true));
    menuList.push_back(MENUITEM(PRODUCT("016", "Bac xiu da", true), 20000, 25000, true));
    menuList.push_back(MENUITEM(PRODUCT("017", "Socola da xay", true), 33000, 38000, true));
    menuList.push_back(MENUITEM(PRODUCT("018", "Americano", true), 35000, 40000, true));
    menuList.push_back(MENUITEM(PRODUCT("019", "Matcha da xay", true), 33000, 38000, true));
    menuList.push_back(MENUITEM(PRODUCT("020", "Tra sa tac", true), 30000, 35000, true));
}
MENU::MENU(string menuName){
    this->menuName = menuName = "Main menu";
    initialMenuList();
}
void MENU::addItem(const PRODUCT &product, double priceForSizeM, double priceForSizeL, bool isBestSeller){
    MENUITEM newItem (product, priceForSizeM, priceForSizeL, isBestSeller);
    menuList.push_back(newItem);
}

void MENU::additemInMenuListFromInput(){
    string id, name;
    double priceForSizeM, priceForSizeL;
    bool status, isBestSeller;
    cout << "Enter product ID: "; getline(cin, id);
    cout << "Enter product name: "; getline(cin , name);
    cout << "Enter product price for size M: "; cin >> priceForSizeM;
    cout << "Enter product price for size L: "; cin >> priceForSizeL;
    cout << "Enter product status (1: in stock/ 0: out of stock): "; cin >> status;
    PRODUCT product(id, name, status);
    MENUITEM newItem (product, priceForSizeM, priceForSizeL, isBestSeller);
    menuList.push_back(newItem);
    cout << "Product added successfully!" << endl;
}

MENUITEM* MENU::findItemInMenuListById(string id){
    for(auto &item : menuList){
        if(item.getIdProduct() == id){
            item.displayMenuItems();
            return &item;
        }
    }
    cout << " The product you are looking for does not exist!" << endl;
    return nullptr;
}
void MENU::displayMenu()const{
    for (const MENUITEM& displayItem : menuList){
        displayItem.displayMenuItems();
    }
}
bool MENU::updatePrice(string id, char size, double newPrice){
    MENUITEM* item = findItemInMenuListById(id);
    if(item != nullptr){
        if(toupper(size) == 'M'){
            item->setPriceForSizeM(newPrice);
            return true;
        }
        else if(toupper(size) == 'L'){
            item->setPriceForSizeL(newPrice);
            return true;
        }
    }
    return false;
}

vector<MENUITEM> MENU::getBestSellerItems(){
    vector<MENUITEM> bestSeller;
    for (MENUITEM& item : menuList){
        if(item.getIsBestSeller()){
            bestSeller.push_back(item);
        }
    }
    return bestSeller;
}

vector<MENUITEM> MENU::getMenuList(){
    return menuList;
}

MENU::~MENU(){
    for (auto it = menuList.begin(); it != menuList.end(); it++){
        menuList.erase(it);
    }
}