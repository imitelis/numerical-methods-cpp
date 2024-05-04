#include <iostream>
#include <cstdlib>
using namespace std;

void LeeMat(int n, double A[][20]){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cout<<"Entre componente	"<<i<<", "<<j<<" = ";
			cin>>A[i][j];
			cout<<endl;
		}
}

void impMat(int n, double A[][20]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<A[i][j]<<"\t";
		cout<<endl;	
	}
}



int main()
{
	int n;
	cout<<"Introduzca el numero de filas y columnas "; cin>>n;
	
	double A[n][20],k,B[n][20];
	
	LeeMat(n,A);
	
	impMat(n,A);
	cout<<endl;
	
	
	for(int i = 0; i <(n-1);i++){
		for(int j = i+1; j < n ;j++){
			k=(A[j][i]/A[i][i]);
			for(int h=0;h<n;h++)
					A[j][h]=A[j][h]-(k*A[i][h]);
		}
	}
	
	
	impMat(n,A);
	system("PAUSE");
    return EXIT_SUCCESS;
}
