#include"transaction.h"


TRANSACTION::TRANSACTION(int id, string method) {
    idTransaction = id;
    paymentMethod = method;
    totalAmount = 0;
    setCurrentDateAndTime();
}

TRANSACTION::TRANSACTION(string paymentMethod){
    this->paymentMethod = paymentMethod;
}

void TRANSACTION::setCurrentDateAndTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    dateTransaction.day = ltm->tm_mday;
    dateTransaction.month = 1 + ltm->tm_mon;
    dateTransaction.year = 1900 + ltm->tm_year;
    dateTransaction.hour = ltm->tm_hour;
    dateTransaction.minute = ltm->tm_min;
    dateTransaction.second = ltm->tm_sec;
}
// phương thức thêm món để thanh toán
void TRANSACTION::addItem(double price, int quantity) {
    items.push_back(make_pair(price, quantity));
}
// phương thức tính toán tổng đơn hàng
void TRANSACTION::calculateOrder() {
    totalAmount = 0;
    for (const auto &item : items) {
        totalAmount += item.first * item.second;
    }
    
}

// phương thức chuyển đổi tồng tiền từ số sang chữ
string TRANSACTION::convertToWords(long long amount) {
    string result = "";
    string units[] = {"", "nghin", "trieu", "ty"};
    int unitIndex = 0;

    while (amount > 0) {
        int part = amount % 1000;
        amount /= 1000;

        string partStr = "";
        int hundreds = part / 100;
        int tens = (part % 100) / 10;
        int ones = part % 10;

        // Hundreds place
        if (hundreds > 0) {
            switch (hundreds) {
                case 1: partStr += "mot tram "; break;
                case 2: partStr += "hai tram "; break;
                case 3: partStr += "ba tram "; break;
                case 4: partStr += "bon tram "; break;
                case 5: partStr += "nam tram "; break;
                case 6: partStr += "sau tram "; break;
                case 7: partStr += "bay tram "; break;
                case 8: partStr += "tam tram "; break;
                case 9: partStr += "chin tram "; break;
            }
            if (tens == 0 && ones > 0) partStr += "linh ";
        }

        // Tens place
        if (tens > 0) {
            switch (tens) {
                case 1: partStr += "muoi "; break;
                case 2: partStr += "hai muoi "; break;
                case 3: partStr += "ba muoi "; break;
                case 4: partStr += "bon muoi "; break;
                case 5: partStr += "nam muoi "; break;
                case 6: partStr += "sau muoi "; break;
                case 7: partStr += "bay muoi "; break;
                case 8: partStr += "tam muoi "; break;
                case 9: partStr += "chin muoi "; break;
            }
        }

        // Ones place
        if (ones > 0) {
            if (tens > 1 && ones == 1) {
                partStr += "mots ";
            } else if (ones == 5 && tens > 0) {
                partStr += "lam ";
            } else {
                switch (ones) {
                    case 1: partStr += "mot "; break;
                    case 2: partStr += "hai "; break;
                    case 3: partStr += "ba "; break;
                    case 4: partStr += "bon "; break;
                    case 5: partStr += "nam "; break;
                    case 6: partStr += "sau "; break;
                    case 7: partStr += "bay "; break;
                    case 8: partStr += "tam "; break;
                    case 9: partStr += "chin "; break;
                }
            }
        }

        if (!partStr.empty()) {
            partStr += units[unitIndex] + " ";
            result = partStr + result;
        }

        unitIndex++;
    }

    if (result.empty()) {
        result = "khong";
    }

    return result;
}
// phương thức hiển thị chi tiết giao dịch cho khách hàng
void TRANSACTION::displayTransactionDetails() {
    cout << "Transaction ID: " << idTransaction << endl;
    cout << "Payment method: " << paymentMethod << endl;
    cout << "Payment date: " << dateTransaction.day << "/" 
         << dateTransaction.month << "/" << dateTransaction.year << endl;
    cout << "Payment time: " << dateTransaction.hour << ":" 
         << dateTransaction.minute << ":" << dateTransaction.second << endl;
    cout << "Item:" << endl;
    int i = 1;
    for (const auto &item : items) {
        cout << i << ". Price: " << item.first << ", Quantity: " << item.second << endl;
        i++;
    }
    cout << "Total amount: " << totalAmount << " VND" << endl;
    cout << "Total amount in words: " << convertToWords(totalAmount) << "dong" << endl;
}

