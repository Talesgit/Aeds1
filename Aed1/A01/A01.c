/*
A01 - Tales Rocha Moreira - 27/04/2023
*/
#include "io.h"

void exercicio00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

// QUAL DAS SAIDAS ABAIXO SERA UMA IGUALDADE:
// A CORRETA:
void exercicio01()
{
    printf("\n%d = %d", (4 / (2 + 2) / 4), (4 / (2 + 2) / 4));

    printf("Aperte ENTER para sair");
    getchar();
}

// A SAIDA A SER DIFERENTE DAS OUTRAS E 'c = 0'
void exercicio02()
{
    bool a = (int)(3, 14 * 1.0f) / 3;
    char b = (char)(((int)'2' - 1) - 48);
    double c = 4 / 3 + (int)(double)3 / 5;
    int d = (a < 4) && (c <= 2 % 3);

    printf("\n a = %d", a);
    printf("\n b = %d", b);
    printf("\n c = %d", c);
    printf("\n d = %d", d);

    printf("Aperte ENTER para sair");
    getchar();
}

// A SAIDA SERA D = 10
void exercicio03()
{
    int a = 10, b = 20, c = 30, d = 0;

    if (b > a && a > c || b > c && a > b)
    {
        d = c;
    }
    else if (a > b && c > b || b < c && a > b)
    {
        d = b;
    }
    else if (a < b && b > c || a < b && c > b)
    {
        d = a;
    }

    printf("\nd = %d\n", d);
    printf("Aperte ENTER para sair");
    getchar();
}

// A SAIDAS DO CODIGO ABAIXO SAO: 13, 10, 6, 1
void exercicio04()
{
    int x = 0, y = 0, n = 5;
    y = n * (n + 1) / 2;
    for (x = 2; x <= n; x++)
    {
        y = y - x;
        printf(" %d\n", y);
    }

    printf("Aperte ENTER para sair");
    getchar();
}

// QUAL A SAIDA DA FUNCAO ABAIXO : 26
int f1(int x, int y)
{
    int z = 0;
    if (x < 0)
    {
        z = f1(-x, 1);
    }
    else
    {
        if (y <= 1)
        {
            z = f1(x, 2);
        }
        else if (x >= y / 2 && x % y == 0)
        {
            z = y + f1(x, y + 2);
        }
        else if (x >= y / 2)
        {
            z = f1(x, y + 2);
        }
    }
    return (z);
}
void exercicio05() // saida 26
{
    printf("\nf1(18, 1) = %d\n", f1(18, 1));
    printf("Aperte ENTER para sair");
    getchar();
}

// DEFINIR UMA FUNÇÃO INTEIRA PARA CALCULAR O VALOR DE UM NUMERO ELEVADO A UMA POTENCIA INTEIRA
// METODO PARA PROCURAR E MOSTRAR DOIS VALORES INTEIROS CONSECUTIVOS (M E N) MENORES OU IGUAIS A 10
// PARA OS QUAIS HAVERA A RELACAO ABAXO: m^n = n^m

int calcularPotenciaInteira(int base, int expoente)
{
    int potencia = 1;
    for (int i = 1; i <= expoente; i++)
    {
        potencia = potencia * base;
    }
    return (potencia);
}

void mostrarValoresConsecutivosRelacao(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (pow(i, i + 1) == pow(i + 1, i))
        {
            printf("Os valores que sao consecutivos e satisfazem m^n = n^m ate 10 sao: %d e %d\n", i, i + 1);
        } // fim if

    } // fim for'
} // fim funcao

void exercicio06()
{
    int base = 0;
    int expoente = 0;
    printf("Qual a base da potencia? ");
    scanf("%d", &base);

    printf("\nQual o expoente? ");
    scanf("%d", &expoente);

    printf("O resultado da potenciacao e: %d\n", calcularPotenciaInteira(base, expoente));
    mostrarValoresConsecutivosRelacao(10);

    printf("Aperte ENTER para sair");
    getchar();
}

// LER PALAVRAS UMA DE CADA VEZ
// A ULTIMA DEVERA SER 'PARAR' E NAO DEVERAR SER PROCESSADA
// DIZER SE ANTES DE B E P VEM M E NAO N EM CADA PALAVRA

int verificarSintaxe(char palavra[], int tamanho)
{
    bool correto = false;
    for (int i = 0; i < tamanho; i++)
    {

        if (palavra[i] == 'b' || palavra[i] == 'p')
        {
            if (palavra[i - 1] == 'm')
            {
                correto = true;
            }
        }

    } // fim for

    return (correto);

} // fim funcao

void exercicio07()
{
    // definir dados
    char palavra[100];
    int tamanho;

    do
    {
        // printf("\nEntrar com palavra para verificar: ");
        // fgets(palavra, 80, stdin); // melhor usar scanf
        scanf("%s", palavra);

        if (palavra[0] == 'p' || palavra[0] == 'b')
        {
            printf("O p ou b esta  na na primeira posicao\n");
            break;
        }

        tamanho = strlen(palavra);

        printf("0 caso a sintaxe esteja incorreta, e 1 para caso esteja correta: %d\n", verificarSintaxe(palavra, tamanho));

    } while (strcmp(palavra, "PARAR") != 0);

    getchar();
    printf("Aperte ENTER para sair");
    getchar();
}

// CALCULAR A SOMA
// DIZER QUAL DOS TRES VALORES INTEIROS POSSUIRA A MENOR SOMA
double somaFracoes(int quantidade, int denominador)
{
    int numerador = 0;
    double soma = 0;

    for (int i = 1; i <= quantidade; i++)
    {
        numerador = i;
        soma = soma + (numerador / denominador);

        denominador = denominador - 1;
    }
    return (soma);
} // fim somaFracoes

void exercicio08()
{
    // definir dados
    int denominador = 0;
    int quantidade = 0;

    // ler valores
    printf("A partir de qual denominador somar? ");
    scanf("%d", &denominador);

    printf("\nQuantidade de vezes a somar? ");
    scanf("%d", &quantidade);

    printf("\nSoma das fracoes: %lf\n", somaFracoes(quantidade, denominador));
    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim A01

double retornarSoma(int n)
{
    double soma1 = 0;
    double soma2 = 0;
    double soma3 = 0;
    // int valor = n;
    for (int i = 1; i <= n; i++)
    {
        int valor = n - i + 1;
        soma1 = soma1 + (double)i / valor;
        printf("%lf\n", soma1);
    }
    for (int i = n; i >= 1; i--)
    {
        soma2 = soma2 + (double)(n - 1) / i;
    }
    soma3 = soma1 + soma2;
    return (soma3);
}

void questao8()
{
    int n[3];
    double menor = 0;

    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &n[i]);
    }
    menor = retornarSoma(n[0]);

    if (retornarSoma(n[1]) < menor)
    {
        menor = n[1];
    }

    if (retornarSoma(n[2]) < menor)
    {
        menor = n[2];
    }
    printf("O menor das somar e: %lf\n", menor);
}

int main()
{
    printf("A01 - exercicios corrigidos - Tales Rocha Moreira");

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
            questao8();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}