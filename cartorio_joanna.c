#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{	
	//In�cio da cria��o de vari�veis/string (Conjunto de "char")
	
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final das vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa "escrever"
	fprintf (file,cpf); //Salva o valor da vari�vel
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� existente
	fprintf(file,",");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf ("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� existente
	fprintf(file, nome); //Salva o valor da vari�vel
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o sobrenome a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf ("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� existente
	fprintf(file, sobrenome); //Salva o valor da vari�vel
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo j� existente
	fprintf(file,",");
	fclose (file); // Fecha o arquivo
	
	printf ("Digite o cargo a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf ("%s", cargo); // %s refere-se a string
	
	file = fopen (arquivo, "a"); //Abre o arquivo j� existente
	fprintf (file, cargo);
	fclose (file); // Fecha o arquivo
	
	system ("pause"); //Respons�vel por manter a informa��o na tela
	
}

int consulta() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[100];
	
    printf("Digite o CPF a ser consultado: "); //Consultando o CPF
    scanf("%s",cpf); // %s refere-se a string
  	
    FILE *file;
    file = fopen(cpf,"r"); //"r" significa "lendo"
  	
    if(file == NULL)
    {
	   printf("N�o foi possivel abrir o arquivo, arquivo n�o localizado!.\n");
    }
	
    while(fgets(conteudo, 100, file) != NULL) // Busca de informa��es/ "NULL" significa nulo
{
	printf("\nEssas s�o as informa��es do usu�rio : ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause"); //Respons�vel por manter a informa��o na tela
	
}


int deletar() //Fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40];
    
    printf ("Digite o CPF do usu�rio que voc� deseja deletar: "); // Informando o usu�rio a ser deletado
    scanf ("%s", cpf); // %s refere-se a string
    
    remove (cpf); //Deletando o usu�rio
    
    printf ("Voc� deletou o usu�rio com sucesso! \n");
    
    FILE *file;
    file = fopen (cpf,"r"); //"r" significa "lendo"
    
    if (file == NULL) //"NULL" significa nulo
    {
    	("O usu�rio n�o se encontra no sistema.\n");
		system ("pause"); //Respons�vel por manter a informa��o na tela
	}
    

}

int main() //Fun��o principal
    
{
	int opcao=0; //Definindo vari�veis
	int laco=1; //Defindo repeti��o
	
	for(laco=1; laco=1;) //In�cio da repeti��o
	{
		
		system("cls"); //Limpeza tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n \n"); //In�cio do menu
	    printf("Escolha a op��o desejada no menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf ("\t4 - Sair do sistema\n\n"); 
	    printf("Op��o:"); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls");//Limpeza tela
	    
	    switch(opcao) //Chamada de fun��es
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
		    printf("Obrigado por utilizar o sistema!\n");
		    system("pause");
			break;
			return 0;
		    break;
		    
		    default:
			printf("Essa op��o n�o est� dispon�vel.\n");
		    system("pause");
		    break;
		    
		}
        }//Fim da repeti��o
        
}
