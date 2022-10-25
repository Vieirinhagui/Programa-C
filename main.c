#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <winsock2.h>
#include <string.h>
#include <C:\ConectorC\include\mysql.h>
#include <windows.h>
#include <TIME.H>
#define servidor "localhost"
#define usuario "root"
#define senha ""
#define bd "bancoc"

int main()
{
    setlocale(LC_ALL, "Portuguese");
    welcome();
    printf("\n");
    return 0;
}

cadastroCliente()
{
    setlocale(LC_ALL, "Portuguese");
    char query[2000];
    char nomecliente[100];
    char emailcliente[100];
    char enderecocliente[100];
    char telefonecliente[100];
    char cpfcliente[100];

    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("             CADASTRO DE CLIENTES              \n");
        printf("-----------------------------------------------\n");
        printf("Nome:");
        scanf("%s", &nomecliente);
        fflush(stdin);
        printf("Telefone:");
        scanf("%s", &telefonecliente);
        fflush(stdin);
        printf("E-mail:");
        scanf("%s", &emailcliente);
        fflush(stdin);
        printf("CPF:");
        scanf("%s", &cpfcliente);
        fflush(stdin);
        printf("Endereço:");
        scanf("%s", &enderecocliente);
        fflush(stdin);
        sprintf(query, "INSERT INTO `clientes`(`nomeCliente`, `telefoneCliente`, `emailCliente`, `cpfCliente`, `enderecoCliente`) VALUES ('%s','%s','%s','%s','%s');", nomecliente, telefonecliente, emailcliente, cpfcliente, enderecocliente);
        mysql_query(&conexao, query);
        printf("\nCadastrado com sucesso\n");
        sleep(1);
        system("cls");
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexaon");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
buscarCliente()
{
    char query1[2000];
    char buscpfcliente[100];
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("             BUSCADOR DE CLIENTES              \n");
        printf("-----------------------------------------------\n");
        printf("Digite o cpf para localizar o cadastro:");
        scanf("%s", &buscpfcliente);
        fflush(stdin);
        system("cls");
        sprintf(query1, "SELECT * FROM `clientes` WHERE `cpfCliente`='%s';", buscpfcliente);
        if (mysql_query(&conexao, query1))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nNome:%s\nTelefone:%s\nEmail:%s\nCPF:%s\nEndereço:%s\n\n\n\n ", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        mysql_free_result(res);
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
    return 0;
}

editarCliente()
{
    char query2[2000];
    char query3[2000];
    char busidcliente[100];
    int escolha1;
    char editnomecliente[100];
    char edittelefonecliente[100];
    char editemailcliente[100];
    char editcpfcliente[100];
    char editenderecocliente[100];
    int deletecliente;
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("             EDITOR DE CLIENTES              \n");
        printf("-----------------------------------------------\n");
        printf("Digite o numero 'ID' do cliente para editar:");
        scanf("%s", &busidcliente);
        fflush(stdin);
        system("cls");
        sprintf(query2, "SELECT * FROM `clientes` WHERE `idCliente`='%s';",busidcliente);
        if (mysql_query(&conexao,query2))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nNome:%s\nTelefone:%s\nEmail:%s\nCPF:%s\nEndereço:%s\n ", row[0], row[1], row[2], row[3], row[4], row[5]);
            mysql_free_result(res);
        }
        printf("\n\n\nQual dado quer alterar\n");
        printf("1-Nome\n");
        printf("2-Telefone\n");
        printf("3-Email\n");
        printf("4-CPF\n");
        printf("5-Endereco\n");
        printf("6-Apagar Cliente\n");
        scanf("%d", &escolha1);
        switch (escolha1)
        {
        case 1:
            printf("Qual o novo nome?");
            scanf("%s", &editnomecliente);
            sprintf(query3, "UPDATE `clientes` SET `nomeCliente`='%s' WHERE `idCliente`='%s'", editnomecliente, busidcliente);
            mysql_query(&conexao, query3);
            break;
        case 2:
            printf("Qual o novo Telefone?");
            scanf("%s", &edittelefonecliente);
            sprintf(query3, "UPDATE `clientes` SET `telefoneCliente`='%s' WHERE `idCliente`='%s'", edittelefonecliente, busidcliente);
            mysql_query(&conexao, query3);
            break;
        case 3:
            printf("Qual o novo Email?");
            scanf("%s", &editemailcliente);
            sprintf(query3, "UPDATE `clientes` SET `telefoneCliente`='%s' WHERE `idCliente`='%s'", editemailcliente, busidcliente);
            mysql_query(&conexao, query3);
            break;
        case 4:
            printf("Qual o novo CPF?");
            scanf("%s", &editcpfcliente);
            sprintf(query3, "UPDATE `clientes` SET `telefoneCliente`='%s' WHERE `idCliente`='%s'", editcpfcliente, busidcliente);
            mysql_query(&conexao, query3);
            break;
        case 5:
            printf("Qual o novo Endereco?");
            scanf("%s", &editenderecocliente);
            sprintf(query3, "UPDATE `clientes` SET `telefoneCliente`='%s' WHERE `idCliente`='%s'", editenderecocliente, busidcliente);
            mysql_query(&conexao, query3);
            break;
        case 6:
            printf("Tem certeza?\n");
            printf("1-Sim\n");
            printf("2-Nao\n");
            scanf("%d",&deletecliente);
            switch (deletecliente){
                case 1:
                sprintf(query3, "DELETE FROM `clientes` WHERE `idCliente`='%s'",busidcliente);
                mysql_query(&conexao, query3);
                system("cls");
                printf("\n");
                printf("\n");
                printf("Cliente apagado com sucesso");
                Sleep(1000);
                system("cls");
                menu();
                break;
                case 2:
                menu();
                break;
                default:
                    printf("opcao incorreta");
                    break;
            }
        default:
            break;
        }
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexaon");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
        return 0;
    }
}
cadastroPet()
{
    setlocale(LC_ALL, "Portuguese");
    char query4[2000];
    char nomepet[100];
    char pelagempet[100];
    char pesopet[100];
    char sexopet[100];
    char racapet[100];
    char especiepet[100];
    char cpfdonopet[100];

    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("               CADASTRO DE PETS                \n");
        printf("-----------------------------------------------\n");
        printf("Nome do Pet:");
        scanf("%s", &nomepet);
        fflush(stdin);
        printf("Pelagem do Pet:");
        scanf("%s", &pelagempet);
        fflush(stdin);
        printf("Peso do Pet em KG:");
        scanf("%s", &pesopet);
        fflush(stdin);
        printf("Sexo do pet:");
        scanf("%s", &sexopet);
        fflush(stdin);
        printf("Raça do Pet:");
        scanf("%s", &racapet);
        fflush(stdin);
        printf("Especie do Pet:");
        scanf("%s", &especiepet);
        fflush(stdin);
        printf("CPF dono do Pet:");
        scanf("%s", &cpfdonopet);
        fflush(stdin);
        sprintf(query4, "INSERT INTO `animal`(`idAnimal`, `nomePet`, `cpfdonopet`, `pelagemPet`, `PesoPet`, `SexoPet`, `racaPet`, `especiePet`) VALUES ('%s','%s','%s','%s','%s','%s','%s')",nomepet,pelagempet,cpfdonopet,pesopet,sexopet,racapet,especiepet) ;
        mysql_query(&conexao, query4);
        printf("\nCadastrado com sucesso\n");
        sleep(1);
        system("cls");
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
buscarPet()
{
    char query5[2000];
    char buscpfdonopet[100];
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("               BUSCADOR DE PETS                \n");
        printf("-----------------------------------------------\n");
        printf("Digite o cpf para localizar o cadastro do PET:");
        scanf("%s", &buscpfdonopet);
        fflush(stdin);
        system("cls");
        sprintf(query5, "SELECT * FROM `animal` WHERE `cpfdonopet`='%s';", buscpfdonopet);
        if (mysql_query(&conexao, query5))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nNome:%s\nTelefone:%s\nEmail:%s\nCPF:%s\nEndereço:%s\n\n\n\n ", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        mysql_free_result(res);
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
    return 0;
}

editarPet()
{
    char query6[2000];
    char query7[2000];
    char busidpet[100];
    int escolha2;
    char editnomepet[100];
    char editcpfdono[100];
    char editpelagempet[100];
    char editpesopet[100];
    char editsexopet[100];
    char editracapet[100];
    char editespeciepet[100];

    int deletecliente;
    MYSQL_RES *res;
    MYSQL_ROW row;
    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("             EDITOR DE PETS              \n");
        printf("-----------------------------------------------\n");
        printf("Digite o numero 'ID' do cliente para editar:");
        scanf("%s", &busidpet);
        fflush(stdin);
        system("cls");
        sprintf(query6, "SELECT * FROM `animal` WHERE `cpfdonopet`='%s';",busidpet);
        if (mysql_query(&conexao,query6))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID pet:%s\nNome do Pet:%s\nCPF do dono:%s\nPelagem do Pet:%s\nPeso do Pet:%s\nSexo do Pet:%s\nRaca do Pet:%s\nEspecie do Pet:%s\n ", row[0], row[1], row[2], row[3], row[4], row[5],row[6], row[7]);
            mysql_free_result(res);
        }
        printf("\n\n\nQual dado quer alterar\n");
        printf("1-Nome do Pet\n");
        printf("2-CPF do Pet\n");
        printf("3-Pelagem do Pet\n");
        printf("4-Peso do Pet\n");
        printf("5-Sexo do Pet\n");
        printf("6-Raca do Pet\n");
        printf("7-Especie do Pet\n");
        printf("8-Apagar Cliente\n");
        scanf("%d", &escolha2);
        switch (escolha2)
        {
        case 1:
            printf("Qual o novo nome do Pet?");
            scanf("%s", &editnomepet);
            sprintf(query7, "UPDATE `animal` SET `nomePet`='%s' WHERE `cpfdonopet`='%s'", editnomepet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 2:
            printf("Qual o novo CPF do dono?");
            scanf("%s", &editcpfdono);
            sprintf(query7, "UPDATE `animal` SET `cpfdonopet`='%s' WHERE`cpfdonopet`='%s'", editcpfdono, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 3:
            printf("Qual a Pelagem do Pet?");
            scanf("%s", &editpelagempet);
            sprintf(query7, "UPDATE `animal` SET `pelagemPet`='%s' WHERE`cpfdonopet`='%s'", editpelagempet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 4:
            printf("Qual o peso do Pet?");
            scanf("%s", &editpesopet);
            sprintf(query7, "UPDATE `animal` SET `PesoPet`='%s' WHERE`cpfdonopet`='%s'", editpesopet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 5:
            printf("Qual o Sexo do Pet?");
            scanf("%s", &editsexopet);
            sprintf(query7, "UPDATE `animal` SET `SexoPet`='%s' WHERE`cpfdonopet`='%s'", editsexopet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 6:
            printf("Qual a Raca do Pet?");
            scanf("%s", &editracapet);
            sprintf(query7, "UPDATE `animal` SET `racaPet`='%s' WHERE`cpfdonopet`='%s'", editracapet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 7:
            printf("Qual a Especie do Pet?");
            scanf("%s", &editespeciepet);
            sprintf(query7, "UPDATE `animal` SET `especiePet`='%s' WHERE`cpfdonopet`='%s'", editespeciepet, busidpet);
            mysql_query(&conexao, query7);
            break;
        case 8:
            printf("Tem certeza?\n");
            printf("1-Sim\n");
            printf("2-Nao\n");
            scanf("%d",&deletecliente);
            switch (deletecliente){
                case 1:
                sprintf(query7, "DELETE FROM `animal` WHERE `idCliente`='%s'",busidpet);
                mysql_query(&conexao, query7);
                system("cls");
                printf("\n");
                printf("\n");
                printf("Cliente apagado com sucesso");
                Sleep(1000);
                system("cls");
                menu();
                break;
                case 2:
                menu();
                break;
                default:
                    printf("opcao incorreta");
                    break;
            }
        default:
            break;
        }
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexaon");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
        return 0;
    }
}
welcome()
{
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("            BEM VINDO AO SISPET EM C           \n");
    printf("-----------------------------------------------\n");
    Sleep(1000);
    system("cls");
    menu();
}

login()
{
    int login1, senha1;
    printf("Login:\n");
    scanf("%i", &login1);
    printf("Senha:\n");
    scanf("%i", &senha);
    menu();
}

menu_root()
{
    int escolhafuncionario;
    printf("1- Cadastrar Funcionario\n");
    printf("2- Buscar Funcionario\n");
    scanf("%d", &escolhafuncionario);

    switch (escolhafuncionario)
    {
    case 1:
        printf("ok");
        break;
    case 2:
        printf("ok");
        break;
    default:
        printf("Opçao Invalida!");
        menu_root();
    }
}

menu()
{
    int escolha;
    setlocale(LC_ALL, "Portuguese");
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("                  MENU DE OPCOES               \n");
    printf("-----------------------------------------------\n");
    printf("\n");
    printf("Escolha uma opcao:\n");
    printf("1- Cadastrar Cliente\n");
    printf("2- Buscar Clientes\n");
    printf("3- Editar Clientes\n");
    printf("4- Cadastrar Pet\n");
    printf("5- Buscar Pet\n");
    printf("6- Editar Pet\n");
    printf("7- Cadastrar Servico\n");
    printf("8- Buscar Servico\n");
    printf("9- Editar Servico\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        system("cls");
        cadastroCliente();
        break;
    case 2:
        system("cls");
        buscarCliente();
        break;
    case 3:
        system("cls");
        editarCliente();
        break;
    case 4:
        system("cls");
        cadastroPet();
        break;
    case 5:
        system("cls");
        buscarPet();
        break;
    case 6:
        system("cls");
        editarPet();
        break;
    case 7:
        printf("ok");
        break;
    case 8:
        printf("ok");
        break;
    case 9:
        printf("ok");
        break;
    default:
        printf("Opcao Invalida!");
        menu();
        break;
    }
}
