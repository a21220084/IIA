#include "Bibliotecas.h"
#include "utils.h"
#include "funcao.h"
#include "algoritmo.h"

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
	int **grafo = NULL, **sol, **best;
	int vert, runs, num_iter = 10, i, k, custo, best_custo;
	float mbf = 0.0;

	//////////////////DEFINE SE QUEREMOS MANDAR ARGUMENTOS POR LINHAS COMANDOS OU AO CHAMAR O EXECUTAVEL
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

		// //////////////////////////2º Preenche matriz de adjacencias ////////////////////////////
	grafo = init_dados(nome_fich, &vert);

	interface();

	///////////////////////ALOCA MEMORIA PARA A VARIAVEL 'SOL'////////////////

	sol = malloc(sizeof(int)*(vert));
	for (int i = 0; i < vert; i++)
	{
		sol[i] = malloc(sizeof(int)*vert);	//Para cada linha do array aloca o numcolunas inserido
	}

	///////////////////////ALOCA MEMORIA PARA A VARIAVEL 'BEST'////////////////

	best = malloc(sizeof(int)*(vert));
	for (int i = 0; i < vert; i++)
	{
		best[i] = malloc(sizeof(int)*vert);	//Para cada linha do array aloca o numcolunas inserido
	}

	if (sol == NULL || best == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}

	//for (k = 0; k<runs; k++)
	//{
	//	// Gerar solucao inicial
	//	//gera_sol_inicial(sol, vert);		// Não tem interesse para o trabalho pratico porque inicializamos já uma matriz a 0

	//	// Trepa colinas
	//	custo = trepa_colinas(sol, grafo, vert, num_iter);

	//	// Escreve resultados da repeticao k
	//	printf("\nRepeticao %d:", k);
	//	escreve_sol(sol, vert);
	//	printf("Custo final: %2d\n", custo);

	//	mbf += custo;
	//	if (k == 0 || best_custo > custo)
	//	{
	//		best_custo = custo;
	//		substitui(best, sol, vert);
	//	}
	//}

	//// Escreve resultados globais
	//printf("\n\nMBF: %f\n", mbf / k);
	//printf("\nMelhor solucao encontrada");
	//escreve_sol(best, vert);
	//printf("Custo final: %2d\n", best_custo);

	free(grafo);
	free(sol);
	free(best);

}
