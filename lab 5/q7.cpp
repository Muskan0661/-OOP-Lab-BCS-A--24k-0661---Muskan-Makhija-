#include <iostream>
#include <string>
using namespace std;

class ClassSchedule {
private:
    string days;
    string timeSlot;

public:
    ClassSchedule(string d, string t) : days(d), timeSlot(t) {
        cout << "class schedule created: " << days << " " << timeSlot << endl;
    }

    void display() const {
        cout << "schedule: " << days << ", Time: " << timeSlot << endl;
    }

    ~ClassSchedule() {
        cout << "class schedule destroyed." << endl;
    }
};

class Student {
private:
    const int id;
    string name;

public:
    Student(int Id, string n) : id(Id), name(n) {}

    void display() const {
        cout << "student ID: " << id << ", name: " << name << endl;
    }
};

class CourseSection {
private:
    string section;
    ClassSchedule schedule;
    Student* students[3];
    int studentCount;
    static int totalSections;

public:
    CourseSection(string name, string days, string time,
                  Student* s1, Student* s2, Student* s3)
        : section(name), schedule(days, time) {
        students[0] = s1;
        students[1] = s2;
        students[2] = s3;
        studentCount = 3;
        totalSections++;
        cout << "Course section created: " << section << endl;
    }

    void display() const {
        cout << "\nCourse Section: " << section << endl;
        schedule.display();
        cout << "enrolled Students:\n";
        for (int i = 0; i < studentCount; i++) {
            students[i]->display();
        }
    }

    static void showTotalSections() {
        cout << "\ntotal Course Sections this semester: " << totalSections << endl;
    }

    ~CourseSection() {
        totalSections--;
        cout << "course Section destroyed: " << section << endl;
    }
};

int CourseSection::totalSections = 0;
int main() {
    Student s1(661, "Muskan");
    Student s2(102, "Ali");
    Student s3(103, "Sara");

    CourseSection::showTotalSections();

    CourseSection cs1("BCS-3K", "Mon-Thurs-Fri", "9:00 AM - 12:00 PM", &s1, &s2, &s3);

    cs1.display();

    CourseSection::showTotalSections();

    return 0;
}
