#include <iostream>
#include <chrono>

using namespace std;

void experimentarMultiplicacionClasicaMatriz(int MAX)
{
	
	std::cout<<"MAX = "<<MAX<<"\n";
	
	int i=0, j=0;
	
	//Inicializar memoria dinámica
	double **A = new double *[MAX];
	double **B = new double *[MAX];
	double **C = new double *[MAX];
	for(i=0; i<MAX; i++)
	{
		A[i] = new double [MAX];
		B[i] = new double [MAX];
		C[i] = new double [MAX];
	}

	
	//Inicializar A, B, y C (matriz resultante) con ceros
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
		{
			A[i][j] = rand()%(100-0 + 1) + 0; 
			B[i][j] = rand()%(100-0 + 1) + 0; 
			C[i][j] = 0;
		}
	}
	

			
			
	//MULTIPLICACIÓN DE MATRICES
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

	for(i = 0; i < MAX; ++i)
	{
		for(j = 0; j < MAX; ++j)
        {
        	for(int k = 0; k < MAX; ++k)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
		}
	}
	
	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Tiempo ejecucion " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosegundos" << std::endl;

	//Liberamos la memoria

	
	
	for(i=0; i<MAX; i++)
	{
		delete[] *(A+i);
		delete[] *(B+i);
		delete[] *(C+i);
	}		
	
	delete[] A;
	delete[] B;
	delete[] C;
	
	delete[] *A;
	delete[] *B;
	delete[] *C;
	
}

int main()
{

	//int n = 100;
	//experimentarMultiplicacionClasicaMatriz(n);
	
	//int n = 500;
	//experimentarMultiplicacionClasicaMatriz(n);
	
	//int n = 1000;
	//experimentarMultiplicacionClasicaMatriz(n);
	
	//int n = 5000;
	//experimentarMultiplicacionClasicaMatriz(n);
	
	int n = 1000;
	experimentarMultiplicacionClasicaMatriz(n);
	
	
	return 0;	
}
