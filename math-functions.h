/*Hola, Para llamar esta cabecera(header) solo deben colocar este archivo dentro de la carpeta del proyecto de Dev-C++, Code::Blocks, Geany o cualquier IDE(Entorno de Desarrollo Integrado) que estén usado, incluso si usan GCC. Escribir en la parte superior #include "todo.h" (con comillas).
Esto les ayudara sobre todo si utilizan un IDE con función de autocompletar, o de indicación de parámetros, pues les indicaran como están colocados los parámetros.

Si leyeron esto tan largo completo, si conocen LaTeX, existe un código que es \input{} que tiene exactamente la misma función que #include en C++, escribir todo lo que este en él .h en el archivo.

Recuerden por ultimo que esto es libre y pueden modificar el codigo a su antojo.*/


//Factorial de n
long long int factorial(int n) {
	if(n>20) {
		std::cout << "El numero ingresado es demasiado grande, por favor ingrese uno menor. ";
		return -1;
	}
	if(n==0) return 1;
	return n*factorial(n-1);
}


//Fibonacci de n
long int fibonacci(int n) {
	if(n==1||n==2) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}


//Leer Arreglo
void leerArreglo(double Arreglo[],int Tamano) {
	for(int i=0;i<Tamano;i++) {
		std::cout << "Escriba la posicion " << i+1 <<": ";
		std::cin >> Arreglo[i];
	}
}


//Escribir Arreglo
void imprimirArreglo(double Arreglo[],int Tamano) {
    for (int i=0;i<Tamano;i++) std::cout << Arreglo[i] << "\t";
}



//Leer Matriz
void leerMatriz(double Matriz[][20],int mFilas,int nColumnas) {
    for(int i=0;i<mFilas;i++) {
        for(int j=0;j<nColumnas;j++) {
            std::cout << "Escriba la posicion (" << i+1 << "," << j+1 <<"): ";
            std::cin >> Matriz[i][j];
        }
    }
}



//Imprimir Matriz
void imprimirMatriz(double Matriz[][20],int mFilas,int nColumnas) {
    for(int i=0;i<mFilas;i++) {
        for(int j=0;j<nColumnas;j++) {
            std::cout << Matriz[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}



//Suma de Matrices
void sumaMatriz(double MatrizA[][20],double MatrizB[][20],double Suma[][20],int mFilas,int nColumnas) {
    for(int i=0;i<mFilas;i++) {
        for(int j=0;j<nColumnas;j++) {
            Suma[i][j]=MatrizA[i][j]+MatrizB[i][j];
        }
    }
}



//Multiplicacion de Matrices
void multMatriz(double MatrizA[][20],double MatrizB[][20],double Multi[][20],int mFilasA,int pFilaColumnaAB,int nColumnasB) {
    for(int i=0;i<mFilasA;i++) {
        for(int j=0;j<nColumnasB;j++) {
            Multi[i][j]=0;
            for(int k=0;k<pFilaColumnaAB;k++) {
                Multi[i][j]+=MatrizA[i][k]*MatrizB[k][j];
            }
        }
    }
}
