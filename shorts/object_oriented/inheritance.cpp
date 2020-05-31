#include <iostream>
#include <sstream>
using namespace std;

class Employee {
protected:
    string name;
    double pay;

public:
    Employee() : name(""), pay(0) {}

    Employee(string empName, double payRate) : name(empName), pay(payRate) {}

    ~Employee() {
        // free resources
    }

    string getName() {
        return name;  //a
    }

    void setName(string empName) {
        name = empName;
    }

    double getPay() {
        return pay;
    }

    void setPay(double payRate) {
        pay = payRate;
    }

    virtual string toString() {
        stringstream ss;
        ss << name << ": " << pay;
        return ss.str();
    }

    virtual double grossPay(int hours) {
        return pay * hours;
    }
};

class Manager : public Employee {
private:
    bool salaried;

public:
    // default constructor
    Manager() : salaried(true) {}

    Manager(string name, double pay, bool isSalaried) : Employee(name, pay), salaried(isSalaried) {}

    bool isSalaried() {
        return salaried;
    }

    double grossPay(int hours) override {
        if (salaried) {
            return pay;
        } else {
            return pay * hours;
        }
    }

    string toString() override {
        stringstream ss;
        string salary = salaried ? "Salaried" : "Hourly";
        ss << name << ": " << pay << ": " << salary;
        return ss.str();
    }
};

int main() {
    Employee e("John", 15.0);
    cout << e.toString() << ", Gross pay: " << e.grossPay(40) << endl;

    Manager m("Tom", 2000.0, true);
    cout << m.toString() << endl;

    return 0;
}
