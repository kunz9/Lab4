/*
Dakota Kunz
C++
Lab 4
Description: The goal of this lab was to import temperature values from 
a file and create a bar graph with set values for star ina  range from
-30 degrees to 120 degrees
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
//Precondition: include library iostream
//Postcondition: Ouputs the Header to Screen
float heading();

//Precondition: fstream, string, iomanip,iostream, pos(), neg(), stored values at temp 
//Postcondition: Gets called to main and outputs graph 
float fileinput();

//Precondition:iostream, int temp, int star, int starR
//Postcondition:Gets called to fileinput to round up or not on stars
float filecalculations();

//Precondition:int star
//Postcondition: Output stars for 1/3 the original positive value, called in pos()
float staroutput();

//Precondition: int star
//Postcondition: Output star for 1/3 the original negative value, called in neg()
float staroutputNeg();

//Precondition:iostream, iomanip,Fileinput, pos, filecalculations
//Postcondition: Sets width at zero and outputs line
float output();

//Precondition:
//Postcondition:
float outputNeg();

//Precondition:
//Postcondition:
float starNeg();

//Precondition:
//Postcondition:
float pos();

//Precondition:
//Postcondition:
float neg();
string input = "Temperatur.dat";
ofstream outfile;
string readin; 
int i;
int temp;
int star;
int starR;

int main()
{
	heading();
	fileinput();
	return 0;
}
float heading()
{
	cout << "Temperature per hours (Each Star represents 3 degrees)\n";
	cout << setw(10) << "-30" << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;
	return 0;
}
float fileinput()
{
	ifstream infile;
	infile.open(input);

	if (!infile)
	{
		cout << "File could not be found!";
	}

	string readin; 
	while (!infile.eof())
	{
		infile >> temp;
		neg();
		pos();
		cout << endl;
	}
	infile.close();
	return 0;
}
float filecalculations()
{
	star = temp / 3;
	starR = temp % 3;
	if (starR == 2)
	{
		star = star + 1;
	}
	return 0;
}
float starNeg()
{
	star = -temp / 3;
	starR = -temp % 3;
	if (starR == 2)
	{
		star = star + 1;
	}
	return 0;
}
float staroutput()
{
	for (int i = 1; i <= star; i++)
	{
		cout << "*";
	}
	return 0;
}
float staroutputNeg()
{
	for (int i = 1;i <= star; i++)
	{ ;
		cout << "*";;
	}
	return 0;
}
float output()
{
	if (temp < 100 && temp > 9)
		cout << setw(18) << "|";
	if (temp < 10 && temp >0)
		cout << setw(19) << "|";
	if (temp < 121 && temp > 99)
		cout << setw(17) << "|";
	return 0;
}
float outputNeg()
{
	if (temp <= -10 && temp >= -30)
		cout << setw(17 - star); 
	if (temp < 0 && temp >= -9)
		cout << setw(17 - star);
	return 0;
}
float pos()
{
	if (temp >= 0 && temp <= 120)
	{

		cout << temp << setw(15);
		filecalculations();
		output();
		staroutput();
	}
	return 0;
}
float neg()
{
	if (temp >= -30 && temp <= -1)
	{
		cout << temp;
		starNeg();
		outputNeg();
		staroutputNeg();
		cout << "|";
	}
	return 0;
}