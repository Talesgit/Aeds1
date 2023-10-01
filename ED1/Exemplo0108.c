/*
Exemplo0108 - v0.0. - __ / __ / _____
Author: Tales Rocha Moreira
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0101 exemplo0101.c
Windows: gcc -o exemplo0101 exemplo0101.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0104
Windows: exemplo0104
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdbool.h> 
#include <string.h>
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
char x [80] = "abc"; //definir variavel com tamanho e valor inicial
char y [80] = "def"; 
char z [80]; 
strcpy ( z, "" );   // e copiar para (z) a representacao de vazio
// identificar
printf ( "%s\n", "Exemplo0108 - Programa = v0.0" );
printf ( "%s\n", "Autor: Tales Rocha Moreira" );
printf ( "\n" ); // mudar de linha
// mostrar valores iniciais e comprimento de cadeias
printf ( "%s%s (%d)\n", "x = ", x, strlen( x) );
printf ( "%s%s (%d)\n", "y = ", y, strlen( y) );
// OBS.: O formato para int -> %d (ou %i)
// ler do teclado
printf ( "Entrar com caracteres: " );
scanf ( "%s", x );
// OBS.: Necessario indicar o endereco -> &
getchar ( );
printf ( "%s%s (%d)\n", "x = ", x, strlen( x) );
printf ( "%s%s (%d)\n", "y = ", y, strlen( y) );
// OBS.: O formato para int -> %d (ou %i) // OBS.: Limpar a entrada de dados

getchar( ); // aguardar por ENTER

// operar valores
strcpy ( z, x ); // copiar (x) para (z)
strcat ( z, y ); // concatenar (juntar) (y) a (z)
// OBS.: Forma mais eficiente
// mostrar valor resultante
printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );
// operar valores (forma alternativa)
strcpy ( z, strcat ( strdup(x), y ) );
// copiar para (z)
// o resultado de concatenar
// a copia de (x) com (y)
// OBS.: Se nao duplicar, o valor (x) sera' alterado.
// mostrar valor resultante
printf ( "%s[%s]*[%s] = [%s]\n", "z = ", x, y, z );
// encerrar
printf ( "\n\nApertar ENTER para terminar.\n" );
getchar( ); // aguardar por ENTER




return ( 0 ); // voltar ao SO (sem erros)
} // fim main( )
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 5
b.) -5
c.) 123456789
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste 
0.1 01. ( ___ ) identificacao de programa
                leitura e exibicao de inteiro
0.2 01.(OK)   
*/