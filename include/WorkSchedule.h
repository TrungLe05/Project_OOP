#include"staff.h"
#include<vector>
#include<iomanip>





class WorkSchedule : public STAFF{
    public:
    struct Shift{
            string day, shift;
            string name;
            bool Status;
        };
    private:
        vector<Shift> Schedule;
    public:
        WorkSchedule() {}

    WorkSchedule(const Shift& a) {
        Schedule.push_back(a);
    }

    void addSchedule(string name, const std::string& day, const std::string& shift, bool status) {
        Schedule.push_back({name, day, shift, status});
    }

    void displaySchedule() const;
};
