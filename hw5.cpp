#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include <cstdlib>
using namespace std;

//const for value of e used in function 2
const double e = 2.718281828459045235;

//declaring functions outside of main
double f1(double);
double f2(double);
double f3(double);

int main()
{
	cout<<"Welcome! ";
	int again = 1;
	
	//condition for loop
	while (again==1)
	{
		//prompt+naming functions
		cout<<"Please select a function to numerically integrate from the options below."<<endl;
		cout<<"1. |sin(x^2)|"<<endl;
		cout<<"2. e^(-x^2)"<<endl;
		cout<<"3. |arctan(x)|"<<endl;
		
		int functionNumber; //either f1,f2,f3
		double lower; //lower bound
		double upper; //upper bound
		double iterations; //number of iterations
		double x, y, u; //for random values
		//count is outside of loops otherwise would be infinite
		int count=0;
		
		//inputs for function number, lower and upper bounds, and number of iterations
		cout<<"\nIntegrate function number: "<<endl;
		cin>>functionNumber;
		
		cout<<"Please specify a lower bound: "<<endl;
		cin>>lower;
		cout<<"Please specify an upper bound: "<<endl;
		cin>>upper;
		cout<<"Please specify the number of iterations: "<<endl;
		cin>>iterations;
		
		//calculation if function 1 was selected
		if(functionNumber==1)
		{
			for(int i=0; i<iterations;++i) //repeats loop for number of iterations inputted
			{
				//generating random number
				u = static_cast<double>(rand())/RAND_MAX;
				//using random number to get an x variable within range
				x = u*(upper-lower)+lower;
				
				//generating random y variable
				u = static_cast<double>(rand())/RAND_MAX;
				y = u*(1-0)+0;
				
				//if y value generated falls under f1 curve, adds to count
				if(y<=f1(x))
					++count;
			}
			//estimate of area is number of values that are under the curve divided by total iterations multiplied by area of box created by xmin to xmax and ymin to ymax
			cout<<"The estimate for the area of |sin(x ^2)| from "<<lower<<" to "<<upper<<" is "<<((double)count/iterations)*((upper-lower)*(1-0))<<"."<<endl;
		}
		
		//calulation if function 2 was selected
		if(functionNumber==2)
		{
			for(int i=0; i<iterations;++i)
			{
				//same as if functionNumber==1
				u = static_cast<double>(rand())/RAND_MAX;
				x = u*(upper-lower)+lower;
				
				u = static_cast<double>(rand())/RAND_MAX;
				y = u*(1-0)+0;
				
				if(y<=f2(x))
					++count;
			}
			cout<<"The estimate for the area of e^(-x^2) from "<<lower<<" to "<<upper<<" is "<<((double)count/iterations)*((upper-lower)*(1-0))<<"."<<endl;
		}
		
		//calculation if function 3 was selected
		if(functionNumber==3)
		{
			for(int i=0; i<iterations;++i)
			{
				u = static_cast<double>(rand())/RAND_MAX;
				x = u*(upper-lower)+lower;
				
				u = static_cast<double>(rand())/RAND_MAX;
				y = u*(1.571-0)+0;
				
				if(y<=f3(x))
					++count;
			}
			cout<<"The estimate for the area of |arctan(x)| from "<<lower<<" to "<<upper<<" is "<<((double)count/iterations)*((upper-lower)*(1.571-0))<<"."<<endl;
			//only thing that is different is that ymax is 1.571 instead of 1.
		}
		
		//prompt for continuing loop
		cout<<"Would you like to integrate again? Enter 0 for 'no' and 1 for 'yes': "<<endl;
		cin>>again;
		
	}
	
}

//defining functions outside of main
double f1(double x)
{
	//|sin(x^2)|
 double b = abs(sin(pow(x,2)));
 return b;
}

double f2(double x)
{
	//e^(-x^2)
 double b = pow(e,-pow(x,2));
 return b;
}

double f3(double x)
{
	//|arctan(x)|
 double b = abs(atan(x));
 return b;
}
