/*Exemplo0301-v0.0-01/04/2022
Autor-Tales Rocha Moreira
*/
// bibliotecas
#include "io.h"
/*Metodo00-nao faz nada*/
void exemplo00()
{
    // nenhuma ação
} // fim metodo00

void exemplo01() // Repetição com teste no início
{

    IO_id("Exemplo0301-Metodo01-v0.0"); // identificação

    int x = 0;
    x = IO_readint("Entrar com uma quantidade: ");

    while (x > 0) // repetir x vezes
    {
        // mostrar valor atual
        IO_printf("%d\n", x); // FOI APENAS UM TESTE SUBSTITUIR PELO PRINTF
        // passar -1 valor
        x--;
    }
    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // fim metodo01

void exemplo02()
{
    // definir dado
    int x = 0;
    int y = 0;
    // identificar
    IO_id("EXEMPLO0302 - Method02 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    y = x; // copiar o valor lido (e' melhor)
    while (y > 0)
    {
        // mostrar valor atual
        IO_println(IO_toString_d(x));
        // passar ao proximo valor
        y = y - 1;
    } // fim repetir
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim exemplo02 ( )

void exemplo03()
{
    // definir dado
    int x = 0;
    int y = 0;
    // identificar
    IO_id("EXEMPLO0303 - Method03 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    y = 1; // o valor lido devera' ser preservado
    while (y <= x)
    {
        // mostrar valor atual
        IO_printf("%d\n", y);
        // passar ao proximo valor
        y = y + 1;
    } // fim repetir
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

void exemplo04()
{
    // definir dado
    int x = 0;
    int y = 0;
    int z = 0;
    // identificar
    IO_id("EXEMPLO0304 - Method04 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    // inicio teste variacao
    for (y = 1; y <= x; y = y + 1)
    {
        // ler valor do teclado
        z = IO_readint("Valor = ");
        // mostrar valor atual
        IO_printf("%d. %d\n", y, z);
    } // fim repetir
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim exemplo04 ( )

void exemplo05()
{
    // definir dado
    int x = 0;
    int y = 0;
    int z = 0;
    // identificar
    IO_id("EXEMPLO0305 - Method05 - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com uma quantidade: ");
    // repetir (x) vezes
    // inicio teste variacao
    for (y = x; y >= 1; y = y - 1)
    {
        // ler valor do teclado
        z = IO_readint("Valor = ");
        // mostrar valor atual
        IO_printf("%d. %d\n", y, z);
    } // fim repetir
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim exemplo05 ( )

void exemplo06 ( )
{
// definir dado
int x = 0;
int y = 0;
chars palavra = IO_new_chars ( STR_SIZE );
int tamanho = 0;
// identificar
IO_id ( "EXEMPLO0306 - Method06 - v0.0" );
// ler do teclado
palavra = IO_readstring ( "Entrar com uma palavra: " );
// repetir para cada letra
tamanho = strlen ( palavra ) - 1;
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
for ( y = tamanho; y >= 0; y = y - 1 )
{
// mostrar valor atual
IO_printf ( "%d: [%c]\n", y, palavra [y] );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim exemplo06 ( )

void exemplo07 ( )
{
// definir dado
int x = 0;
int y = 0;
char palavra [STR_SIZE];
int tamanho = 0;
// identificar
IO_id ( "EXEMPLO0307 - Method07 - v0.0" );
// ler do teclado
IO_printf ( "Entrar com uma palavra: " );
scanf ( "%s", palavra );
// OBS: A cadeia de caracteres dispensa a indicacao de endereco (&) na leitura.
// repetir para cada letra
tamanho = strlen ( palavra );
// OBS: A cadeia de caracteres iniciam suas posições em zero.
// inicio teste variacao
for ( y = 0; y < tamanho; y = y + 1 )
{
// mostrar valor atual
IO_printf ( "%d: [%c]\n", y, palavra [y] );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim exemplo07 ( )

void exemplo08 ( )
{
// definir dado
int inferior = 0;
int superior = 0;
int x = 0;
// identificar
IO_id ( "EXEMPLO0310 - Method08 - v0.0" );
// ler do teclado
inferior = IO_readint ( "Limite inferior do intervalo: " );
superior = IO_readint ( "Limite superior do intervalo : " );
// inicio teste variacao
for ( x = inferior; x <= superior; x = x + 1 )
{
// mostrar valor atual
IO_printf ( "%d\n", x );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim exemplo08 ( )

void exemplo09 ( )
{
// definir dado
double inferior = 0;
double superior = 0;
double passo = 0;
double x = 0;
// identificar
IO_id ( "EXEMPLO0310 - Method09 - v0.0" );
// ler do teclado
inferior = IO_readdouble ( "Limite inferior do intervalo : " );
superior = IO_readdouble ( "Limite superior do intervalo : " );
passo = IO_readdouble ( "Variacao no intervalo (passo): " );
// inicio teste variacao
for ( x = superior; x >= inferior; x = x - passo )
{
// mostrar valor atual
IO_printf ( "%lf\n", x );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim exemplo09 ( )


void exemplo10 ( )
{
// definir dado
double inferior = 0;
double superior = 0;
double passo = 0;
double x = 0;
// identificar
IO_id ( "EXEMPLO0310 - Method10 - v0.0" );
// ler do teclado
inferior = IO_readdouble ( "Limite inferior do intervalo : " );
// repetir ate' haver confirmacao de validade
do
{
superior = IO_readdouble ( "Limite superior do intervalo: " );
}
while ( inferior >= superior );
// repetir ate' haver confirmacao de validade
do
{
passo = IO_readdouble ( "Variacao no intervalo (passo): " );
}
while ( passo <= 0.0 );
// inicio teste variacao
for ( x = inferior; x <= superior; x = x + passo )
{
// mostrar valor atual
IO_printf ( "%lf\n", x );
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );
} // fim exemplo10 ( )

/*
Funcao principal.
@return codigo de encerramento
*/

int main()
{
    int x = 0;

    // método para repetição até parar "do-while"
    do
    {
        IO_id("EXEMPLO03-Programa - v0.0");

        // ler do telcado
        IO_println("Opcoes");
        IO_println("0-parar");
        IO_println("1-repetecao com teste no inicio");
        IO_println("2-repeticao com teste co inicio (alternativo)");
        IO_println("3-repeticao com teste no inicio ( crescente )");
        IO_println("4 - repeticao com teste no inicio e variacao ( crescente )");
        IO_println("5 - repeticao com teste no inicio e variacao (decrescente)");
        IO_println ("6 - repeticao sobre cadeia de caracteres (decrescente)" );
        IO_println ( "7 - repeticao sobre cadeia de caracteres ( crescente )" );
        IO_println ( "8 - repeticao com intervalos ( crescente )" );
        IO_println ( "9 - repeticao com intervalos (decrescente)" );
        IO_println ( "10 - repeticao com confirmacao " );

        x = IO_readint("Ir para a opcao:");

        // escolher exemplo
        switch (x)
        {
        case 0:
            exemplo00();
            break;
        case 1:
            exemplo01();
            break;
        case 2:
            exemplo02();
            break;
        case 3:
            exemplo03();
            break;
        case 4:
            exemplo04();
            break;
        case 5:
             exemplo05();
             break;
        case 6:
             exemplo06();
             break;
        case 7:
             exemplo07();
             break;
        case 8:
             exemplo08();
            break;
        case 9:
             exemplo09();
             break;
        case 10:
             exemplo10();
             break;
        default:
            IO_pause(IO_concat("Valor diferente das opcoes [0,1] (",
                               IO_concat(IO_toString_d(x), ")")));
        } // fim switch

    } while (x != 0);
    // encerrar
    IO_pause("Aperte ENTER para sair");
    return (0);

} // fim main()

/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
a.) 0
b.) 1
c.) 2
d.) 3
e.) 4
f.) -1
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/