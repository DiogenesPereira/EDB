#include <iostream>
#include <cmath>

using namespace std;

int ordena_vetor(int vetor[], int tam);
void gerar_valor(int vetor, int max);

int main ()
{
	int vetor [], i ,tam = 10, valores;
	cout << "Digite o valor \"x\" para ser gerado valores aleatórios";
	cin >> valores;

	gerar_valores(valores);	

	ordena_vetor (vetor[], tam);
		
	return 0;
}

void gerar_valores(int vetor, int max)
{
	int i;
	srand (time(NULL));
	
	for (i = 0; i < 10; i++)
	{	
		vetor[i] = rand() % max;
	}	 
}
