#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    system("title Factorizacion LU");
    //system("color F0");

    int n;
    cout << "Ingrese el n\243mero de ecuaciones y de incognitas: "; cin >> n;
	cout << endl;
	double A[n][n],B[n],L[n][n],U[n][n],Ui[n][n],Y[n],X[n];
	bool temp=true;


	/** Pedir A */
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
            cout << "Ingrese la componete " << j+1 << " de la ecuaci\242n " << i+1 <<": ";
            cin >> A[i][j];
            U[i][j]=A[i][j];
		}
        cout << "Ingrese la respuesta de la ecuaci\242n " << i+1 <<": ";
        cin >> B[i];
	}


	/** Hallar U */
	for(int i=0;i<n;i++) {
		for(int j=1;j<n-i;j++) {
            double k=U[i+j][i]/U[i][i];
			for(int f=0;f<=n;f++) {
                U[i+j][f]-=k*U[i][f];
			}
		}
	}

	endl(cout);
	cout << "La matriz U (Upper) es: " << endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << U[i][j] << "\t";
		}
		cout << endl;
	}


    /** Hallar L */
    while(temp) {
        double Ua[n][2*n];
        for(int i=0;i<n;i++) {
            for(int j=0;j<2*n;j++) {
                if(j<n) {
                    Ua[i][j]=U[i][j];
                } else {
                    Ua[i][j]=((i+n==j)?1:0);
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int f=2*n-1;f>=0;f--) {
                Ua[i][f]/=Ua[i][i];
            }
            for(int j=1;j<=n-i;j++) {
                double k=Ua[i+j][i]/Ua[i][i];
                for(int c=0;c<2*n;c++) {
                    Ua[i+j][c]-=k*Ua[i][c];
                }
            }
            for(int j=1;j<=i;j++) {
                double k=Ua[i-j][i]/Ua[i][i];
                for(int c=0;c<2*n;c++) {
                    Ua[i-j][c]-=k*Ua[i][c];
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                Ui[i][j]=Ua[i][j+n];
            }
        }
        temp=false;
    }
    temp=true;

    endl(cout);
	cout << "La matriz Ui es: " << endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << Ui[i][j] << "\t";
		}
		cout << endl;
	}


	/** Hallar L */
	for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            double s=0;
            for(int k=0;k<n;k++){
                s+=A[i][k]*Ui[k][j];
            }
            L[i][j]=s;
        }
	}

	endl(cout);
	cout << "La matriz L (Lower) es: " << endl;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << L[i][j] << "\t";
		}
		cout << endl;
	}


	/** Hallar Y */
	while(temp) {
        double LB[n][n+1];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n+1;j++) {
                if(j<n) {
                    LB[i][j]=L[i][j];
                } else {
                    LB[i][j]=B[i];
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int f=n;f>=0;f--) {
                LB[i][f]/=LB[i][i];
            }
            for(int j=1;j<=n-i;j++) {
                double k=LB[i+j][i]/LB[i][i];
                for(int f=0;f<=n;f++) {
                    LB[i+j][f]-=k*LB[i][f];
                }
            }
            for(int j=1;j<=i;j++) {
                double k=LB[i-j][i]/LB[i][i];
                for(int f=0;f<=n;f++) {
                    LB[i-j][f]-=k*LB[i][f];
                }
            }
        }
        for(int i=0;i<n;i++) {
            Y[i]=LB[i][n];
        }
        temp=false;
	}
	temp=true;

	endl(cout);
	cout << "El vector Y es: " << endl;
	for(int i=0;i<n;i++) {
        cout << Y[i] << "\t";
	}
	endl(cout);


	/** Hallar X */
	while(temp) {
        double UY[n][n+1];
        for(int i=0;i<n;i++) {
            for(int j=0;j<n+1;j++) {
                if(j<n) {
                    UY[i][j]=U[i][j];
                } else {
                    UY[i][j]=Y[i];
                }
            }
        }
        for(int i=0;i<n;i++) {
            for(int f=n;f>=0;f--) {
                UY[i][f]/=UY[i][i];
            }
            for(int j=1;j<=n-i;j++) {
                double k=UY[i+j][i]/UY[i][i];
                for(int f=0;f<=n;f++) {
                    UY[i+j][f]-=k*UY[i][f];
                }
            }
            for(int j=1;j<=i;j++) {
                double k=UY[i-j][i]/UY[i][i];
                for(int f=0;f<=n;f++) {
                    UY[i-j][f]-=k*UY[i][f];
                }
            }
        }
        for(int i=0;i<n;i++) {
            X[i]=UY[i][n];
        }
        temp=false;
	}
	temp=true;

	endl(cout);
	cout << "El vector X (Soluci\242n) es: " << endl;
	for(int i=0;i<n;i++) {
        cout << X[i] << "\t";
	}
	endl(cout);

    system("pause>nul");
    return 0;
}
