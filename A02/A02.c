/*
A02 - Tales Rocha Moreira - 05/06/2023
*/
#include "io.h"
#include <stdio.h>

void questao00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

// questao01

void q01(int a[], int n, int x, int y)
{
    int z = 0;
    if (x < y)
    {
        a[x] = a[x] + a[y];
        a[y] = a[x] - a[y];
        a[x] = a[x] - a[y];
        q01(a, n, x + 1, y - 1);
    }
}

void questao01()
{
    int n = 7;
    int a[] = {2, 4, 6, 7, 5, 3, 1};
    q01(a, n, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }

    // encerrar
    printf("Apertar ENTER para continuar");
    getchar();
} // fim questao01 ( )

// questao02.

void questao02()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void questao03()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void questao04()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void questao05()
{
    printf("Aperte ENTER para sair");
    getchar();
}

// questao06

void centralizar(char *s, int n)
{
    int k = 0;
    int tamanho = strlen(s);
    int lim = (n - tamanho) / 2;

    if (n > 0)
    {
        char palavra2[n];

        for (int i = 0; i < lim; i++)
        {
            palavra2[k++] = '-';
        }

        for (int i = 0; i < tamanho; i++)
        {
            palavra2[k++] = s[i];
        }

        for (int i = 0; i < lim; i++)
        {
            palavra2[k++] = '-';
        }
        printf("%s\n", palavra2);
    }

    getchar();
}

void questao06()
{
    char cadeia[100];
    scanf("%s", cadeia);

    int n = 0;
    scanf("%d", &n);

    int tamanho = strlen(cadeia);
    if (n > tamanho)
    {
        centralizar(cadeia, n);
    }

    printf("Aperte ENTER para sair");
    getchar();
}

// questao07

void arranjoMaior(int rc, int matriz[][rc])
{
    int arranjo[rc];
    int maior = matriz[0][0];
    int col = 0;

    for (int j = 0; j < rc; j++)
    {
        for (int i = 0; i < rc; i++)
        {
            if (maior < matriz[j][i])
            {
                maior = matriz[j][i];
                col = i;
            }
        }
    }

    printf("maior: %d, col: %d\n", maior, col);

    for (int j = 0; j < rc; j++)
    {
        arranjo[j] = matriz[j][col];
    }

    for (int i = 0; i < rc; i++)
    {
        printf(" %d ", arranjo[i]);
    }
    getchar();
}

void questao07()
{
    int rc = 0;

    printf("linhas e colunas da matriz quadrada: ");
    scanf("%d", &rc);

    int matriz[rc][rc];
    for (int j = 0; j < rc; j++)
    {
        for (int i = 0; i < rc; i++)
        {
            scanf("%d", &matriz[j][i]);
        }
    }

    arranjoMaior(rc, matriz);

    printf("\nAperte ENTER para sair");
    getchar();
}

// questao08

void verificarArq(char *arquivo)
{
   int x = 0;
   int count = 0;
   FILE *arq = fopen(arquivo, "rt");
   FILE *out = fopen("resultados.txt", "wt");

   while(!feof (arq) && fscanf(arq, "%d", &x) == 1)
   {
    if(x >= 30001 && x <= 39991 && count < 7)
    {
        fprintf(out, "%d\n", x);
        count++;
    }
   }
   fclose(arq);
   fclose(out);
}

void questao08()
{
    verificarArq("dados.txt");

    printf("Aperte ENTER para sair");
    getchar();
}

int main()
{
    printf("A02 - questoes - Tales Rocha Moreira");

    int x = 0;

    do
    {
        IO_println(" 0 - questao00(SAIR)");
        IO_println(" 1 - questao01");
        IO_println(" 2 - questao02");
        IO_println(" 3 - questao03");
        IO_println(" 4 - questao04");
        IO_println(" 5 - questao05");
        IO_println(" 6 - questao06");
        IO_println(" 7 - questao07");
        IO_println(" 8 - questao08");

        x = IO_readint("Entrar com a opcao: ");
        printf("\n");

        switch (x)
        {
        case 1:
            questao01();
            break;
        case 2:
            questao02();
            break;
        case 3:
            questao03();
            break;
        case 4:
            questao04();
            break;
        case 5:
            questao05();
            break;
        case 6:
            questao06();
            break;
        case 7:
            questao07();
            break;
        case 8:
            questao08();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}