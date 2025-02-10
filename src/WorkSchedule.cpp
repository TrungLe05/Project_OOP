#include"WorkSchedule.h"


void WorkSchedule::displaySchedule() const {
        const int max_width = 100;
        std::cout << std::setw((max_width - 50) / 2 + 20)<< STAFF::getName() << "Employee's Work Schedule" << std::endl;
        std::cout << std::string(max_width, '-') << std::endl;
        std::cout<< std::setw(15) << "Name:" << std::setw(25) << "Day" << std::setw(25) << "Shift" << std::setw(25) << "Status" << std::endl;
        std::cout << std::string(max_width, '-') << std::endl;

        for (const auto& shift : Schedule) {
            std::string status = shift.Status ? "Working" : "Day Off";
            std::cout  << std::setw(15) << shift.day << std::setw(2) << shift.name << std::setw(25) << shift.shift << std::setw(25) << status << std::endl;
        }

        std::cout << std::string(max_width, '-') << std::endl;
}