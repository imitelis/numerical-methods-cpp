#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;

double f(double x){
	return exp(x)+x;
}

double df(double x){
	return exp(x)+1;
}

int main ()
{	
	double a=0, b=0, e=0.0001;
	cout<<"Entre un real : ";
	cin>>a;

		int i=0;
		while(i<100)
		{
			b=(a-(f(a)/df(a)));
			if(e>fabs(b-a))
			{
				cout<<a;
				i=100;
			}
			else{
			a=b;
			
			i++;
		}
		}
	
	
	system("PAUSE");
    return EXIT_SUCCESS;
}

