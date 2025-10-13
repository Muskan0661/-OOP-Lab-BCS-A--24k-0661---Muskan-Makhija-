#include<iostream>
using namespace std;
class student
{
	private:
	string name;
	int roll;
	double marks;
	char grade;
public:
	student(string n, int r, double m)
	{
		name=n;
		roll=r;
		marks=m;
		grade='f';
	}
	void calculateGrade()
	{
		if(marks>=90 && marks<100)
		{
			grade= 'A';
		}
		else if(marks<90 & marks>=80)
		{
			grade= 'B';
		}
		else if(marks<80 & marks>=70)
		{
			grade= 'C';
		}
		else
		{
			grade= 'F';
	}
	}
	void displayStudentInfo()
	{
		cout<<"name: "<<name<<endl;
		cout<<"roll num: "<<roll<<endl;
		cout<<"marks: "<<marks<<endl;
		cout<<"grade: "<<grade<<endl;
		cout<<"\n";
	}
};
int main (){
	student s1("muskan makhija",661,85.5);
	student s2("Ishita",661,86.5);

	s1.calculateGrade();
	s2.calculateGrade();

	s1.displayStudentInfo();
	s2.displayStudentInfo();
}
