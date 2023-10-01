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
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main ( int argc, char* argv [ ] )
{
// definir dado
int x = 0;
int y = 0;
int z = 0;

// identificar
printf ( "%s\n", "Exemplo0101 - Programa = v0.0" );
printf ( "%s\n", "Autor: Tales Rocha Moreira" );
printf ( "\n" ); // mudar de linha
// mostrar valor inicial
printf ( "%s%d\n" , "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
printf ( "&%s%p\n", "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
printf ( "Comprimento paralelepipedo: " );
scanf ( "%d", &x );
printf ( "largura: ");
scanf ( "%d", &y );
printf ( "altura: ");
scanf ( "%d", &z );

// OBS.: Necessario indicar o endereco -> &
getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
int area_da_base = x * y;
printf ( "%s%i\n", "area da base = ", area_da_base );
int volume = area_da_base * z;
printf ( "%s%i\n", "volume do paralelepipedo = ", volume);
//printf ( "%s%i\n", "volume do paralelepipedo = ", volume );
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