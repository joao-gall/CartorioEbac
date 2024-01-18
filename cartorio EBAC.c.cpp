#include <stdio.h> //biblioteca de comunicacao c o usuario
#include <stdlib.h> // biblioteca de alocacao de memoria
#include <locale.h> // alocacoes de texto por regiao
#include <string.h>

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	
	FILE *file; // cria o banco de dados
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvar o arquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}


int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	printf("este arquivo nao foi localizado em nosso banco de dados\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nessas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}


int deletar()
{
	char cpf[40];
	
	printf("digite o cpf do usuario a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
		printf("usuario nao se encontra no sistema.\n\n");
		system("pause");
		

	}
		
}

int main()
{
	int opcao=0; //definido as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
	
	
	    setlocale(LC_ALL, "Portuguese"); //linguagem
	
	//construcao do menu
	
		printf("   cartorio da EBAC   \n\n");
		printf("escolha a opcao desejada no menu:\n\n");
		printf("\t1- registrar nomes\n");
		printf("\t2- consultar nomes\n");
		printf("\t3- deletar nomes\n");
		printf("\nopcao");
	
		scanf("%d", &opcao); //scaner para a escolha do usuario
	
		system("cls");
	
		switch(opcao)
		
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
		
			case 3:
			deletar();
			break;
			
			case 4:
			printf("obrigado por ultilizar o nosso sistema!");
			return 0;
			break;
		
			default:
			printf("essa opcao nao esta disponivel!");
			system("pause");
			break;
				
		}
	
	}
		
}
