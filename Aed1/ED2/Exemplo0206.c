/*
Exemplo0206 - v0.0. - __ / __ / _____
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
/*
Funcao principal.
@return codigo de encerramento
@param argc - quantidade de parametros na linha de comandos
@param argv - arranjo com o grupo de parametros na linha de comandos
*/
int main()
{ 
    // definir dado
    char x = '_'; // definir variavel com valor inicial
    // identificar
    IO_id("EXEMPLO0206 - Programa - v0.0");
    // ler do teclado
    x = IO_readchar("Entrar com um caractere: ");
    // testar valor
    if (('a' <= x && x <= 'z') ||   //minuscula OU
       ('A' <= x && x <= 'Z') )      //maiuscula
    {
        IO_printf("%s (%c)\n", "letra ", x);
    }
    else
    {
        IO_printf("%s (%c)\n", "Valor diferente de letra ", x);
    }//fim se
      
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