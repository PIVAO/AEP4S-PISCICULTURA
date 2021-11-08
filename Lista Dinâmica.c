#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include "Estrutura Lista Dinâmica.c"

void inserir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Tanque a ser inserido: ");
	scanf("%d",&ch);
	REGISTRO reg;
	reg.chave = ch;
	if (inserirElemTanqueOrd(reg,l)) {
		printf("Tanque %d inserido corretamente.\n",ch);
	}
	else {
		printf("Não foi possível inserir o tanque %d.\n",ch);
	}
}

void buscar(TANQUE *l){
	TIPOCHAVE ch;
	printf("Tanque a ser excluido: ");
	scanf("%d",&ch);
	PONT posicao = buscaSeq(ch,l);
	if (posicao != NULL) {
		printf("Tanque %d encontrado no endereço %d.\n",ch,posicao);
	}
	else {
		printf("Não foi possível encontrar tanque %d.\n",ch);
	}
}

void exibirPrimeiro(TANQUE *l){
	TIPOCHAVE ch;
	PONT posicao = retornarPrimeiro(l,&ch);
	if (posicao != NULL) {
		printf("Primeiro tanque %d encontrado no endereço %d.\n",ch,posicao);
	}
	else {
		printf("Não foi possível encontrar o primeiro tanque (lista vazia).\n");
	}
}

void exibirUltimo(TANQUE *l){
	TIPOCHAVE ch;
	PONT posicao = retornarUltimo(l,&ch);
	if (posicao != NULL) {
		printf("Último tanque %d encontrado no endereço %d.\n",ch,posicao);
	}
	else {
		printf("Não foi possível encontrar o último tanque (lista vazia).\n");
	}
}

void excluir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Tanque a ser excluído: ");
	scanf("%d",&ch);
	if (excluirElemTanque(ch,l)) {
		printf("Tanque %d excluído corretamente.\n",ch);
	}
	else {
		printf("Não foi possível excluir o tanque %d.\n",ch);
	}
}

void imprimir_elementos(TANQUE *l){
	exibirTanque(l);
}

void exibir_detalhes_tanque(TANQUE *l){
	printf("Número de tanques na lista: %d.\n",tamanho(l));
	printf("Tamanho da lista (em bytes): %d.\n",tamanhoEmBytes(l));
}

void destruir(TANQUE *l){
     destruirTanque(l);
     printf("Lista de tanques zerada.\n");
}

void menu() {
	TANQUE Tanque;
	inicializarTanque(&Tanque);
	
	while (opcao != 9) {
		setlocale(LC_ALL, "Portuguese");
		system("cls");
		printf("MENU\n");
		printf("1 : Inserir tanque \n");
		printf("2 : Excluir tanque \n");
		printf("3 : Imprimir lista de tanques \n");
		printf("4 : Destruir (zerar) tanques \n");
		printf("5 : Exibir log de utilizacao da tanque \n");
		printf("6 : Buscar tanque \n");
		printf("7 : Exibir primeiro tanque \n");
		printf("8 : Exibir último tanque \n");
		printf("9 : SAIR \n");
		printf("Digite a opção desejada: ");
		scanf("%d",&opcao);
		system("cls");
		switch (opcao) {
		    case 1 : inserir(&Tanque); break;
		    case 2 : excluir(&Tanque); break;
		    case 3 : imprimir_elementos(&Tanque); break;
		    case 4 : destruir(&Tanque); break;
		    case 5 : exibir_detalhes_tanque(&Tanque); break;
		    case 6 : buscar(&Tanque); break;
		    case 7 : exibirPrimeiro(&Tanque); break;
		    case 8 : exibirUltimo(&Tanque); break;
		}
    system("pause");
	}
}

int main(){

	menu();

	return 0;
}
