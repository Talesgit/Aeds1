/*
Exemplo0501 - v0.0. - __ / __ / _____
Author: ________________________
*/
// dependencias
#include "io.h" // para definicoes proprias
/**
Method00 - nao faz nada.
*/
void method00()
{
    // nao faz nada
} // fim method00 ( )
/**
Method01a - Mostrar certa quantidade de valores.
@param x - quantidade de valores a serem mostrados
*/
void method01a(int x)
{
    // definir dado local
    int y = 1; // controle
    // repetir enquanto controle menor que a quantidade desejada
    while (y <= x)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", y);
        // passar ao proximo
        y = y + 1;
    } // fim se
} // fim method01a( )
/**
Method01 - Mostrar certa quantidade de valores.
OBS.: Preparacao e disparo de outro metodo.
*/
void method01()
{
    // identificar
    IO_id("EXEMPLO0501 - Method01 - v0.0");
    // executar o metodo auxiliar
    method01a(10);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method01 ( )

/**
Method02.
*/

void method02a(int x) // mostrar certa quantidade de pares
{
    int y = 1; // controle
    int z = 0; // passar de 2 em 2

    while (y <= x)
    {
        printf("%d: %d\n", y, z);
        z = z + 2; // passar de 2 em 2
        y++;       // adicionar + 1 a y, caso contrário loop infinito
    }
}
void method02() // mostrar certa quantidade de pares
{
    // identificar
    IO_id("EXEMPLO0501 - Method02 - v0.0");

    // executar
    method02a(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method02 ( )

/**
Method03.
*/

void method03a(int x) // mostrar pares crescentes a partir de 2
{
    int y = 1; // controle
    int z = 0; // multiplicar

    while (y <= x)
    {
        z = y * 2;
        printf("%d: %d\n", y, z);
        y++;
    }
}

void method03()
{
    // identificar
    IO_id("EXEMPLO0501 - Method03 - v0.0");

    // executar
    method03a(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
Method04.
*/

void method04a(int x) // mostrar pares crescentes a partir de 2 inversa(começando do maior)
{
    int y = x; // controle
    int z = 0; // resultado da multiplicação de 2 por y(x)

    while (y > 0)
    {
        z = 2 * y;
        printf("%d: %d\n", y, z);
        y--;
    }
}

void method04()
{
    // identificar
    IO_id("EXEMPLO0501 - Method04 - v0.0");

    // executar
    method04a(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
Method05.
*/

void method05a(int x) // mostrar pares em ordem decrescente
{
    int y = 0; // controle

    for (y = x; y > 0; y--)
    {
        printf("%d: %d\n", y, (y * 2));
    }
}

void method05()
{
    // identificar
    IO_id("EXEMPLO0501 - Method05 - v0.0");

    // mostrar
    method05a(5);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
Method06.
*/

int somarValores(int x) // somar valores na sequencia de 2 + 2
{
    int soma = 1; // somar
    int y = 0;    // controle

    for (y = x - 1; y > 0; y--)
    {
        printf("%d: %d\n", y, (2 * y));

        soma = soma + (2 * y);
    }
    return (soma);
}

void method06()
{
    // identificar
    IO_id("EXEMPLO0501 - Method06 - v0.0");

    // definir dados
    int soma = 0;

    // executar
    soma = somarValores(5);
    printf("Soma dos valores: %i", soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
Method07
*/

int somarFracoes1(int x)
{
    int y = 0; // controle
    double numerador = 0.0;
    double denominador = 0.0;
    double soma = 1.0;

    for (y = x - 1; y > 0; y--) // começará de ordem decrescente, com uma unidade a menos da posição, para ser multiplicada por 2 no denominador, caso 5, den = 8, pois 5 - 1 e 4 * 2
    {
        numerador = 1.0;
        denominador = (2 * y); // denominador será sempre par e sera calculado a partir dado valor da repetição (2 * o valor da rep)

        printf("%d: %1.0lf %1.0lf divisao: %lf\n", y, numerador, denominador, numerador / denominador);
        soma = soma + (1.0) / (2.0 * y);
    }
    return (soma);
}

void method07()
{
    // identificar
    IO_id("EXEMPLO0501 - Method07 - v0.0");

    // definir dado
    double soma = 0.0;

    // executar
    soma = somarFracoes1(5);

    printf("Soma de fracoes = %lf", soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
Method08.
*/

/**
somarFracao2 - funcao para somar certa quantidade de fracoes.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracao2(int x)
{
    // definir dados locais
    double soma = 1.0;
    double numerador = 0.0;
    double denominador = 0.0;
    int y = 0; // controle
    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // calcular numerador
        numerador = 2.0 * y - 1;
        // calcular denominador
        denominador = 2.0 * y;
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %lf\n",
                  y + 1, numerador, denominador, (numerador / denominador));
        // somar valor
        soma = soma + (2.0 * y - 1) / (2.0 * y);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracao2 ( )

void method08()
{
    // identificar
    IO_id("EXEMPLO0501 - Method08 - v0.0");
    double soma = 0.0;
    // executar

    // chamar e receber resultado da funcao
    soma = somarFracao2(5);
    // mostrar resultado
    IO_printf("soma de fracoes = %lf\n", soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
Method09.
*/

/**
somarFracao3 - funcao para somar certa quantidade de fracoes.
@return soma dos valores
@param x - quantidade de valores a serem mostrados
*/
double somarFracao3(int x)
{
    // definir dados locais
    double soma = 1.0;
    int y = 0; // controle
    // mostrar primeiro valor
    IO_printf("%d: %7.4lf/%7.4lf\n", 1, 1.0, soma);
    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= (x - 1); y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %7.4lf/%7.4lf = %7.4lf\n",
                  y + 1, (2.0 * y), (2.0 * y + 1), ((2.0 * y) / (2.0 * y + 1)));
        // somar valor
        soma = soma + (2.0 * y) / (2.0 * y + 1);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracao3 ( )

void method09()
{
    // identificar
    IO_id("EXEMPLO0501 - Method09 - v0.0");

    double soma = 0.0;

    // chamar e receber resultado da funcao
    soma = somarFracao3(5);
    // mostrar resultado
    IO_printf("soma de fracoes = %lf\n", soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method09 ( )

/**
Method10.
*/

/**
multiplicarValores - funcao para multiplicar certa quantidade de valores impares.
@return produto de valores
@param x - quantidade de valores
*/
int multiplicarValores(int x)
{
    // definir dados locais
    int produto = 1;
    int y = 0; // controle
    // repetir enquanto controle menor que a quantidade desejada
    for (y = 1; y <= x; y = y + 1)
    {
        // mostrar valor
        IO_printf("%d: %d\n", y, (2 * y - 1));
        // somar valor
        produto = produto * (2 * y - 1);
    } // fim se
    // retornar resultado
    return (produto);
} // fim multiplicarValores ( )

void method10()
{
    // identificar
    IO_id("EXEMPLO0501 - Method10 - v0.0");
    // mostrar produto de valores
    IO_printf("%s%d\n", "produto = ", multiplicarValores(5));
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method10 ( )
/*
Funcao principal.
@return codigo de encerramento
*/
int main()
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        IO_id("EXEMPLO0501 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - mostrar certa quantidade de valores");
        IO_println(" 2 - mostrar certa quantidade de pares");
        IO_println(" 3 - mostrar pares crescentes a partir de 2 ");
        IO_println(" 4 - mostrar pares crescentes comecando do maior");
        IO_println(" 5 - mostrar pares em ordem decrescente");
        IO_println(" 6 - somar valores na sequencia 2 + 2");
        IO_println(" 7 - ");
        IO_println(" 8 - ");
        IO_println(" 9 - ");
        IO_println("10 - ");
        IO_println("");
        x = IO_readint("Entrar com uma opcao: ");
        // testar valor
        switch (x)
        {
        case 0:
            method00();
            break;
        case 1:
            method01();
            break;
        case 2:
            method02();
            break;
        case 3:
            method03();
            break;
        case 4:
            method04();
            break;
        case 5:
            method05();
            break;
        case 6:
            method06();
            break;
        case 7:
            method07();
            break;
        case 8:
            method08();
            break;
        case 9:
            method09();
            break;
        case 10:
            method10();
            break;
        default:
            IO_println("ERRO: Valor invalido.");
        } // fim escolher
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  a.) 5 -> { 1, 2, 3, 4, 5 }
  ---------------------------------------------- historico
  Versao Data Modificacao
  0.1 __/__ esboco
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  */