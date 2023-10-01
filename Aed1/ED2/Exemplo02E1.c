/*
Exemplo02E1 - v0.0. - __ / __ / _____
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
    char a;
    char b;
    char c;
    // identificar
    IO_id("EXEMPLO02E1 - Programa - v0.0");
    // ler do teclado
    a = IO_readchar("Entrar com um primeiro valor : ");
    b = IO_readchar("Entrar com o segundo valor : ");
    c = IO_readchar("Entrar com um terceiro valor : ");

    if (b > c)
    {
        if (a < b && a > c)
        {
            printf("O caractere esta no intervalo");
        }
        else
        {
            printf("O caractere nao esta no intervalo");
        }
    }
    else
    {
        if (b < c)
        {
            if (a > b && a < c)
            {
                printf("O caractere esta no intervalo");
            }
            else
            {
                printf("O caractere nao esta no intervalo");
            }
        }
    }
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