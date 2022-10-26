#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <string.h>
#include <C:\ConectorC\include\mysql.h>
#include <windows.h>
#include <locale.h>
#define servidor "localhost"
#define usuario "root"
#define senha ""
#define bd "bancoc"

void limpar()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
void ler(char *buffer, int length)
{
    fgets(buffer, length, stdin);
    strtok(buffer, "\n");
}
int main()
{
    welcome();
    printf("\n");
    return 0;
}

cadastroCliente()
{
    char query[2000];
    char nomecliente[255];
    char emailcliente[255];
    char enderecocliente[255];
    char telefonecliente[255];
    char cpfcliente[255];

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

        limpar();

        printf("Nome:");
        ler(nomecliente, 255);
        fflush(stdin);

        printf("Telefone:");
        ler(telefonecliente, 255);
        fflush(stdin);

        printf("E-mail:");
        ler(emailcliente, 255);
        fflush(stdin);

        printf("CPF:");
        ler(cpfcliente, 255);
        fflush(stdin);

        printf("Endereco:");
        ler(enderecocliente, 255);
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
        printf("Falha de conex�o");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
buscarCliente()
{
    char query1[2000];
    char buscpfcliente[255];
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
        scanf("%s",&buscpfcliente);
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
            printf("ID:%s\nNome:%s\nTelefone:%s\nEmail:%s\nCPF:%s\nEndereco:%s\n\n\n\n ", row[0], row[1], row[2], row[3], row[4], row[5]);
        }
        mysql_free_result(res);
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conex�o");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
    return 0;
}

editarCliente()
{
    char query2[2000];
    char query3[2000];
    char busidcliente[255];
    int escolha1;
    char editnomecliente[255];
    char edittelefonecliente[255];
    char editemailcliente[255];
    char editcpfcliente[255];
    char editenderecocliente[255];
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
        printf("Digite o numero 'ID' do cliente para editar:\n");
        scanf("%s",&busidcliente);
        fflush(stdin);
        system("cls");
        sprintf(query2, "SELECT * FROM `clientes` WHERE `idCliente`='%s';", busidcliente);
        if (mysql_query(&conexao, query2))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nNome:%s\nTelefone:%s\nEmail:%s\nCPF:%s\nEndereco:%s\n ", row[0], row[1], row[2], row[3], row[4], row[5]);
            mysql_free_result(res);
        }
        printf("\n\n\nQual dado quer alterar\n");
        printf("1-Nome\n");
        printf("2-Telefone\n");
        printf("3-Email\n");
        printf("4-CPF\n");
        printf("5-Endereco\n");
        printf("6-Apagar Cliente\n");
        printf("7-Cancelar\n");
        scanf("%d", &escolha1);
        switch (escolha1)
        {
            case 1:
                printf("Qual o novo nome?\n");
                scanf("%s",&editnomecliente);
                sprintf(query3, "UPDATE `clientes` SET `nomeCliente`='%s' WHERE `idCliente`='%s'", editnomecliente, busidcliente);
                mysql_query(&conexao, query3);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 2:
                printf("Qual o novo Telefone?\n");
                scanf("%s",&edittelefonecliente);
                sprintf(query3, "UPDATE `clientes` SET `telefoneCliente`='%s' WHERE `idCliente`='%s'", edittelefonecliente, busidcliente);
                mysql_query(&conexao, query3);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 3:
                printf("Qual o novo Email?\n");
                scanf("%s",&editemailcliente);
                sprintf(query3, "UPDATE `clientes` SET `emailCliente`='%s' WHERE `idCliente`='%s'", editemailcliente, busidcliente);
                mysql_query(&conexao, query3);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 4:
                printf("Qual o novo CPF?\n");
                scanf("%s",&editcpfcliente);
                sprintf(query3, "UPDATE `clientes` SET `cpfCliente`='%s' WHERE `idCliente`='%s'", editcpfcliente, busidcliente);
                mysql_query(&conexao, query3);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 5:
                printf("Qual o novo Endereco?\n");
                scanf("%s",&editenderecocliente);
                sprintf(query3, "UPDATE `clientes` SET `enderecoCliente`='%s' WHERE `idCliente`='%s'", editenderecocliente, busidcliente);
                mysql_query(&conexao, query3);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 6:
                printf("Tem certeza?\n");
                printf("1-Sim\n");
                printf("2-Nao\n");
                scanf("%d",&deletecliente);
                switch (deletecliente)
                {
                case 1:
                    sprintf(query3, "DELETE FROM `clientes` WHERE `idCliente`='%s'", busidcliente);
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
            case 7:
                system("cls");
                menu();
                break;
            default:
                break;
        }
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
        return 0;
    }
}
cadastroPet()
{
    char query4[2000];
    char nomepet[255];
    char pelagempet[255];
    char pesopet[255];
    char sexopet[255];
    char racapet[255];
    char especiepet[255];
    char cpfdonopet[255];

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
        limpar();
        printf("Nome do Pet:");
        ler(nomepet, 255);
        fflush(stdin);
        printf("Pelagem do Pet:");
        ler(pelagempet, 255);
        fflush(stdin);
        printf("CPF dono do Pet:");
        ler(cpfdonopet, 255);
        fflush(stdin);
        printf("Peso do Pet em KG:");
        ler(pesopet, 255);
        fflush(stdin);
        printf("Sexo do pet:");
        ler(sexopet, 255);
        fflush(stdin);
        printf("Especie do Pet:");
        ler(especiepet, 255);
        fflush(stdin);
        printf("Raca do Pet:");
        ler(racapet, 255);
        fflush(stdin);
        sprintf(query4, "INSERT INTO `animal`(`nomePet`, `cpfdonopet`, `pelagemPet`, `PesoPet`, `SexoPet`,`especiePet` ,`racaPet` ) VALUES ('%s','%s','%s','%s','%s','%s','%s')", nomepet, cpfdonopet, pelagempet, pesopet, sexopet, especiepet, racapet);
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
    char buscpfdonopet[255];
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
        scanf("%s",&buscpfdonopet);
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
            printf("ID:%s\nNome:%s\nCPF dono:%s\nPelagem:%s\nPeso:%s KG\nSexo:%s\nEspecie:%s\nRaca:%s\n\n ", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
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
    char busidpet[255];
    int escolha2;
    char editnomepet[255];
    char editcpfdono[255];
    char editpelagempet[255];
    char editpesopet[255];
    char editsexopet[255];
    char editracapet[255];
    char editespeciepet[255];

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
        printf("Digite o numero 'ID' do pet para editar:\n");
        scanf("%s",&busidpet);
        fflush(stdin);
        system("cls");
        sprintf(query6, "SELECT * FROM `animal` WHERE `idAnimal`='%s';", busidpet);
        if (mysql_query(&conexao, query6))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID pet:%s\nNome do Pet:%s\nCPF do dono:%s\nPelagem do Pet:%s\nPeso do Pet:%s KG\nSexo do Pet:%s\nEspecie do Pet:%s\n%Raca do Pet:%s\n ", row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7]);
            mysql_free_result(res);
        }
        printf("\n\n\nQual dado quer alterar\n");
        printf("1-Nome do Pet\n");
        printf("2-CPF do Pet\n");
        printf("3-Pelagem do Pet\n");
        printf("4-Peso do Pet\n");
        printf("5-Sexo do Pet\n");
        printf("6-Especie do Pet\n");
        printf("7-Raca do Pet\n");
        printf("8-Apagar Pet\n");
        printf("9-Cancelar\n");
        scanf("%d", &escolha2);
        switch (escolha2)
        {
            case 1:
                printf("Qual o novo nome do Pet?");
                scanf("%s",&editnomepet);
                sprintf(query7, "UPDATE `animal` SET `nomePet`='%s' WHERE `idAnimal`='%s'", editnomepet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 2:
                printf("Qual o novo CPF do dono?");
                scanf("%s",&editcpfdono);
                sprintf(query7, "UPDATE `animal` SET `cpfdonopet`='%s' WHERE`idAnimal`='%s'", editcpfdono, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 3:
                printf("Qual a Pelagem do Pet?");
                scanf("%s",&editpelagempet);
                sprintf(query7, "UPDATE `animal` SET `pelagemPet`='%s' WHERE`idAnimal`='%s'", editpelagempet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 4:
                printf("Qual o peso do Pet?");
                scanf("%s",&editpesopet);
                sprintf(query7, "UPDATE `animal` SET `PesoPet`='%s' WHERE`idAnimal`='%s'", editpesopet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 5:
                printf("Qual o Sexo do Pet?");
                scanf("%s",&editsexopet);
                sprintf(query7, "UPDATE `animal` SET `SexoPet`='%s' WHERE`idAnimal`='%s'", editsexopet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 6:
                printf("Qual a Especie do Pet?");
                scanf("%s",&editespeciepet);
                sprintf(query7, "UPDATE `animal` SET `especiePet`='%s' WHERE`idAnimal`='%s'", editespeciepet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 7:
                printf("Qual a Raca do Pet?");
                scanf("%s",&editracapet);
                sprintf(query7, "UPDATE `animal` SET `racaPet`='%s' WHERE`idAnimal`='%s'", editracapet, busidpet);
                mysql_query(&conexao, query7);
                Sleep(1000);
                system("cls");
                menu();
                break;
            case 8:
                printf("Tem certeza?\n");
                printf("1-Sim\n");
                printf("2-Nao\n");
                scanf("%d", &deletecliente);
                switch (deletecliente)
                {
                case 1:
                    sprintf(query7, "DELETE FROM `animal` WHERE `idAnimal`='%s'", busidpet);
                    mysql_query(&conexao, query7);
                    system("cls");
                    printf("\n");
                    printf("\n");
                    printf("Pet apagado com sucesso");
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
            case 9:
                system("cls");
                menu();
            default:
                break;
        }
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
        return 0;
    }
}
cadastroServico()
{
    char query8[2000];
    char servcpfcliente[255];
    char servtype[255];
    char servdatain[255];
    char servdataout[255];

    MYSQL conexao;
    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, servidor, usuario, senha, bd, 0, NULL, 0))
    {
        printf("Conectado com sucesso ao banco de dados!\n");
        printf("\n");
        printf("\n");
        printf("-----------------------------------------------\n");
        printf("             CADASTRO DE SERVICOS              \n");
        printf("-----------------------------------------------\n");
        printf("CPF do Cliente:");
        scanf("%s",&servcpfcliente);
        fflush(stdin);
        printf("Tipo de Servico:");
        ler(servtype, 255);
        fflush(stdin);
        printf("Data de Entrada:");
        ler(servdatain, 255);
        fflush(stdin);
        printf("Data de Saida:");
        ler(servdataout, 255);
        fflush(stdin);
        sprintf(query8, "INSERT INTO `servicos`(`servcpfcliente`, `tipo`, `dataIn`, `dataOut`) VALUES ('%s','%s','%s','%s');", servcpfcliente, servtype, servdatain, servdataout);
        mysql_query(&conexao, query8);
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
buscarServico()
{
    char query9[2000];
    char buscpfserv[255];
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
        printf("             BUSCADOR DE SERVICOS              \n");
        printf("-----------------------------------------------\n");
        printf("Digite o cpf para localizar o servico:");
        scanf("%s",&buscpfserv);
        fflush(stdin);
        system("cls");
        sprintf(query9, "SELECT * FROM `servicos` WHERE `servcpfcliente`='%s';", buscpfserv);
        if (mysql_query(&conexao, query9))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nCPF Cliente:%s\nTipo de Servico:%s\nData de Entrada:%s\nData de Saida:%s\n\n\n\n ", row[0], row[1], row[2], row[3], row[4]);
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

editarServico()
{
    char query10[2000];
    char query11[2000];
    char busidserv1[255];
    int escolha1;
    char editservcpfcliente[255];
    char editservtype[255];
    char editservdatain[255];
    char editservdataout[255];
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
        printf("             EDITOR DE SERVICOS              \n");
        printf("-----------------------------------------------\n");
        printf("Digite o numero 'ID' do cliente para editar o servico:\n");
        scanf("%s",&busidserv1);
        fflush(stdin);
        system("cls");
        sprintf(query10, "SELECT * FROM `servicos` WHERE `idservico`='%s';", busidserv1);
        if (mysql_query(&conexao, query10))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nCPF Cliente:%s\nTipo de Servico:%s\nData de Entrada:%s\nData de Saida:%s\n\n ", row[0], row[1], row[2], row[3], row[4]);
        }
        printf("\nQual dado quer alterar\n");
        printf("1-CPF\n");
        printf("2-Tipo de Servico\n");
        printf("3-Data de Entrada\n");
        printf("4-Data de Saida\n");
        printf("5-Apagar Cliente\n");
        printf("6-Cancelar\n");
        scanf("%d", &escolha1);
        switch (escolha1)
        {
        case 1:
            printf("Qual o novo CPF?");
            scanf("%s",&editservcpfcliente);
            sprintf(query11, "UPDATE `servicos` SET `servcpfcliente`='%s' WHERE `idservico`='%s'", editservcpfcliente, busidserv1);
            mysql_query(&conexao, query11);
            Sleep(1000);
            system("cls");
            menu();
            break;
        case 2:
            printf("Qual o Tipo de Servico?");
            scanf("%s",&editservtype);
            sprintf(query11, "UPDATE `servicos` SET `tipo`='%s' WHERE `idservico`='%s'", editservtype, busidserv1);
            mysql_query(&conexao, query11);
            Sleep(1000);
            system("cls");
            menu();
            break;
        case 3:
            printf("Qual a Data de Entrada");
            scanf("%s",&editservdatain);
            sprintf(query11, "UPDATE `servicos` SET `dataIn`='%s' WHERE `idservico`='%s'", editservdatain, busidserv1);
            mysql_query(&conexao, query11);
            Sleep(1000);
            system("cls");
            menu();
            break;
        case 4:
            printf("Qual a Data de Saida?");
            scanf("%s",&editservdataout);
            sprintf(query11, "UPDATE `servicos` SET `dataOut`='%s' WHERE `idservico`='%s'", editservdataout, busidserv1);
            mysql_query(&conexao, query11);
            Sleep(1000);
            system("cls");
            menu();
            break;
        case 5:
            printf("Tem certeza?\n");
            printf("1-Sim\n");
            printf("2-Nao\n");
            scanf("%d", &deletecliente);
            switch (deletecliente)
            {
            case 1:
                sprintf(query11, "DELETE FROM `servicos` WHERE `idservico`='%s'", busidserv1);
                mysql_query(&conexao, query11);
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
        case 6:
            system("cls");
            menu();
        default:
            break;
        }
        mysql_close(&conexao);
        menu();
    }
    else
    {
        printf("Falha de conexao");
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
    printf("             BEM VINDO AO E-PET EM C           \n");
    printf("-----------------------------------------------\n");
    Sleep(1000);
    system("cls");
    menu();
}

menu()
{
    setlocale(LC_ALL, "Portuguese");
    int escolha;
    printf("\n");
    printf("-----------------------------------------------\n");
    printf("                 MENU DE OPCOES                \n");
    printf("-----------------------------------------------\n");
    printf("\n");
    printf("Escolha uma opcoes:\n");
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
        system("cls");
        cadastroServico();
        break;
    case 8:
        system("cls");
        buscarServico();
        break;
    case 9:
        system("cls");
        editarServico();
        break;
    default:
        printf("Opcao Invalida!");
        menu();
        break;
    }
}
