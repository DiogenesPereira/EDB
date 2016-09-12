#include <iostream>
#include <cmath>

using namespace std;

//int ordena_vetor(int vetor[], int tam);
//void gerar_valor(int vetor, int max);

int main ()
{
	int *vetor;
	int i ,tam = 10, valores;
	cout << "Digite o valor "<< tam << " para ser gravado valores no vetor";
	for (i = 0; i < 10; i++)
	{	
		cin >> vetor[i];
	}	 

	selection_sort(vetor, tam);

//	gerar_valores(vetor[], valores);	

//	ordena_vetor (vetor[], tam);
		
	return 0;
}
//============================================================
/*
void gerar_valores(int vetor[], int max)
{
	int i;
	srand (time(NULL));
	
	for (i = 0; i < 10; i++)
	{	
		vetor[i] = rand() % max;
	}	 
}
*/
//=============================================================

/* int ordena_vetor(int vetor[], int& tam)
{
	vetor[]
	for (int i= 0; i < tam)
}
*/

//=============================================================

void selection_sort(int v[], int tam)
{
	int i, j, min, aux;
	
	for (i = 0; i < tam-1; i++){
		min = i;
		for (j = (i+1); j < tam; j++)
		{
			if (v[min] < v[j])
			{
				min = j;
			}
		}
		if (i != min)
		{
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
		}
	}
}
