cadastroServico()
{
    setlocale(LC_ALL, "Portuguese");
    char query8[2000];
    char servcpfcliente[100];
    char servtype[100];
    char servdatain[100];
    char servdataout[100];

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
        scanf("%s", &servcpfcliente);
        fflush(stdin);
        printf("Tipo de Servico:");
        scanf("%s", &servtype);
        fflush(stdin);
        printf("Data de Entrada:");
        scanf("%s", &servdatain);
        fflush(stdin);
        printf("Data de Saida:");
        scanf("%s", &servdataout);
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
        printf("Falha de conexaon");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
}
buscarServico()
{
    char query9[2000];
    char busservcpfcliente[100];
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
        scanf("%s", &busservcpfcliente);
        fflush(stdin);
        system("cls");
        sprintf(query9, "SELECT * FROM `servicos` WHERE `servcpfcliente`='%s';", busservcpfcliente);
        if (mysql_query(&conexao, query9))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nCPF Cliente:%s\nTipo de Servico:%s\nData de Entrada:%s\nData de Saida:%s\n\n\n\n ", row[0], row[1], row[2], row[3]);
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
    char busservcpfcliente[100];
    int escolha1;
    char editservcpfcliente[100];
    char editservtype[100];
    char editservdatain[100];
    char editservdataout[100];
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
        printf("Digite o numero 'cpf' do cliente para editar o servico:\n");
        scanf("%s", &busservcpfcliente);
        fflush(stdin);
        system("cls");
        sprintf(query10, "SELECT * FROM `servicos` WHERE `servcpfcliente`='%s';",busservcpfcliente);
        if (mysql_query(&conexao,query10))
        {
            fprintf(stderr, "%s\n", mysql_error(&conexao));
            return (0);
        }
        res = mysql_use_result(&conexao);
        while ((row = mysql_fetch_row(res)) != NULL)
        {
            printf("ID:%s\nCPF Cliente:%s\nTipo de Servico:%s\nData de Entrada:%s\nData de Saida:%s\n\n\n\n ", row[0], row[1], row[2], row[3]);
            mysql_free_result(res);
        }
        printf("\n\n\nQual dado quer alterar\n");
        printf("1-CPF\n");
        printf("2-Tipo de Servico\n");
        printf("3-Data de Entrada\n");
        printf("4-Data de Saida\n");
        printf("5-Apagar Cliente\n");
        scanf("%d", &escolha1);
        switch (escolha1)
        {
        case 1:
            printf("Qual o novo CPF?");
            scanf("%s", &editservcpfcliente);
            sprintf(query11, "UPDATE `clientes` SET `servcpfcliente`='%s' WHERE `servcpfcliente`='%s'", editservcpfcliente, busservcpfcliente);
            mysql_query(&conexao, query11);
            break;
        case 2:
            printf("Qual o Tipo de Servico?");
            scanf("%s", &editservtype);
            sprintf(query11, "UPDATE `clientes` SET `tipo`='%s' WHERE `servcpfcliente`='%s'", editservtype, busservcpfcliente);
            mysql_query(&conexao, query11);
            break;
        case 3:
            printf("Qual a Data de Entrada");
            scanf("%s", &editservdatain);
            sprintf(query11, "UPDATE `clientes` SET `dataIn`='%s' WHERE `servcpfcliente`='%s'", editservdatain, busservcpfcliente);
            mysql_query(&conexao, query11);
            break;
        case 4:
            printf("Qual a Data de Saida?");
            scanf("%s", &editservdataout);
            sprintf(query11, "UPDATE `clientes` SET `dataOut`='%s' WHERE `servcpfcliente`='%s'", editservdataout, busservcpfcliente);
            mysql_query(&conexao, query11);
            break;
        case 5:
            printf("Tem certeza?\n");
            printf("1-Sim\n");
            printf("2-Nao\n");
            scanf("%d",&deletecliente);
            switch (deletecliente){
                case 1:
                sprintf(query11, "DELETE FROM `servicos` WHERE `servcpfcliente`='%s'",busservcpfcliente);
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