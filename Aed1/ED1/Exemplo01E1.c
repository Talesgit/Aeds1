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
#include <stdio.h>
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
float area = 0; // definir variavel com valor inicial
// identificar
printf ( "%s\n", "Exemplo0101 - Programa = v0.0" );
printf ( "%s\n", "Autor: Tales Rocha Moreira" );
printf ( "\n" ); // mudar de linha

// ler do teclado
printf ( "area: " );
scanf ( "%f", &area );
// OBS.: Necessario indicar o endereco -> &
getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
float a = 1/4*area;
float b = a/3.14;
float diametro = sqrt(b) * 2;
float raio = diametro/2;
printf ( "%s%f\n", "d = ", a );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
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
*/