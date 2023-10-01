/*
ED07 - Tales Rocha Moreira - 27/04/2023
*/
#include "io.h"

void exemplo00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void writeInts(char *fileName, int x) // exemplo01 USEI CHAR* PARA ME ACOSTUMAR O PADRAO DO C
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt"); // escrever arquivo com "nome"
    int y = 0;

    // repetir para
    for (y = 1; y <= x; y++)
    {
        // gravar valor
        fprintf(arquivo, "%d\n", y);
    } // fim for

    // fechar arquivo(INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeInts

void exemplo01() // mostrar certa quantidade de valores
{
    IO_id("EXEMPLO0701 - Method01 - v0.0");

    // executar o metodo auxiliar
    writeInts("DADOS1.TXT", 10); // passou nome do arquivo e condicao de parada do for para a leitura de valores

    printf("Aperte ENTER para sair");
    getchar();
}

/**
readInts - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void readInts(char *fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt"); // leitura
    int x = 0;

    // tentar ler o primeiro
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados
    while (!feof(arquivo)) // so sera verdadeira apos uma tentativa fracassade de leitura
    {
        // mostrar valor
        printf("%d\n", x);
        // tentar ler o proximo
        fscanf(arquivo, "%d", &x);
    }
    // fecharo arquivo, para leitura RECOMENDAVEL
    fclose(arquivo);
} // fim readInts

void exemplo02()
{
    // identificar
    IO_id("EXEMPLO0702 - Method02 - v0.0");
    // executar o metodo auxiliar
    readInts("DADOS1.TXT");
    // enxerrar
    printf("Aperte ENTER para sair");
    getchar();
}

/**
writeDoubles - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/
void writeDoubles(char *fileName, int x)
{
    // definir dadors
    FILE *arquivo = fopen(fileName, "wt");
    int y = 0;
    // gravar quantidade de valores
    IO_fprintf(arquivo, "%d\n", x);
    // repetir para a quantidade de dados
    for (y = 1; y <= x; y++)
    {
        // gravar valor
        IO_fprintf(arquivo, "%lf\n", (0.1 * y));
    } // fim for

    // fechar arquivo INDISPENSAVEL para gravacao
    fclose(arquivo);

} // fim writeDoubles

void exemplo03()
{
    // identificar
    IO_id("EXEMPLO0710 - Method03 - v0.0");
    // executar o metodo auxiliar
    writeDoubles("DADOS2.TXT", 10);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

/**
readDoubles - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/

// Y E X FORAM DEFINIDOS APENAS COMO MAIS UMA CONDICAO DE PARADA??! !feof JA VERIFICARA
void readDoubles(char *fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    int x = 0;
    int y = 1;
    double z = 0.0;

    // tentar ler a quantidade de dados
    fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados e quantidade ao for alcancada
    while (!feof(arquivo) && y <= x)
    {
        // tentar ler
        fscanf(arquivo, "%lf", &z); // A CADA LOOP, UM VALOR E LIDO COM SCANF E ATRIBUIDO A Z E IMPRESSO COM O PRINTF
        // mostrar valor
        printf("%2d: %lf\n", y, z);
        // passar ao proximo
        y++; // ADD Y + 1 PARA PARAR QUANDO CHEGAR AO TAMANHO DE X AO AO FINAL DO ARQUIVO
    }        // fim repetir
    // fechar arquivo(RECOMENDAVEL PARA LEITURA)
    fclose(arquivo);
} // fim readDoubles

void exemplo04()
{
    // identificar
    IO_id("EXEMPLO0710 - Method04 - v0.0");
    // executar o metodo auxiliar
    readDoubles("DADOS2.TXT");
    printf("Aperte ENTER para sair");
    getchar();
}

/**
writeText - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/

void writeText(chars fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "wt");
    chars linha = IO_new_chars(STR_SIZE);
    // repetir ate' desejar parar
    IO_println("Gravar linhas (para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do teclado
        strcpy(linha, IO_readln(""));
        // gravar valor
        IO_fprintf(arquivo, "%s\n", linha);
    } while (strcmp("PARAR", linha) != 0);

    // fechar arquivo (INDISPENSAVEL para gravacao)
    fclose(arquivo);
} // fim writeText()

void exemplo05()
{
    // identificar
    IO_id("EXEMPLO0710 - Method05 - v0.0");
    // executar o metodo auxiliar
    writeText("DADOS3.TXT");

    printf("Aperte ENTER para sair");
    getchar();
}

/**
readText - Ler de arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
*/

void readText(char *fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    // tentar ler o primeiro
    strcpy(linha, IO_freadln(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp("PARAR", linha) != 0) //!= se nao sao iguais a 0
    // PARAR JA FOI LIDO NO METODO "wt"
    {
        // mostrar o valor
        printf("%s\n", linha);
        // tentar ler o proximo
        strcpy(linha, IO_freadln(arquivo));
    } // fim while
      // fechar
    fclose(arquivo);
} // fim readText

void exemplo06()
{
    // identificar
    IO_id("EXEMPLO0710 - Method06 - v0.0");
    // executar o metodo auxiliar
    readText("DADOS3.TXT");
    printf("Aperte ENTER para sair");
    getchar();
}

/**
copyText - Copiar arquivo texto.
@param fileOut - nome do arquivo de saida (destino)
@param fileIn - nome do arquivo de entrada (origem )
*/
void copyText(chars fileOut, chars fileIn)
{
    // definir dados
    FILE *saida = fopen(fileOut, "wt");
    FILE *entrada = fopen(fileIn, "rt");
    chars linha = IO_new_chars(STR_SIZE);

    int contador = 0;
    // ler da origem
    strcpy(linha, IO_freadln(entrada));

    // repetir enquanto houver dados
    while (!feof(entrada))
    {
        // contar linha lida
        contador = contador + 1;
        // gravar no destino,
        // EXCEPCIONALMENTE sem a ultima linha, nesse caso

        if (strcmp("PARAR", linha) != 0)
        { // COPIA A LINHA ATE "PARAR"
            IO_fprintln(saida, linha);
        } // fim se

        // ler da origem
        strcpy(linha, IO_freadln(entrada));
        printf("%s\n", linha);
    } // fim repetir

    // informar total de linhas copiadas
    IO_printf("Lines read = %d\n", contador);
    // fechar arquivos
    fclose(saida);
    fclose(entrada);

} // fim copyText ( )

void exemplo07()
{
    // identificar
    IO_id("EXEMPLO0707 - Method07 - v0.0");
    // executar o metodo auxiliar
    copyText("DADOS4.TXT", "DADOS3.TXT");

    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo07

/**
appendText - Gravar em arquivo texto certa quantidade de valores.
@param fileName - nome do arquivo
@param x - quantidade de valores
*/

void appendText(char *fileName)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "at");
    chars linha = IO_new_chars(STR_SIZE);

    // repetir ate´desejar parar
    IO_println("Gravar linhas(para terminar, entrar com \"PARAR\"):\n");
    do
    {
        // ler do tamanho
        strcpy(linha, IO_readln(""));
        // gravar valor
        IO_fprintln(arquivo, linha);

    } while (strcmp("PARAR", linha) != 0);
    // fechar arquivo INDISPENSAVEL
    fclose(arquivo);

} // fim appendText

void exemplo08()
{
    // identificar
    IO_id("EXEMPLO0710 - Method08 - v0.0");
    // executar metodo
    appendText("DADOS4.TXT");
    // executar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo08

/**
readWords - Ler palavras de arquivo.
@param fileName - nome do arquivo
*/
void readWords(char *fileName) // exemplo09
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    char *linha = IO_new_chars(STR_SIZE);

    // tentar ler primeira
    strcpy(linha, IO_fread(arquivo));
    // repetir enquanto houver dados
    while (!feof(arquivo) && strcmp("PARAR", linha) != 0)
    {
        // mostrar valor
        printf("%s\n", linha);
        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // fim repetir
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);
} // fim readWords

void exemplo09()
{
    // identificar
    IO_id("EXEMPLO0710 - Method09 - v0.0");
    // executar o metodo auxiliar
    readWords("DADOS4.TXT");

    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo09

/**
searchWord - Procurar palavra em arquivo.
@return true, se encontrar; false, caso contrario
@param fileName - nome do arquivo
@param word - palavra a procurar
*/
bool searchWord(char *fileName, char *word)
{
    // definir dados
    FILE *arquivo = fopen(fileName, "rt");
    char linha[80];

    // tentar ler a primeira
    strcpy(linha, IO_fread(arquivo));

    // repetir enquanto houver dados
    while (!feof(arquivo) &&
           strcmp(word, linha) != 0)
    {
        // tentar ler o proximo
        strcpy(linha, IO_fread(arquivo));
    } // fim repetir
    // fechar arquivo (RECOMENDAVEL para leitura)
    fclose(arquivo);

    // retornar resultado
    return (strcmp(word, linha) == 0);
}

void exemplo10()
{
    // identificar
    IO_id("EXEMPLO0710 - Method10 - v0.0");

    // procurar palavra
    IO_printf("Procurar (\"%s\") = %d\n", "pqr", searchWord("DADOS4.TXT", "pqr")); //pqr e pqs como parametros
    IO_printf("Procurar (\"%s\") = %d\n", "pqs", searchWord("DADOS4.TXT", "pqs"));

    printf("Aperte ENTER para sair");
    getchar();
}

int main()
{
    printf("ED07 - EXEMPLOS - Tales Rocha Moreira");

    int x = 0;

    do
    {
        IO_println(" 0 - exemplo00(SAIR)");
        IO_println(" 1 - exemplo01");
        IO_println(" 2 - exemplo02");
        IO_println(" 3 - exemplo03");
        IO_println(" 4 - exemplo04");
        IO_println(" 5 - exemplo05");
        IO_println(" 6 - exemplo06");
        IO_println(" 7 - exemplo07");
        IO_println(" 8 - exemplo08");
        IO_println(" 9 - exemplo09");
        IO_println("10 - exemplo10");

        x = IO_readint("Entrar com a opcao: ");
        printf("\n");

        switch (x)
        {
        case 1:
            exemplo01();
            break;
        case 2:
            exemplo02();
            break;
        case 3:
            exemplo03();
            break;
        case 4:
            exemplo04();
            break;
        case 5:
            exemplo05();
            break;
        case 6:
            exemplo06();
            break;
        case 7:
            exemplo07();
            break;
        case 8:
            exemplo08();
            break;
        case 9:
            exemplo09();
            break;
        case 10:
            exemplo10();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}
