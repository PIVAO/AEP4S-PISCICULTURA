#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0

int opcao;

typedef int bool;
typedef int TIPOCHAVE;

typedef struct tempRegistro{
	TIPOCHAVE chave;
	struct tempRegistro *prox;
} REGISTRO;

typedef REGISTRO* PONT;

typedef struct {
	PONT inicio;
} TANQUE;

void inicializarTanque(TANQUE *l){
	l->inicio = NULL;
}

void exibirTanque(TANQUE *l){
	PONT end = l->inicio;
	printf("Tanques: \" ");
	while (end != NULL){
    	printf("%d ", end->chave);
    	end = end->prox;
	}
	printf("\"\n");
}

int tamanho(TANQUE *l) {
	PONT end = l->inicio;
	int tam = 0;
	while (end != NULL){
		tam++;
		end = end->prox;
	}
	return tam;
}

int tamanhoEmBytes(TANQUE *l) {
	return(tamanho(l) * sizeof(REGISTRO)) + sizeof(TANQUE);
}

PONT buscaSeq(TIPOCHAVE ch, TANQUE *l){
	PONT pos = l->inicio;
	while (pos != NULL){
		if (pos->chave == ch) {
			return pos;
    	}
    pos = pos->prox;
	}
	return NULL;
}

PONT buscaSeqExc(TIPOCHAVE ch, TANQUE *l, PONT *ant){
	*ant = NULL;
	PONT pos = l->inicio;
	while ((pos != NULL) && (pos->chave<ch)){
		*ant = pos;
		pos = pos->prox;
	}
	if ((pos != NULL) && (pos->chave == ch)) {
		return pos;
	}
	return NULL;
}

bool excluirElemTanque(TIPOCHAVE ch, TANQUE *l){
	PONT ant, i;
	i = buscaSeqExc(ch, l, &ant);
	if (i == NULL) {
		return false;
	}
	if (ant == NULL) {
		l->inicio = i->prox;
	}
	else {
		ant->prox = i->prox;
	}
	free(i);
	return true;
}

void destruirTanque(TANQUE *l) {
	PONT end = l->inicio;
	while (end != NULL){
		PONT apagar = end;
		end = end->prox;
		free(apagar);
	}
	l->inicio = NULL;
}

bool inserirElemTanqueOrd(REGISTRO reg, TANQUE *l) {
	TIPOCHAVE ch = reg.chave;
	PONT ant, i;
	i = buscaSeqExc(ch, l, &ant);
	if (i != NULL)  {
		return false;
	}
	i = (PONT) malloc(sizeof(REGISTRO));
	*i = reg;
	if (ant == NULL) {
		i->prox = l->inicio;
		l->inicio = i;
	}
	else {
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}

PONT retornarPrimeiro(TANQUE *l, TIPOCHAVE *ch){
	if (l->inicio != NULL) {
		*ch = l->inicio->chave;
	}
	return l->inicio;
}

PONT retornarUltimo(TANQUE *l, TIPOCHAVE *ch){
	PONT ultimo = l->inicio;
	if (l->inicio == NULL) {
		return NULL;
	}
	while (ultimo->prox != NULL) {
		ultimo = ultimo->prox;
	}
	*ch = ultimo->chave;
	return ultimo;
} 
