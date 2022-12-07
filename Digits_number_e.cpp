#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main()
{
    //Preliminares del codigo, para crear un vector con todos los numeros primos
    long long int MAX_PRIMOS = 100000;
    long numero=3;
    long primos[MAX_PRIMOS];
    long primos_num=1;


    //Primer numero primo: 2
    primos[0]=2;

    while (primos_num < MAX_PRIMOS)
    {
        long i;        //Indice para la coleccion de numeros primos

        for (i=0;i<primos_num;i++) //"Loop" hasta usar la coleccion completa
        {
            if ( !(numero%primos[i]) ) //Si se hizo una division entera
                break;                 //salimos del "loop"
        }

        if (i == primos_num) //si no se pudo dividir el numero
        {
            primos[primos_num]=numero; //Entonces guardamos el numero en el indice actual
            primos_num++; //incremento del numero de numeros primos
        }

        numero++; //Incrementamos el numero

    }

    //Creamos un arreglo con los digitos del numero e
    int i,j,q,x;
	int longitud;
    ofstream numeroE;
	longitud = 1002;
  	int A[longitud];
	A[0] = 2;
  	for(i = 2; i < longitud; ++i) {
        A[i] = 1;
	}
	numeroE.open("Numero_e.txt");
	numeroE << A[0] ;
	for(i = 1; i < 1001; ++i)
    {
		q = 0;
		for(j = longitud; j > 1; --j)
		{
            x  = 10 * A[j] + q;
            q = x / j;
      		A[j] = x - q*j;
    	}
        numeroE << q;
 	}
	cout << "Archivo \"Numero_e.txt\" creado" << endl;
	numeroE << endl;
 	numeroE.close();

    ifstream numero_e;
    ofstream salida;

    salida.open("Numero_e_Separado.txt");

    char a;
    int inicio=0;

    while(!numero_e.eof())
    {
        numero_e.open("numero_e.txt");
        for (int i=0;i<inicio;i++)
        {
            numero_e >> a;
        };
        for (int j=1;j<=9;j++)
        {
            numero_e >> a;
            salida << a;
        };
        numero_e >> a;
        salida << a << endl;
        inicio++;
        numero_e.close();
    };
    salida.close();

    cout << "Archivo \"Numero_e_Separado.txt\" creado" << endl;
    ifstream dig;
    ofstream odig;
    dig.open("Numero_e_Separado.txt");
    odig.open("Numero_Primo.txt");

    long long int b,k;

    while(!dig.eof())
    {
        dig >> b;
        int c=0;
        for(k=0;k<MAX_PRIMOS;++k)
        {
            double resto=remainder(b,primos[k]);
            cout << primos[k] << " : " << resto << endl;
            if(remainder(b,primos[k])==0)
            {
                c++;
                break;
            };
        };
        if(c==0)
        {
            odig << "Encontrado " << b << endl;
            cout << "Encontrado " << b << endl;
            cout << "Archivo \"Numero_Primo.txt\" creado" << endl;
            return 0;
        };
        cout << b << endl;
    };

    cout << "Archivo \"Numero_Primo.txt\" creado" << endl;
	system("pause");
    return 0;
};
