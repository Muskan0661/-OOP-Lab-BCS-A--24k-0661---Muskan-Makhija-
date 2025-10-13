#include <iostream>
#include <string>
using namespace std;

class CallRecord {
private:
    string callerId;
    float durationMin;

    static int totalCalls;

public:

    CallRecord() {
        callerId = "";
        durationMin = 0;
    }

    CallRecord(string id, float duration) {
        callerId = id;
        durationMin = duration;
        totalCalls++;
    }

    void details() const {
        cout << "caller ID: " << callerId
             << " , duration: " << durationMin << " min" << endl;
    }

    static void getTotalCalls() {
        cout << "\ntotal calls Logged today: " << totalCalls << endl;
    }
};

int CallRecord::totalCalls = 0;

int main() {

    CallRecord calls[20] = {
        CallRecord("03001234567", 9),
        CallRecord("03019876543", 3),
        CallRecord("03451239876", 2),
        CallRecord("03345671234", 1)
    };

    for (int i = 0; i < 4; i++) {
        calls[i].details();
}

    CallRecord::getTotalCalls();

    return 0;
}
