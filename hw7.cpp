//Olivia Chen 5/25/17 (froyo using vectors passed into functions)
#include<iostream>
#include<iomanip>
#include<string>
#include <cmath>
#include<vector>

using namespace std;
//declaring functions used in main
void printWelcomeMessage();
double getYogurtSize(string& yogurtSize);
void getYogurtFlavors(vector<string>&flavors);
void printOrder (string& yogurtSize, vector<string>&flavors, int counter);
void printTotalCosts(double subtotal);

int main()
{
	//initialize the loop variables
	bool repeat=1;
	int counter=1;
	
	//Variables for size and flavors
	string yogurtSize;
	vector<string>flavors;
	
	//Variable for cost
	double subtotal=0;
	//print the welcome message
	printWelcomeMessage();
	//continue to get orders until the user is done
	
	while(repeat==1)
	{
		//Update the size and subtotal
		subtotal=subtotal + getYogurtSize(yogurtSize);
		
		//Update the flavors
		getYogurtFlavors(flavors);
		
		//Print current order
		printOrder(yogurtSize, flavors, counter);
		
		//Determine whether or not to keep repeating
		string keepGoing;
		cout<<"Would you like to add another order?"<<endl;
		cout<<"Please enter yes or no: "<<endl;
		getline(cin, keepGoing);
		if(keepGoing=="yes")
		{
			repeat=1;
		}
		
		counter++;
	}
	
	//Print out subtotal, tax, and total
	printTotalCosts(subtotal);
	
	return 0;
}

//outputs the welcome message
void printWelcomeMessage()
{
	cout<<"Welcome to My Frozen Yogurt!"<<endl;
	return;
}

//prompts for the size of the order and returns cost to subtotal
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

//prompts user for yogurt flavors
void getYogurtFlavors(vector<string>& flavors)
//uses vector<string>& because need to modify the vector, but don't want to make a copy
{
	//initialize input flavor
	string flavor;
	int i=0;
	while (i<10 && flavors[i]!=("DONE"))
	//loop until either 10 values are put in or DONE is input
	{
		//prompts for flavor number, (i+1) because we start at flavor 1, but that is indexed to 0
		cout<<"Enter flavor "<<(i+1)<<": "<<endl;
		getline(cin,flavor);
		//for each flavor entered, the vector gets a new element
		flavors.push_back(flavor);
		i++;
	}
	return;
	
}

//function to print the order
void printOrder(string& yogurtSize, vector<string>& flavors, int counter)
{
	//prints size
	cout<<"**Order "<<counter<<": "<<yogurtSize<<" ";
	//for each element of flavors vector, print out the first four characters of the flavor
	for(int i=0; i<flavors.size(); ++i)
	{
		cout<<flavors[i].substr(0,4)<<"- "<<endl;
	}
	cout<<" **"<<endl;
	return;
}


//function to print total cost
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


