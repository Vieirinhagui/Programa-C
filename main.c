#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int login1, senha, escolha, escolhafuncionario;

welcome()
{
    printf("\n");
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("            BEM VINDO AO SISPET EM C           \n");
    printf("-----------------------------------------------\n");
    return 0;
}

login()
{
    printf("Login:\n");
    scanf("%i", &login1);
    printf("Senha:\n");
    scanf("%i", &senha);
    if (login1 == 123)
    {
        system("cls");
        menu();
    }
    else if (login1 == 234)
    {
        system("cls");
        menu_root();
    }
    else
    {
        printf("Usuario ou Senha Invalidos!");
        login();
    }
}
menu_root()
{
    printf("1- Cadastrar Funcionário\n");
    printf("2- Buscar Funcionário\n");
    scanf("%d", &escolhafuncionario);

    switch (escolhafuncionario)
    {
    case 1:
        cad_cli();
        break;
    case 2:
        cad_cli();
        break;
    default:
        printf("Opção Invalida!");
        menu_root();
    }
}
menu()
{
    setlocale(LC_ALL, "Portuguese");
    printf("Escolha uma opção:\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Buscar Clientes\n");
    printf("3- Editar Clientes\n");
    printf("4- Cadastrar Pet\n");
    printf("5- Buscar Pet\n");
    printf("6- Editar Pet\n");
    printf("7- Cadastrar Serviço\n");
    printf("8- Buscar Serviço\n");
    printf("9- Editar Serviço\n");
    printf("10- Finalizar sessão\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
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
    case 8:
        cad_cli();
        break;
    case 9:
        cad_cli();
        break;
    case 10:
        cad_cli();
        break;
    default:
        printf("Opção Invalida!");
        menu();
    }
}
cad_cli()
{
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
