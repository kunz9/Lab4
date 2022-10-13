/*
Dakota Kunz
C++
Lab 4
Due: October 14th, 2022
Description: Design and write a C++ program that inputs a series of hourly temperature 
from a file, and outputs a bar chart (using stars) of the temperatures. The temperature 
should be printed to the left of the corresponding bar, and there should be a heading 
that gives the scale of the chart. The range of temperatures should be from  -30 to 120. 
Because it is hard to display 150 characters on the screen, you should have each star 
represent a range of 3 degrees.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
//Precondition:iostream, iomanip
//Postcondition: Outputs title and header of graph 
void heading();

//Precondition:iostream, fstream 
//Postcondition: Stores value at temp from file,Vets some numbers out of range, 
//combines positive and negative sides of the graph ,closes file
void bargraph (int temp, int star, int i);

//Precondition:iostream, stored value in star from starpeg 
//Postcondition: Outputs * right of | for value of calculated star
void staroutput(int star, int i);

//Precondition:  iostream, stored value in star from starNeg 
//Postcondition: Outputs * left of | for value of calculated star
void staroutputNeg(int star, int i);

//Precondition: iostream,iomanip, stored value of temp from bargraph
//Postcondition:Sets width at zero and outputs 0
void output(int temp);

//Precondition: iostream,iomanip,stored value of temp from bargraph, stored value of star from starpos
//Postcondition: Sets width at zero and outputs 0
void outputNeg(int temp, int star);

//Precondition:stored value of temp from bargraph,
//Postcondition:stores a value of star, calculates for remanider with starR
void starNeg(int temp, int& star);

//Precondition: stored value of temp from bargraph, 
//Postcondition: stores a value of star, calculates for remanider with starR
void starpos(int temp, int& star);

//Precondition:iostream, iomanip, stored value at temp bargraph,
//Postcondition: Ouputs the postive side of the graph with the line
void pos(int temp, int star, int i);

//Precondition:iostream, iomanip, stored value at temp bargraph, 
//Postcondition: Ouputs the negative side of the graph with the line
void neg(int temp, int star, int i);

string input = "Temperatur.dat";
ofstream outfile;
string readin; 


int main()
{//Initializes the variables; temp, star, and i
 //combines everything to creat the bar graph and heading
	int temp=0; int star=0; int i=0;
	heading();
	bargraph(temp, star, i);
	return 0;
}
void heading()
{	//Outputs Heading 
	cout << "Temperature per hours (Each Star represents 3 degrees)\n";
	cout << setw(10) << "-30" << setw(10) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(10) << "120" << endl;
}
void bargraph(int temp, int star, int i)
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
		infile >> temp;//reads in temp from file 
		if (temp > 120 || temp < -30)//makes sure temp is in range from -30 to 120
			continue;
		//combines positive and negative sides of the bar graph 
		neg(temp, star, i);
		pos(temp, star, i);
		cout << endl;
	}
	
	infile.close();//closes file so there is no possibility of an endless loop
}
void starpos(int temp, int& star)
{
	int starR;
	star = temp / 3;
	starR = temp % 3;//calculates remainder to see if an extra star needs added
	if (starR == 2)
	{
		star = star + 1;
	}
}
void starNeg(int temp, int& star)
{
	int starR;
	star = -temp / 3;
	starR = -temp % 3;//Calculates remainder fro negative numbers 
	if (starR == 2)
	{
		star = star + 1;
	}
}
void staroutput(int star,int i)
{
	//Outputs 1/3 the value of temp including possible remainders 
	for (int i = 1; i <= star; i++)
	{
		cout << "*";
	}
}
void staroutputNeg(int star, int i)
{//Outputs 1/3 the value of temp including possible remainders 
	for (int i = 1;i <= star; i++)
	{
		cout << "*";
	}
}
void output(int temp)
{// sets rules for spacing depending on the number of characters in the number 
	if (temp < 100 && temp > 9)
		cout << setw(18) << "|";
	if (temp < 10 && temp >=0)
		cout << setw(19) << "|";
	if (temp < 121 && temp > 99)
		cout << setw(17) << "|";
}
void outputNeg(int temp, int star)
{// sets rules for spacing depending on the number of characters in the number 
 //also accounts for the negative sign as a character 
	if (temp <= -10 && temp >= -30)
		cout << setw(17 - star); 
	if (temp < 0 && temp >= -9)
		cout << setw(17 - star);
}
void pos(int temp, int star, int i)
{ //Ouptputs temp and set a certain distance before anything is outputted to the scrren
  //combines all positive side of the graph 
	if (temp >= 0 && temp <= 120)
	{
		cout << temp << setw(15);
		starpos(temp,star);
		output(temp);
		staroutput(star, i);
	}
}
void neg(int temp, int star, int i)
{//Outputs temp and sets a certain spacing depending on the size of the number
 //Combines all negative side of the graph 
	if (temp >= -30 && temp <= -1)
	{
		cout << temp;
		starNeg(temp,star);
		outputNeg(temp,star);
		staroutputNeg(star, i);
		cout << "|";
	}
}