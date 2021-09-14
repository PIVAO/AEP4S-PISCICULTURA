#include "Estrutura Lista Estática.cpp"

void menu() {
	printf("MENU\n");
	printf("1 : Cadastrar tanque (em números) \n");
	printf("2 : Excluir um tanque \n");
	printf("3 : Mostrar tanques cadastrados \n");
	printf("4 : Apagar todos os tanques \n");
	printf("5 : Exibir log de utilização da lista \n");
	printf("6 : SAIR \n");
	printf("Digite a opção desejada: ");
	scanf("%d",&opcao);
	system("cls");
}

void incluir(LISTA *l){
	TIPOCHAVE ch;
	printf("Qual tanque deseja incluir? ");
	scanf("%d",&ch);
	REGISTRO reg;
	reg.chave = ch;
	if (incluirElemListaOrd(reg,l)) {
		printf("Tanque %d incluído com sucesso.\n\n",ch);
	}
	
	else {
		printf("Não foi possível incluir o tanque %d.\n\n",ch);
	}
}

void excluir(LISTA *l){
	TIPOCHAVE ch;
	printf("Tanque a ser excluído: ");
	scanf("%d",&ch);
	if (excluirElemLista(ch,l)) {
		printf("Tanque %d excluído com sucesso.\n\n",ch);
	}
	
	else {
		printf("Não foi possível excluir tanque %d.\n\n",ch);
	}
}

void imprimir_elementos(LISTA *l){
	exibirLista(l);
}

void destruir(LISTA *l){
	destruirLista(l);
	printf("Lista de tanques zerados.\n\n");
}

void exibir_detalhes_lista(LISTA *l){
	printf("Número de tanques na lista: %d.\n",tam(l));
	printf("Tamanho da lista de tanques (em bytes): %d.\n\n",tamEmBytes(l));
}

int main(){
	system("mode80,25");
	setlocale (LC_ALL,"portuguese");
	LISTA lista;
	inicializarLista(&lista);
	while (opcao != 6) {
	system("cls");
	menu();
		switch (opcao) {
		    case 1 : incluir(&lista); break;
		    case 2 : excluir(&lista); break;
		    case 3 : imprimir_elementos(&lista); break;
		    case 4 : destruir(&lista); break;
		    case 5 : exibir_detalhes_lista(&lista); break;
		}
	system("pause");
	}
	return 0;
}
