# ePET

> Sistema desenvolvido para matéria de Engenharia de Requisitos do curso de Engenharia de Software da Universidade Católica de Brasília.

![prewview](https://cdn.discordapp.com/attachments/982291225283551262/1034518787095015444/unknown.png)

## 🛠 Tecnologias

  - C
  - MYSQL
  - MYSQL CONNECTOR/C  
  - XAMPP
  
## Instalando e Configurando

### Instalando o MySQL Connector/C
1- Realizar o download do arquivo ZIP em [MySQL Product Archives](https://downloads.mysql.com/archives/c-c/) de acordo com seu sistema operacional.
2- Criar uma pasta com nome "ConectorC"no Disco Local C , após isso deve ser extraido o arquivo baixado nesta pasta.

### Instalando Code::Blocks
1- Realizar o download do instalador em [Code::Blocks](https://www.codeblocks.org/downloads/binaries/).
2- Realizar instalação padrão do software.

### Configurando o MySQL Connector/C no Codeblocks
Nesta etapa será feita a inserção da biblioteca na IDE.

1. Inicialize o Code::Blocks.
2. No menu vá para Settings/Compiler/Linker Settings.
![Screen1](https://cdn.discordapp.com/attachments/982291225283551262/1034524002951106640/unknown.png)

Vá para função 'ADD' encontre a pasta em que foi extraido MySQL Connector/C e adicione os arquivos libmysql.lib e libmysql.dll da pasta lib (C:\conectorC\lib\libmysql.lib).
3. Novamente no menu vá para Settings/Compiler/Search Compiler.
![Screen2](https://media.discordapp.net/attachments/982291225283551262/1034529264286044221/unknown.png?width=693&height=676)

Vá para função 'ADD' encontre a pasta em que foi extraido MySQL Connector/C , em Compiler adicione as pastas include (C:\conectorC\include) , lib (C:\conectorC\lib), bin (C:\conectorC\bin) e em Linker lib(C:\conectorC\lib) e bin(C:\conectorC\bin).

### Instalando XAMPP e configurando 

1. Realizar o download do instalador em [XAMPP](https://www.apachefriends.org/pt_br/index.html) de acordo com o seu sistema operacional.
2. Realizar instalação padrão do software.
3. Iniciar o software e logo após iniciar Apache e o MySQL.
![Screen3](https://cdn.discordapp.com/attachments/982291225283551262/1034532879935479849/unknown.png)

4. Baixar o arquivo [banco.sql](https://drive.google.com/file/d/1KIvwJCknmUh_qLfUpU3LNMCOEglnOu3b/view?usp=sharing)
5. Abrir no navegador [http://localhost/phpmyadmin](http://localhost/phpmyadmin)
6. Criar uma base de dados com nome bancoc
![Screen4](https://user-images.githubusercontent.com/96095997/197899392-8eb81743-5daa-4b3a-b554-0bf44df8eaa8.png)
7. Selecionar o bancoc e clicar em **IMPORTAR** 
![Screen5](https://cdn.discordapp.com/attachments/982291225283551262/1034608601232318494/unknown.png)
9. Selecionar o arquivo banco.sql e confirmar.
![Screen6](https://media.discordapp.net/attachments/982291225283551262/1034608773878259742/unknown.png?width=732&height=193)

### Execução
Basta compilar e executar o [código](https://github.com/Vieirinhagui/Programa-C/blob/main/main.c)

