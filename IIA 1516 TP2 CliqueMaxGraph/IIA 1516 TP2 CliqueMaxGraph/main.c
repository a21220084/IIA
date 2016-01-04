#include "Bibliotecas.h"
#include "algoritmo.h"
#include "utils.h"


void interface()
{
	int a = 0;
	printf("Que pesquisa deseja fazer?\n\n 1->Pesquisa Local\n 2->Algoritmo Evolutivo\n 3->Metodo Hibrido\n\n");
	scanf("%d", &a);

	switch (a)
	{
	case 1:
		printf("Ainda nao implementado");
		break;
	case 2:
		printf("Ainda nao implementado");
		break;
	case 3:
		printf("Ainda nao implementado");
		break;
	default:
		break;
	}

}

int main(int argc, char *argv[])
{
	
	char nome_fich[100];
	int **grafo = NULL/*, *sol, *best*/;
	int vert, runs/*, num_iter = 10, i, k, custo, best_custo*/;
	float mbf = 0.0;



	//////////////////1� DEFINE SE QUEREMOS MANDAR ARGUMENTOS POR LINHAS COMANDOS OU AO CHAMAR O EXECUTAVEL
	if (argc == 3)
	{
		runs = atoi(argv[2]);
		strcpy(nome_fich, argv[1]);
	}
	else if (argc == 2)
	{
		runs = DEFAULT_RUNS;
		strcpy(nome_fich, argv[1]);
	}
	else
	{
		runs = DEFAULT_RUNS;
		printf("Nome do Ficheiro: ");
		gets(nome_fich);
	}

	if (runs <= 0)
		return 0;


	// //////////////////////////2� Preenche matriz de adjacencias ////////////////////////////
	grafo = init_dados(nome_fich, &vert);

	/*Deve criar uma solu��o inicial do tamanho da matriz pretendida completamente preenchida com 0, 
		depois disso deve analisar o ficheiro e ir substituir na posi��o indicada no ficheiro*/

	/////////////////3� Escolhe-se o metodo de optimiza��o!!!!/////////////////
	interface();


}
