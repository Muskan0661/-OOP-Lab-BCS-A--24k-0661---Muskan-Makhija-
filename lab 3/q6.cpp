#include<iostream>
using namespace std;
class vehicle
{
	public:
	string make;
	string model;
	void display()
	{
		cout<<"make: "<<make<<", model: "<<model<<endl;
	}
};
class car: public vehicle
{
	public:
	string engine;
	void display()
	{
		vehicle::display();
		cout<<"engine type is: "<<engine<<endl;
	}
};

int main ()
{
car c;
c.make=" KIA";
c.model="sportage";
c.engine="hybrid";
c.display();

}