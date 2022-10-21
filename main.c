#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int login1,senha,escolha;

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
        printf("senha invalida");
    }
}

menu()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Escolha uma opção:\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Buscar Clientes\n");
    printf("2- Editar Clientes\n");
    printf("3- Cadastrar Pet\n");
    printf("4- Buscar Pet\n");
    printf("4- Editar Pet\n");
    printf("5- Cadastrar Serviço\n");
    printf("6- Buscar Serviço\n");
    printf("6- Editar Serviço\n");
    printf("7- Finalizar sessão\n");
    scanf("%d",&escolha);

    switch (escolha){
        case 1:
            cad_cli();
            break;
        case 2:
            cad_cli();
            break;
        case 3:
            cad_cli();
            break;
        case 4:
            cad_cli();
            break;
        case 5:
            cad_cli();
            break;
        case 6:
            cad_cli();
            break;
        case 7:
            cad_cli();
            break;
        default:
            printf("Opção Invalida!");
            menu();
    }
}
cad_cli(){

    printf("Cadastrar Cliente");

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
