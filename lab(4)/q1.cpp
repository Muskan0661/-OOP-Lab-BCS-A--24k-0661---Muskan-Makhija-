#include <iostream>
#include <string>
using namespace std;

class user {
private:
    int id;
    string name;
    string pass;
    string role;

public:
    user(int ID, string n, string p, string r) {
        this->id = ID;
        this->name = n;
        this->pass = p;
        this->role = r;
    }
    user(int id, string name, string pass) {
        this->id = id;
        this->name = name;
        this->pass = pass;
        this->role = "Guest";
    }

    int getId() { return id; }
    string getName() { return name; }
    string getPass() { return pass; }
    string getRole() { return role; }

    void setRole(string r) { role = r; }
    void setPass(string p) { pass = p; }

    void display() {
        cout << "ID: " << id << " , Name: " << name << " , Role: " << role << endl;
    }
};

class Admin {
private:
    user** users;
    int capacity;
    int count;

public:
    Admin(int capacity = 10) {
        this->capacity = capacity;
        this->count = 0;
        users = new user*[capacity];
    }

    bool validpass(string pass) {
        if (pass.length() < 6) return false;
        bool hasSpecial = false;
        for (char c : pass) {
            if (!isalnum(c)) {
                hasSpecial = true; break;
            }
        }
        return hasSpecial;
    }

    void addUser(string name, string password, string role = "Guest") {
        if (!validpass(password)) {
            cout << "Password invalid! Must be >=6 chars and contain a special character.\n";
            return;
        }
        if (count == capacity) {
            cout << "User storage full!\n";
            return;
        }
        int id = count + 1;
        if (role == "")
            users[count] = new user(id, name, password);
        else
            users[count] = new user(id, name, password, role);
        count++;
        cout << "User added successfully with ID: " << id << endl;
    }

    void removeUser(int id) {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                delete users[i];
                for (int j = i; j < count - 1; j++) {
                    users[j] = users[j + 1];
                }
                count--;
                found = true;
                cout << "User removed.\n";
                break;
            }
        }
        if (!found) cout << "User not found!\n";
    }

    void searchUser(int id) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                cout << "User found: ";
                users[i]->display();
                return;
            }
        }
        cout << "User not found!\n";
    }

    void displayAll() {
        cout << "\nAll Users \n";
        for (int i = 0; i < count; i++) {
            users[i]->display();
        }
    }

    void changeRole(int id, string newRole) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getId() == id) {
                users[i]->setRole(newRole);
                cout << "Role updated!\n";
                return;
            }
        }
        cout << "User not found!\n";
    }

    ~Admin() {
        for (int i = 0; i < count; i++) {
            delete users[i];
        }
        delete[] users;
    }
};

int main() {
    Admin admin(10);

    admin.addUser("muskan", "muskan@123", "Admin");
    admin.addUser("ishita", "ishita@123", "User");
    admin.addUser("momina", "pass@20");

    admin.displayAll();
    admin.searchUser(2);
    admin.changeRole(3, "User");
    admin.removeUser(1);
    admin.displayAll();

    return 0;
}
