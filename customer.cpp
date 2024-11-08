#include"customer.h"


CUSTOMER::CUSTOMER(){}
//phương thức order món cho khách hàng
void CUSTOMER::orderItems(MENU &menu){
    string id;
    char sizeOption;
    int quantity;
    cout << "\nPlease select item by product code " << endl;
    cout << "If you do not order anything else, please select 0 to finish.!" << endl;
    while(true){
        cout << "Enter product ID: "; cin >> id;
        if(id == "0") break;
        for (auto &menuItem : menu.getMenuList()) {
            if (menuItem.getProduct().getIdproduct() == id) {
                cout << "Select quantity: ";
                cin >> quantity;
                double price = menuItem.getPriceForSizeM();
                cout << "Select size (M: Medium, L: Large): ";
                do{
                    cin >> sizeOption;
                    if(sizeOption!='M' || sizeOption!='m' || sizeOption != 'L' || sizeOption != 'l') {
                        cout << "Invalid size!";
                        break;
                    }
                }while(sizeOption!='M' || sizeOption!='m' || sizeOption != 'L' || sizeOption != 'l');
                if (sizeOption == 'M' || sizeOption == 'm') {
                    price = menuItem.getPriceForSizeL();
                } else if (sizeOption == 'L' || sizeOption == 'l') {
                    price = menuItem.getPriceForSizeL(); 
                }
                orderList.push_back(make_pair(menuItem, quantity));
                cout << "Added " << menuItem.getProduct().getNameProduct() << "on order." << endl;
                break;
            }
        }
    }
}
// phương thức thanh toán cho khách hàng
void CUSTOMER::checkout(int &id,const string &paymentMethod){
    TRANSACTION transaction(id,paymentMethod);
    for (auto &item : orderList) {
        MENUITEM menuItems = item.first;
        int quantity = item.second;
        transaction.addItem(menuItems.getPriceForSizeM(), quantity);  
    }
    // thanh toán ngay sau khi khách hàng order xong
    transaction.calculateOrder();
    transaction.displayTransactionDetails();
}