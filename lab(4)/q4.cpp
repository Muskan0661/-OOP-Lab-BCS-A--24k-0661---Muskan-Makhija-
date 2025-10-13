#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    string designation;
    int hoursWorked;
    double salary;

public:
    Employee(int id, string n, string d, int hours, double sal = 0) {
        this->id = id;
        this->name = n;
        this->designation = d;
        this->hoursWorked = hours;
        this->salary = sal;
    }

    Employee(int id, string n, string d) {
        this->id = id;
        this->name = n;
        this->designation = d;
        this->hoursWorked = 0;
        this->salary = 0;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getDesignation() { return designation; }
    int getHours() { return hoursWorked; }
    double getSalary() { return salary; }

    void addHours(int h) { hoursWorked += h; }
    void setSalary(double s) { salary = s; }

    void display() {
        cout << "ID: " << id
             << " ,  Name: " << name
             << " , Designation: " << designation
             << " , Hours Worked: " << hoursWorked
             << " , Salary: " << salary << endl;
    }
};
class Admin {
private:
    Employee** employees;
    int capacity;
    int count;
    double hourlyRate;

public:
    Admin(int capacity = 10, double rate = 500) {
        this->capacity = capacity;
        this->count = 0;
        this->hourlyRate = rate;
        employees = new Employee*[capacity];
    }

    void addEmployee(string name, string designation, int hours = 0) {
        if (count == capacity) {
            cout << "employee list is full!\n";
            return;
        }
        int id = count + 1;
        if (hours > 0)
            employees[count] = new Employee(id, name, designation, hours);
        else
            employees[count] = new Employee(id, name, designation);
        count++;
        cout << "employee added (ID) : " << id << endl;
    }

    void recordAttendance(int id, int hours) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                employees[i]->addHours(hours);
                cout << "attendance updated for: " << employees[i]->getName() << endl;
                return;
            }
        }
        cout << "employee not found!\n";
    }

    void calculateSalary(int id) {
        for (int i = 0; i < count; i++) {
            if (employees[i]->getId() == id) {
                double sal = employees[i]->getHours() * hourlyRate;
                employees[i]->setSalary(sal);
                cout << "Salary calculated for: " << employees[i]->getName() << endl;
                return;
            }
        }
        cout << "employee not found!\n";
    }

    void displayAll() {
        cout << "\n employee records \n";
        for (int i = 0; i < count; i++) {
            employees[i]->display();
        }
    }

    ~Admin() {
        for (int i = 0; i < count; i++) {
            delete employees[i];
        }
        delete[] employees;
    }
};

int main() {
    Admin admin(10, 1000);

    admin.addEmployee("suha", "manager", 10);
    admin.addEmployee("muskan", "developer");
    admin.addEmployee("ishita", "designer");

    admin.recordAttendance(2, 8);
    admin.calculateSalary(1);
    admin.calculateSalary(2);

    admin.displayAll();

    return 0;
}
