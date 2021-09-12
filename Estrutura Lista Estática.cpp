#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 10
#define ERRO -1
#define true 1
#define false 0

int i = 0, opcao;

typedef int TIPOCHAVE;

typedef struct{
	TIPOCHAVE chave;
} REGISTRO;

typedef struct {
	REGISTRO A[MAX+1];
	int nroElem;
} LISTA;

void inicializarLista(LISTA *l){
	l->nroElem = 0;
} 

void exibirLista(LISTA *l){
	int i;
	
	printf("Lista: \" ");
	for (i=0; i < l->nroElem; i++)
    printf("%d ", l->A[i].chave); 
	printf("\"\n");
} 

int tam(LISTA *l) {
	return(l->nroElem);
} 

int tamEmBytes(LISTA *l) {
	return(sizeof(LISTA));
} 

void destruirLista(LISTA *l) {
	l->nroElem = 0;
} 

bool incluirElemLista(REGISTRO reg, int i, LISTA *l){
	int j;
	
	if ((l->nroElem >= MAX) || (i < 1) || (i > (l->nroElem+1))) {
		return(false);
	}
	if((l->nroElem > 0) && (i < l->nroElem+1)){
		for (j = l->nroElem; j >= i; j--) {
			l->A[j] = l->A[j-1];
		}
	}
	
	l->A[i-1] = reg;
	l->nroElem++;
	return(true);
}

int buscaSeq(TIPOCHAVE ch, LISTA *l) {
	while (i < l->nroElem){
		if(ch == l->A[i].chave) {
			return(i);
		}
		
		else {
			i++;
	    }
	}
	return(ERRO);
}

bool incluirElemListaOrd(REGISTRO reg, LISTA *l) {
	int x = 0;
	
	TIPOCHAVE ch = reg.chave;
	if(l->nroElem >= MAX) {
		return(false);
	}
	
	l->A[l->nroElem].chave = ch;
	while(l->A[x].chave < ch) {
		x++;
	}
	
	if((l->A[x].chave == ch) && (x < l->nroElem)) {
		return(false);
	}
	
	else {
		return(incluirElemLista(reg, x+1, l));
	}
}

bool excluirElemLista(TIPOCHAVE ch, LISTA *l) { 
	int pos, j;
	pos = buscaSeq(ch, l);
	if(pos == ERRO) {
		return(false);
	}
	
	for(j = pos; j < l->nroElem-1; j++) {
		l->A[j] = l->A[j+1];
	}
	
	l->nroElem--;
	return(true);
}
