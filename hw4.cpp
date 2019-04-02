//Olivia Chen, 4/28/2017 (froyo)
#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

int main()
{
    //repeat at the end of loop each time
	//repeat="yes" otherwise loop will not start in the first place
    string repeat="yes";
	//count is order number and it starts at 1 because order numbers start at 1, subtotal is declared outside of while loop because variable is used outside of loop
    int count = 1;
    double subtotal=0;
    cout<<"Welcome to My Frozen Yogurt!\n";
	
    while (repeat == "yes")
	{
        string size;
        cout<<"What size would you like?\nPlease enter small, medium, or large: "<<endl;
		getline(cin,size);
		
        if(size=="small")
            subtotal+=2.19;
        if(size=="medium")
            subtotal+=3.49;
        if(size=="large")
            subtotal+=4.49;
		//prices are added to subtotal
        
        string f1;
        string f2;
        string f3;
		//f1, f2, and f3 are flavors and are declared before if statements an if-else statements because they need to exist outside of those statements
		
		//using getline instead of cin for flavors names that have spaces
        cout<<"Enter flavor 1: "<<endl;
		getline(cin,f1);
		
        cout<<"Enter flavor 2: "<<endl;
		getline(cin,f2);
		
		//if statement for option to end order
        if(f2 == "DONE")
            cout<<"** Order "<<count<<": "<<size<<" "<<f1.substr(0,4)<<" **"<<endl;
		//substr(0,4) to take the characters 0 to 4 of the flavor
        else
		{
			cout<<"Enter flavor 3: "<<endl;
			getline(cin,f3);
			//this second if-else statement is nested inside the first one because if it is not, then program will ask for f3 even if f2=="DONE"
			if(f3=="DONE")
				cout<<"** Order "<<count<<": "<<size<< " "<<f1.substr(0,4)<<"-"<<f2.substr(0,4)<<" **"<<endl;
			else
				cout<<"** Order "<<count<<": "<<size<< " "<<f1.substr(0,4)<<"-"<<f2.substr(0,4)<<"-"<<f3.substr(0,4)<<" **"<<endl;
		}
		
        cout<<"Would you like to add another order?\nPlease enter yes or no: \n";
        cin>>repeat;
    
        ++count;
		//if the answer is yes then the whole thing loops over to take the second order
    }
    cout<<"Subtotal: $"<<subtotal<<endl;
    cout<<"Tax (8.75%): $";
    cout<<setprecision(2)<<fixed<<0.0875*subtotal<<endl;
	//setprecision is to ensure that there are only 2 digits after the decimal point
	//fixed is so that the figures are after the decimal pt, instead of total sig figs
    cout<<"Total: $";
    cout<<setprecision(2)<<fixed<<1.0875*subtotal<<endl;
	
    return 0;
}

