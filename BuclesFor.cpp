#include <iostream>
#include <chrono>

using namespace std;

void experimentarMatriz(int MAX)
{
	
	std::cout<<"MAX = "<<MAX<<"\n";
	
	int i=0, j=0;
	
	//Inicializar memoria dinámica
	double **A = new double *[MAX];
	for(i=0; i<MAX; i++)
	{
		A[i] = new double [MAX];
	}
	double *x = new double[MAX];
	double *y = new double[MAX];
	
	//Inicializar A, x, y 
	for(i=0; i<MAX; i++)
	{
		for(j=0; j<MAX; j++)
			A[i][j] = rand()%(100-0 + 1) + 0; 
		
		x[i] = rand()%(100-0 + 1) + 0; 
		y[i] = 0;
	}
	
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	//PRIMEROS FOR
	for(i=0; i<MAX; i++)
		for(j=0; j<MAX; j++)
			y[i] += A[i][j]*x[j];
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Primeros Bucles For " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosegundos" << std::endl;
	
	//Setear y con 0s
	for(i=0; i<MAX; i++)
		y[i] = 0;
		
		
	//SEGUNDOS FOR
	
	begin = std::chrono::steady_clock::now();
	for (j = 0; j < MAX; j++)
		for (i = 0; i < MAX; i++)
			y[i] += A[i][j]*x[j];
	end = std::chrono::steady_clock::now();
	
	std::cout << "Segundos Bucles For " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << " nanosegundos" << std::endl;

	//Liberamos la memoria

	delete[] x;
	delete[] y;
	delete[] *A;
	
	for(i=0; i<MAX; i++)
	{
		delete[] *(A+i);
	}		
	delete[] A;
	
}

int main()
{

	//int n = 100;
	//experimentarMatriz(n);
	
	//int n = 500;
	//experimentarMatriz(n);
	
	//int n = 1000;
	//experimentarMatriz(n);
	
	//int n = 5000;
	//experimentarMatriz(n);
	
	int n = 1000;
	experimentarMatriz(n);
	
	
	return 0;	
}
