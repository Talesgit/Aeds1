/*
   Algoritmos e estruturas de dados - ED06 - Exercicios06
   Autor: Tales Rocha Moreira - Data: 21/04/2023
*/

#include "io.h"

void Exercicio00()
{
}

void mostrarParesPartir6(int x) // exercicio01, recursividade para mostrar pares a partir de 6
{
    if (x >= 1)
    {
        printf("Valor = %d\n", (2 * (x - 1) + 6));
        mostrarParesPartir6(x - 1); // motor
    }

} // fim mostrarPares

void Exercicio01()
{
    // definir dado
    int x = 0; // ler do teclado

    printf("Quantos numeros mostrar: ");
    scanf("%d", &x);

    mostrarParesPartir6(x);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

void mostrarMultiplos6Decrescente(int x) // exercicio02
{
    if (x >= 1)
    {
        mostrarMultiplos6Decrescente(x - 1);
        printf("Valor = %d\n", x * 6);
    }
}

void Exercicio02()
{
    int x = 0; // ler do teclado
    // executar
    printf("Quntos numeros mostrar: ");
    scanf("%d", &x);

    mostrarMultiplos6Decrescente(x);

    // encerrar
    printf("\n\nAperte ENTER para sair");
    getchar();
}

void sequencia6em6(int x) // exercicio03
{
    if (x - 1 >= 1)
    {
        sequencia6em6(x - 1);
        printf("Valor = %d\n", x * 6);
    }
    else
    {
        printf("Valor = %d\n", 1);
    }
}

void Exercicio03()
{
    int x = 0;

    // executar
    printf("Quantos numeros mostrar: ");
    scanf("%d", &x);

    sequencia6em6(x);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

void mostrarDenominadoresMultiplosDecre(int x) // exercicio04
{
    if (x >= 1)
    {
        printf("1 / %d\n", x * 6);
        mostrarDenominadoresMultiplosDecre(x - 1);
    }
    else
    {
        printf("%d", 1);
    }
}

void Exercicio04()
{
    int x = 0;
    // executar
    printf("Quantos valores mostrar: ");
    scanf("%d", &x);

    mostrarDenominadoresMultiplosDecre(x);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

void somaParesPositivos6(int x, int soma) // exercicio05
{
    if (x >= 1)
    {
        somaParesPositivos6(x - 1, soma + (x * 6)); // atribuir o resultado da soma atual da recursão na proxima chamada da função para ir somando sucessivamente
        printf("%d + ", x * 6);
    }
    else
    {
        printf("\nSoma = %d", soma);
        printf("\n");
    }
}

void Exercicio05()
{
    int x = 0;
    // executar
    printf("Quantos valores somar: ");
    scanf("%d", &x);

    somaParesPositivos6(x, 0);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

void calcularSomaInversosPares6(double x, double soma) // exercicio06
{
    double numerador = 1;

    if (x > 1)
    {
        printf("%1.0lf / %1.0lf\n \nDivisao = %lf\n\n", numerador, x * 6, numerador / (x * 6));
        calcularSomaInversosPares6(x - 1, soma + (numerador / (x * 6)));
    }
    else
    {
        printf("\nSoma das divisoes = %lf", soma);
        printf("\n");
    }
}

void Exercicio06()
{
    double x = 0;

    // executar
    printf("Entrar com a quantidade de denominadores: ");
    scanf("%lf", &x);

    calcularSomaInversosPares6(x, 0);

    // encerrar
    printf("\n\nAperte ENTER para sair");
    getchar();
} // fim exercicio06

void mostrarCaracteresUmPorLinha(char palavra[], int controle) // exercicio07
{
    int tamanho = strlen(palavra);

    if (controle < tamanho)
    {
        char simbolo = palavra[controle];
        printf("%c\n", simbolo);
        mostrarCaracteresUmPorLinha(palavra, controle + 1);
    }

    /*for (int i = 0; i <= tamanho; i++)
    {
        char simbolo = palavra[i]; //atribuir cada simbolo isolado a uma variavel
        printf("%c\n", simbolo);
    }*/
}

void Exercicio07()
{
    char palavra[100];
    // executar
    printf("Entrar um uma palavra: ");
    fgets(palavra, 100, stdin);

    mostrarCaracteresUmPorLinha(palavra, 0);

    printf("\n\nAperte ENTER para sair");
    getchar();
} // fim exercicio07

void contarImpares(char palavra[], int controle, int impares) // exercicio08
{
    int tamanho = strlen(palavra);
    if (controle < tamanho)
    {
        char caractere = palavra[controle];
        if (caractere >= '0' && caractere <= '9')
        {
            if (caractere % 2 != 0)
            {
                impares++;
                printf(" %d ", impares);
            }
        }
        contarImpares(palavra, controle + 1, impares);
    }
} // fim contar impares

void Exercicio08()
{
    char palavra[100];
    // executar
    printf("Entrar com uma palavra para contar numeros impares: ");
    scanf("%s", &palavra);

    printf("Numero de impares: ");
    contarImpares(palavra, 0, 0);

    printf("\n\nAperte ENTER para sair");
    getchar();
} // fim exercicio08

void CalcularMaiusculas(char palavra[], int controle, int maiusculas) // exercicio09
{
    int tamanho = strlen(palavra);
    if (controle < tamanho)
    {
        char caractere = palavra[controle]; // isolar cada caractere da palavra, controle ira percorrer cada caractere + 1
        if (caractere >= 'A' && caractere <= 'Z')
        {
            maiusculas++;
            printf(" %d ", maiusculas);
        }
        CalcularMaiusculas(palavra, controle + 1, maiusculas);
    } // fim if
} // fim calcularMaiusculas

void Exercicio09()
{
    char palavra[100];
    int maiusculas = 0;
    // executar
    printf("Entrar com uma palavra para mostrar maiusculas: ");
    fgets(palavra, 100, stdin);

    printf("Maiusculas = ");
    CalcularMaiusculas(palavra, 0, maiusculas);

    printf("\n\nAperte ENTER para sair");
    getchar();
} // fim exercicio09

int seqFinonacci(int x[], int tamanho, int controle) // exercicio10 *TAMANHO = X, POIS É O NUMERO DE ELEMENTOS DENTRO DO VETOR X*
// CONTROLE DE 2 EM 2, começa com 2 pois os dois primeiros elementos já estão definidos
{
    while (controle < tamanho)
    {
        x[controle] = x[controle - 1] + x[controle - 2];
        controle++;
    }
    return(x);
} // fim seqFibonacci

int mostrarPrimeirosPares(int n, int Fibo[]) // exercicio10
{
    int controle = 1;
    for (int i = 0; i < n; i++)
    {
         int EPar = Fibo[i];

        if (EPar % 2 == 0)
        {
            printf(" %d ", EPar);
        }
    }
}

void Exercicio10()
{
    int x = 0;
    int n = 0;
    // executar
    printf("Entrar quantidade de valores a serem mostrados da fibonacci: ");
    scanf("%d", &x);

    /*printf("Quantos pares mostrar dessa sequencia? ");
    scanf("%d", &n);*/

    int vetor[x];
    vetor[0] = 0;
    vetor[1] = 1;
 
    seqFinonacci(vetor, x, 2); //tentei 
    mostrarPrimeirosPares(x, vetor);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

void somarFraFatoriais(int x, int controle)
{
   while(controle < x)
   {
   int numerador = 1 + 2;
   int denominador = 2;
   for(int i = 1; i < x; i++)
  {
      denominador = denominador * i;
      printf("%d / %d\n ", numerador, denominador);
  }
   controle++;
   }
}
void ExercicioE2()
{
 int x = 0;
 int controle = 1;
 printf("quantos numeros no denominador: ");
 scanf("%d", &x);
 somarFraFatoriais(x, controle);
}

int main()
{
    int x = 0;

    do
    {
        IO_id("\nExercicios06 - ED06 - Tales Rocha Moreira");

        IO_println(" 0 - Sair");
        IO_println(" 1 - Exercicio01");
        IO_println(" 2 - Exercicio02");
        IO_println(" 3 - Exercicio03");
        IO_println(" 4 - Exercicio04");
        IO_println(" 5 - Exercicio05");
        IO_println(" 6 - Exercicio06");
        IO_println(" 7 - Exercicio07");
        IO_println(" 8 - Exercicio08");
        IO_println(" 9 - Exercicio09");
        IO_println("10 - Exercicio10");
        IO_println("11 - ExercicioExtra2");

        x = IO_readint("Entrar com uma opcao: ");
        printf("\n");

        switch (x)
        {
        case 1:
            Exercicio01();
            break;
        case 2:
            Exercicio02();
            break;
        case 3:
            Exercicio03();
            break;
        case 4:
            Exercicio04();
            break;
        case 5:
            Exercicio05();
            break;
        case 6:
            Exercicio06();
            break;
        case 7:
            Exercicio07();
            break;
        case 8:
            Exercicio08();
            break;
        case 9:
            Exercicio09();
            break;
        case 10:
            Exercicio10();
            break;
        case 11:
            ExercicioE2();
            break;
        default:
            IO_println("ERRO: Valor invalido.");

        } // fim switch
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}