#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 50
#define ERRO -1
#define NUL -1
#define true 1
#define false 0

int opcao;

/*Usei o Dev-Cpp 5.11 para desenvolver este projeto, nele o código "typedef int bool;" não é necessário, 
caso não compile em outro compilador, favor remover o comentário da linha 11*/

//typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
	int prox;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX];
	int inicio;
	int dispo;
} TANQUE;

void inicializarTanque(TANQUE *l){
	int i;
	l -> inicio = NUL;
	l -> dispo = 0;
	for (i = 0; i < MAX-1; i++) {
		l -> A[i].prox = i + 1;
	}
l -> A[MAX-1].prox = NUL;
} 

void exibirTanque(TANQUE *l){
	int i = l -> inicio;
	printf("Tanque: \" ");
	while (i != NUL){
		printf("%d ", l->A[i].chave); 
		i = l -> A[i].prox;
	}
printf("\"\n");
} 

/*int tamanho(TANQUE *l) {
	int i = l->inicio;
	int tam = 0;
	while (i != NUL){
		tam++;
		i = l->A[i].prox;
  }
return tam;
}*/

/*int tamanhoEmBytes(TANQUE *l) {
	return(sizeof(TANQUE));
}*/

int buscaSeq(TIPOCHAVE ch, TANQUE *l){
	int i = l->inicio;
	while (i != NUL){
		if (l -> A[i].chave == ch) {
			return i;
		}
	i = l -> A[i].prox;
	}
return NUL;
}

int buscaSeqExc(TIPOCHAVE ch, TANQUE *l, int *ant){
	*ant = NUL;
	int i = l -> inicio;
	while ((i != NUL) && (l -> A[i].chave<ch)){
		*ant = i;
		i = l -> A[i].prox;
	}

	if ((i != NUL) && (l -> A[i].chave == ch)) {
		return i;
	}
return NUL;
}

int obterNo(TANQUE *l){
	int resultado = l->dispo;
	if (l -> dispo != NUL) {
		l -> dispo = l -> A[l -> dispo].prox;
	}
return resultado;
}

void devolverNo(TANQUE *l, int j){
	l -> A[j].prox = l -> dispo;
	l -> dispo = j;
}

bool excluirElemTanque(TIPOCHAVE ch, TANQUE *l){
	int ant, i;
	i = buscaSeqExc(ch, l, &ant);
	if (i == NUL) {
		return false;
	}
	
	if (ant == NUL) {
		l -> inicio = l -> A[i].prox;
	}
	
	else {
		l -> A[ant].prox = l -> A[i].prox;
	}
devolverNo(l,i);
return true;
}

void destruirTanque(TANQUE *l) {
	inicializarTanque(l);
}

bool inserirElemTanqueOrd(REGISTRO reg, TANQUE *l) {
	if (l -> dispo == NUL) {
		return false;
	}
	
	TIPOCHAVE ch = reg.chave;
	int ant, i;
	i = buscaSeqExc(ch, l, &ant);
	if (i != NUL)  {
		return false;
	}
	
	i = obterNo(l);
	l -> A[i] = reg;
	if (ant == NUL) {
		l -> A[i].prox = l->inicio;
		l -> inicio = i;
	}
	
	else {
		l -> A[i].prox = l -> A[ant].prox;
		l -> A[ant].prox = i;
	}  
return true;
}
