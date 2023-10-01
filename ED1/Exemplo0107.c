/*
Exemplo0107 - v0.0. - __ / __ / _____
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
// definir dados
double x = 0.0; //definir variavel com valor inicial
double y = 0.0;
double z = 0.0;


// identificar
printf ( "%s\n", "Exemplo0107 - Programa = v0.0" );
printf ( "%s\n", "Autor: Tales Rocha Moreira" );
printf ( "\n" ); // mudar de linha
// mostrar valores iniciais
printf ( "%s%lf\n" , "x = ", x );
printf("%s%lf\n", "y =", y);
// OBS.: O formato para int -> %d (ou %i)
printf ( "&%s%p\n", "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
printf ( "Entrar com um valor real: " );
scanf ( "%lf", &x );
getchar();
printf ("Entrar com outro valor real: ");
scanf ("%lf", &y);
// OBS.: Necessario indicar o endereco -> &
getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
printf ( "%s%s\n", "x = ", x );
// mostrar valor resultante
printf ( "%s(%i)*(%i) = (%d)\n", "z = ", x, y, z );
// encerrar
printf ( "\n\nApertar ENTER para terminar." );
getchar( ); // aguardar por ENTER
// operar valores
z = pow( x, y ); // elevar a base (x) 'a potencia (y)
// mostrar valor resultante
printf ( "%s(%lf) elevado a (%lf) = (%lf)\n", "z = ", x, y, z );
// operar valores
x = pow( z, 1.0/y ); // elevar a base (x) 'a potencia inversa de (y) (raiz)
// mostrar valor resultante
printf ( "%s(%lf) elevado a (1/%lf) = (%lf)\n", "z = ", z, y, x );
// operar valores
z = sqrt( x ); // raiz quadrada do argumento
// mostrar valor resultante
printf ( "%sraiz(%lf) = (%lf)\n", "z = ", x, z );
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