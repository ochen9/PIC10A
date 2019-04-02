//Olivia Chen 6/9/17 (froyo using classes and vectors)
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

//functions that are not member functions, either don't have parameters or don't use private variables as parameters
void printWelcomeMessage();
bool addAnotherOrderQ();
void printTotalCosts(double subtotal);

//declaring class
class Order
{
	//public functions/constructor
public:
	//declaring constructor
	Order(int count);
	//declaring member functions
	double getYogurtSize();
	double getPrice();
	void getYogurtFlavors();
	void clearFlavors();
	void printOrder();
	//private variables
private:
	//declaring size and flavors
	string yogurtSize;
	double price;
	vector<string>flavors;
	//counter is here so that when the function is called, it doesn't need to use the counter in main as a parameter
	int counter;
};

int main()
{
	//declare vector of Order class objects
	vector<Order>orderList;
	
	// initialize the loop variables
	bool repeat = 1;
	int counter=1;
	//variable for subtotal
	double subtotal=0;
	
	// Print the welcome message
	printWelcomeMessage();
	
	// Continue to get orders until the user is done
	while(repeat == 1)
	{
		Order yogurt(counter);
		// Update the size and subtotal
		subtotal = subtotal + yogurt.getYogurtSize();
		// Update the flavors
		yogurt.getYogurtFlavors();
		
		// Determine whether or not to keep repeating.
		repeat = addAnotherOrderQ();
		counter++;
		//adds new order into orderList
		orderList.push_back(yogurt);
	}
	
	//prints all of the orders
	for(int i=0; i<orderList.size();++i)
	{
		orderList[i].printOrder();
	}
	
	//Edit order
	//variables that will be inputted by user
	string edit;
	int orderNumber;
	//boolean for while loop
	bool done=1;
	while(done==1)
	{
		//asks user if they would like to edit any of the orders
		cout<<"Would you like to change any of these orders?"<<endl;
		cout<<"Please enter yes or no: "<<endl;
		getline(cin, edit);
	
		if(edit=="no")
		{
			done=0;
			//breaks out of loop
		}
		
		else if(edit=="yes")
		{
			//asks for which order
			cout<<"Which order? : "<<endl;
			cin>>orderNumber;
			//cin.ignore() so that the cin doesn't interfere with the getline later on when you use getYogurtSize()
			cin.ignore();
			
			//makes sure that the order number is in bounds
			if(orderNumber>0 && orderNumber<=orderList.size())
			{
				//removes the previous price of that order from subtotal
				subtotal-=orderList[orderNumber-1].getPrice();
				//adds the new price of the size prompted
				subtotal+=orderList[orderNumber-1].getYogurtSize();
				
				//clearing the vector of flavors
				orderList[orderNumber-1].clearFlavors();
				//prompts for new flavors
				orderList[orderNumber-1].getYogurtFlavors();
			}
			else
			{
				//if the order number of bounds, outputs this and loops over again
				cout<<"That is not a valid order number"<<endl;
			}
		}
	}
	//prints all of the orders
	for(int i=0; i<orderList.size();++i)
	{
		orderList[i].printOrder();
	}

	
	// Print out the subtotal, tax, and total
	printTotalCosts(subtotal);
	return 0;
}

//constructor
Order::Order(int count)
{
	//private variable counter is assigned the same value as counter in main
	counter=count;
}
//outputs the welcome message
//not a member function
void printWelcomeMessage()
{
	cout<<"Welcome to My Frozen Yogurt!"<<endl;
	return;
}
//prompts for the size of order and returns cost to subtotal
//member function, no parameters because they are private and inputted by the user within the function, rather than in main
double Order::getYogurtSize()
{
	cout<<"What size would you like?"<<endl;
	cout<<"Please enter small, medium, or large: "<<endl;
	//use getline instead of cin because later on flavors can be multiple words
	getline(cin, yogurtSize);
	if(yogurtSize=="small")
		price = 2.19;
	if(yogurtSize=="medium")
		price = 3.49;
	if(yogurtSize=="large")
		price = 4.49;
	else
		price = 0;
	return price;
	//returns cost of each size to be added to subtotal later
}

//returns the price of an order without prompting for new size every time in order to edit subtotal accurately
double Order::getPrice()
{
	return price;
}

//prompts user for yogurt flavors
void Order::getYogurtFlavors()
{
	//initialize input flavor
	//creates private variable that is only initialized in the function, and not needed anywhere else in program
	string flavor;
	size_t i=0;
	
	//loop until either 10 values are put in or DONE is input
	//do while loop because otherwise the vector is empty and error will occur because loop cannot occur without at least one element in vector
	do
	{
		//prompts for flavor number, (i+1) because we start at flavor 1, but that is indexed to 0
		cout<<"Enter flavor "<<(i+1)<<": "<<endl;
		getline(cin,flavor);
		//for each flavor entered, the vector gets a new element
		flavors.push_back(flavor);
		i++;
	}
	while (flavors[i-1] != "DONE" && i<10);
	//is flavors[i-1] because of the push_back function that messes up index of vectors
	return;
	
}

//needs member function to clear the flavors vector because flavors is private class variable
void Order::clearFlavors()
{
	flavors.clear();
}
//function to print the order
void Order::printOrder()
{
	//prints size
	cout<<"**Order "<<counter<<": "<<yogurtSize<<" ";
	//for each element of flavors vector, print out the first four characters of the flavor
	for(size_t i=0; i<flavors.size()-1; ++i)
		//is flavors.size()-1 because size of vector is going to be 1 bigger than the max index of the elements, since those start at 0
	{
		cout<<flavors[i].substr(0,4)<<"-";
	}
	
	cout<<"**"<<endl;
	return;
}

//function to continue looping for next order
bool addAnotherOrderQ()
{
	//variable only used in this function
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
//function to print out total costs and tax
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
