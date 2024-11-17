#include"customer.h"


CUSTOMER::CUSTOMER(){}
//phương thức order món cho khách hàng
void CUSTOMER::orderItems(MENU &menu) {
    string id;
    char sizeOption;
    int quantity;
    cout << "\nPlease select item by product code " << endl;
    cout << "\033[31m" << "Note: If you do not order anything else, please select 0 to finish!" << "\033[0m" << endl;

    while (true) {
        cout << "Enter product ID: "; 
        cin >> id;
        if (id == "0") break;

        bool validProduct = false;
        for (auto &menuItem : menu.getMenuList()) {
            if (menuItem.getProduct().getIdproduct() == id) {
                validProduct = true;
                
                while (true) {
                    cout << "Select quantity: ";
                    cin >> quantity;
                    if (cin.fail() || quantity <= 0) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\033[31m" << "Invalid input! Please enter a valid quantity as a number." << "\033[0m" << endl;
                    } else {
                        break;
                    }
                }

                double price = menuItem.getPriceForSizeM();
                
                while (true) {
                    cout << "Select size (M: Medium, L: Large): ";
                    cin >> sizeOption;
                    if (sizeOption == 'M' || sizeOption == 'm' || sizeOption == 'L' || sizeOption == 'l') {
                        if (sizeOption == 'M' || sizeOption == 'm') {
                            price = menuItem.getPriceForSizeM();
                        } else if (sizeOption == 'L' || sizeOption == 'l') {
                            price = menuItem.getPriceForSizeL();
                        }
                        orderList.push_back(make_pair(menuItem, quantity));
                        cout << "\033[32m" << "Added " << menuItem.getProduct().getNameProduct() << " to order." << "\033[0m" << endl;
                        break;
                    } else {
                        cout << "\033[31m" << "Invalid size! Please enter again (M or L): " << "\033[0m" << endl;
                        cin.clear();  // Xóa trạng thái lỗi nếu có
                        cin.ignore(1000, '\n');  // Bỏ qua ký tự thừa trong bộ đệm
                    }
                }
                break;
            }
        }

        if (!validProduct) {
            cout << "\033[31m" << "Invalid product ID! Please enter a valid product ID." << "\033[0m" << endl;
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