//Olivia Chen 5/19/17 (froyo using functions)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;
//declaring functions used in main
void printWelcomeMessage();
double getYogurtSize(string& yogurtSize);
void getYogurtFlavors(string& flavor1, string& flavor2, string& flavor3);
void printOrder(string& yogurtSize, string& flavor1, string& flavor2, string& flavor3, int counter);
bool addAnotherOrderQ();
void printTotalCosts(double subtotal);

int main()
{
	// initialize the loop variables
	bool repeat = 1;
	int counter=1;
	
	// Variables for size and flavors
	string yogurtSize;
	string flavor1, flavor2, flavor3;
	
	// Variable for cost
	double subtotal=0;
	
	// Print the welcome message
	printWelcomeMessage();
	
	// Continue to get orders until the user is done
	while(repeat == 1)
	{
		// Update the size and subtotal
		subtotal = subtotal + getYogurtSize(yogurtSize);
		// Update the flavors
		getYogurtFlavors(flavor1, flavor2, flavor3);
	
		// Print the current order
		printOrder(yogurtSize, flavor1, flavor2, flavor3, counter);
		
		// Determine whether or not to keep repeating.
		repeat = addAnotherOrderQ();
		counter++;
	}
	
	// Print out the subtotal, tax, and total
	printTotalCosts(subtotal);
	return 0;
}
//outputs the welcome message
void printWelcomeMessage()
{
	cout<<"Welcome to My Frozen Yogurt!"<<endl;
	return;
}
//prompts for the size of order and returns cost to subtotal
double getYogurtSize(string& yogurtSize)
{
	cout<<"What size would you like?"<<endl;
	cout<<"Please enter small, medium, or large: "<<endl;
	//use getline instead of cin because later on flavors can be multiple words
	getline(cin,yogurtSize);
	if(yogurtSize=="small")
		return 2.19;
	if(yogurtSize=="medium")
		return 3.49;
	if(yogurtSize=="large")
		return 4.49;
	else
		return 0;
}

void getYogurtFlavors(string& flavor1, string &flavor2, string& flavor3)
{
	cout<<"Enter flavor 1: "<<endl;
	getline(cin,flavor1);
	cout<<"Enter flavor 2: "<<endl;
	getline(cin,flavor2);
	if (flavor2=="DONE")
		return;
	cout<<"Enter flavor 3: "<<endl;
	getline(cin,flavor3);
	return;
}

void printOrder(string& yogurtSize, string& flavor1, string& flavor2, string& flavor3, int counter)
{
	cout<<"** Order "<<counter<<": "<<yogurtSize<<" "<<flavor1.substr(0,4);
	if (flavor2!="DONE")
	{
		cout<<"-"<<flavor2.substr(0,4);
	}
	if (flavor3!="DONE")
	{
		cout<<"-"<<flavor3.substr(0,4);
	}
	cout<<" **"<<endl;
	return;
}

bool addAnotherOrderQ()
{
	string keepGoing;
	cout<<"Would you like to add another order?"<<endl;
	cout<<"Please enter yes or no: "<<endl;
	getline(cin,keepGoing);
	if (keepGoing=="yes")
	{
		return true;
	}
	else
	{
		return false;
	}
}
void printTotalCosts(double subtotal)
{
	//tax and totalTax, for the values of tax and then tax plus total, to avoid magic numbers
	double tax=0.0875;
	double totalTax=1.0875;
	cout<<"Subtotal: $"<<subtotal<<endl;
	cout<<"Tax (8.75%): $";
	//setprecision to 2 digits after decimal pt
	cout<<setprecision(2)<<fixed<<tax*subtotal<<endl;
	cout<<"Total: $"<<setprecision(2)<<fixed<<totalTax*subtotal<<endl;
	return;
}
