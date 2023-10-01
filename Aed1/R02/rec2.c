/*
REC02 - Tales Rocha Moreira
*/
#include "io.h"

void exemplo00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

struct arranjo
{
    int *vetor;
    int quantidade;
    FILE *arquivo;
};

void swap(int *a, int *b)
{
    int copy = *a;
    *a = *b;
    *b = copy;
}

void isDecrec(char *nome)
{
    bool decrec = false;
    struct arranjo ex1;
    int countDecrec = 1;

    FILE *arquivo = fopen(nome, "rt");

    fscanf(arquivo, "%d", &ex1.quantidade);

    ex1.vetor = (int *)malloc(ex1.quantidade * sizeof(int));
    for (int i = 0; i < ex1.quantidade; i++)
    {
        fscanf(arquivo, "%d", &ex1.vetor[i]);
    }
    fclose(arquivo);

    for (int i = 1; i < ex1.quantidade; i++)
    {
        if (ex1.vetor[i] < ex1.vetor[i - 1])
        {
            countDecrec++;
        }
    }

    if (countDecrec == ex1.quantidade)
    {
        decrec = true;
    }

    if (!decrec)
    {
        for (int i = 1; i < ex1.quantidade; i++)
        {
            for (int j = 1; j < ex1.quantidade; j++)
            {
                if (ex1.vetor[j] > ex1.vetor[j - 1])
                {
                    swap(ex1.vetor[j], ex1.vetor[j - 1]);
                } // fim if
            }
        } // fim for
    }

    FILE *arq = fopen("decrescente.txt", "wt");
    fprintf(arq, "%d\n", ex1.quantidade);
    for (int i = 0; i < ex1.quantidade; i++)
    {
        fprintf(arq, "%d\n", ex1.vetor[i]);
    }
    fclose(arq);
}

void exemplo01()
{
    isDecrec("dados1.txt");
    printf("Aperte ENTER para sair");
    getchar();
}

void invertArray(int vector[])
{
    struct arranjo ex2;
    ex2.arquivo = fopen("decrescente.txt", "rt");

    fscanf(ex2.arquivo, "%d", &ex2.quantidade);

    for (int j = 1; j < ex2.quantidade; j++)
    {

        for (int i = 1; i < ex2.quantidade; i++)
        {
            if (vector[i] < vector[i - 1])
            {
                // swap(&vector[i], &vector[i-1]);
                int temp = vector[i];
                vector[i] = vector[i - 1];
                vector[i - 1] = temp;
            }
        }
    }

    for (int i = 0; i < ex2.quantidade; i++)
    {
        printf("%d\n", vector[i]);
    }

    ex2.arquivo = fopen("invertidos.txt", "wt");
    fprintf(ex2.arquivo, "%d\n", ex2.quantidade);

    for (int i = 0; i < ex2.quantidade; i++)
    {
        fprintf(ex2.arquivo, "%d\n", vector[i]);
    }
    fclose(ex2.arquivo);
}

void exemplo02()
{
    struct arranjo ex2;

    int x = 0;
    ex2.arquivo = fopen("decrescente.txt", "rt");

    fscanf(ex2.arquivo, "%d", &ex2.quantidade);
    ex2.vetor = (int *)malloc(ex2.quantidade * sizeof(int));

    while (x < ex2.quantidade)
    {
        fscanf(ex2.arquivo, "%d", &ex2.vetor[x]);
        x++;
    }
    fclose(ex2.arquivo);

    invertArray(ex2.vetor);

    printf("Aperte ENTER para sair");
    getchar();
}

void verifyValue(int array[], int n, int quantidade)
{
    int maior = array[1];
    int maior2 = 0;
    int secMaior = 0;

    for (int i = 1; i < quantidade; i++)
    {
        if (maior < array[i - 1])
        {
            maior = array[i - 1];
            if (maior < n)
            {
                secMaior = maior2;
                maior2 = maior;
            }
            if (array[i - 1] > secMaior && array[i - 1] < maior2)
            {
                secMaior = array[i - 1]; // Atualiza o segundo maior se o valor estiver entre o atual segundo maior e o maior
            }

        } // end if
    }     // end for

    printf("maior valor: %d\n", maior2);
    printf("segundo maior valor: %d\n", secMaior);
}

void exemplo03()
{
    int quantidade = 0;
    int numero = 0;
    FILE *arquivo = fopen("dados1.txt", "rt");
    fscanf(arquivo, "%d", &quantidade);
    int array[quantidade];

    int control = 0;
    while (control < quantidade)
    {
        fscanf(arquivo, "%d", &array[control]);
        control++;
    }

    printf("Qual numero verificar(max ate 9): ");
    scanf("%d", &numero);

    verifyValue(array, numero, quantidade);
    printf("Aperte ENTER para sair");
    getchar();
}

void mostrarIdenticos(int quantidade, int array[quantidade], int array2[quantidade])
{
    int counter = 0;
    FILE *arquivo = fopen("filtrados.txt", "wt");
    bool valoresAlready[quantidade];

    for (int i = 0; i < quantidade; i++)
    {
        valoresAlready[i] = false;
    }

    for (int i = 0; i < quantidade; i++)
    {
        for (int j = 0; j < quantidade; j++)
        {

            if (array[i] == array2[j] && !valoresAlready[i] && !valoresAlready[j])
            {
                counter++;
                valoresAlready[i] = true;
                valoresAlready[j] = true;
            }
        }
    }

    fprintf(arquivo, "%d\n", counter);
    counter = 0;

    for (int i = 0; i < quantidade; i++)
    {
        valoresAlready[i] = false;
    }

    for (int i = 0; i < quantidade; i++)
    {
        for (int j = 0; j < quantidade; j++)
        {
            if (array[i] == array2[j] && !valoresAlready[i] && !valoresAlready[j])
            {
                fprintf(arquivo, "%d\n", array[i]);
                valoresAlready[i] = true;
                valoresAlready[j] = true;
            }
        }
    }

    fclose(arquivo);
}

void exemplo04()
{
    int quantidade = 0;
    int quantidade2 = 0;

    FILE *arquivo = fopen("dados1.txt", "rt");
    fscanf(arquivo, "%d", &quantidade);
    int *array = malloc(quantidade * sizeof(int));
    int controle = 0;

    while (controle < quantidade)
    {
        fscanf(arquivo, "%d", &array[controle]);
        controle++;
    }
    controle = 0;
    fclose(arquivo);

    arquivo = fopen("dados2.txt", "rt");
    fscanf(arquivo, "%d", &quantidade2);
    int *array2 = malloc(quantidade2 * sizeof(int));

    while (controle < quantidade2)
    {
        fscanf(arquivo, "%d", &array2[controle]);
        controle++;
    }
    fclose(arquivo);

    mostrarIdenticos(quantidade2, array, array2);

    free(array);
    free(array2);

    printf("Aperte ENTER para sair");
    getchar();
}

int arranjo_paraDecimal(int arranjo[], int tamanho)
{
    int decimal = 0;
    int potencia = 1;

    for (int i = tamanho - 1; i >= 0; i--)
    {
        decimal += arranjo[i] * potencia;
        potencia *= 2;
    }

    return decimal;
}

void exemplo05()
{
    FILE *arquivo = fopen("binarios1.txt", "rt");

    char linha[100];
    if (fgets(linha, sizeof(linha), arquivo) == NULL)
    {
        printf("Erro ao ler a linha do arquivo.\n");
        fclose(arquivo);
    }

    int tamanho = strlen(linha);
    int arranjo[tamanho];
    int contador = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (linha[i] == '0' || linha[i] == '1')
        {
            arranjo[contador] = linha[i] - '0';
            contador++;
        }
    }

    int decimal = arranjo_paraDecimal(arranjo, contador);

    printf("Valor decimal: %d\n", decimal);

    fclose(arquivo);

    printf("Aperte ENTER para sair");
    getchar();
}

void gerarMatrizTridiagonal(int n)
{
    int matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 0;
        }
    }

    int valor = 1;
    for (int i = 0; i < n; i++)
    {
        matriz[i][i] = valor++;
        if (i < n - 1)
        {
            matriz[i + 1][i] = valor++;
            matriz[i][i + 1] = valor++;
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    FILE *arquivo = fopen("matriz2.txt", "wt");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

void exemplo06()
{
    int n;
    FILE *arquivo = fopen("matriz1.txt", "rt");

    fscanf(arquivo, "%d", &n);
    fclose(arquivo);

    fclose(arquivo);

    gerarMatrizTridiagonal(n);

    printf("Aperte ENTER para sair");
    getchar();
}


void gerarMatrizTridiagonalDecrec(int n)
{
    int matriz[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = 0;
        }
    }

   // Preenche os elementos tridiagonais com valores decrescentes
    int valor = n * n;
    for (int i = 0; i < n; i++) {
        matriz[i][i] = valor--;
        if (i < n - 1) {
            matriz[i + 1][i] = valor--;
            matriz[i][i + 1] = valor--;
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    FILE *arquivo = fopen("matriz4.txt", "wt");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fprintf(arquivo, "%d ", matriz[i][j]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}


void exemplo07() 
{
    int n;
    FILE *arquivo = fopen("matriz1.txt", "rt");

    fscanf(arquivo, "%d", &n);
    fclose(arquivo);

    fclose(arquivo);

    gerarMatrizTridiagonalDecrec(n);

    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo08()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo09()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo10()
{
    printf("Aperte ENTER para sair");
    getchar();
}

int main()
{
    printf("REC02 - Tales Rocha Moreira");

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