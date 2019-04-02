//Olivia Chen, 4/18/2017 (froyo)
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //used double instead of int because later on I need to be able to get a decimal result and int would just cut it off to zero automatically
    double vanilla;
    double chocolate;
    double strawberry;
    
    cout<< "Enter total vanilla scoops: "<< endl;
    cin>>vanilla;
    
    cout<< "Enter total chocolate scoops: " <<endl;
    cin>>chocolate;
    
    cout<< "Enter total strawberry scoops: " <<endl;
    cin>>strawberry;
    
    double total = vanilla + chocolate + strawberry;
    
    //setprecision is 1 because I want 1 digit after the decimal point to appear. 'fixed' is included otherwise would cut off at 1 sig fig rather than 1 digit after decimal pt
    cout<<"The proportions of vanilla , chocolate , and strawberry are ";
    cout<<setprecision(1)<<fixed<<vanilla/total<< ", "<<chocolate/total<< ", "<<strawberry/total<< " ."<<endl;
    
    
    return 0;
}

