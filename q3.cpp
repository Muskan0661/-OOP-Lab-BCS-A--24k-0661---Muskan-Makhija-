#include <iostream>
#include <string>
using namespace std;

class doctor {
private:
    string name;
    string specialization;

public:
    doctor(string n, string s) {
        name = n;
        specialization = s;
    }

    void details() const {
        cout << "doctor Name: " << name
             << " , specialization: " << specialization << endl;
    }

    string getName() const {
        return name;
    }
};

class hospital {
private:
    string hospitalName;
    doctor* doctors[5];
    int docCount;

public:
    hospital(string name) : hospitalName(name), docCount(0) {}

    void addDoc(doctor* d) {
        if (docCount < 5) {
            doctors[docCount] = d;
            docCount++;
        } else {
            cout << "cannot add more doctors to " << hospitalName << endl;
        }
    }

    void showDoctors() const {
        cout << "\nhospital: " << hospitalName << endl;
        cout << "doctors working here:" << endl;
        for (int i = 0; i < docCount; i++) {
            doctors[i]->details();
        }
    }
};

int main() {
    doctor d1("Dr. Ali", "Cardiologist");
    doctor d2("Dr. Lara", "Neurologist");
    doctor d3("Dr. Fatima", "Dermatologist");

    hospital h1("hira hospital");
    hospital h2("jinnah hospital");

    h1.addDoc(&d1);
    h1.addDoc(&d2);

    h2.addDoc(&d3);
    h2.addDoc(&d1);

    h1.showDoctors();
    h2.showDoctors();

    cout << "\ndoctors exist independently:\n";
    d1.details();
    d2.details();
    d3.details();

    return 0;
}
