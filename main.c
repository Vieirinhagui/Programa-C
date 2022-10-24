#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>
#include <windows.h>
#include <C:\ConectorC\include\mysql.h>
#include <locale.h>

int login1, senha, escolha, escolhafuncionario;

MYSQL *__stdcall obterConexao()
{
    char *servidor = "127.0.0.1";
    char *usuario = "root";
    char *senha = "";
    char *nomeBanco = "bancoC";

    MYSQL *conexao = mysql_init(NULL);

    if (!mysql_real_connect(conexao, servidor, usuario, senha, nomeBanco, 0, NULL, 0))
    {
        fprintf(stderr, "\n%s\n", mysql_error(conexao));
        mysql_close(conexao);
        exit(1);
    }
    else
    {
        printf("\nConexao realizada com sucesso!\n");
        return conexao;
    }
}

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
    inserir();
}

menu_root()
{
    printf("1- Cadastrar Funcionário\n");
    printf("2- Buscar Funcionário\n");
    scanf("%d", &escolhafuncionario);

    switch (escolhafuncionario)
    {
    case 1:
        inserir();
        break;
    case 2:
        inserir();
        break;
    default:
        printf("Opção Invalida!");
        menu_root();
    }
}

menu()
{
    setlocale(LC_ALL,"Portuguese");
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
        printf("ok");
        break;
    case 2:
        printf("ok");
        break;
    case 3:
        printf("ok");
        break;
    case 4:
        printf("ok");
        break;
    case 5:
        printf("ok");
        break;
    case 6:
        printf("ok");
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
    case 10:
        printf("ok");
        break;
    default:
        printf("Opção Inválida!");
        menu();
    }
}
void inserir(MYSQL conexao, char nomecliente, int telefonecliente, char emailcliente, int cpfcliente, char enderecocliente)
{
    printf("Nome: \n");
    scanf("%s",&nomecliente);
    printf("Telefone:\n");
    scanf("%d",&telefonecliente);
    printf("Email:\n");
    scanf("%s",&emailcliente);
    printf("CPF:\n");
    scanf("%s",&cpfcliente);
    printf("Endereço:\n");
    scanf("%s",&enderecocliente);
    char query[100];
    sprintf(query, "INSERT INTO 'clientes' (nomecliente, telefonecliente , emailcliente , cpfcliente , enderecocliente ) VALUES( '%s', '%d' , '%s', '%d','%s' );", nomecliente, telefonecliente , emailcliente,cpfcliente,enderecocliente);

}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    MYSQL *conexao = obterConexao();
    welcome();
    printf("\n");
    login();
    printf("\n");
    return 0;
}
