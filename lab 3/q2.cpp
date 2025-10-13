#include <iostream>
using namespace std;

class student {
public:
    string name;

private:
    int rollnum;

public:

    void setrollnum(int roll) {
        rollnum = roll;
    }

    int getrollnum() {
        return rollNumber;
    }
};

int main() {
    Student s1;

    s1.name = "muskan";

    s1.setrollnum(661);

    cout << "name: " << s1.name << endl;
    cout << "roll number: " << s1.getrollnum() << endl;

    return 0;
}
