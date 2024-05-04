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

void id(int n, double I[][20]){
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(j!=i)
				I[i][j]=0;
			else
				I[i][j]=1;
		}
}

void Gaus(int n,double A[][20],double I[][20],double k){
	for(int i = 0; i <(n-1);i++){
		for(int j = i+1; j < n ;j++){
			k=(A[j][i]/A[i][i]);
			for(int h=0;h<n;h++){
					A[j][h]=A[j][h]-(k*A[i][h]);
					I[j][h]=I[j][h]-(k*I[i][h]);
			}
		}
	}
}

void Jordan(int n,double A[][20],double I[][20],double l,double t){
	for(int i = (n-1) ; i >0;i--){
		for(int j = (i-1); j >= 0;j--){
			l=(A[j][i]/A[i][i]);
			for(int h=(n-1);h>=0;h--){
					A[j][h]=A[j][h]-(l*A[i][h]);
					I[j][h]=I[j][h]-(l*I[i][h]);
			}
		}
	}
	
	for(int i = 0; i <n;i++){
		t=A[i][i];
		for(int j = 0; j <n;j++){
			A[i][j]= A[i][j]*(1/t);
			I[i][j]= I[i][j]*(1/t);
		}
	}
}

double ProMul(int n,int f,int c,double A[][20],double B[][1]){
	double s=0;
	for(int i=0;i<n;i++)
			s=s+(A[f][i]*B[i][c]);
	return s;
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
	
	double A[n][20],k=0,l=0,I[n][20],t=0,B[n][1],M[n][1];
	
	LeeMat(n,A);
	id(n,I);
	LeeVec(n,B);
	
	cout<<"La matriz es "<<endl;
	impMat(n,A);
	cout<<"El vector de terminos independientes es "<<endl;
	impVec(n,B);
	cout<<endl;

	
	Gaus(n,A,I,k);
	Jordan(n,A,I,l,t);
	
	
	cout<<"La matriz inversa es "<<endl;
	impMat(n,I);
	
	/*for(int i=0;i<n;i++)
				M[i][0]=ProMul(n,i,0,I,B);
	
	cout<<"El vector resultado es "<<endl;
	impVec(n,M);*/
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
