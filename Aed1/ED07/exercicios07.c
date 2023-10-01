/*
ED07 - Tales Rocha Moreira - 27/04/2023
EXERCICIOS
EXTRAS NO FINAL
*/
#include "io.h"

void exercicio00() // nao faz nada, encerrar a execucao
{
    printf("Aperte ENTER para sair");
    getchar();
}

void gravarEmMultiplos3(char *nomeArquivo, int x) // exercicio01
{
    FILE *arquivo = fopen(nomeArquivo, "wt");

    for (int i = 1; i <= x; i++)
    {
        fprintf(arquivo, " %d ", i * 6);
    }
    fclose(arquivo);
} // fim gravarEmMultiplos3

void exercicio01()
{
    // identificar
    printf("Exercicio01\n");
    // definir dados
    int x = 0; // parametro a ser passado

    // executar
    printf("Quantos valores multiplos de 6 pares gravar no arquivo? ");
    scanf("%d", &x);

    gravarEmMultiplos3("Exercicio01.txt", x);

    printf("\nAperte ENTER para sair");
    getchar();
}

void gravarMultiplos5Impares(char *arquivoNome, int x) // exercicio02
{
    FILE *arquivo = fopen(arquivoNome, "wt");

    int contador = 1;
    for (int i = 10 * x + 5; i >= 15; i -= 10)
    {
        fprintf(arquivo, " %d ", i);
        contador++;
    }
    fclose(arquivo);
} // fim gravarMultiplos5Impares

void exercicio02()
{
    // identificar
    printf("Exercicio 02\n");
    // definir dados
    int x;
    // executar
    printf("Quantos multiplos de 5 impares mostrar: ");
    scanf("%d", &x);

    gravarMultiplos5Impares("Exercicio02.txt", x);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

void gravarMultiplicar6(char *arquivoNome, int x) // exercicio03
{
    FILE *arquivo = fopen(arquivoNome, "wt");
    int result = 1;

    for (int i = 1; i <= x; i++)
    {
        fprintf(arquivo, " %d ", result);
        result = result * 6;
    }
    fclose(arquivo);

} // fim gravar

void exercicio03()
{
    // identificar
    printf("Exercicio03\n");
    // definir dados
    int x = 0;
    // executar
    printf("Quantos valores multiplicados de 6 gravar: ");
    scanf("%d", &x);

    gravarMultiplicar6("Exercicio03", x);
    printf("\nAperte ENTER para sair");
    getchar();
} // fim exericio03

void gravarDecrescendoFracionario6(char *nomeArquivo, int x) // exercicio04
{
    FILE *arquivo = fopen(nomeArquivo, "wt");
    int numerador = 1;
    int denominador = 1;

    for (int i = x - 1; i >= 1; i--)
    {
        denominador = pow(6, i);
        /*denominador = 1;
        for (int j = 1; j < i; j++)
        {
            denominador *= 6;
        }*/
        fprintf(arquivo, "%d\n", denominador);
        // TIVE QUE PARAR DE USAR O NUMERADOR POR PROBLEMA DE LEITURA DO ARQUIVO NO EX07
    }

    fclose(arquivo);
} // fim gravar

void exercicio04()
{
    // identificar
    printf("Exercicio04\n");
    // definir dados
    int x = 0;
    // executar
    printf("Quantos valores mostrar: ");
    scanf("%d", &x);

    gravarDecrescendoFracionario6("Exercicio4.txt", x);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio04

void potenciaDenominador(char *nomeArquivo, int x, int y) // exercicio05
{
    FILE *arquivo = fopen(nomeArquivo, "wt");
    int numerador = 1;
    int denominador = 1;

    for (int j = 0; j <= x; j++)
    {
        for (int i = 1; i <= j; i = i + 1)
        {
            denominador = pow(y, j);
        }
        fprintf(arquivo, "%d  %d\n", numerador, denominador);
    }

} // fim potencia

void exercicio05()
{
    // identificar
    printf("Exercicio05\n");
    // definir dados
    int x = 0;
    // executar
    printf("Entrar com quantos valores mostrar: ");
    scanf("%d", &x);

    potenciaDenominador("Exercicio5.txt", x, 2);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio05

void somaDoEx5(char *fileOut, char *fileIn) // exercicio06
{
    FILE *saida = fopen(fileOut, "wt");
    FILE *entrada = fopen(fileIn, "rt");
    // int contador = 0;

    int x = 0; // dados do arquivo Exercicio5.txt
    int soma = 0;
    int vezes = 5;

    // tentar ler o primeiro
    // fscanf(arquivo, "%d", &x);
    // repetir enquanto houver dados
    for (int i = 1; i <= vezes; i++)
    {
        fscanf(entrada, "%d", &x);
        soma = x + x;
        // fprintf(saida, "soma = %d \n", soma);
    }
    fprintf(saida, "soma = %d \n", soma);

    // fecharo arquivo, para leitura RECOMENDAVEL
    fclose(entrada);
    fclose(saida);

} // fim soma

void exercicio06()
{
    int x = 0; // valor para calcular a soma
    somaDoEx5("RESULTADOS06.txt", "Exercicio5.txt");

    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio06

void LerECalcularInversos04(char *InPut, char *OutPut, int x) // exercicio07
{
    // definir dados
    FILE *entrada = fopen(InPut, "rt");
    FILE *saida = fopen(OutPut, "wt");
    int controle = 1;
    int numero = 0; // a ser lido do arquivo
    double somaInversos = 0;

    // executar
    while (controle <= x)
    {
        fscanf(entrada, "%d", &numero);

        somaInversos = somaInversos + 1.0 / pow(numero, 2);
        controle++;
    }

    fprintf(saida, "Soma dos inversos das potencias do EX04 = %d", somaInversos);

    fclose(entrada);
    fclose(saida);
    // encerrar
    getchar();
}

void exercicio07()
{
    // definir dados
    int x = 0; // quantidade a ser lida
    printf("Calcular a soma de quantos inversos?(digite algo no maximo da quantidade de termos do EX4) ");
    scanf("%d", &x);

    LerECalcularInversos04("Exercicio4.txt", "resultado07.txt", x);

    printf("Aperte ENTER para sair");
    getchar();
}

void Fibonacci(char *arquivoName, int x) // exercicio08
{
    FILE *arquivo = fopen(arquivoName, "wt");
    int fibonacci[x];
    int i = 0;

    for (i = 1; i <= x; i++)
    {
        if (i == 1)
        {
            fibonacci[i] = 0;
        }
        else if (i == 2)
        {
            fibonacci[i] = 1;
        }
        else
        {
            fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
        }
        fprintf(arquivo, "%d\n", fibonacci[i]);
    }
    fclose(arquivo);
}

void LerFiboPares(char *input, char *output, int y, int x) // exercicio08
{
    FILE *entrada = fopen(input, "rt");
    FILE *saida = fopen(output, "wt");
    int controle = 0;
    int pares[x];
    int i = 0; // posicao
    int z = 0;

    fscanf(entrada, "%d", &pares[i]);

    printf("\nx=%d z=%d\n", x, z);
    fprintf(saida, "Os %d primeiros pares da Fibonacci = \n", y);
    while (controle < x)
    {
        if (pares[i] % 2 == 0)
        {
            fprintf(saida, " %d ", pares[i]);
            fprintf(saida, "\n");
        }

        controle = controle + 1;
        i++;

        fscanf(entrada, "%d", &pares[i]);
    }
    fclose(saida);

} // fim lerFibo

void exercicio08()
{
    // definir dados
    int x = 0; // quantidade de termos da fibonacci
    int y = 0; // quantos termos pares da fibonacci
    // executar
    printf("Quantos termos calcular da fibonacci? ");
    scanf("%d", &x);

    printf("Quantos termos PARES gravar da Fibonacci? ");
    scanf("%d", &y);

    // funcao auxiliar
    Fibonacci("MetodoAuxiliar08.txt", x);
    // funcao para calcular e gravar os pares
    LerFiboPares("MetodoAuxiliar08.txt", "resultados08.txt", y, x);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio08

void contarMinusculas(char *output, char frase[]) // exercicio09
{
    // definir dados
    FILE *saida = fopen(output, "a");
    int tamanho = strlen(frase);
    int minusculas = 0;
    int i = 0;

    // fprintf(saida, "%s\n", frase);

    for (i = 0; i < tamanho; i++)
    {
        if (frase[i] >= 'a' && frase[i] <= 'z')
        {
            minusculas = minusculas + 1;
        }

    } // fim for

    fprintf(saida, "Minusculas em %s = %d \n", frase, minusculas);

    fclose(saida);
} // fim contarMinusculas

void exercicio09()
{
    // definir dados
    int x = 0;
    int controle = 1;
    char frase[80];
    // executar
    printf("Quantas cadeias de caracteres contar? ");
    scanf("%d", &x);
    getchar(); // consumir a linha deixada pelo scanf

    while (controle <= x)
    {
        printf("Entrar com cadeia de char(max 80 carac): ");
        fgets(frase, 80, stdin);

        contarMinusculas("resultado09.txt", frase);
        controle++;
    }
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio09

void contarDigitos(char *output, char caracteres[]) // exercicio10
{
    // definir dados
    FILE *saida = fopen(output, "a");
    int tamanho = strlen(caracteres);
    int digitosTres = 0;

    // executar
    for (int i = 0; i < tamanho; i++)
    {
        // printf("for: %c\n", caracteres[i]);
        if (caracteres[i] >= '0' && caracteres[i] <= '9')
        {
            // printf("1 if: %c\n", caracteres[i]);
            // char numero = caracteres[i];
            if (caracteres[i] >= '3')
            {
                // printf("2 if: %c\n", caracteres[i]);
                digitosTres = digitosTres + 1;
            }
        }
    }
    fprintf(saida, "Na frase: %s ha %d digitos maiores que 3\n", caracteres, digitosTres);
    getchar();
} // fim contarDigitos

void exercicio10()
{
    // definir dados
    char digitos[80];
    int x = 0; // quantas cadeias
    int controle = 1;

    // executar
    printf("Quantas cadeias de caracteres contar os digitos >= 3? ");
    scanf("%d", &x); 
    getchar(); //limpar o buffer

    while (controle <= x)
    {
        printf("Entrar com cadeia de char(max 80 carac): ");
        fgets(digitos, 80, stdin);

        contarDigitos("resultado10.txt", digitos);
        controle++;
    }

    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio10

void gravarDivisores(char *output, int x) // extra01
{
    // definir dados
    FILE *saida = fopen(output, "wt");

    printf("x = %d\n", x);

    // verificar divisores
    fprintf(saida, "divisores de: %d\n", x);
    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            fprintf(saida, "%d\n", i);
        }
    }
    getchar();
} // fim gravarDivisores

void Extra01()
{
    // definir dados
    int n = 0; // numero a ser verificado

    // executar
    printf("Qual numero gravar os seus divisores? ");
    scanf("%d", &n);

    gravarDivisores("resultadoEXTRA01.txt", n);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim Extra01

void lerPalavras(char *input, int x) // Extra02
{
    // definir dados
    FILE *entrada = fopen(input, "rt");
    char palavra[80];
    int controle = 1;
    int contador = 0; // quantidade que comçam com c ou C

    // executar
    while (controle <= x)
    {
        fscanf(entrada, "%s", &palavra);

        if (palavra[0] == 'c' || palavra[0] == 'C')
        {
            contador++;
        }
        controle++;
    }

    printf("\nQuantas palavras comecam com c ou C = %d\n\n", contador);

    fclose(entrada);
    // encerrar
    getchar();
} // fim LerPalavras

void Extra02()
{
    // definir dados
    char palavra[80];
    FILE *Entrada = fopen("palavrasEXTRA02.txt", "wt");
    int x = 0; // quantas palavras guardar
    int controle = 1;

    // executar
    printf("Quantas palavras testar? ");
    scanf("%d", &x);

    while (controle <= x)
    {
        printf("Qual palavra verificar se comeca com c ou C? ");
        scanf("%s", palavra);

        fprintf(Entrada, "%s\n", palavra);
        controle++;
    }
    fclose(Entrada);

    lerPalavras("palavrasEXTRA02.txt", x);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim Extra02

int main()
{
    printf("ED07 - exercicios - Tales Rocha Moreira");

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
        IO_println("11 - extra01");
        IO_println("12 - extra02");

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
            Extra01();
            break;
        case 12:
            Extra02();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}