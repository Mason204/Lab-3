/*
Mason Henry
C++
Due: Sept. 26, 2019
In this lab we are to take data from a file and from a user input and calculate mean and standard deviation for both sets of
data and then output the results to the screen and to a seperat file.
*/

#include <iostream>
#include <fstream>

using namespace std;

//The two function prototypes that I will be using to calculate mean and standard deviation.
float mean(int a, int b, int c, int d);
float stdDev(int a, int b, int c, int d, float mean);

int main()
{
	//These are the assigned data values. A through D are to be user inputed and d1 to d4 are to be inputed through a file.
	int a;
	int b;
	int c;
	int d;
	int d1;
	int d2;
	int d3;
	int d4;

	//This is where I linked the input and output file locations to the strings.
	string inMeanStd = "C:/Users/jhphoto/Desktop/Mason Scripts/Lab 3/inMeanStd.dat";
	string outMeanStd = "C:/Users/jhphoto/Desktop/Mason Scripts/Lab 3/outMeanStd.dat";

	//Creating a stream that allows the input and output of data to files.
	ifstream inFile;
	ofstream outFile;

	//opens the input and output files
	inFile.open(inMeanStd);
	outFile.open(outMeanStd);

	//inputs data from the file and stores them as the integers d1,d2,d3,d4
	inFile >> d1 >> d2 >> d3 >> d4;

	//inputs and outputs data from the user
	cout << "Please input four real numbers to calculate the mean and standard deviation (use spaces between numbers):";
	cin >> a >> b >> c >> d;
	cout << "\nThe mean for the values you entered is:" << mean(a, b, c, d) << endl;
	cout << "The standard deviation for the values you entered is:" << stdDev(a, b, c, d, mean(a,b,c,d)) << endl;
	//Here I insert the file values (d1,d2,d3,d4) in place of the user inputted valuess so that it calculates the mean of the file data
	cout << "the mean for the input file is:" << mean(d1,d2,d3,d4) << endl;
	cout << "The standard deviation for the input file is:" << stdDev(d1,d2,d3,d4,mean(d1,d2,d3,d4)) << endl;

	//outputs data to the file
	outFile << "File inputed mean:" << mean(d1,d2,d3,d4) << endl;
	outFile << "File inputed standard deviation:" << stdDev(d1,d2,d3,d4,mean(d1,d2,d3,d4)) << endl;
	outFile << "User inputed mean:" << mean(a, b, c, d) << endl;
	outFile << "User inputed standard deviation:" << stdDev(a, b, c, d, mean(a, b, c, d));

	//closes the input and output files
	inFile.close();
	outFile.close();

	return 0;

}

//the two function definitions that will calculate the mean and standard deviation. 
float mean(int a, int b, int c, int d)
{
	return float(a + b + c + d) / 4;
}

//I used the power to the .5 instead of sqrt so that I didn't need to include the cmath library.
float stdDev(int a, int b, int c, int d, float mean)
{
	return pow(((pow((a - mean), 2) + pow((b - mean), 2) + pow((c - mean), 2) + pow((d - mean), 2)) / float(4)), (.5));
}












































































//why did you scroll down here, there's nothing here for you.