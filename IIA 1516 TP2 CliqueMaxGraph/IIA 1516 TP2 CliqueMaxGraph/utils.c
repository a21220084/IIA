#include "utils.h"
#include <string.h>

////////////////CONFIGURAR LEITURA DE DADOS DO FICHEIRO PARA IGNORAR OS C/////////////////


// Leitura do ficheiro de input
// Recebe: nome do ficheiro, numero de vertices (ptr), numero de iteracoes (ptr)
// Devolve a matriz de adjacencias
//int* init_dados(char *nome, int *n, int *iter)
//{
//	FILE *f;
//	int *p, *q;
//	int i, j;
//
//	f=fopen(nome, "r");
//	if(!f)
//	{
//		printf("Erro no acesso ao ficheiro dos dados\n");
//		exit(1);
//	}
//	
//	// Numero de iteracoes
//	fscanf(f, " %d", iter);
//	
//	// Numero de vertices
//	fscanf(f, " %d", n);
//	
//	// Alocacao dinamica da matriz
//	p = (int**)malloc(sizeof(int)*(*n));
//	if(!p)
//	{
//	    printf("Erro na alocacao de memoria\n");
//	    exit(1);
//	}
//	q=p;
//
//	////////////maestro
//
//	for (i = 0; i<*n; i++)
//	{
//		p[i] = (int *)malloc(sizeof(int)*(*n));
//
//		for (j = 0; j<*n; j++)
//			p[i][j] = 0;
//	}
//	//////////end maestro
//
//	
//	// Preenchimento da matriz
//	for(i=0; i<*n; i++)
//	 for(j=0; j<*n; j++)
//	   fscanf(f, " %d", q++);
//	fclose(f);
//	
//	return p;
//}

int** init_dados(char *nome, int *n)
{
	////////Declaração de variaveis
	FILE *f;
	int **p = NULL , **q = NULL ;
	int i = 0, j = 0, valor1 = 0, valor2 = 0, arestas = 0, vertices = 0, contador = 0;
	char c1;
	

	
	///////////Abertura de ficheiro
	f = fopen(nome, "rb");
	if (!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

	///////////Leitura de ficheiro

	
			
				fscanf(f, "%c%d %d", &c1, n, &arestas); 
				
				printf("char: %c n: %d arestas: %d",c1, *n, arestas);
				
				// Alocacao dinamica da matriz
				p = malloc(sizeof(int)*(*n));
				for (i = 0; i < *n; i++)
				{
					p[i] = malloc(sizeof(int)*(*n));	//Para cada linha do array aloca o numcolunas inserido
				}
				if (!p)
				{
					printf("\nErro na alocacao de memoria\n");
					exit(1);
				}

				q = p;

				for (i = 0; i < *n; i++)		//Inicializamos os primeiros dois numero com zero mais estes vao ser ignorados
					for (j = 0; j < *n; j++)
						q[i][j] = 0;
				
				while(!(feof(f)))
				{
					
						fscanf(f, "%c %d %d ",&c1, &valor1, &valor2);

						printf("\n %d %d\n", valor1, valor2);		//TEMPORARIO	//O PRIMEIRO VALOR é 0 0 porque????

						if (valor1 != 0 && valor2 != 0)
						{
							q[valor1 - 1][valor2 - 1] = 1;
							
							//q[valor2 - 1][valor1 - 1] = 1;

							printf("\n %d \n", q[valor1 - 1][valor2 - 1]);
						}
							
				}


				for (i = 0; i < *n; i++)		//Inicializamos os primeiros dois numero com zero mais estes vao ser ignorados
				{
					for (j = 0; j < *n; j++)
					{
						printf("%d ", q[i][j]);
						if (q[i][j] == 1)
							contador++;

					}
					printf("\n");
				}
				printf(" \n\n CONTADOR: %d arestas \n", contador);
	
	fclose(f);

	if(contador == arestas)
		return p;
	else
	{
		printf("\n\n\n O numero de arestas nao coincide com o ficheiro!\n                   A ABORTAR!!!\n\n");
		exit(1);
		free(p);
	}

}



// Gera a solucao inicial
// Parametros: solucao, numero de vertices
void gera_sol_inicial(int *sol, int v)
{
	int i, x;

	for (i = 0; i<v; i++)
		sol[i] = 0;

	for (i = 0; i<v / 2; i++)
	{
		do
			x = random_l_h(0, v - 1);
		while (sol[x] != 0);
		sol[x] = 1;
	}
}

// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(int *sol, int vert)
{
	int i;

	printf("\nConjunto A: ");
	for (i = 0; i<vert; i++)
		if (sol[i] == 0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for (i = 0; i<vert; i++)
		if (sol[i] == 1)
			printf("%2d  ", i);
	printf("\n");
}


// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
	int i;
	for (i = 0; i<n; i++)
		a[i] = b[i];
}


// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}


// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max - min + 1);
}


// Devolve um valor real aleatorio do intervalo [0, 1]  
float rand_01()
{
	return ((float)rand()) / RAND_MAX;
}