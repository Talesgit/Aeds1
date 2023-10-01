/*
Exemplo0204 - v0.0. - __ / __ / _____
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
    double x = 0.0; // definir variavel com valor inicial
    // identificar
    IO_id("EXEMPLO0204 - Programa - v0.0");
    // ler do teclado
    x = IO_readint("Entrar com um valor real: ");
    // testar valor
    if (1.0 <= x && x <= 10.0)
    {
        IO_printf("%s (%lf)\n", "Valor dentro do intervalo[1:10]", x);
    }
    else
    {
        IO_printf("%s (%lf)\n", "Valor fora o intervalo [1:10] ", x);
        if (x < 1.0)
        {
            IO_printf("%s (%lf)\n", "Valor  abaixo do intervalo[1:10]", x);
        }
        else
        {
            IO_printf("%s (%lf)\n", "Valor acima do intevalo [1:10]", x);
        } // fim else
    }     // fim se
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
  */