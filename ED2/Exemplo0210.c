/*
Exemplo0210 - v0.0. - __ / __ / _____
Author: ________________________
Para compilar em terminal (janela de comandos):
Linux : gcc -o exemplo0201 exemplo0201.c
Windows: gcc -o exemplo0201 exemplo0201.c
Para executar em terminal (janela de comandos):
Linux : ./exemplo0201
Windows: exemplo0201
*/
// dependencias
#include "io.h" // para definicoes proprias
 void metodo00()
 {
    //nao faz nada
 }//fim metodo 00
void metodo01 ()
{
    IO_println ("Valor igual a um");
}//fim metodo01
void metodo02 (int x)
{
    IO_println ( IO_concat ( "valor igual a (", IO_concat (IO_toString_d(x), ")\n")));
}//fim metodo2

//@param text1 - texto a ser exibido
//@param x - valor a ser exibido
void metodo03 ( char* text1, int x )
{
    IO_println ( IO_concat(IO_concat (text1, "("), IO_concat ( IO_toString_d (x), ")\n")));
}//fim metodo03
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
    // identificar
    IO_id("EXEMPLO0210 - Programa - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com um inteiro [0,1,2,3]: ");

    // testar valor
    switch (x)
    {
    case 0:
        metodo00();
        break;
    case 1:
        metodo01();
        break;
    case 2:
        metodo02(x);
        break;
    case 3:
        metodo03("valor igual a tres", x);
        break;

    default:
        IO_printf(IO_concat ( "Valor diferente das opcoes[0,1,2,3](",
                  IO_concat ( IO_toString_d (x), ")")));
    } // fim switch

    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
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
  0.2 01. ( OK )
  0.3 01. ( OK )
  0.4 01. ( OK )
  0.5 01. ( OK )
  0.6 01. ( OK )
  0.7 01. ( OK )
  0.8 01. ( OK )
  0.9 01. ( OK )
  1.0 01. ( OK )
  */