#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

void gerar_valores(int *vetor, int valores);
void selection_vetor(int vetor[], int tam);
void bubble_vetor(int vetor[], int tam);
void insertion_vetor(int vetor[], int tam);
void merge(int vetor[], int inicio, int tam, int meio);
void merge_vetor(int vetor[], int inicio, int tam);
void quick_vetor(int vetor[], int inicio, int tam);
void troca(int vetor[], int i, int j);
int particao(int vetor[], int inicio, int tam);

int main ()
{
	int i, valores, inicio = 0, tam, *ptr, *vetor; 
	
	cout << "Digite um valor para o tamanho do vetor: " << endl;
	cin >> tam;
	int meio = tam / 2;
	cout << "Digite um valor para ser gerado uma faixa de valores aleatórios: " << endl;
	cin >> valores;

	vetor = nullptr;
	vetor = new int[tam];

	gerar_valores(vetor, valores);	
	cout << "Programa espera parâmetro de entrada. Opções abaixo (sem aspas simples): " << endl << "- '1' para selection_vetor " << endl << "- '2' para bubble_vetor." << endl << "- '3' para insertion_vetor." << endl << "- '4' para merge_sort." << endl << "- '5' para quick_sort." << endl << "- '6' para EXIT." << endl;
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
		merge_vetor(vetor, inicio, tam);
	case 5:
		quick_vetor(vetor, inicio, tam);
	case 6: 
		break;
	default:
		cout << "Numero de argumentos invalido!" << endl;
	return EXIT_FAILURE;
    }
	


//	selection_vetor(vetor, tam);
//	bubble_vetor(vetor, tam);
//	InsertionSort(vetor, tam);	

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
//=================================================================
void merge_vetor(int vetor[], int inicio, int tam) 
{
	int meio;

    if(inicio == tam) return;

    // ordenacao recursiva das duas metades
    meio = (inicio + tam ) / 2;
    merge_vetor(vetor, inicio, meio);
    merge_vetor(vetor, meio + 1, tam);
    merge(vetor, inicio, tam, meio);

}
//-----------------------------------------------------------------

void merge(int vetor[], int inicio, int tam, int meio)
{
	int i, k, meio2, *vetorTemp;

	// intercalacao no vetor temporario t
	i = inicio;
	meio2 = meio + 1;
	k = inicio;
	vetorTemp;// = new int[tam];//NÃO PRECISA!!!!!

	while(i <= meio && meio2 <= tam) 
	{
		if (i <= meio )// i passou do final da primeira metade, pegar v[j]
		{
			vetorTemp[k] = vetor[i];
			k++;
		}
		else {// j passou do final da segunda metade, pegar v[i]
                	vetorTemp[k] = vetor[meio2];
			k++;
        	    }
	}
	//se existem números do primeiro vetor que não foram intercalados
	for(i = inicio; i <= meio; i++)
	{
		vetorTemp[k] = vetor[i];
		k ++;
	}
	//se existem números do segundo vetor que não foram intercalados
	for(i = meio2; i <= tam; i++)
	{
		vetorTemp[k] = vetor[i];
		k ++;
	}
	// copia vetor intercalado para o vetor original
	for(i = inicio; i <= tam; i++)
	{
		vetor[i] = vetorTemp[i];
	}
/*
    delete [] vetorTemp;
	vetorTemp = nullptr;*/
}
//=================================================================

void troca(int vetor[], int i, int j)
{
	int aux;
	aux = vetor[i];
	vetor[i] = vetor[j];
	vetor[j] = aux;
}
//-----------------------------------------------------------------
int particao(int vetor[], int inicio, int tam)
{
	int i, j, pivo;
	
	pivo = vetor[(inicio+tam) / 2];

	i = inicio - 1;
	j = tam + 1;
	
	while (i < j)
	{
		do
		{
			j -= 1;
		} while(vetor[j] > pivo);

		do
		{
			i += 1;
		} while(vetor[i] < pivo);

		if(i < j)
		troca(vetor, i, j);
	}
	return j;
}
//-----------------------------------------------------------------
void quick_vetor(int vetor[], int inicio, int tam)
{
	int j;
	if (inicio < tam)
	{
		j = particao(vetor, inicio, tam);
		quick_vetor(vetor, inicio, j);
		quick_vetor(vetor, j + 1, tam);
	}
}
