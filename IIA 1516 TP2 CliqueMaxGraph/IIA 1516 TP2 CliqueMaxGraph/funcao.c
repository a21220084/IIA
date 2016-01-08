#include "funcao.h"

// Calcula a qualidade de uma solucao
// Recebe: solucao, matriz, numero de vertices
// Devolve o custo
int calcula_fit(int a[], int *mat, int vert)
{
	int total = 0, max_lig;
	int i, j;
	max_lig = (vert*(vert - 1)) / 2;		//Calcula o numero max_lig de ligacoes
		for (i = 0; i < vert; i++)
			if (a[i] == 1)			// Alteração de a[i]==0 -> tendo 1 significa que tá analisar os do mesmo conjunto
			{
				for (j = 0; j < vert; j++)
				{
					if (a[j] == 1 && *(mat + i*vert + j) == 1)
					{
						total++;
					}
					
				}
			}
		
		if (total == max_lig)
			return total;			// só deve retornar o total caso todos estejam ligado entre si, ou seja total = numero max_lig de ligacoes para o numero de 1s
		else
		{
			/*printf("Devolvi 0");*/
				return 0;			// caso não se verifique, deve recursivamente calcular outra solução.
		}
	
}


int evaluate(int a[], int *mat, int vert)
{
	int *num_lig;
	int total = 0, max_lig, pos = 0, temp, num_1 = 0;
	int i, j;
	
	num_lig = malloc(sizeof(int)*vert);
	if (num_lig == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}
	for (i = 0; i < vert; i++)



	
		for (i = 0; i < vert; i++)
			if (a[i] == 1)
				num_1++;
	do {
		total = 0;
		max_lig = 0;

		for (i = 0; i < vert; i++)
		{
			num_lig[i] = 0;
			printf("PAWWW%d", i);
			if (a[i] == 1)			// Alteração de a[i]==0 -> tendo 1 significa que tá analisar os do mesmo conjunto
			{
				
				for (j = 0; j < vert; j++)
				{
					
						
					if (a[j] == 1 && *(mat + i*vert + j) == 1)
					{
						if (i != j)
						num_lig[i]++;
						total++;
					}
					/*else
					{
						printf("%d", a[j]);
						a[j] = 0;
						vert = vert - 1;
						printf("%d", a[j]);
					}*/
				}
				printf("\nNLIG: %d\n", num_lig[i]);
			}

		}
		max_lig = (num_1*(num_1 - 1)) / 2;		//Calcula o numero max_lig de ligacoes

		
		for (i = 0, temp = 0; i < vert; i++)
		{
			if (i == 0)
			{
				temp = num_lig[i];
				pos = 0;
				printf("\nTEMP1: %d\n", temp);
			}

			if (num_lig[i] < temp)
			{
				temp = num_lig[i];
				pos = i;
				printf("\nTEMP2: %d\n", temp);
			}
	
			
		}

		if (temp != max_lig)
		{
			printf("\nTEMP3: %d\n", temp);
			printf("\nNUM1: %d\n", num_1);
			a[pos] = 0;
			num_1--;
			printf("\nNUM1: %d\n", num_1);
		}

		printf("\nTEMP4: %d\n", temp);
		

		
	} while (total != max_lig || num_1 != 1);
	system("PAUSE");

	free(num_lig);
	if (total == max_lig)
		return total;			// só deve retornar o total caso todos estejam ligado entre si, ou seja total = numero max_lig de ligacoes para o numero de 1s
	else
	{
		/*printf("Devolvi 0");*/
		return 0;			// caso não se verifique, deve recursivamente calcular outra solução.
	}



}
