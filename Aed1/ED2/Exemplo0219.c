/*
Exemplo0219 - v0.0. - __ / __ / _____
Author: Tales Rocha Moreira
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0201 exemplo0201.c
Windows: gcc -o exemplo0201 exemplo0201.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0216
Windows: exemplo0216
*/
// dependencias
#include "io.h" // para definicoes proprias
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    int y = 0;
    int z = 0;
    // identificar
    IO_id("EXEMPLO0219 - Programa - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com um primeiro valor : ");
    y = IO_readint("Entrar com o segundo valor : ");
    z = IO_readint("Entrar com um terceiro valor : ");

    if (y > z)
    {
        if (x < y && x > z)
        {
            printf("O numero esta no intervalo");
        }
        else
        {
            printf("O numero nao esta no intervalo");
        }
    }
    else
    {
        if (y < z)
        {
            if (x > y && x < z)
            {
                printf("O numero esta no intervalo");
            }
            else
            {
                printf("O numero nao esta no intervalo");
            }
        }
    }

    /*char maior;
    char menor;

    if (x > y && x > z)
    {
        maior = 'x';
        if (y < z)
        {
            menor = 'y';
        }
        else
        {
            menor = 'z';
        }
    }
    else if (y > x && y > z)
    {
        maior = 'y';
        if (x < z)
        {
            menor = 'x';
        }
        else
        {
            menor = 'z';
        }
    }
    else if (z > x && z > y)
    {
        maior = 'z';
        if (x < y)
        {
            menor = 'x';
        }
        else
        {
            menor = 'y';
        }
    }

    if (maior == 'x')
    {
        printf("Fora");
    }
    else if (maior == 'y')
    {
        if (menor == 'z')
        {
            printf("Dentro");
        }
        else
        {
           printf("Fora") ;// z é o menor
        }
    }
    else if (maior == 'z')
    {
        if (menor == 'x'){
            printf("Fora");
        } else {
            printf("Dentro");
        }
    }
    else
    {
        // Maior é o y
        if(menor == 'x'){
            printf("Fora");
        } else {
            printf("Dentro");
        }
    }*/
}

// testar valor
/*if ( x == 0 )
{
IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
}
if ( x != 0 )
{
IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
} // fim se
// encerrar*/
// IO_pause("Apertar ENTER para terminar");
// return (0);
//  fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 5
c.) -5
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/