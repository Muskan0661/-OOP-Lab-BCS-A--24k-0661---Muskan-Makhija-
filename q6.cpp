#include<iostream>
using namespace std;
class employee
{
	private:
   int employeeId;
   string employeeName;

   static int totalemployee;
   public:

   	employee(int id, string n)
   	{
   		employeeId=id;
   		employeeName=n;
   		totalemployee++;

	   }
	   void display() const
	   {
	   	cout<<"employee id: "<<employeeId<<" , name: "<<employeeName<<endl;
	   }

	   static void total()
	   {
	   	cout<<"total employee in company: "<<totalemployee<<endl;
	   }

	   ~employee()
	   {
	   	totalemployee--;
	   }

};
int employee::totalemployee=0;

class clientproject{
private:
	string projectName;
	employee* team[3];

	public:
		clientproject(string n,employee* e1,employee* e2,employee* e3)
		{
			projectName=n;
			team[0]=e1;
			team[1]=e2;
			team[2]=e3;
		}
	void display() const
	{
		cout<<"project: "<<projectName<<endl;
		cout<<"employees:\n"<<endl;
		for(int i=0; i<3; i++)
		{
			team[i]->display();
		}
	}
};

int main()
{
	employee e1(611, "muskan");
	employee e2(685,"ashita");
	employee e3(123,"rutba");

	employee::total();

	clientproject p1("website dev",&e1,&e2,&e3);
	p1.display();

	employee::total();
	}