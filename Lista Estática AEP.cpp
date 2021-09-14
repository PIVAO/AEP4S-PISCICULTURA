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

void incluir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Qual tanque deseja incluir? ");
	scanf("%d",&ch);
	REGISTRO reg;
	reg.chave = ch;
	if (incluirElemTanqueOrd(reg,l)) {
		printf("Tanque %d incluído com sucesso.\n\n",ch);
	}
	
	else {
		printf("Não foi possível incluir o tanque %d.\n\n",ch);
	}
}

/*void buscaUnic() {
	printf("Digite ")
}*/

void excluir(TANQUE *l){
	TIPOCHAVE ch;
	printf("Tanque a ser excluído: ");
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
	printf("Número de tanques na lista: %d.\n\n",tam(l));
}

void destruir(TANQUE *l){
	destruirTanque(l);
	printf("Lista de tanques zerados.\n\n");
}

void exibir_detalhes_tanque(TANQUE *l){
	printf("Número de tanques na lista: %d.\n",tam(l));
	printf("Tamanho da lista de tanques (em bytes): %d.\n\n",tamEmBytes(l));
}

int main(){
	system("color 0a");
	system("mode80,25");
	setlocale (LC_ALL,"portuguese");
	TANQUE tanque;
	inicializarTanque(&tanque);
	while (opcao != 6) {
	system("cls");
	menu();
		switch (opcao) {
		    case 1 : incluir(&tanque); break;
		    case 2 : excluir(&tanque); break;
		    case 3 : imprimir_elementos(&tanque); break;
		    case 4 : destruir(&tanque); break;
		    case 5 : exibir_detalhes_tanque(&tanque); break;
		}
	system("pause");
	}
	return 0;
}
