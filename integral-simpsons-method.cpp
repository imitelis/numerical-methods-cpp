#include <math.h>
#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x) {
    return x*x;
}

int main() {
    int n;
	double a,b;
	cout << "Ingrese a: ";
	cin >> a;
	cout << "Ingrese b: ";
	cin >> b;
	do {
		cout << "Ingrese el numero de intervalos n (numero par): ";
		cin >> n;
	} while(n%2!=0);
	double Resultado=0,Dx=(double) (b-a)/n;
	for(int i=0;i<=n;i++) {
	    double x=(double) a+i*Dx;
	    if(i==0 || i==n) {
	        Resultado+=f(x);
		} else if(i%2==0) {
			Resultado+=2*f(x);
	    } else {
			Resultado+=4*f(x);
		}
	}
	Resultado*=Dx/3;
	cout << endl
		 << "    " << b << endl
		 << "   /" << endl
		 << "   [" << endl
		 << "   I f(x) dx = " << Resultado << endl
		 << "   ]" << endl
		 << "   /" << endl
		 << "    " << a << endl;
	system("pause>nul");
	return 0;
}

