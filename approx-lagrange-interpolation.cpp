/*interpolacion: polinomio de lagrange

en un estudio se tiene solo un numero discreto de datos, que probablemente se aproxima al comportamiento de una funcion determinada. el exito del metodo esta en la cantidad de datos que disponibles. 7
la teoria dice f(x)=Psub(n)=?, la idea es encontrar el polinomio que dara o aproximara al x deseado.
se quiere llegar a un polinomio de grado n-1, donde n es el numero de datos que son conocidos y f(xi)=Pn(xi). 
x0<x<x2 (menor o igual) tener encuenta que x0 es el menor de todos los datos disponibles y x2 el mayor de todos.
*/
#include <iostream>
#include <cstdlib>
using namespace std;
void leerareg(int n, double X[]){
	for(int i=0;i<n;i++)
	cin>>X[i];
}
double sumatoria (int n, double X[], double Y[], double x){
	double f=0;
	for(int k=0;k<n;k++){
		double g=1;
		for(int i=0;i<n;i++){
			if( i!=k)
				g*=(x-X[i])/(X[k]-X[i]);			
		}
		f+=Y[k]*g;
	}
	return f;
}
int main (){
	double Y[50],X[50],x;
	cout<<"ingrese el numero de datos disponibles: ";
	int n;
	cin>>n;
	cout<<"ingrese el valor x, del cual desea conocer su aproximacion: ";
	cin>>x;
	cout<<"ingrese los valores de los datos ";
	leerareg(n,X);
	cout<<endl;
	cout<<"ingrese los valores de las imagenes de los datos ";
	leerareg(n,Y);
	cout<<endl;
	cout << sumatoria(n,X,Y,x);
	system("pause>nul");
}
