/*
ED09 EXERCICIOS - Tales Rocha Moreira - 13/05/2023
*/
#include "io.h"

void exercicio00()
{
    printf("\nAperte ENTER para sair");
    getchar();
}

void lerNegativeMatrix(int rows, int columns, double matriz[][columns])
{
    // percorrer matriz e atribuir
    printf("Popular Matriz\n");
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            printf("%d, %d: ", j, i);
            scanf("%lf", &matriz[j][i]);
        }
    }
    getchar(); // pegar caractere que sobrou da quebra de linha????
} // fim ler

void printMatrizDouble(int linhas, int colunas, double matriz[][colunas])
{
    printf("Matriz:\n");
    for (int j = 0; j < linhas; j++)
    {
        for (int i = 0; i < colunas; i++)
        {
            printf("%7.4lf ", matriz[j][i]);
        }
        printf("\n");
    } // fim percorrer para mostrar

} // fim

void exercicio01()
{
    // identificar
    printf("EXERCICIO01 - ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;
    // ler dados
    rows = IO_readint("Qual o numero de linhas da matriz? ");
    columns = IO_readint("\nQual o numero de colunas da matriz? ");
    // definir matriz
    double matriz[rows][columns];
    // testar se sao negativos ou nulos
    if (rows <= 0 && columns <= 0)
    {
        printf("\nValor invalido, negativo ou nulo");
    } // fim verificar

    lerNegativeMatrix(rows, columns, matriz);
    printMatrizDouble(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio01

void gravarDoubleMatrix(char *arquivo, int rows, int columns, double matriz[][columns]) // ex2
{
    FILE *saida = fopen(arquivo, "wt");

    // gravar matriz
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            fprintf(saida, "%lf ", matriz[j][i]);
        }
        fprintf(saida, "\n");
    }
    fclose(saida);
} // fim gravarDoubleMatrix

void printfDoubleMatriz(char *input, int rows, int columns, double matriz[][columns]) // ex2
{
    FILE *entrada = fopen(input, "rt");
    // percorrer para leitura e printar
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            fscanf(entrada, "%lf ", &matriz[j][i]);
            printf("%7.4lf ", matriz[j][i]);
        } // fim for
        printf("\n");
    }
    fclose(entrada);

} // fim printMatrizDOUBLEzss

void exercicio02() // gravar matriz real em arquivo
{
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Quantas linhas terao na matriz? ");
    scanf("%d", &rows);
    printf("\nQuantas colunas terao na matriz? ");
    scanf("%d", &columns);
    // definir matriz
    double matrizEX2[rows][columns];

    // enviar para leitura
    lerNegativeMatrix(rows, columns, matrizEX2);
    // enviar para gravacao
    gravarDoubleMatrix("matrizEX2.txt", rows, columns, matrizEX2);
    // enviar para imprimir no terminal
    printfDoubleMatriz("matrizEX2.txt", rows, columns, matrizEX2);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();

} // fim exercicio02

void printDiagonalDoubleMatrix(int rows, int columns, double matriz[][columns])
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            printf("%7.4lf", matriz[j][i]);
            j++;
        }
    }
} // fim printDiagonalMatrix

void exercicio03()
{
    // identificar
    printf("EXERCICIO03-ED09\n");

    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Quantas linhas terao a matriz? ");
    scanf("%d", &rows);
    printf("\nQuantas colunas terao a matriz? ");
    ;
    scanf("%d", &columns);

    double matriz[rows][columns]; // definir matriz com dimensoes

    // enviar para execucao
    lerNegativeMatrix(rows, columns, matriz);

    printDiagonalDoubleMatrix(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio03

void printDiagonalSecundariaDoubleMatriz(int rows, int columns, double matriz[][columns])
{
    // percorrer para mostrar
    for (int j = 0; j < rows; j++)
    {
        printf("%7.4lf", matriz[j][columns - 1 - j]);
    } // fim for

} // fim printDiagonal

void exercicio04()
{
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Quantas linhas tera a matriz? ");
    scanf("%d", &rows);
    printf("\nQuantas colunas tera a matriz? ");
    scanf("%d", &columns);

    double matriz[rows][columns];
    // enviar para exec
    lerNegativeMatrix(rows, columns, matriz);
    printDiagonalSecundariaDoubleMatriz(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio04

void printDiagonalPEAbaixo(int rows, int columns, double matriz[][columns])
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            if (j < i)
            {
                //printf("        ");
            }
            else
            {
                printf("%7.4lf", matriz[j][i]);
            }
        }
        printf("\n");
    }
} // fim printAbaixoDiagonal

void exercicio05()
{
    // identificar
    printf("EXERCICIO05-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    rows = IO_readint("Entrar com quantidade de colunas da matriz: ");
    columns = IO_readint("\nEntrar com colunas: ");

    double matriz[rows][columns]; // definir matriz

    // enviar para execucao
    lerNegativeMatrix(rows, columns, matriz);
    printDiagonalPEAbaixo(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio05

void mostrarAcimaDiagonalPrincpal(int rows, int columns, double matrix[][columns])
{
    // percorrer para mostrar
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            if (j > i)
            {
                printf("       ");
     
            }
            else
            {
                printf("%7.4lf", matrix[j][i]);
            } // fim if p/ mostrar
        }
        printf("\n");
    } // fim percorrer

} // fim mostrarAcima

void exercicio06()
{
    // identificar
    printf("EXERCICIO06-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Entrar com numero de linhas: ");
    scanf("%d", &rows);
    printf("Entrar com numero de colunas: ");
    scanf("%d", &columns);

    double matriz[rows][columns];

    // enviar para execucao
    lerNegativeMatrix(rows, columns, matriz);
    mostrarAcimaDiagonalPrincpal(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio06

void mostrarAbaixoDiagonalSecundaria(int rows, int columns, double matriz[][columns])
{
    for (int j = 0; j < rows; j++)
    {
        printf("%7.4lf", matriz[j][columns - 1 - j]); // mostrar do ex4 a diagonal sec
        for (int i = 0; i < columns; i++)
        {
            if (i + j >= rows) // observando que a soma da pos linh, col dos abaixo sao sempre >= linhas
            {
                printf("%7.4lf", matriz[j][i]);
            }
            else
            {
                printf("      ");
            }
        }
        printf("\n");
    }

} // fim mostrarAbaixoDSec

void exercicio07()
{
    // identificar
    printf("EXERCICIO07-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Entrar com linhas da matriz: ");
    scanf("%d", &rows);
    printf("\nEntrar com colunas da matriz: ");
    scanf("%d", &columns);

    double matriz[rows][columns];
    // enviar para execucao
    lerNegativeMatrix(rows, columns, matriz);
    mostrarAbaixoDiagonalSecundaria(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio07

void mostrarAcimaDIGsec(int rows, int columns, double matriz[][columns])
{
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            if (j + i >= rows)
            {
                printf("       ");
            }
            else
            {
                printf("%7.4lf", matriz[j][i]);
            }
        }
        printf("\n");
    }

} // fim mostrar

void exercicio08()
{
    // identificar
    printf("EXERCICIO08-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Entrar com quantidade de linhas: ");
    scanf("%d", &rows);
    printf("\nEntrar com quantidade de colunas: ");
    scanf("%d", &columns);

    double matriz[rows][columns];

    // enviar para teste
    lerNegativeMatrix(rows, columns, matriz);
    mostrarAcimaDIGsec(rows, columns, matriz);

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio08

int AllzerosDPrincipal(int rows, int columns, double matriz[][columns])
{
    bool isZeros = false;
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            if (j < i)
            {
                printf("       ");
            }
            else
            {
                if (matriz[j][i] == 0)
                {
                    printf("%7.4lf\n", matriz[j][i]);
                    isZeros = true;
                }
                else
                {
                    isZeros = false;
                }

            } // fim if
        }

    } // fim for
    return (isZeros);
} // fim allZeros

void exercicio09()
{
    // identificar
    printf("EXERCICIO09-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Entrar com quantidade de linhas: ");
    scanf("%d", &rows);
    printf("\nEntrar com quantidade de colunas: ");
    scanf("%d", &columns);

    double matriz[rows][columns];
    // enviar para testes
    lerNegativeMatrix(rows, columns, matriz);

    // mostrar resultados
    if (AllzerosDPrincipal(rows, columns, matriz) > 0)
    {
        printf("\nTodos os valores abaixo da diagonal principal sao zeros");
    }
    else
    {
        printf("\nHa valores que nao sao iguais a zero na diagonal principal");
    }

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio09

int AllZerosAcimaDprincipal(int rows, int columns, double matriz[][columns])
{
    bool isZeros = false;
    for (int j = 0; j < rows; j++)
    {
        for (int i = 0; i < columns; i++)
        {
            if (j > i)
            {
                printf("       ");
            }
            else
            {
                if (matriz[j][i] == 0)
                {
                    isZeros = true;
                }
                else
                {
                    isZeros = false;
                }
            } // fim if
        }
    }
    return (isZeros);
}

void exercicio10()
{
    // identificar
    printf("EXERCICIO10-ED09\n");
    // definir dados
    int rows = 0;
    int columns = 0;

    printf("Entrar com quantidade de linhas: ");
    scanf("%d", &rows);
    printf("\nEntrar com quantidade de colunas: ");
    scanf("%d", &columns);

    double matriz[rows][columns];
    // enviar para testes
    lerNegativeMatrix(rows, columns, matriz);

    if (AllzerosDPrincipal(rows, columns, matriz))
    {
        printf("Todos os valores acima da diagonal principal sao zeros");
    }
    else
    {
        printf("\nHa valores acima da diagonal principal que sao diferentes de zero");
    }

    // encerrar
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exercicio10

void AdicionarLeCMatriz(char *arquivo, int rows, int columns, double matriz[][columns])
{
    FILE *output = fopen(arquivo, "wt");

    int numero = rows * columns;
    while (rows >= 2 && columns >= 2)
    {
        fprintf(output, "rows: %d\n", rows);
        for (int j = rows; j > 0; j--)
        {
            for (int i = columns; i > 0; i--)
            {
                matriz[j][i] = numero--;
                fprintf(output, "   %7.4lf   ", matriz[j][i]);
                if (numero < 1)
                {
                    rows--;
                    columns--;
                    numero = rows * columns;
                }
            }
            fprintf(output, "\n");
        }
    }
    fclose(output);
}

void exercicioEXTRA01()
{
    // identificar
    printf("EXTRA1-ED09\n");
    // definir dados
    int rows = 4;
    int columns = 4;

    double matriz[rows][columns];
    AdicionarLeCMatriz("EXTRA01.txt", rows, columns, matriz);

    printf("\nAperte ENTER para sair\n");
    getchar();

} // exercicioEXTRA01

void extra02FUNC(char *arquivo, int rows, int columns, int matriz[][columns])
{
    FILE *output = fopen(arquivo, "wt");

    int numero = rows * columns;
    while (rows >= 2 && columns >= 2)
    {
        fprintf(output, "rows: %d\n", rows);
        for (int j = rows - 1; j >= 0; j--)
        {
            for (int i = columns - 1; i >= 0; i--)
            {
                matriz[i][j] = numero--;
                fprintf(output, "   %d   ", matriz[j][i]);
 
                if (numero < 1)
                {
                    rows--;
                    columns--;
                    numero = rows * columns;
                }
            }
            fprintf(output, "\n");
        }
    }
    fclose(output);
    
} // fim extra02FUNC

void EXTRA02()
{
    int rows = 4;
    int columns = 4;

    int matriz[rows][columns];
    extra02FUNC("EXTRA02.txt", rows, columns, matriz);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim extra02

int main()
{
    printf("ED10 - exercicios - Tales Rocha Moreira");

    int x = 0;

    do
    {
        IO_println(" 0 - exercicio00(SAIR)");
        IO_println(" 1 - exercicio01");
        IO_println(" 2 - exercicio02");
        IO_println(" 3 - exercicio03");
        IO_println(" 4 - exercicio04");
        IO_println(" 5 - exercicio05");
        IO_println(" 6 - exercicio06");
        IO_println(" 7 - exercicio07");
        IO_println(" 8 - exercicio08");
        IO_println(" 9 - exercicio09");
        IO_println("10 - exercicio10");
        IO_println("11 - exercicioEXTRA01");
        IO_println("12 - exercicioEXTRA02");

        x = IO_readint("Entrar com a opcao: ");
        printf("\n");

        switch (x)
        {
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;
        case 11:
            exercicioEXTRA01();
            break;
        case 12:
            EXTRA02();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}