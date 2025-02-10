#include"customer.h"


CUSTOMER::CUSTOMER(){}
//phương thức order món cho khách hàng
void CUSTOMER::orderItems(MENU &menu) {
    string id;
    char sizeOption;
    int quantity;
    cout << "\nPlease select item by product ID " << endl;
    while (true) {
        cout << "Enter product ID: ";
        cin >> id;
        if (id == "0") break;

        bool validProduct = false;
        for (auto &menuItem : menu.getMenuList()) {
            if (menuItem.getProduct().getIdproduct() == id) {
                validProduct = true;

                // Nhập số lượng
                while (true) {
                    cout << "Select quantity: ";
                    cin >> quantity;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\033[31m" << "Invalid input! Please enter a valid quantity as a number." << "\033[0m" << endl;
                    }else if(quantity < 0){
                        cout << "\033[31m" << "Invalid quantity! Please enter a positive number." << "\033[0m" << endl;
                    } 
                    else if(quantity >= 100){
                        cout << "\033[31m" << "Invalid quantity! Please enter a smaller quantity." << "\033[0m" << endl;
                    }
                    else {
                        break;
                    }
                }

                // Nhập kích cỡ
                double price = menuItem.getPriceForSizeM();
                while (true) {
                    cout << "Select size (M: Medium, L: Large): ";
                    cin >> sizeOption;
                    if (sizeOption == 'M' || sizeOption == 'm') {
                        price = menuItem.getPriceForSizeM();
                        break;
                    } else if (sizeOption == 'L' || sizeOption == 'l') {
                        price = menuItem.getPriceForSizeL();
                        break;
                    } else {
                        cout << "\033[31mInvalid size! Please enter again (M or L)\033[0m" << endl;
                        cin.clear();
                        cin.ignore(1000, '\n');
                    }
                }

                // Xác nhận hoặc điều chỉnh đơn hàng
                while (true) {
                    cout << "1. Confirm Order\n";
                    cout << "2. Adjust Order\n";
                    int choice;
                    cout << "Enter selection: ";
                    cin >> choice;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\033[31mInvalid selection!\033[0m" << endl;
                        continue;
                    }
                    
                    if (choice == 1) {
                        orderList.push_back(make_pair(menuItem, quantity));
                        cout << "\033[32mAdded " << menuItem.getProduct().getNameProduct() << " to order.\033[0m" << endl;
                        break;
                    } 
                    else if (choice == 2) {
                        // Cho phép điều chỉnh ID, số lượng hoặc kích cỡ
                        int adjustChoice;
                        cout << "Select the item you want to adjust:\n";
                        cout << "1. ID\n";
                        cout << "2. Quantity\n";
                        cout << "3. Size\n";
                        cout << "Enter selection: ";
                        cin >> adjustChoice;

                        if (adjustChoice == 1) {
                            cout << "Enter new product ID: ";
                            cin >> id;
                            validProduct = false;
                            for (auto &adjustItem : menu.getMenuList()) {
                                if (adjustItem.getProduct().getIdproduct() == id) {
                                    menuItem = adjustItem;
                                    validProduct = true;
                                    break;
                                }
                            }
                            if (!validProduct) {
                                cout << "\033[31mInvalid product ID!\033[0m" << endl;
                            }
                        } 
                        else if (adjustChoice == 2) {
                            while (true) {
                                cout << "Select new quantity: ";
                                cin >> quantity;
                                if (cin.fail() || quantity <= 0) {
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                    cout << "\033[31mInvalid input! Please enter a valid quantity.\033[0m" << endl;
                                } else {
                                    break;
                                }
                            }
                        } 
                        else if (adjustChoice == 3) {
                            while (true) {
                                cout << "Select new size (M: Medium, L: Large): ";
                                cin >> sizeOption;
                                if (sizeOption == 'M' || sizeOption == 'm') {
                                    price = menuItem.getPriceForSizeM();
                                    break;
                                } else if (sizeOption == 'L' || sizeOption == 'l') {
                                    price = menuItem.getPriceForSizeL();
                                    break;
                                } else {
                                    cout << "\033[31mInvalid size! Please enter again (M or L):\033[0m" << endl;
                                    cin.clear();
                                    cin.ignore(1000, '\n');
                                }
                            }
                        }
                    } 
                    else {
                        cout << "\033[31mInvalid selection!\033[0m" << endl;
                    }
                }
                char continueOrdering;
                while (true) {
                    cout << "Would you like to order another item? (Y/N): ";
                    cin >> continueOrdering;
                    if (continueOrdering == 'N' || continueOrdering == 'n') {
                        cout << "\033[32mProceeding to checkout.\033[0m" << endl;
                        return; 
                    } else if (continueOrdering == 'Y' || continueOrdering == 'y') {
                        cout << "\033[32m" << "Continuing with the order.\033[0m" << endl;
                        break; 
                    } else {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\033[31mInvalid input. Please enter 'Y' for Yes or 'N' for No.\033[0m" << endl;
                    }
                }
                break;
            }
        }

        if (!validProduct) {
            cout << "\033[31mInvalid product ID! Please enter a valid product ID.\033[0m" << endl;
        }
    }
}

int CUSTOMER::generateTransactionID() {
    srand(static_cast<unsigned int>(time(0)));
    int transactionID = rand() % 9000 + 1000;  
    return transactionID;
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
