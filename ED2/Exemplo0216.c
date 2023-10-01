/*
Exemplo0216 - v0.0. - __ / __ / _____
Author: ________________________
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
int main ( )
{
// definir dado
int x = 0; // definir variavel com valor inicial
int y = 0;
// identificar
IO_id ( "EXEMPLO0216 - Programa - v0.0" );
// ler do teclado
x = IO_readint ( "Entrar com um valor inteiro: " );
y = IO_readint ( "Entrar com o segundo valor : ");

if ( x % 2 == 0 )
{
  printf("O primeiro numero e par\n"); 
}
else
{
    printf("O primeiro numero nao e par\n");
}

if ( y % 2 == 1)
{
    printf("O segundo valor e impar\n");
}
else
{
    printf("O segundo valor nao e impar\n");
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
IO_pause ( "Apertar ENTER para terminar" );
return ( 0 );
} // fim main( )
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