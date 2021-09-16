#include "Estrutura Lista Estática.cpp"

void menu() {
	printf("MENU\n");
	printf("1 - Cadastrar tanque (em números) \n");
	printf("2 - Excluir um tanque \n");
	printf("3 - Mostrar tanques cadastrados\n");
	printf("4 - Apagar todos os tanques\n");
	printf("5 - Buscar tanque na lista\n");
	printf("6 - SAIR \n");
	printf("Digite a opção desejada: ");
	scanf("%d", &opcao);
	system("cls");
}

void inserir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Qual tanque deseja incluir: ");
	scanf("%d",&ch);
	REGISTRO reg;
	reg.chave = ch;
	if (inserirElemTanqueOrd(reg,l)) {
		printf("Tanque %d incluído com sucesso.\n\n",ch);
	}
	else {
		printf("Não foi possível incluir o tanque %d.\n\n",ch);
	}
}

void excluir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Qual tanque deseja excluir: ");
	scanf("%d",&ch);
	if (excluirElemTanque(ch,l)) {
    	printf("Tanque %d excluído com sucesso.\n\n",ch);
	}
	
	else {
		printf("Não foi possível excluir tanque %d.\n\n",ch);
	}
}

void imprimir_elementos(TANQUE *l){
	exibirTanque(l);
}

void destruir(TANQUE *l){
	destruirTanque(l);
	printf("Lista de tanques zerados.\n\n");
}

void buscar_elemento(TANQUE *l){
	TIPOCHAVE ch;
	printf("Qual tanque deseja buscar: ");
	scanf("%d",&ch);
	int i = buscaSeq(ch,l);
	if (i != NUL) {
		printf("Tanque %i encontrado na posição %i \n\n",ch,i);
	}

	else {
		printf("Nao foi possível encontrar tanque %d.\n\n",ch);
	}
}

int main(){
	system("mode 80,25");
	system("color 0a");
	setlocale (LC_ALL,"portuguese");
	TANQUE tanque;
	inicializarTanque(&tanque);
	while (opcao != 6) {
		system("cls");
		menu();
		switch (opcao) {
			case 1 : inserir(&tanque); break;
			case 2 : excluir(&tanque); break;
			case 3 : imprimir_elementos(&tanque); break;
			case 4 : destruir(&tanque); break;
			case 5 : buscar_elemento(&tanque); break;
		}
	system("pause");
	}
	return 0;
}
