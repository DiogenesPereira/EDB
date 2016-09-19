#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;

void gerar_valores(int *vetor, int valores);
void selection_vetor(int vetor[], int tam);
void bubble_vetor(int vetor[], int tam);
void insertion_vetor(int vetor[], int tam);
void merge(int vetor[], int inicio, int tam);
void merge_sort(int vetor[], int inicio, int tam);

int main ()
{

	int i, valores, inicio, tam, *ptr, *vetor;
	
	cout << "Digite um valor para o tamanho do vetor: " << endl;
	cin >> tam;
	cout << "Digite um valor para ser gerado uma faixa de valores aleatórios: " << endl;
	cin >> valores;

	vetor = nullptr;
	vetor = new int[tam];

	gerar_valores(vetor, valores);
	cout << "Programa espera parâmetro de entrada. Opções abaixo (sem aspas simples): " << endl << "- '1' para selection_vetor " << endl << "- '2' para bubble_vetor." << endl << "- '3' para insertion_vetor." << endl << "- '4' para merge_sort." << endl << "- '5' para sair." << endl;
	int funcao;
	cin >> funcao;
	switch (funcao) 
  {
    case 1:
      selection_vetor(vetor, tam);
    case 2:
      bubble_vetor(vetor, tam);
    case 3:
    	insertion_vetor(vetor, tam);
    case 4:
    	merge(vetor, inicio, tam);
    case 5: 
      break;
    default:
      cout << "Numero de argumentos invalido!" << endl;
      return EXIT_FAILURE;
    }	

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
		for (j = 0; j < tam; j++)
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
//=====================================================
void insertion_vetor(int vetor[], int tam)
{
	int i, j, aux;

	for (i = 1; i < tam; i++)
	{
		aux = vetor[i];
		j = i - 1;

		while ((j >= 0) && (aux < vetor[j]))
		{
			vetor[j + 1] = vetor[j];
            		j = j - 1;
		}
    
		vetor[j + 1] = aux;
	}
}
void merge(int vetor[], int inicio, int tam) 
{
	int metade;

    if(inicio == tam) return;

    // ordenacao recursiva das duas metades
    metade = (inicio + tam ) / 2;
    merge_sort(vetor, inicio, metade);
    merge_sort(vetor, metade + 1, tam);
    merge(vetor, inicio, tam);

}

    void merge_sort(int vetor[], int inicio, int tam) 
{
    int i, j, k, metade, *vetorTemp;

    // intercalacao no vetor temporario t
    i = inicio;
    j = metade + 1;
    k = 0;
    vetorTemp = new int[tam];

    while(i < metade + 1 || j  < tam + 1) {
        if (i == metade + 1 ) { // i passou do final da primeira metade, pegar v[j]
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == tam + 1) { // j passou do final da segunda metade, pegar v[i]
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (vetor[i] < vetor[j]) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    // copia vetor intercalado para o vetor original
    for(i = inicio; i <= tam; i++) {
        vetor[i] = vetorTemp[i - inicio];
    }

    delete [] vetorTemp;
	vetorTemp = nullptr;
}
