#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsavel por cadastrar os usuários no sistema
{
    //inicio de criação de variaveis/string
  char arquivo[40];
  char cpf[40];
  char nome[40];
  char sobrenome[40];
  char cargo[40];
  //Final da criação de variaveis/string

  printf("Digite o CPf a ser cadastrado: "); //coletando iformações do usuário
  scanf("%s", cpf); //%s refere-se a string

  strcpy(arquivo, cpf); //responsavel por copiar os valores das string

  FILE *file; //cria o arquivo
  file = fopen(arquivo, "w"); //cria o arquivo, o 'W' significa escrever
  fprintf(file,cpf);//salvo o valor da variavel
  fclose(file);//fecha o arquivo

  file = fopen(arquivo, "a");
  fprintf(file,",");
  fclose(file);

  printf("Digite um nome a ser cadastrado: ");
  scanf("%s", nome);

  file = fopen(arquivo, "a");
  fprintf(file,nome);
  fclose(file);

  file = fopen(arquivo,"a");
  fprintf(file,",");
  fclose(file);

  printf("Digite o sobrenome a ser cadastrado: ");
  scanf("%s", sobrenome);

  file = fopen(arquivo,"a");
  fprintf(file,sobrenome);
  fclose(file);

  file = fopen(arquivo,"a");
  fprintf(file,",");
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
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("digite o cpf a ser consultado: ");
    scanf("%s",cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Consulta não realizada pois o CPF não foi encontrado! \n");
    }

    while(fgets(conteudo, 200,file) != NULL)
    {
        printf("\essas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }


        system("pause");



}

int deletar()
{
    char cpf[40];

    printf("digite o CPF a ser deletado: ");
    scanf("%s",cpf);

    remove(cpf);

    FILE *file;
    file = fopen(cpf,"r");

    if(file == NULL)
    {
        printf("usuario não encontrado!.\n");
        system("pause");
    }







}

int main()
{
    int opcao=0; //definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)

  {

    system("cls"); //responsável por limpar a tela


    setlocale (LC_ALL, "Portuguese"); //definindo linguagem

    printf("### Diego's Office ###\n\n"); //inicio do menu
    printf("Escolha a opção desejada\n\n");
    printf("\t1 - Registrar Nomes\n");
    printf("\t2 - Consultar Nomes\n");
    printf("\t3 - Deletar Nomes\n");
    printf("\t4 - Sair do Sistema\n");
    printf("opção: "); //fim do menu

    scanf("%d", &opcao); //armazenamento de escolha do usuário

    system("cls");

    switch(opcao) //inicio da seleção do menu

    {
      case 1:
      registro(); //chamada da função
      system("pause");
      break;

      case 2:
      consulta();
      system("pause");
      break;

      case 3:
      deletar();
      system("pause");
      break;
      
      case 4:
      printf("Obrigado por utilizar o sistema!\n\n");
      return 0;
      break;

      default:
      printf("essa opção não está disponivel!\n");
      system("pause");
      break;

    }

  }

}
