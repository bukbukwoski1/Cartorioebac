#include<stdio.h> //biblioteca de comunica��o com o usu�rio
#include<stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das strings

int registro() //Fun��o responsavel por cadastrar os usuarios no sistema
{
	//Inicio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//Final da cria��o de vari�veis/strings
	
	printf("Digite o cpf � ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s se refere a strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo no banco de dados (nossa pasta)
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa: "escrever".
	fprintf(file, cpf); //salvo o valor da variavel
	fclose(file); //Fecha o arquivo, muito importante!
	
	file = fopen(arquivo, "a"); //A variavel "a" � de Atualiza��o
	fprintf(file, ","); // Adc "virgulas" entre os dados
	fclose(file);
	
	printf("Digite um nome a ser cadastrado:" );
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado:");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //A variavel "r" � de escrita
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file; 
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuario n�o se encotra no sistema! \n");
		system("pause");
	}	
		
}

int main()
{
	int opcao=0; //Definindo as variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	
		for(laco=1;laco=1;)//(x=1;x=1 == Repeti��o) Criando la�o de retorno; incremento opcional, n�o se aplica nesse caso. 
		{
		
			system("cls");//"apagar mensagens em tela" 
		
			setlocale(LC_ALL, "Portuguese"); //Definindo a liguagem 
	
			printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
			printf ("Escolha a op��o desejada do menu:\n\n");
			printf ("\t1 - Registrar nomes?\n");
			printf ("\t2 - Consultar nomes?\n");
			printf ("\t3 - Deletar nomes?\n"); 
			printf ("\t4 - Sair do sistema\n\n");
			printf ("(Digite um n�mero entre 1 � 3 e tecle: ENTER)\n\n");
			printf ("Op��o: ");//fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usuario
	
			system("cls"); //responsavel por limpar a tela (Windows)
	
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf ("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
				default:
				printf("Essa op��o n�o est� disponivel.\n\n");
				printf("(No menu, digite um numero entre 1 � 3)\n\n");
				system("pause");
				break;
				
			}//fim do Switch
	
		}
	}
	
	else
		printf("senha incorreta!");
}
