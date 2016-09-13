#include <iostream>
#include <cmath>

using namespace std;

void selection_vetor(int vetor[], int tam);
void gerar_valor(int vetor, int max);
void bubble_vetor(int vetor[], int tam);

int main ()
{
	int vetor[];
	int i, valores, tam = 10;
	cout << "Digite o valor \"x\" para ser gerado valores aleatórios";
	cin >> valores;

	gerar_valores(vetor[], tam);	

	ordena_vetor (vetor[], tam);
		
	return 0;
}

void gerar_valores(int vetor[], int max)
{
	int i;
	srand (time(NULL));
	
	for (i = 0; i < 10; i++)
	{	
		vetor[i] = rand() % max;
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
	int i, aux;
	for (i = 0; i< tam; i++)
}
