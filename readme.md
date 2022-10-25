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

1. Inicializa o Code::Blocks.
2. No menu vá para Settings/Compiler/Linker Compiler.
![Screen1](https://cdn.discordapp.com/attachments/982291225283551262/1034524002951106640/unknown.png)

Vá para função 'ADD' encontre a pasta em que foi extraido MySQL Connector/C e adicione os arquivos libmysql.lib e libmysql.dll da pasta lib (C:\conectorC\lib\libmysql.lib).
3. Novamente no menu vá para Settings/Compiler/Search Compiler.
![Screen2](https://cdn.discordapp.com/attachments/982291225283551262/1034528875222401084/unknown.png)

Vá para função 'ADD' encontre a pasta em que foi extraido MySQL Connector/C , em Compiler adicione as pastas include (C:\conectorC\include) , lib (C:\conectorC\lib), bin (C:\conectorC\bin) e em Linker lib(C:\conectorC\lib) e bin(C:\conectorC\bin).

### Instalando XAMPP 

1- Realizar o download do instalador em [XAMPP](https://www.apachefriends.org/pt_br/index.html) de acordo com o seu sistema operacional.
2- Realizar instalação padrão do software.
3- Inicar o Apache e logo após o MySQL.
