#include <iostream>
using namespace std;

class calculator {
private:
    int num1,num2;
public:

    void setNumbers(int n1, int n2) {
       num1=n1;
         num2=n2;
    }

   int add()
    {
    	return num1+num2;
	}
};

int main() {
   calculator c1;
   c1.setNumbers(10,23);
   cout<<"sum is: "<<c1.add();
    return 0;
}
