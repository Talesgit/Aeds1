/*
Exemplo0101 - v0.0. - __ / __ / _____
Author: ________________________
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0101 exemplo0101.c
Windows: gcc -o exemplo0101 exemplo0101.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0101
Windows: exemplo0101
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <math.h>
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
float x;
x = 0.0; // definir variavel com valor inicial
// identificar
printf ( "%s\n", "Exemplo0101 - Programa = v0.0" );
printf ( "%s\n", "Autor: Tales Rocha Moreira" );
printf ( "\n" ); // mudar de linha
// mostrar valor inicial
printf ( "%s%f\n" , "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
printf ( "&%s%f\n", "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
printf ( "Lado do triangulo: " );
scanf ( "%f", &x );
// OBS.: Necessario indicar o endereco -> &
getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
printf ( "%s%f\n", "Altura do triangulo = ", x * sqrt(3)/2);
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
getchar( ); // aguardar por ENTER
return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( ___ ) identificacao de programa
leitura e exibicao de inteiro
*/