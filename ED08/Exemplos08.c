/*
ED08 - Tales Rocha Moreira - 27/04/2023 - Exemplos
*/
#include "io.h"

void exemplo00() // Nao faz nada
{
    printf("Aperte ENTER para sair");
    getchar();
}

/**
printIntArray - Mostrar arranjo com valores inteiros.
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

void printIntArray(int n, int valores[])
{
    // definir dados
    int x = 0;
    // mostrar valores no vetor
    for (x = 0; x < n; x++)
    {
        // mostrar valor
        IO_printf("%2d: %d\n", x, valores[x]);
    } // fim repetir
} // printIntArray ( )

void exemplo01() // mostrar arranjo com valores inteiros
{
    // definir dados
    int array[] = {1, 2, 3, 4, 5};
    // identificar
    printf("EXEMPLO0810 - Method01\n");
    // executar funcao auxiliar
    printIntArray(5, array);

    printf("Aperte ENTER para sair");
    getchar();
}

/**
readIntArray - Ler arranjo com valores inteiros.
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

void readIntArray(int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    chars text = IO_new_chars(STR_SIZE);
    // ler e guardar valores em arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // ler valor
        strcpy(text, STR_EMPTY);
        y = IO_readint(IO_concat(
            IO_concat(text, IO_toString_d(x)), " : "));
        // guardar valor
        array[x] = y;
    } // fim repetir
} // readIntArray ( )

void exemplo02()
{
    // definir dados
    int n = 5; // quantidade de valores, para ser colocada como tamanho do vetor
    int vetor[n];
    // identificar
    printf("EXEMPLO02\n");
    // ler dados, funcao anterior
    readIntArray(n, vetor);
    // mostrar dados
    printf("\n");
    printIntArray(n, vetor);

    printf("Aperte ENTER para sair");
    getchar();
}

/**
fprintIntArray - Gravar arranjo com valores inteiros.
@param fileName - nome do arquivo
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

void fprintIntArray(char *nomeArquivo, int n, int vetor[])
{
    // definir dados
    FILE *arquivo = fopen(nomeArquivo, "wt");
    int x = 0;
    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", n);
    // gravar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // gravar valor
        IO_fprintf(arquivo, "%d\n", vetor[x]);
    } // fim for

    // fechar
    fclose(arquivo);
} // fim fprintfIntArray

void exemplo03()
{
    // identificar
    printf("EXEMPLO03\n");
    // definir dados
    int n = 5;
    int vetor[n];
    // chamar metodo auxiliar , ler dados
    readIntArray(n, vetor); // popular o vetor com entradas do teclado
    // mostrar valores lidos no array
    printf("\n");
    fprintIntArray("ARRAY1.txt", n, vetor); // chamar a func com as var atualizadas

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo03

/**
freadArraySize - Ler tamanho do arranjo com valores inteiros.
@return quantidade de valores lidos
@param fileName - nome do arquivo
*/

int freadArraySize(char *nomeArquivo)
{

    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(nomeArquivo, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    } // fim se
    // retornar dado lido
    return (n);
}

/**
freadIntArray - Ler arranjo com valores inteiros.
@param fileName - nome do arquivo
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

void freadIntArray(chars fileName, int n, int array[])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    printf("%d", x);
    if (n <= 0 || n > x)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < n)
        {
            // ler valor
            IO_fscanf(arquivo, "%d", &y);
            // guardar valor
            array[x] = y;
            // passar ao proximo
            x++;
        } // fim repetir
    }     // fim se
} // fim freadIntArray ( )

void exemplo04()
{
    // definir dados
    int n = 0; // quantidade de valores
    // identificar
    IO_id("ED08 - Method04 - v0.0");
    // ler dados
    n = freadArraySize("ARRAY1.TXT");
    printf("%d\t", n);
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\n");
        printIntArray(n, array);
    } // fim se

    // encerrar

    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo04

/**
copyIntArray - Copiar arranjo com valores inteiros.
@param n - quantidade de valores
@param copy - copia do grupo de valores inteiros
@param array - grupo de valores inteiros
*/

void copyIntArray(int n, int copy[], int array[]) // exemplo05
{
    // definir dados locais
    int x = 0;
    int y = 0;
    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido.");
        n = 0;
    }
    else
    {
        // copiar valores em arranjo
        for (x = 0; x < n; x = x + 1)
        {
            // copiar valor
            copy[x] = array[x];
        } // fim repetir
    }     // fim se
} // copyIntArray ( )

void exemplo05()
{
    // definir dados
    int n = 0; // quantidade de valores
    // identificar
    IO_id("EXEMPLO0810 - Method05 - v0.0");
    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];

        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);

        // copiar dados
        copyIntArray(n, other, array);

        // mostrar dados
        IO_printf("\nOriginal\n");

        printIntArray(n, array);

        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);

    } // fim se
      // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

/**
sumIntArray - Somar valores em arranjo com inteiros.
@return - soma dos valores
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

int sumIntArray(int n, int array[]) // somar valores do vetor(arquivo ARRAY.TXT)
{
    // definir dados locais
    int soma = 0;
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        soma = soma + array[x];
    } // fim repetir

    // retornar resposta
    return (soma);
} // sumIntArray ( )

void exemplo06()
{
    // definir dados
    int n = 0; // quantidade de valores
    // identificar
    IO_id("EXEMPLO0810 - Method06 - v0.0");
    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // printf(" %d ", n);
        // printf("%d", array[0]);
        //  mostrar a soma dos valores no arranjo
        IO_printf("\nSoma = %d\n", sumIntArray(n, array));
    } // fim se

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

/**
isAllZeros - Testar valores inteiros em arranjo.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/

bool isAllZeros(int n, int array[])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array[x] == 0);

        // passar ao proximo
        x = x + 1;

    } // fim repetir

    // retornar resposta
    return (result);

} // isAllZeros ( )

void exemplo07()
{
    // definir dados
    int n = 5; // quantidade de valores
    int array1[] = {0, 0, 0, 0, 0};
    int array2[] = {1, 2, 3, 4, 5};
    int array3[] = {1, 2, 0, 4, 5};

    // testar dados
    IO_println("\nArray1");
    printIntArray(n, array1);
    IO_printf("isAllZeros (array1) = %d", isAllZeros(n, array1));

    // SOMENTE O ARRAY1 RETORNA 1, POIS SO ELE SATISFAZ TODOS ARRAY[X] == 0;

    IO_println("\nArray2");
    printIntArray(n, array2);
    IO_printf("isAllZeros (array2) = %d", isAllZeros(n, array2));

    IO_println("\nArray3");
    printIntArray(n, array3);
    IO_printf("isAllZeros (array3) = %d\n", isAllZeros(n, array3));

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

/**
addIntArray - Somar arranjos com inteiros.
@return - arranjo com a soma resultante
@param n - quantidade de valores
@param array3 - soma de grupo de valores inteiros
@param array1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo arranjo
@param array2 - grupo de valores inteiros (2)
*/

void addIntArray(int n, int array3[], int array1[], int k, int array2[]) // exemplo08
{
    // definir dados locais
    int x = 0;
    // mostrar valores no arranjo
    for (x = 0; x < n; x = x + 1)
    {
        // somar valor
        array3[x] = array1[x] + k * array2[x];
    } // fim repetir

} // addIntArray ( )

void exemplo08()
{
    // definir dados
    int n = 0; // quantidade de valores
    // identificar
    IO_id("EXEMPLO0810 - Method08 - v0.0");
    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        int sum[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        // operar soma de arranjos
        addIntArray(n, sum, array, (-2), other);
        // mostrar resultados
        IO_printf("\nSoma\n");
        printIntArray(n, sum);
    } // fim se

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo08

/**
isEqual - Testar arranjos com inteiros sao iguais.
@return - true, se todos os dados forem iguais;
false, caso contrario
@param n - quantidade de valores
@param array1 - grupo de valores inteiros (1)
@param array2 - grupo de valores inteiros (2)
*/

bool isEqual(int n, int array1[], int array2[]) // exemplo09
{
    // definir dados locais
    bool result = true;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && result)
    {
        // testar valor
        result = result && (array1[x] == array2[x]);
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // fim isEqual ( )

void exemplo09()
{
    // definir dados
    int n = 0; // quantidade de valores
    // identificar
    IO_id("EXEMPLO0810 - Method09 - v0.0");
    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        int other[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // copiar dados
        copyIntArray(n, other, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar dados
        IO_printf("\nCopia\n");
        printIntArray(n, other);
        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
        // modificar um valor
        other[0] = (-1) * other[0];
        // mostrar dados
        IO_printf("\nCopia alterada\n");
        printIntArray(n, other);
        // mostrar resultado da comparacao
        IO_printf("\nIguais = %d\n", isEqual(n, array, other));
    } // fim se

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo09

/**
searchArray - Procurar valor em arranjo com inteiros.
@return - true, se encontrar;
false, caso contrario
@param value - valor a ser procurado
@param n - quantidade de valores
@param array - grupo de valores inteiros
*/
bool searchArray(int value, int n, int array[]) // exemplo10
{
    // definir dados locais
    bool result = false;
    int x = 0;
    // mostrar valores no arranjo
    x = 0;
    while (x < n && !result)
    {
        // testar valor
        result = (value == array[x]);
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // fim searchArray ( )

void exemplo10()
{
    // definir dados
    int n = 0;     // quantidade de valores
    int value = 0; // valor a ser procurado
    // identificar
    IO_id("EXEMPLO0810 - Method10 - v0.0");
    // ler a quantidade de dados
    n = freadArraySize("ARRAY1.TXT");
    if (n <= 0)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // definir armazenador
        int array[n];
        // ler dados
        freadIntArray("ARRAY1.TXT", n, array);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printIntArray(n, array);
        // mostrar resultados de procuras
        value = array[0];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));
        value = array[n / 2];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));
        value = array[n - 1];
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));
        value = (-1);
        IO_printf("\nProcurar por (%d) = %d\n",
                  value, searchArray(value, n, array));
    } // fim se

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exemplo10

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