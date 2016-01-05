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
	int **p = NULL, **q = NULL;
	int i = 0, j = 0, valor1 = 0, valor2 = 0, arestas = 0, vertices = 0;
	char *c1, *c2="p";
	int a = 1;
	///////////Abertura de ficheiro
	f = fopen(nome, "rb");
	if (!f)
	{
		printf("Erro no acesso ao ficheiro dos dados\n");
		exit(1);
	}

	///////////Leitura de ficheiro


	while (!(feof(f)))
	{
		
		
		fscanf(f, "%c", c1);
		if (strcmp(c1, c2) == 0)
		{
			printf("%c", c1);
			system("PAUSE");
		}
		printf("Vou ler");
		system("PAUSE");
		//while (a == 1)
		//{
		//	fscanf(f, "%c", &c1);
		//	printf("%c", c1);
		//	a = 0;
		//	if (strcmp(&c1, "p") == 0)
		//	{
		//	
		//		printf("Entrei");
		//		//fscanf(f, "%s", &c2);
		//		//printf("%s", c2);
		//		//if (strcmp(&c2, "edge") == 0)
		//		//	a = 0;
		//		//break;
		//	}
		//} 

		//fscanf(f, /*"%c*/" %s %d %d",/* &c1,*/ &c2, n, &arestas); // Detecta se já estamos na parte do ficheiro que interessa
		exit(0);
		if ( a == 1/*a == 1strcmp(&c1, "p") == 0 &&  strcmp(&c2, "edge") == 0*/)
		{

			
			//// Alocacao dinamica da matriz
			//p = malloc(sizeof(int)*(*n)*(*n));
			//if (!p)
			//{
			//	printf("Erro na alocacao de memoria\n");
			//	exit(1);
			//}
			//q = p;

			//do
			//{
			//	fscanf(f, "%c %d %d", &c1, &valor1, &valor2);
			//	if (strcmp(c1, "e") == 0)
			//	{
			//		
			//		q[valor1][valor2] = 1;
			//		q[valor2][valor1] = 1;

			//	}
			//} while (strcmp(c1, "e") == 0);
		}
	}
	fclose(f);
	return p;
}


// Gera a solucao inicial
// Parametros: solucao, numero de vertices
void gera_sol_inicial(int *sol, int v)
{
	int i, x;
	
	for(i=0; i<v; i++)
	 sol[i]=0;
	 
	for(i=0; i<v/2; i++)
    {
        do
			x = random_l_h(0, v-1);
        while(sol[x] != 0);
        sol[x]=1;
    }	
}

// Escreve solucao
// Parametros: solucao e numero de vertices
void escreve_sol(int *sol, int vert)
{
	int i;
	
	printf("\nConjunto A: ");
	for(i=0; i<vert; i++)
		if(sol[i]==0)
			printf("%2d  ", i);
	printf("\nConjunto B: ");
	for(i=0; i<vert; i++)
		if(sol[i]==1)
			printf("%2d  ", i);
	printf("\n");
}


// copia vector b para a (tamanho n)
void substitui(int a[], int b[], int n)
{
    int i;
    for(i=0; i<n; i++)
        a[i]=b[i];
}


// Inicializa o gerador de numeros aleatorios
void init_rand()
{
	srand((unsigned)time(NULL));
}


// Devolve valor inteiro aleatorio entre min e max
int random_l_h(int min, int max)
{
	return min + rand() % (max-min+1);
}


// Devolve um valor real aleatorio do intervalo [0, 1]  
float rand_01()
{
	return ((float)rand())/RAND_MAX;
}


