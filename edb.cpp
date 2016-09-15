#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void gerar_valores(int* vetor, int valores);
void selection_vetor(int vetor[], int tam);
void bubble_vetor(int vetor[], int tam);


int main ()
{
	int i, valores, tam, *ptr, *vetor;
	
	cout << "Digite um valor para o tamanho do vetor: " << endl;
	cin >> tam;
	cout << "Digite um valor para ser gerado uma faixa de valores aleatórios: " << endl;
	cin >> valores;

	vetor = nullptr;
	vetor = new int[tam];

	gerar_valores(vetor, valores);	

	selection_vetor(vetor, tam);
	bubble_vetor(vetor, tam);	

	cout << "[";
	for (int i = 0; i < tam; ++i)
	{
		cout << vetor[i] << " ";
	}
	cout << "]" << endl;	

	delete [] vetor;
	vetor = nullptr;

	return 0;
}
//=========================================================

void gerar_valores(int vetor[], int valores)
{
	int i;
	srand (time(NULL));
	
	for (i = 0; i < 10; i++)
	{	
		vetor[i] = rand() % valores;
	}	 
}
//=========================================================
void selection_vetor(int vetor[], int tam)
{
	int i, j, menor, aux;

	for (i = 0; i < (tam - 1); i++)
	{
		menor = i;

		for (j = (i + 1); j < tam; j++)
		{
			if (vetor[j] < vetor[menor])
			{
				menor = j;
			}
		}
		if (i != menor)
		{
			aux = vetor[i];
			vetor[i] = vetor[menor];
			vetor[menor] = aux;
		}
	}
}
//=====================================================
void bubble_vetor(int vetor[], int tam)
{
	int i, j, aux;
	for (i = 0; i < tam; i++)
	{
		for (j = 0; i < tam; j++)
		{
			if (vetor[j] > vetor[j+1])
			{
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
			}
		}
	}
}
