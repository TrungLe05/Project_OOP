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
    while(true){
    cout << "Enter product name: "; getline(cin , name);
     if (!name.empty() && all_of(name.begin(), name.end(), [](char c) { return isalpha(c) || isspace(c); })) {
            break;
        } else {
            cout << "\033[31m" << "Please enter letters only, no special characters or numbers!" << "\033[0m" << endl;
        }
    }
    // kiểm tra giá tiền nhập vào có hợp lệ không (Giá tiền không được là số âm)
    while (true) {
        cout << "Enter product price for size M: ";
        if (cin >> priceForSizeM ) { 
        if (priceForSizeM > 0) {
        break; 
        } else {
        cout << "\033[31m" << "Invalid price! Please enter a positive number." << "\033[0m" << endl;
        }
        } else {
        cout << "\033[31m" << "Invalid input! Please enter a numeric value." << "\033[0m" << endl;
        cin.clear();               
        }
        cin.ignore(1000, '\n');        
        }
         while (true) {
        cout << "Enter product price for size L: ";
        if (cin >> priceForSizeL ) { 
        if (priceForSizeL > 0) {
        break; 
        } else {
        cout << "\033[31m" << "Invalid price! Please enter a positive number." << "\033[0m" << endl;
        }
        } else {
        cout << "\033[31m" << "Invalid input! Please enter a numeric value." << "\033[0m" << endl;
        cin.clear();               
        }
        cin.ignore(1000, '\n');        
        }
        isBestSeller = status = 1;
    PRODUCT product(id, name, status);
    MENUITEM newItem (product, priceForSizeM, priceForSizeL, isBestSeller);
    menuList.push_back(newItem);
    cout << "\033[32m" << "Product added successfully!" <<"\033[0m" << endl;
}

MENUITEM* MENU::findItemInMenuListById(string id){
    for(auto &item : menuList){
        if(item.getIdProduct() == id){
            item.displayMenuItems();
            return &item;
        }
    }
    cout <<  "\033[31m" << "The product you are looking for does not exist!" <<  "\033[0m" << endl;
    return nullptr;
}
void MENU::displayMenu()const{   
 int count = 0;
for (const MENUITEM& displayItem : menuList) {
    displayItem.displayMenuItems();
    count++;

    if (count % 10 == 0) {
        std::cout << "\t";  // Chuyển sang cột ngang sau mỗi 10 mục
    } else {
        std::cout << " ";   // Thêm khoảng trắng giữa các mục
    }
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