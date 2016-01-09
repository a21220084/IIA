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
	int *grafo = NULL, *sol, *best;
	int runs, arestas, vert, num_iter, k, custo, best_custo;
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

	init_rand();
		// //////////////////////////2º Preenche matriz de adjacencias ////////////////////////////
	arestas = init_fich(nome_fich);

	grafo = init_dados("resultados.txt", &vert, &num_iter);


	/*interface();*/

	///////////////////////ALOCA MEMORIA PARA A VARIAVEL 'SOL' e 'BEST'////////////////

	sol = malloc(sizeof(int)*vert);

	best = malloc(sizeof(int)*vert);

	if (sol == NULL || best == NULL)
	{
		printf("Erro na alocacao de memoria");
		exit(1);
	}

	for (k = 0; k<runs; k++)
	{
		do
		{

		// Gerar solucao inicial
		gera_sol_inicial(sol, vert/*, percent*/);	

		custo = evaluate(sol, grafo, vert);
			
		if (custo > 0)
		{
			system("PAUSE");
		}
		} while (!custo != 0);
		system("PAUSE");
		// Trepa colinas
		custo = trepa_colinas(sol, grafo, vert, num_iter);

		// Escreve resultados da repeticao k
		printf("\nRepeticao %d:", k);
		escreve_sol(sol, vert);
		printf("Custo final: %2d\n", custo);

		mbf += custo;
		if (k == 0 || best_custo < custo)
		{
			best_custo = custo;
			substitui(best, sol, vert);
		}
	}

	// Escreve resultados globais
	printf("\n\nMBF: %f\n", mbf / k);
	printf("\nMelhor solucao encontrada");
	escreve_sol(best, vert);
	printf("Custo final: %2d\n", best_custo);

	free(grafo);
	free(sol);
	free(best);

	return 0;
}
