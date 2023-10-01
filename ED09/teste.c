#include "io.h"
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange
struct limites
{
    int superior;
    int inferior;
    int quantidade;
    int *vetor;
};

void numAleatorios(struct limites dados)
{
    for (int i = 0; i < dados.quantidade; i++)
    {
        dados.vetor[i] = RANDOM(dados.inferior, dados.superior);
    }
}

int main()
{
    struct limites teste;

    printf("Entrar com limite superior do intervalo: ");
    scanf("%d", &teste.superior);
    printf("\nEntrar com limite inferior do intervalo: ");
    scanf("%d", &teste.inferior);

    printf("\nQuantidade de valores: ");
    scanf("%d", &teste.quantidade);
    teste.vetor = (int *)malloc(teste.quantidade * sizeof(int));

    numAleatorios(teste);

    for (int i = 0; i < teste.quantidade; i++)
    {
        printf("%d\n", teste.vetor[i]);
    }

    free(teste.vetor);
    return 0;
}
