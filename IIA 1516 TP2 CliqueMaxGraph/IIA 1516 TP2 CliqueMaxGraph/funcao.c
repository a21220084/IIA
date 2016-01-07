#include "funcao.h"

// Calcula a qualidade de uma solucao
// Recebe: solucao, matriz, numero de vertices
// Devolve o custo
int calcula_fit(int a[], int *mat, int vert)
{
	int total = 0, maximo;
	int i, j;

	maximo = (vert*(vert - 1)) / 2;		//Calcula o numero maximo de ligacoes

	for(i=0; i<vert; i++)
		if(a[i]==1)			// Alteração de a[i]==0 -> tendo 1 significa que tá analisar os do mesmo conjunto
		{
			for(j=0; j<vert;j++)
				if(a[j]==1 && *(mat+i*vert+j)==1)
				    total++;
		}
	if (total == maximo)
		return total;			// só deve retornar o total caso todos estejam ligado entre si, ou seja total = numero maximo de ligacoes para o numero de 1s
	else
		return 0;				// caso não se verifique, deve recursivamente calcular outra solução.
}

