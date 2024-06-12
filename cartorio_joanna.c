#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{	
	//Início da criação de variáveis/string (Conjunto de "char")
	
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	//Final das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); //Cria o arquivo e o "w" significa "escrever"
	fprintf (file,cpf); //Salva o valor da variável
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo já existente
	fprintf(file,",");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o nome a ser cadastrado: "); //Coletando informação do usuário
	scanf ("%s", nome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo já existente
	fprintf(file, nome); //Salva o valor da variável
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); 
	fprintf(file,",");
	fclose (file); //Fecha o arquivo
	
	printf ("Digite o sobrenome a ser cadastrado: "); //Coletando informação do usuário
	scanf ("%s", sobrenome); // %s refere-se a string
	
	file = fopen(arquivo, "a"); //Abre o arquivo já existente
	fprintf(file, sobrenome); //Salva o valor da variável
	fclose (file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); //Abre o arquivo já existente
	fprintf(file,",");
	fclose (file); // Fecha o arquivo
	
	printf ("Digite o cargo a ser cadastrado: "); //Coletando informação do usuário
	scanf ("%s", cargo); // %s refere-se a string
	
	file = fopen (arquivo, "a"); //Abre o arquivo já existente
	fprintf (file, cargo);
	fclose (file); // Fecha o arquivo
	
	system ("pause"); //Responsável por manter a informação na tela
	
}

int consulta() //Função responsável por consultar os usuários no sistema
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
	   printf("Não foi possivel abrir o arquivo, arquivo não localizado!.\n");
    }
	
    while(fgets(conteudo, 100, file) != NULL) // Busca de informações/ "NULL" significa nulo
{
	printf("\nEssas são as informações do usuário : ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause"); //Responsável por manter a informação na tela
	
}


int deletar() //Função responsável por deletar os usuários no sistema
{
    char cpf[40];
    
    printf ("Digite o CPF do usuário que você deseja deletar: "); // Informando o usuário a ser deletado
    scanf ("%s", cpf); // %s refere-se a string
    
    remove (cpf); //Deletando o usuário
    
    printf ("Você deletou o usuário com sucesso! \n");
    
    FILE *file;
    file = fopen (cpf,"r"); //"r" significa "lendo"
    
    if (file == NULL) //"NULL" significa nulo
    {
    	("O usuário não se encontra no sistema.\n");
		system ("pause"); //Responsável por manter a informação na tela
	}
    

}

int main() //Função principal
    
{
	int opcao=0; //Definindo variáveis
	int laco=1; //Defindo repetição
	
	for(laco=1; laco=1;) //Início da repetição
	{
		
		system("cls"); //Limpeza tela
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n \n"); //Início do menu
	    printf("Escolha a opção desejada no menu:\n\n"); 
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
		printf ("\t4 - Sair do sistema\n\n"); 
	    printf("Opção:"); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");//Limpeza tela
	    
	    switch(opcao) //Chamada de funções
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
			printf("Essa opção não está disponível.\n");
		    system("pause");
		    break;
		    
		}
        }//Fim da repetição
        
}
