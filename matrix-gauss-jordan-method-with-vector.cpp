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

void LeeVec(int n, double A[][1]){
	for(int i=0;i<n;i++){
		cout<<"Entre componente	"<<i<<" del vector solucion = ";
		cin>>A[i][1];
		cout<<endl;
		}
}

void impVec(int n, double A[][1]){
	for(int i=0;i<n;i++){
			cout<<A[i][1]<<"\t";
		cout<<endl;	
	}
}


int main()
{
	int n;
	cout<<"Introduzca el numero de filas y columnas "; cin>>n;
	
	double A[n][20],k=0,l=0,B[n][1],s=0;
	
	LeeMat(n,A);
	LeeVec(n,B);
	
	impMat(n,A);
	cout<<" = "<<"\t";
	impVec(n,B);
	cout<<endl;
	
	
	for(int i = 0; i <(n-1);i++){
		for(int j = i+1; j < n ;j++){
			k=(A[j][i]/A[i][i]);
			for(int h=0;h<n;h++){
					A[j][h]=A[j][h]-(k*A[i][h]);
			}
			B[j][1]=B[j][1]-(k*B[i][1]);
		}
	}
	impMat(n,A);
	cout<<" = "<<"\t";
	impVec(n,B);
	cout<<endl;
	
	for(int i = (n-1) ; i >0;i--){
		for(int j = (i-1); j >= 0;j--){
			l=(A[j][i]/A[i][i]);
			for(int h=(n-1);h>=0;h--){
					A[j][h]=A[j][h]-(l*A[i][h]);
			}
			B[j][1]=B[j][1]-(l*B[i][1]);
		}
	}
	
	impMat(n,A);
	cout<<" = "<<"\t";
	impVec(n,B);
	cout<<endl;
	
	for(int i = 0; i <n;i++){
		s=A[i][i];
		for(int j = 0; j <n;j++)
			A[i][j]= A[i][j]*(1/s);
		B[i][1]=B[i][1]*(1/s);
	}
	
	impMat(n,A);
	cout<<" = "<<"\t";
	impVec(n,B);
	
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
