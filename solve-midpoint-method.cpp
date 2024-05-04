#include <iostream>
#include <cstdlib>
#include <math.h>

using namespace std;

double f(double x){
	return pow(x,2);
}

double g(double x){
	return x-f(x);
}

int main() {
	system("title Metodo del punto medio (Patata V2)");
	system("color F0");
	double x,a,b,respuesta,e=0.0000000001;
	/*cin >> a;
	cin >> b;*/
	cin >> x;
	while(!(fabs(g(x)-x)<e)){
		respuesta=x;
		x=g(x);
	}
	cout << respuesta;
	system("pause>nul");
}

