#include <iostream>
#include <string>
using namespace std;

class Kitchen {
private:
    float feet;
    bool renovated;

public:
    Kitchen(float f, bool r) {
        feet = f;
        renovated = r;
        cout << "Kitchen covers area in sq.ft: " << feet << " and renovated: "
             << (renovated ? "Yes" : "No") << endl;
    }

    void display() const {
        cout << "kitchen feets: " << feet << " sq.ft, Renovated: "
             << (renovated ? "Yes" : "No") << endl;
    }

    ~Kitchen() {
        cout << "Kitchen destroyed." << endl;
    }
};

class Apartment {
private:
    const int apartmentID;
    string ownerName;
    Kitchen kitchen;

public:
    Apartment(int id, string owner, float kitchenFeet, bool renovated)
        : apartmentID(id), ownerName(owner), kitchen(kitchenFeet, renovated)
    {
        cout << "apartment created (ID: " << apartmentID
             << ", owner: " << ownerName << ")" << endl;
    }

    void display() const {
        cout << "\napartment ID: " << apartmentID
             << ", owner: " << ownerName << endl;
        kitchen.display();
    }

    ~Apartment() {
        cout << "apartment destroyed : " << apartmentID << endl;
    }
};

int main() {
    Apartment a1(661, "Muskan Makhija", 143.4, true);
    a1.display();
    return 0;
}
