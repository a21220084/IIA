#include "funcao.h"

// Calcula a qualidade de uma solucao
// Recebe: solucao, matriz, numero de vertices
// Devolve o custo
int calcula_fit(int a[], int *mat, int vert)
{
	int total = 0, max_lig, num_1=0;
	int i, j;
	for (i = 0; i < vert; i++)		// Antes de analisar a solução, calcula a quantida de vertices no conjunto
		if (a[i] == 1)
			num_1++;
	max_lig = (num_1*(num_1 - 1)) / 2;		//Calcula o numero max_lig de ligacoes
		for (i = 0; i < vert; i++)
			if (a[i] == 1)			// Alteração de a[i]==0 -> tendo 1 significa que tá analisar os do mesmo conjunto
			{
				for (j = 0; j < vert; j++)
				{
					if (a[j] == 1 && *(mat + i*vert + j) == 1)
					{
						if (i < j)
						{
							total++;
						}
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


int evaluate(int *a, int *mat, int vert)
{
	int *num_lig;
	int total = 0, max_lig, pos = 0, temp, num_1 = 0;
	int i, j;
	
	num_lig = malloc(sizeof(int)*vert);		//Aloca dinamicamente a auxiliar 'num_lig'
	if (num_lig == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}
	for (i = 0; i < vert; i++)



	
		for (i = 0; i < vert; i++)		// Antes de analisar a solução, calcula a quantida de vertices no conjunto
			if (a[i] == 1)
				num_1++;

	printf("NUMERO DE UNS %d", num_1);
	//system("PAUSE");

	max_lig = (num_1*(num_1 - 1)) / 2;		//Calcula o numero max_lig de ligacoes
	do {
		total = 0;
		//max_lig = 0;
		printf("\nNEWNEWNEW\n", num_1);
		for (i = 0; i < vert; i++)
		{
			num_lig[i] = 0;

			if (a[i] == 1)			// Alteração de a[i]==0 -> tendo 1 significa que tá analisar os do mesmo conjunto
			{
				printf("\nVertice n %d\n", i);		//ultimo 1 detecta que é 1 mas nao entra no if, porque nao tem valores com os quais comparar
				for (j = 0; j < vert; j++)
				{
					if (a[j] == 1 && *(mat + i*vert + j) == 1)
					{

						printf("\nI = %d J = %d valor da tabela: %d", i, j, *(mat + i*vert + j));
						/*system("PAUSE");*/
						num_lig[i]++;
						if (i < j)
						{
							total++;
						}		//Total de ligações que existe no conjunto entre os vertices pertencentes a este
					}

				}
				if (num_lig[i] == 0)
				{
					a[i] = 0;
				}

				printf("\nnum_lig[%d] = %d TOTAL=%d MAX_LIG= %d\n", i, num_lig[i], total, max_lig);

			}
			printf("\n------------------------------------------------------------------------\n");
		}
		printf("\n'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''\n");

		max_lig = (num_1*(num_1 - 1)) / 2;		//Calcula o numero max_lig de ligacoes



		if (total != max_lig)
		{

			for (i = 0, temp = 0; i < vert; i++)
			{
				if (a[i] == 1 && temp == 0 && i != vert - 1) //se nenhum dos vertices tiver ligacoes ele entra na mesma...
				{
					temp = num_lig[i];
					pos = i;
					printf("\nTEMP1: %d\n", temp);
				}

				else if (num_lig[i] < temp)
				{
					temp = num_lig[i];
					pos = i;
					printf("\nTEMP2: %d\n", temp);
				}


			}

			if (temp != max_lig)
			{
				a[pos] = 0;
			}
		}




		num_1 = 0;
		for (i = 0; i < vert; i++)
			if (a[i] == 1)
				num_1++;
		max_lig = (num_1*(num_1 - 1)) / 2;
		printf("NUMde1::%d maxlig %d total: %d\n", num_1, max_lig, total);

		
	} while (total != max_lig);

	printf("\n\n\n\n\SAI\n\n\n\n\n");
	if (total> 0)
	{
		/*system("PAUSE");*/
	}

	
	if (total == max_lig)
	{
		free(num_lig);
		return total;			// só deve retornar o total caso todos estejam ligado entre si, ou seja total = numero max_lig de ligacoes para o numero de 1s
	}
	else
	{
		printf("Devolvi 0");
		free(num_lig);
		return 0;			// caso não se verifique, deve recursivamente calcular outra solução.
	}



}
