#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x,3)+2*pow(x,2)+0.5;
}

double fp(double x0,double x1) {
    return (x0-x1)/(f(x0)-f(x1));
}

int main(void) {
    double x0,x1,e=0.00000000000001;
    double r=0;
    cout << "Pido x0: ";
    cin >> x0;
    cout << "Pido x1:";
    cin >> x1;
    while(e<fabs(f(x0))) {
        cout << setprecision(10) << fixed << f(x0) << "\t" << fp(x0,x1) << endl;
        r=x0;
        double t=x0;
        x0-=f(x0)*fp(x0,x1);
        x1=t;
    }
    cout << endl << "Raiz f(x): " << r << endl;
    return 0;
}
