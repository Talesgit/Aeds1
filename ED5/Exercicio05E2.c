/*
EXERCICIO EXTRA 02, ED05
TALES ROCHA MOREIRA
*/
#include <stdio.h>

void denominadorFatorial(int x, int contador, int multiplicacao) //função construtora
{
    int numerador = 0; //numerador + 1
    int DenF = 0; //fatorial do denominador
    int divisao = 0;

    if (contador < x)
    {
         DenF = x * (x - contador);
         numerador = contador + 1;
         printf("%d / %d\n",numerador, DenF );
         divisao = (numerador / DenF);
         multiplicacao = multiplicacao * divisao;
         printf("\nmultiplicacao: ", multiplicacao);
         denominadorFatorial(x, contador + 1, multiplicacao);
    }
}

int main() //função chamadora??
{
    //identificar
    printf("\nExercicio EXTRA ED5 - Tales Rocha Moreira\n");
   //definir dado
   int x = 0;
   //executar
   printf("Entrar com o numero a ser calculado o fatorial no denominador: ");
   scanf("%d", &x);

   denominadorFatorial(x, 1, 1); //chamar a função anterior
}