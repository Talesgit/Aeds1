/*
EXERCICIO EXTRA 1 ED5
TALES ROCHA MOREIRA
AED1
*/
#include <stdio.h>
#include <math.h>

void fatorial(int x, int contador)
{
    int xF = 0;
    printf("Fatorial de %d: ", x);
    if (contador < x)
    {
       xF = x * (x - contador);
       printf("%d\n", xF);
       fatorial(x, contador + 1);
    }
}

int main()
{
    //identidicar
    printf("\nExercicio Extra 1, ED05\nAutor: Tales Rocha Moreira\n");
    //definir dado
    int x = 0;
    //executar
    printf("\nQual numero calcular a fatorial: ");
    scanf("%d", &x);
    //chamar a função
    fatorial(x, 1);
}
