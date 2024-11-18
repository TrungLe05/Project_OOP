#ifndef MENU_H
#define MENU_H
#include<vector>
#include <cctype>
#include <algorithm>
#include"menuItem.h"
#include<string>
#include<iostream>
using namespace std;


class MENU{
    private:
        vector<MENUITEM> menuList;
        string menuName;
    public:
        MENU();
        MENU(string menuName);
        void initialMenuList();
        void addItem(const PRODUCT &product, double priceForSizeM, double priceForSizeL, bool isBestSeller);
        void displayMenu()const;
        MENUITEM* findItemInMenuListById(string id);
        bool updatePrice(string id, char size, double newPrice);
        vector<MENUITEM> getBestSellerItems();
        void additemInMenuListFromInput();
        vector<MENUITEM> getMenuList();
        ~MENU();
};

#endif