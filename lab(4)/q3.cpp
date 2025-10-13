#include <iostream>
#include <string>
using namespace std;
struct Doctor {
    string name;
    string department;
};

class Patient {
private:
    int id;
    string name;
    int age;
    string disease;
    Doctor doctorAssigned;

public:

    Patient(int id, string n, int a, string d, Doctor doc) {
        this->id = id;
        this->name = n;
        this->age = a;
        this->disease = d;
        this->doctorAssigned = doc;
    }

    Patient(int id, string n, int a, string d) {
        this->id = id;
        this->name = n;
        this->age = a;
        this->disease = d;
        this->doctorAssigned = {"not assigned", "none"};
    }

    int getId() { return id; }
    void assignDoctor(Doctor doc) { doctorAssigned = doc; }

    void display() {
        cout << " id: " << id
             << "  name: " << name
             << " age: " << age
             << " disease: " << disease
             << " doctor: " << doctorAssigned.name
             << " (" << doctorAssigned.department << ")\n";
    }
};
class Hospital {
private:
    Patient** patients;
    int capacity;
    int count;

public:
    Hospital(int capacity = 10) {
        this->capacity = capacity;
        this->count = 0;
        patients = new Patient*[capacity];
    }

    void addPatient(string name, int age, string disease, Doctor doc, bool withDoctor = true) {
        if (count == capacity) {
            cout << "hospital record is full!\n";
            return;
        }
        int id = count + 1;
        if (withDoctor)
            patients[count] = new Patient(id, name, age, disease, doc);
        else
            patients[count] = new Patient(id, name, age, disease);
        count++;
        cout << "patient added successfully with ID: " << id << endl;
    }

    void removePatient(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                delete patients[i];
                for (int j = i; j < count - 1; j++) {
                    patients[j] = patients[j + 1];
                }
                count--;
                found = true;
                cout << "patient removed.\n";
                break;
            }
        }
        if (!found) cout << "patient not found!\n";
    }

    void searchPatient(int id) {
        for (int i = 0; i < count; i++) {
            if (patients[i]->getId() == id) {
                cout << "Patient found:\n";
                patients[i]->display();
                return;
            }
        }
        cout << "patient not found!\n";
    }

    void displayAll() {
        cout << "\n all Patient Records\n";
        for (int i = 0; i < count; i++) {
            patients[i]->display();
        }
    }

    ~Hospital() {
        for (int i = 0; i < count; i++) {
            delete patients[i];
        }
        delete[] patients;
    }
};
int main() {
    Hospital hospital(10);

    Doctor d1 = {"Dr. karan", "general"};
    Doctor d2 = {"Dr. lara", "neurology"};

    hospital.addPatient("pari", 20, "flu", d1);
    hospital.addPatient("muskan", 22, "fever", d2);
    hospital.addPatient("ishita", 25, "cough", d1, false);

    hospital.displayAll();
    hospital.searchPatient(2);
    hospital.removePatient(1);
    hospital.displayAll();

    return 0;
}
