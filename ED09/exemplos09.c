/*
ED09 - Tales Rocha Moreira - 13/05/2023
*/
#include "io.h"

void exemplo00()
{
    printf("\nAperte ENTER para sair");
    getchar();
}

/**
printIntMatrix - Mostrar arranjo bidimensional com valores inteiros.
@param rows - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/

void printfIntMatrix(int rows, int columns, int matrix[][columns])
{
    // definir dados locais
    int x = 0; // contador linhas
    int y = 0; // contador colunas

    // mostrar valores na matriz
    for (x = 0; x < rows; x++)
    { // percorre as linhas da matriz, pois matrix[x][y]
        for (y = 0; y < columns; y++)
        {
            // colunas
            // mostrar valor
            IO_printf("%3d\t", matrix[x][y]);
        }
        printf("\n");
    } // fim for

} // fim

void exemplo01()
{
    // identificar
    printf("EXEMPLO01-ED09\n");
    // definir dados
    int matrix[][3] = {// sempre definir colunas
                       {1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};

    // executar funcao
    printfIntMatrix(3, 3, matrix);
    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo01

/**
readIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param rows - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/

void readIntMatrix(int rows, int columns, int matrix[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    chars text = IO_new_chars(STR_SIZE);

    // ler e guardar valores em arranjo
    for (x = 0; x < rows; x++)
    {
        // percorre rows
        for (y = 0; y < columns; y++)
        { // percorre columns
            // ler valor
            strcpy(text, STR_EMPTY);
            z = IO_readint(IO_concat(IO_concat(IO_concat(text, IO_toString_d(x)), ","), IO_concat(IO_concat(text, IO_toString_d(y)), ":")));

            // isolar valor??
            matrix[x][y] = z;
        } // fim for

    } // fim for

} // fim

void exemplo02()
{
    // identificar
    printf("EXEMPLO02 - ED09\n");
    // definir dados
    int n = 2; // quantidade de valores
    int matrix[n][n];

    // ler dados
    readIntMatrix(n, n, matrix); // funcao deste exemplo, percorre e le do teclado
    // mostrar dados
    printf("\n");
    printfIntMatrix(n, n, matrix); // funcao ex01, percorre e mostra

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo02

/**
fprintIntMatrix - Gravar arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param rows - quantidade de linhas
@param columns - quantidade de colunas
@param matrix - grupo de valores inteiros
*/

void fprintIntMatrix(char *fileName, int rows, int columns, int matrix[][columns])
{
    // definir dados locais
    FILE *arquivo = fopen(fileName, "wt");
    int x = 0; // percorrer linhas
    int y = 0; // percorrer colunas

    // gravar quantidade de dados
    IO_fprintf(arquivo, "%d\n", rows);
    IO_fprintf(arquivo, "%d\n", columns);

    // gravar valores no arquivo
    for (x = 0; x < rows; x++)
    {
        for (y = 0; y < columns; y++)
        {
            // gravar valor
            IO_fprintf(arquivo, "%d\n", matrix[x][y]);
            // gravar no arquivo os valores de x e y (r e clmns)
        }
    } // fim for
    // fechar arquivo
    fclose(arquivo);
} // fim

void exemplo03()
{
    // identificar
    printf("EXEMPLO03 - ED09");
    // definir dados
    int rows = 0;
    int columns = 0;

    // ler dados
    rows = IO_readint("\nrows = ");
    columns = IO_readint("\ncolumns = ");
    printf("\n");

    if (rows <= 0 || columns <= 0)
    {
        IO_println("\nERRO: Valor invalido.");
    }
    else
    {
        // reservar espaco
        int matrix[rows][columns];
        // ler dados
        readIntMatrix(rows, columns, matrix);
        // gravar dados
        printf("\n");
        fprintIntMatrix("MATRIX1.TXT", rows, columns, matrix);
    } // fim if

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
}

/**
freadMatrixRows - Ler tamanho (linhas) da matriz com valores inteiros.
@return quantidade de linhas da matriz
@param fileName - nome do arquivo
*/

int freadMatrixRows(char *fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");
    // int *array = NULL;

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido");
        n = 0;
    }

    return (n);

} // fim F-read

/**
freadMatrixColumns - Ler tamanho (colunas) da matriz com valores inteiros.
@return quantidade de colunas da matriz
@param fileName - nome do arquivo
*/

int freadMatrixColumns(char *fileName)
{
    // definir dados locais
    int n = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &n);
    IO_fscanf(arquivo, "%d", &n);

    if (n <= 0)
    {
        IO_println("ERRO: Valor invalido");
        n = 0;
    } // fim se

    return (n);
} // fim FreadColumns

/**
freadIntMatrix - Ler arranjo bidimensional com valores inteiros.
@param fileName - nome do arquivo
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/

void freadIntMatrix(char *fileName, int rows, int columns, int matrix[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    FILE *arquivo = fopen(fileName, "rt");

    // ler a quantidade de dados
    IO_fscanf(arquivo, "%d", &x);
    IO_fscanf(arquivo, "%d", &y);

    if (rows <= 0 || rows > x || columns <= 0 || columns > y)
    {
        IO_println("ERRO: Valor invalido");
    }
    else
    {
        // ler e guardar valores em arranjo
        x = 0;
        while (!feof(arquivo) && x < rows)
        {
            y = 0;
            while (!feof(arquivo) && y < columns)
            {
                // ler valor
                IO_fscanf(arquivo, "%d", &z);
                // guardar valor
                matrix[x][y] = z;
                // passar ao proximo
                y = y + 1;
            } // fim repetir
            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }
    fclose(arquivo);

} // fim freadMatrix

void exemplo04()
{
    // identificar
    printf("EXEMPLO04-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    // ler dados
    rows = freadMatrixRows("MATRIX1.TXT");
    columns = freadMatrixColumns("MATRIX1.TXT");

    if (rows <= 0 || columns <= 0)
    {
        IO_println("\nERRO: Valor invalido");
    }
    else
    {
        // definir armazenador
        int matrix[rows][columns];
        // ler dados
        freadIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        // mostrar dados
        IO_printf("\n");
        printfIntMatrix(rows, columns, matrix);
    } // fim

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo04

/**
copyIntMatrix - Copiar matriz com valores inteiros.
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/

void copyIntMatrix(int rows, int columns, int matrix2[][columns], int matrix1[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    if (rows <= 0 || columns <= 0)
    {
        IO_println("ERRO: Valor invalido.");
    }
    else
    {
        // copiar valores em matriz
        for (x = 0; x < rows; x = x + 1)
        {
            for (y = 0; y < columns; y = y + 1)
            {
                // copiar valor
                matrix2[x][y] = matrix1[x][y];
            }
        } // fim repetir
    }     // fim se

} // copyIntMatrix ( )

void exemplo05()
{
    // identificar
    printf("EXEMPLO05-ED09");
    // definir dados
    int rows = 0;
    int columns = 0;

    // ler dados
    rows = freadMatrixRows("MATRIX1.TXT");
    columns = freadMatrixColumns("MATRIX1.TXT");
    if (rows <= 0 || columns <= 0)
    {
        IO_println("\nERRO: Valor invalido.");
    }
    else
    {
        // definir armazenadores
        int matrix[rows][columns];
        int other[rows][columns];
        // ler dados
        freadIntMatrix("MATRIX1.TXT", rows, columns, matrix);
        // copiar dados
        copyIntMatrix(rows, columns, other, matrix);
        // mostrar dados
        IO_printf("\nOriginal\n");
        printfIntMatrix(rows, columns, matrix);
        // mostrar dados
        IO_printf("\nCopia\n");
        printfIntMatrix(rows, columns, other);
    } // fim se

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim  exemplo05

/**
transposeIntMatrix - Transpor valores inteiros em matriz.
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix2 - grupo de valores inteiros (transposto)
@param matrix1 - grupo de valores inteiros
*/

void transposeIntMatrix(int rows, int columns, int matrix2[][rows], int matrix1[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    // percorrer a matriz
    for (x = 0; x < rows; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            matrix2[y][x] = matrix1[x][y];
        }
    } // fim repetir

} // transposeIntMatrix ( )

void exemplo06()
{
    // definir dados
    int matrix1[][2] = {{1, 0},
                        {0, 1}};

    int matrix2[][2] = {{0, 0},
                        {0, 0}};

    int matrix3[][3] = {{1, 2, 3},
                        {4, 5, 6}};

    int matrix4[][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    // testar dados
    IO_println("\nMatrix1 ");
    printfIntMatrix(2, 2, matrix1);
    transposeIntMatrix(2, 2, matrix2, matrix1);

    IO_println("\nMatrix2");
    printfIntMatrix(2, 2, matrix2);

    IO_println("\nMatrix3");
    printfIntMatrix(2, 3, matrix3);
    transposeIntMatrix(2, 3, matrix4, matrix3);

    IO_println("\nMatrix4");
    printfIntMatrix(3, 2, matrix4);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo06

/**
isIdentity - Testar se matriz identidade.
@return - true, se todos os dados forem iguais a zero;
false, caso contrario
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix - grupo de valores inteiros
*/

bool isIdentity(int rows, int columns, int matrix[][columns])
{
    // definir dados locais
    bool result = false;
    int x = 0;
    int y = 0;
    // testar condicao de existencia
    if (rows <= 0 || columns <= 0 ||
        rows != columns)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // testar valores na matriz
        x = 0;
        result = true;
        while (x < rows && result)
        {
            y = 0;
            while (y < columns && result)
            {
                // testar valor
                if (x == y)
                {
                    result = result && (matrix[x][y] == 1);
                }
                else
                {
                    result = result && (matrix[x][y] == 0);
                } // fim se

                // passar ao proximo
                y = y + 1;
            } // fim repetir

            // passar ao proximo
            x = x + 1;
        } // fim repetir
    }     // fim se

    // retornar resposta
    return (result);

} // fim isIdently

void exemplo07()
{
    // identificar
    printf("EXEMPLO07-ED09\n");
    // definir dados
    int matrix1[][2] = {{0, 0},
                        {0, 0}};

    int matrix2[][3] = {{1, 2, 3},
                        {4, 5, 6}};

    int matrix3[][2] = {{1, 0},
                        {0, 1}};

    // testar dados
    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);
    IO_printf("isIdentity (matrix1) = %d", isIdentity(2, 2, matrix1));

    IO_println("\nMatrix2");
    printfIntMatrix(2, 3, matrix2);
    IO_printf("isIdentity (matrix2) = %d", isIdentity(2, 3, matrix2));

    IO_println("\nMatrix3");
    printfIntMatrix(2, 2, matrix3);
    IO_printf("isIdentity (matrix3) = %d", isIdentity(2, 2, matrix3));

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo07

/**
isEqual - Testar se matrizes iguais.
@return - true, se todos os dados forem iguais;
false, caso contrario
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix1 - grupo de valores inteiros (1)
@param matrix2 - grupo de valores inteiros (2)
*/

bool isEqual(int rows, int columns, int matrix1[][columns], int matrix2[][columns])
{
    // definir dados locais
    bool result = true;
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    x = 0;
    while (x < rows && result)
    {
        y = 0;
        while (y < columns && result)
        {
            // testar valor
            result = result && (matrix1[x][y] == matrix2[x][y]);
            // passar ao proximo
            y = y + 1;
        } // fim repetir
        // passar ao proximo
        x = x + 1;
    } // fim repetir
    // retornar resposta
    return (result);
} // fim isEqual

void exemplo08()
{
    // identificar
    printf("EXEMPLO08-ED09\n");

    // definir dados
    int matrix1[][2] = {{0, 0},
                        {0, 0}};

    int matrix2[][2] = {{1, 2},
                        {3, 4}};

    int matrix3[][2] = {{1, 0},
                        {0, 1}};

    // testar dados
    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix2");
    printfIntMatrix(2, 2, matrix2);

    IO_printf("isEqual (matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));

    copyIntMatrix(2, 2, matrix1, matrix3);
    copyIntMatrix(2, 2, matrix2, matrix3);

    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);

    IO_println("\nMatrix3");
    printfIntMatrix(2, 2, matrix2);

    IO_printf("isEqual (matrix1, matrix2) = %d", isEqual(2, 2, matrix1, matrix2));

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo08

/**
addIntMatrix - Somar matrizes com inteiros.
@param rows - quantidade de valores
@param columns - quantidade de valores
@param matrix3 - grupo de valores inteiros resultante
@param matrix1 - grupo de valores inteiros (1)
@param k - constante para multiplicar o segundo termo
@param matrix2 - grupo de valores inteiros (2)
*/

void addIntMatrix(int rows, int columns, int matrix3[][columns], int matrix1[][columns], int k, int matrix2[][columns])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    // mostrar valores na matriz
    for (x = 0; x < rows; x = x + 1)
    {
        for (y = 0; y < columns; y = y + 1)
        {
            // somar valores
            matrix3[x][y] = matrix1[x][y] + k * matrix2[x][y];
        }
    } // fim repetir

} // fim addIntMatrix

void exemplo09()
{
    // identificar
    printf("EXEMPLO09-ED09\n");

    // definir dados
    int matrix1[][2] = {{1, 2},
                        {3, 4}};

    int matrix2[][2] = {{1, 0},
                        {0, 1}};

    int matrix3[][2] = {{0, 0},
                        {0, 0}};

    // testar dados
    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);
    IO_println("\nMatrix2");
    printfIntMatrix(2, 2, matrix2);
    // somar matrizes
    addIntMatrix(2, 2, matrix3, matrix1, (-2), matrix2);
    IO_println("\nMatrix3");
    printfIntMatrix(2, 2, matrix3);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo09

/**
mulIntMatrix - Multiplicar matrizes com inteiros.
@param rows3 - quantidade de linhas da matriz (3)
@param columns3 - quantidade de colunas da matriz (3)
@param matrix3 - grupo de valores inteiros resultante
@param rows1 - quantidade de linhas da matriz (1)
@param columns1 - quantidade de colunas da matriz (1)
@param matrix1 - grupo de valores inteiros (1)
@param rows2 - quantidade de linhas da matriz (2)
@param columns2 - quantidade de colunas da matriz (2)
@param matrix2 - grupo de valores inteiros (2)
*/

void mulIntMatrix(int rows3, int columns3, int matrix3[][columns3], int rows1, int columns1, int matrix1[][columns1], int rows2, int columns2, int matrix2[][columns2])
{
    // definir dados locais
    int x = 0;
    int y = 0;
    int z = 0;
    int soma = 0;
    if (rows1 <= 0 || columns1 <= 0 || rows2 <= 0 || columns2 <= 0 || rows3 <= 0 || columns3 <= 0 || columns1 != rows2 || rows1 != rows3 || columns2 != columns3)
    {
        IO_printf("\nERRO: Valor invalido.\n");
    }
    else
    {
        // percorrer valores na matriz resultante
        for (x = 0; x < rows3; x = x + 1)
        {
            for (y = 0; y < columns3; y = y + 1)
            {
                // somar valores
                soma = 0;
                for (z = 0; z < columns1; z = z + 1) // ou (z < rows2)
                {
                    soma = soma + matrix1[x][z] * matrix2[z][y];
                } // fim repetir
                // guardar a soma
                matrix3[x][y] = soma;
            }
        } // fim repetir
    }     // fim se

} // fim  mulIntMatrix

void exemplo10()
{
    // identificar
    printf("EXEMPLO10-ED09\n");

    // definir dados
    int matrix1[][2] = {{1, 2},
                        {3, 4}};

    int matrix2[][2] = {{1, 0},
                        {0, 1}};

    int matrix3[][2] = {{0, 0},
                        {0, 0}};

    // testar produto
    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);
    IO_println("\nMatrix2");
    printfIntMatrix(2, 2, matrix2);

    // multiplicar matrizes
    mulIntMatrix(2, 2, matrix3, 2, 2, matrix1, 2, 2, matrix2);
    IO_println("\nMatrix3 = Matrix1 * Matrix2");
    printfIntMatrix(2, 2, matrix3);

    // outro teste
    IO_println("\nMatrix2");
    printfIntMatrix(2, 2, matrix2);
    IO_println("\nMatrix1");
    printfIntMatrix(2, 2, matrix1);

    // multiplicar matrizes
    mulIntMatrix(2, 2, matrix3, 2, 2, matrix2, 2, 2, matrix1);
    IO_println("\nMatrix3 = Matrix2 * Matrix1");
    printfIntMatrix(2, 2, matrix3);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exemplo10

int main()
{
    printf("ED09 - EXEMPLOS - Tales Rocha Moreira");

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