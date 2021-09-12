#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<locale.h>

int cadastrar(int quant);						//fun��o cadastrar um cliente

void pesquisar(int quant);						//fun��o pesquisar se cliente existe

void acesso(int quant);							//fun��o acesso do cliente

void transacao(int pessoa, int quant);						//fun��o transa��o banc�ria

void editar(int quant);							//fun��o editar uma conta

void consulta(int conta);						//fun��o de consulta os dados do cliente

void backup();									//fun��o para backup do arquivo

void excluir(int pessoa);						//fun��o para excluir cliente

struct clientes{                   			    //struct dos clientes do banco
	char nome[50];
	char datanasci[30];
	char cpf[30];
	char rg[30];
	char senha[20];
	float deposito;
}cliente[50];

int main(int argc, char *argv[])
{													//Fun��o Principal
	setlocale(LC_ALL,"Portuguese");
	system("color F0");
	FILE *banco;
	int num, quant;
	
	banco = fopen("clientes.txt", "r");
	
	if(banco != NULL){
		while(fread(&cliente[quant], sizeof(struct clientes), 1, banco)){
			quant++;
		}
	}
	
		
	while(num != -500){
		system("cls");
		printf("*************************************************************************\n");
		printf("				BANCO DA UPE CARUARU!!!\n\n");
		printf("1-Cadastrar    2-Pesquisar    3-Acesso    4-Excluir    5-Backup    6-Sair");
		printf("\n\n*************************************************************************");
		
		printf("\nDigite a op��o que deseja: ");
		scanf("%d",&num);
		fflush(stdin);
		
		if(num == 1)
		{
			quant = cadastrar(quant); 				//chama fun��o cadastrar
		}
		
		else if(num == 2)
		{
			pesquisar(quant);						//chama fun��o pesquisar
		}
		
		else if(num == 3)
		{
			acesso(quant);
		}
		
		else if(num == 4)
		{
			
		}
		
		else if(num == 5)
		{
			backup();
		}
		
		else if(num == 6){
			system("cls");
			printf("\nObrigado pela prefenr�ncia!!!\n\nVolte Sempre!!!\n\n");
			//fclose(banco);
			system("pause");
			exit(1);
		}
		
		else
			printf("\nFun��o inexistente!\n");
			system("pause");
		}
		
		//fclose(banco);
		
		return 0;
}

int cadastrar(int quant)
{
	system("cls");
	int i=0, escolha = 0;
	FILE *banco;												//Declara um ponteiro para o arquivo
	
	banco = fopen("clientes.txt", "a");
	if(banco == NULL)											//Abre o arquivo para escrita
	{
		puts("N�o foi possivel abrir o arquivo!");
		exit(1);
	}
	
	while(escolha != 2){
		
		system("cls");
		printf("Digite o nome: ");
		fgets(cliente[i].nome, 100, stdin);
		fflush(stdin);						
		system("cls");
		
		printf("No m�ximo 20 caracteres\n");
		printf("Digite uma senha: ");
		fgets(cliente[i].senha, 20, stdin);
		system("cls");
		
		printf("Digite a data de nascimento do cliente: ");
		fgets(cliente[i].datanasci, 30, stdin);
		system("cls");
		
		printf("Digite o CPF do cliente: ");
		fgets(cliente[i].cpf, 30, stdin);
		system("cls");
		
		printf("Digite o RG do cliente: ");
		fgets(cliente[i].rg, 30, stdin);
		system("cls");
		
		printf("Digite o valor do dep�sito inicial: ");
		scanf("%f",&cliente[i].deposito);
		fflush(stdin);
		system("cls");
		
		printf("Deseja cadastrar outro cliente:\n1-Sim		2-N�o");
		printf("\nOp��o: ");
		scanf("%d",&escolha);
		fflush(stdin);
		
		fwrite(&cliente[quant], sizeof(struct clientes), 1, banco);
		quant += 1;									//adiciona a esse contador que existe +1 cliente
		
	}
	//fwrite(cliente, sizeof(struct clientes), 1, banco);
	return quant;									//retorna o contador para a main
	fclose(banco);
	system("cls");
}

void pesquisar(int quant)
{
	system("cls");
	char procura[50], ch;
	int i=0;
	FILE *banco;
	
	banco = fopen("clientes.txt", "r");
	
	while(fread(&cliente[i], sizeof(struct clientes), 1, banco))
	{
		i++;
	}
					
	
	printf("Digite o nome a ser procurado: ");
	fgets(procura, 50, stdin);
		
	int encontrou = 0;
		
	for(i=0 ; i<quant ; i++){
		if(strncmp(cliente[i].nome, procura, 1) == 0)
		{
			printf("\nCliente: %s",cliente[i].nome);
			printf("CPF: %s\n",cliente[i].cpf);
			encontrou = 1;
			system("pause");
		}
	}
		
		if(encontrou == 0){
			puts("Cliente n�o cadastrado!");
		}
		
		
		fclose(banco);
	
		system("cls");
}

void acesso(int quant)
{
	char pesquisa_nom[50], pesquisa_sen[20];
	int i, opcao, pessoa;
	FILE *banco;
	system("cls");
	
	banco = fopen("clientes.txt", "r");
	if(banco == NULL)											//Abre o arquivo para escrita
	{
		puts("N�o foi possivel abrir o arquivo!");
		exit(1);
	}
	
	fread(cliente, sizeof(struct clientes), 50, banco);			//l� os clientes do arquivo
	
	printf("Digite o Nome: ");								//compara o nome digitado na pesquisa com o existente no arquivo
	fgets(pesquisa_nom, 50, stdin);
	for(i=0 ; i<50 ; i++)
	{
		if(strcmp(cliente[i].nome, pesquisa_nom) == 0)
		{
			printf("\nDigite sua senha: ");	//compara a senha digitada com a existente no arquivo
			fgets(pesquisa_sen, 20, stdin);
			if(strcmp(cliente[i].senha, pesquisa_sen) == 0)
			{
				while(opcao != -500)
				{
					system("cls");
					printf("**********************************************************************\n");
					printf("		BANCO DA UPE CARUARU!!!    Cliente: %s\n\n",cliente[i].nome);
					printf("1-Transa��o    2-Editar Dados    3-Listar Dados    4-voltar");
					printf("\n\n**********************************************************************");
					printf("\nDigite a op��o que deseja: ");
					scanf("%d",&opcao);
					fflush(stdin);
					pessoa = i;
					switch(opcao){
						case 1:
						{
							transacao(pessoa, quant);							//chama a fun��o de transa��o
							break;
						}
						
						case 2:
						{
							editar(pessoa);								//chama a fun��o para editar algum dado
							break;
						}
						
						case 3:
						{	
							consulta(pessoa);						//chama a fun��o que mostra os dados do cliente
							break;
						}
						
						case 4:{
							fclose(banco);
							opcao = -500;
							break;
						}
					}
				
				
				}
			}
			
		}
	}
	fclose(banco);
	system("cls");
}

void transacao(int pessoa,int quant)
{
	int k, escolha; 
	float deposito, saque, transf;
	FILE *banco;
	
	banco = fopen("clientes.txt", "w");
	
	if(banco == NULL){
		puts("N�o foi possivel abrir o arquivo!");
		exit(1);
	}
	
	system("cls");
	
	printf("Escolha uma op��o:\n\n1-Dep�sito	2-Saque    3-Sair\n\nEscolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	
	if(escolha == 1)
	{
		system("cls");
		printf("\nDigite o valor: ");
		scanf("%f",&deposito);
		fflush(stdin);
		cliente[pessoa].deposito += deposito;
			
		system("cls");
			
		printf("%s", cliente[pessoa].nome);
		printf("\n%.2f", cliente[pessoa].deposito);
		
		fwrite(cliente, sizeof(struct clientes), quant, banco);
		
		system("pause");
		fclose(banco);
	}
	
	else if(escolha == 2)
	{
		system("cls");
		printf("\nDigite o valor: ");
		scanf("%f",&saque);
		fflush(stdin);
		cliente[pessoa].deposito = cliente[pessoa].deposito - saque;
			
		system("cls");
			
		printf("%s", cliente[pessoa].nome);
		printf("\n%f", cliente[pessoa].deposito);
		system("pause");
		fwrite(cliente, sizeof(struct clientes), 1, banco);
	}
	
	else if(escolha == 3)
	{
		printf("Op��o Inv�lida");
	}
		
		fclose(banco);
		system("cls");
}

void editar(int pessoa)
{
	int opcao;
	char nome[50], data_nasc[20], CPF[20], RG[20];
	system("cls");
	printf("Nome: %s", cliente[pessoa].nome);	
	printf("\nData de nascimento: %s", cliente[pessoa].datanasci);	
	printf("\nCPF: %s", cliente[pessoa].cpf);	
	printf("\nRG: %s", cliente[pessoa].rg);	
	
	printf("\n\nQual das op��es deseja alterar: \n1-Nome    2-Data de Nascimento    3-CPF    4-RG");
	printf("Op��o: ");
	scanf("%d",&opcao);
	fflush(stdin);
	system("cls");
	switch(opcao)
	{
		case 1:
		{
			printf("Digite o novo nome: ");
			fgets(nome, 50, stdin);
			strcpy(cliente[pessoa].nome, nome);
			break;
		}
	}
}

void consulta(int conta)
{
	printf("Nome: %s", cliente[conta].nome);
		
	printf("\nData de nascimento: %s", cliente[conta].datanasci);
		
	printf("\nCPF: %s", cliente[conta].cpf);
		
	printf("\nRG: %s", cliente[conta].rg);
		
	printf("\nSaldo: %.2f\n\n",cliente[conta].deposito);
	
	system("pause");
}

void backup()
{
	FILE *banco, *extra;
	int i = 0;
	banco = fopen("clientex.txt", "r");
	extra = fopen("backup.txt", "w");
	
	while(fread(&cliente[i], sizeof(struct clientes), 1, banco)){
		i++;
	}
	
	i = 0;
	
	while(fwrite(&banco[i], sizeof(struct clientes), 1, extra)){
		i++;
	}
	
	
	fclose(banco);
	fclose(extra);
}

void excluir(int pessoa)
{
	char nome[] = "clientes.txt";
	if(remove(nome) != 0){
		printf("error!");
	};
	//fclose(banco);
}
