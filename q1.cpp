#include<iostream>
#include<string>
using namespace std;
class petrolPump{
	public:
		int pumpId;
		float litersFilled;

		static float pricePerLiters;

		void display()
		{
			float total=litersFilled*pricePerLiters;
			cout<<"pump id: "<<pumpId<<endl;
			cout<<"liters filled: "<<litersFilled<<endl;
			cout<<"price per liter in pkr: "<<pricePerLiters<<endl;
			cout<<"total amount in pkr: "<<total<<endl;
		}
};

float petrolPump::pricePerLiters=290.5;

int main ()
{
   petrolPump p1;
   p1.pumpId=661;
   p1.litersFilled=10;
   p1.display();
}
