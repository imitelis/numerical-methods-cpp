#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x,3)+2*pow(x,2)+0.5;
}

double fp(double x0) {
    return 3*pow(x0,2)+4*pow(x0,2)+0.5;
}

int main(void) {
    double x,e=0.00000000000001;
    double r=0;
    cout << "Pido x: ";
    cin >> x;
    while(e<fabs(f(x))) {
        r=x;
        x-=f(x)/fp(x);
        cout << setprecision(20) << fixed << r << "\t" << f(x) << "\t" << fp(x) << endl;
    }
    cout << endl << "Raiz f(x): " << r << endl;
    return 0;
}
