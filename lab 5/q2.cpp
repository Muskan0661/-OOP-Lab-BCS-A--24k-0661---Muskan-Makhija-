#include<iostream>
#include<string>
using namespace std;

class mobileDevice{
	private:
		string modelName;
		const string IMEINum;

		public:

			mobileDevice(string name, string num)
    : modelName(name), IMEINum(num)
{
}


		void verifyDevice()
		{

			cout<<"model name: "<<modelName<<endl;
			cout<<"IMEI Num: "<<IMEINum<<endl;

			cout<<"device verified and registered with pta."<<endl;

	}
};
int main ()
{
   mobileDevice d1("oppo f21 pro","233333");
   d1.verifyDevice();
}
