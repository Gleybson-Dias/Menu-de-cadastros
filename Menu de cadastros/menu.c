#include <stdio.h>
#include <string.h>


//estrutura para armazenar as informações de um aluno
struct aluno {
	char nome[50];
	int matricula;
	int idade;
	char curso[50];

};

//função para cadastrar o aluno
void cadastrarAluno(struct aluno alunos[], int* numAlunos) {

	printf("preencha as informacoes do aluno:\n");
	printf("\nnome:\n ");
	scanf("%s", &alunos[*numAlunos].nome);
	printf("matricula:\n ");
	scanf("%d", &alunos[*numAlunos].matricula);
	printf("idade:\n ");
	scanf("%d", &alunos[*numAlunos].idade);
	printf("curso:\n ");
	scanf("%s", &alunos[*numAlunos].curso);
	(*numAlunos)++;

}

//função para listar os alunos cadastrados
void listarAlunos(struct aluno alunos[], int numAlunos) {

	for (int i = 0; i < numAlunos; i++) {

		printf("\nNome: %s\n", alunos[i].nome);
		printf("Matricula: %d\n", alunos[i].matricula);
		printf("Idade: %d\n", alunos[i].idade);
		printf("Curso: %s\n\n", alunos[i].curso);
	}

}

//função para buscar o aluno pelo nome
void buscarAlunoPorNome(struct aluno alunos[], int numAluno, char nomeBusca[]) {
	printf("\nBuscando aluno por nome...\n");

	int encontrado = 0;

	for (int i = 0; i < numAluno; i++) {
		if (strcmp(alunos[i].nome, nomeBusca) == 0) {
			printf("\nAluno encontrado: \n");
			printf("\nNome: %s\n", alunos[i].nome);
			printf("matricula: %d\n", alunos[i].matricula);
			printf("idade: %d\n", alunos[i].idade);
			printf("curso: %s\n\n", alunos[i].curso);
			encontrado = 1;
			break;
		}
	}
	if (!encontrado) {
		printf("Aluno não encontrado.\n\n");
	}

}



int main() {

	//definindo meu arrays
	struct aluno alunos[3];

	//definindo variaveis
	int numAlunos = 0;
	int opcao;
	char nomeBusca[50];


	//opcao de menu
	do {
		printf("escolha uma opcao:\n");
		printf("1 - Cadastrar aluno\n");
		printf("2 - listar alunos cadastrados\n");
		printf("3 - Buscar aluno por nome\n");
		printf("0 - sair\n");
		printf("opcao: ");
		scanf("%d", &opcao);

		//definindo cada funcionalidade do menu
		switch (opcao) {
		case 1:
			//chama a função para cadastrar alunos
			cadastrarAluno(alunos, &numAlunos);
			break;
		case 2:
			//chama a função para listar alunos
			listarAlunos(alunos, numAlunos);
			break;
		case 3:
			printf("Digite o nome do aluno a ser buscado: ");
			scanf("%s", &nomeBusca);

			//chama a função para buscar o aluno pelo seu nome
			buscarAlunoPorNome(alunos, numAlunos, nomeBusca);
			break;
		case 0:
			printf("Encerrando programa...");
			break;
		default:
			printf("Opcao invalida. tente novamente. \n");


		}
		//encerra o programa
	} while (opcao != 0);

	return 0;
}

