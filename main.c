#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int login1,senha;

welcome(){
    printf("\n");
    printf("\n");
    printf("----------------------------------------------- \n");
    printf("            BEM VINDO AO SISPET EM C           \n");
    printf("-----------------------------------------------\n");
    return 0;
}

login(){
    printf("Login:\n");
    scanf("%i",&login1);
    printf("Senha:\n");
    scanf("%i",&senha);
    if (login1==123 && senha==123){
        system("cls");
        menu();
    }else{
        printf("Usuário ou senha incorretos");
    }
    return 0;
}

menu()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Escolha uma opção:\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Buscar Clientes\n");
    printf("3- Cadastrar Pet\n");
    printf("4- Buscar Pet\n");
    printf("5- Cadastrar Serviço\n");
    printf("6- Buscar Serviço\n");
    printf("7- Finalizar sessão\n");
}

main()
{
    setlocale(LC_ALL, "Portuguese");
    welcome();
    printf("\n");
    login();
    printf("\n");
    return 0;
}
