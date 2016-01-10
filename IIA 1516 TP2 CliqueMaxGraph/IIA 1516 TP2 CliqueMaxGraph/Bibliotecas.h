#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DEFAULT_RUNS	20
#define iteracoes		200


#define	PM		 0.001
#define	PR		 0.7
#define	tsize	 2
#define	max_gen  100

#define max_obj 500


// EStrutura para armazenar parametros
struct info {
	int popsize;
	float pm;
	float pr;
	//int tsize;
	float ro;
	int numGenes;
	int capacity;
	int numGenerations;
};


// Individuo (solucao)
typedef struct individual chrom, *pchrom;

struct individual {
	int p[max_obj];
	float fitness;
	int valido;
};