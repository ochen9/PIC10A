
//Olivia Chen, 4/14/2017 (money sorting)
#include <iostream>
using namespace std;

int main()
{
    // x is the number of cents entered initially
    int x;
    cout<< "Enter total cents: \n";
    cin>>x;
    
    //dollars is number of dollars, quarters is number of quarters, etc...
    //divide by the number of cents in that amount, ex: 25 cents in quarter and then the new value of x is the number of cents remaining afterwards, which is the value of the coin multiplied by its number
    int dollars = x/100;
    x -= dollars*100;
    
    int quarters = x/25;
    x-= quarters*25;
    
    int dimes = x/10;
    x-= dimes*10;
    
    int nickels = x/5;
    x-= nickels*5;
    
    //didn't declare pennies as new variable, because at this point x should be in the unit of pennies anyway
    
    cout << "This is "<<dollars<< " dollars, " <<quarters<< " quarters, " <<dimes<< " dimes, " <<nickels<< " nickels, and "<<x<< " pennies. \n";
    return 0;
}
