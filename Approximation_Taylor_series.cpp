#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

long long int factorial(int n) {
	if(n>20) {
		cout << "El numero ingresado es demasiado grande, por favor ingrese uno menor. ";
		return -1;
	}
	if(n==0) return 1;
	return n*factorial(n-1);
}

int main(){
    int n;
	cout << "Ingrese el numero de derivadas de f(a) para el calculo de la serie: ";
    cin >> n;
	double a;
	double fa[n];

    double x;
	cout << "Ingrese el numero del cual desea conocer la aproximacion: ";
    cin >> x;
	
	do {
		cout << "Ingrese a: ";
		cin >> a;
	} while(a==0);

    for(int i=0;i<n;i++) {
		if(i!=0) {
			cout << "         (" << i << ")" << endl;
			cout << "Ingrese f   (a): ";
		} else {
			cout << "Ingrese f(a): ";
		}
        cin >> fa[i];
    }

    double Tx=0;
    for(int k=0;k<n;k++) {;
		Tx+=(fa[k]/factorial(k))*pow(x-a,k);
    }
    cout << "La imagen de " << x << " es aproximadamente " << Tx;
	system("pause>nul");
}
