#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

struct Cliente {
    char telefone[20];
    char email[50];
};


int registro() //FUNÇÃO responsavel por cadastar os usuários no sistema.
{
	//inicio da criação de variáveis/string.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char telefone[20];
    char email[50];
	//final da criação de variáveis/string.
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário.
	scanf("%s", cpf); //%s refere-se a string.
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o"w" significa escrever.
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite um nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
	
	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf("Digite o CPF a ser consultado: \n");
	scanf("%s" ,cpf); // Armazenando a variavel "cpf" com a função string "%s".
	
	FILE *file;
	file = fopen(cpf, "r"); // Abre o arquivo cpf e "r" de Read (ler) a informação. 
	
	if(file == NULL) // Caso a informação não exista.
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // (enquanto) tiver informação, armazenar a informação se estiver diferente de NULL.
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ",");
		printf("O CPF do usuário é: %s\n", token); // informação a aparecer antes dos dados do CPF.
		
		token = strtok(NULL, ",");
		printf("O nome do usuário é: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("O sobre nome do usuário é: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("O cargo do usuário é: %s\n", token);
		
	}
	
	
	system("pause");
	
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
	return 0;
}

void coletarDadosCliente(struct Cliente *cliente) {
    printf("Digite seu telefone: ");
    scanf("%s", cliente->telefone);

    printf("Digite seu email: ");
    scanf("%s", cliente->email);
}

int convenios()
{
	printf("Você escolheu convênios!\n");
	
	struct Cliente cliente;

    coletarDadosCliente(&cliente);

    printf("Informações de contato:\n");
    printf("Telefone: %s\n", cliente.telefone);
    printf("Email: %s\n", cliente.email);

    printf("Grato pelo cadastro, iremos entrar em contato com você em breve...\n");
    while (getchar() != '\n');

    // Limpa o buffer do teclado antes de esperar a confirmação do usuário
    fflush(stdin);

    // Espera a confirmação do usuário
    getchar();

    // Mensagem de retorno ao menu
    printf("Pressione Enter para retornar ao menu...");
    while (getchar() != '\n');

    return 0;
}

int main()
	{
	int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s" ,senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
		system ("cls");
		for(laco=1;laco=1;)
		{


		
			setlocale(LC_ALL, "Portuguese"); //Definindo Linguagem
		
			system("cls");
		
			printf("||Cartório da EBAC||\n\n"); //Inicio do menu
			printf("Escolha a opção desejada do Menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Convênios\n\n");
			printf("\t5 - Sair do sistema\n\n");
			printf("Opção: ");//Fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //responsavel por limpar a tela
		
		
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				convenios();
				break;

				case 5:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
		
				default:
				printf("Essa opção não está disponivel!\n");
				system("pause");
				break;	
			} //fim da seleção
		}
	}
	
	else
		printf("Senha incorreta!");
	
}
