/*
Exercicios05 - v0.0. - _18_ / _04_ / _2023_
Author: _Tales_Rocha_Moreira_
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

void multiplosSeis(int x) //method01
{
    int y = 1;     // controle
    int Mseis = 0; // multiplicação por 6 para mostrar os Multiplos de 6

    while (y < x)
    {
        Mseis = y * 6;
        printf("%d: %d\n", y, Mseis);
        y++;
    }
}

void method01()
{

    // identificar
    IO_id("Exercicio0501 - Method01 - v0.0");
    // definir dados
    int x = 0; // ler do teclado a quantidade de multiplos a ser exibida

    // executar
    printf("Quantos multiplos de 6: ");
    scanf("%d", &x);
    multiplosSeis(x);

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // fim method01 ( )

/**
Method02.
*/

void MultSeisEQuatro(int x) //method02
{
    int y = 1;  // controle
    int M6 = 0; // multiplicar por 6
    int M4 = 0; // multiplicar por 4

    while (y < x)
    {
        M6 = y * 6;
        M4 = y * 4;
        printf("Multiplos de 6 e 4 sao: %d: %d %d\n", y, M6, M4);
        y++;
    }
}

void method02()
{
    // identificar
    IO_id("Exercicio0502 - Method02 - v0.0");

    // definir dado
    int x = 0; // quantidade a ser lida pelo teclado

    // executar
    printf("Quantos multiplos de 6 e 4 mostrar: ");
    scanf("%d", &x);
    MultSeisEQuatro(x);
    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // fim method02 ( )

/**
Method03.
*/

void MultDeNoveDec(int x, int contador) //method03
{
    int z = 0; // multiplicar por 9
    // executar
    if (contador > 0)
    {
        z = 9 * contador;
        printf("%d: %d\n", contador, z);
        MultDeNoveDec(x, contador - 1);
    }
}

void method03()
{
    // identificar
    IO_id("Exercicio0503 - Method03 - v0.0");

    // definir dados
    int x = 0; // quantidade lida do teclado

    // executar
    printf("Quantos multiplos de 9 mostrar: ");
    scanf("%d", &x);

    MultDeNoveDec(x, x);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method03 ( )

/**
Method04.
*/

void SomarFracoes(int x) //method04
{
    int y = 1; // contador
    int numerador = 0;
    int denominador = 1;

    // executar
    while (y <= x)
    {
        numerador = 1;
        denominador = y * 6;
        printf("%d / %d\n", numerador, denominador);
        y++;
    }
}

void method04()
{
    // identificar
    IO_id("Exercicio0504 - Method04 - v0.0");

    // definir dado
    int x = 0; // ler do teclado

    // executar
    printf("Quantos multiplos de 6 mostrar no denominador: ");
    scanf("%d", &x);
    SomarFracoes(x);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method04 ( )

/**
Method05.
*/
void denominadorExpoente(int x, int contador) //method05
{
    // definir dados
    double numerador = 1.0;
    double DenominadorExpo = 0.0;

    if (contador < x)
    {
        DenominadorExpo = pow(x, contador);
        printf("%1.0lf / %1.0lf\n", numerador, DenominadorExpo);
        denominadorExpoente(x, contador + 1);
    }
}
void method05()
{
    // identificar
    IO_id("Exercicio0505 - Method05 - v0.0");
    // definir dado
    int x = 0;

    // executar
    printf("Quantos valores expoentes mostrar no denominador: ");
    scanf("%d", &x);

    denominadorExpoente(x, 1); // chamar a funcao executora

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
Method06.
*/

void paresNmultiplos5(int x, int contador) //method06
{
    int m = 0; // variavel de multiplicação
    if (contador <= x)
    {
        m = 6 * contador;
        if (m % 2 == 0 && m % 5 != 0)
        {
            printf("%d + ", m);
        }
        else if (m % 5 == 0)
        {
            m + 6;
            printf("%d + ", m);
        }

        paresNmultiplos5(x, contador + 1);
    }
}

void method06()
{
    // identificar
    IO_id("Exercicio0506 - Method06 - v0.0");

    // definir dados
    int x = 0;

    // executar
    printf("Quantos valores testar: ");
    scanf("%d", &x);
    paresNmultiplos5(x, 1);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method06 ( )

/**
Method07.
*/

void somaInversos6(int x, int contador) // Method07
{
    int m = 0; // variavel de multiplicação
    int numerador = 1;

    if (contador <= x)
    {
        m = 6 * contador;
        if (m % 2 == 0 && m % 5 != 0)
        {
            printf("%d / %d + ", numerador, m);
        }
        else if (m % 5 == 0)
        {
            m + 6;
            printf("%d / %d + ", numerador, m);
        }

        somaInversos6(x, contador + 1);
    }
}

void method07()
{
    // identificar
    IO_id("Exercicio0507 - Method07 - v0.0");

    // definir dado
    int x = 0;

    // executar
    printf("Quantos valores testar no denominador: ");
    scanf("%d", &x);

    somaInversos6(x, 1);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method07 ( )

/**
Method08.
*/

void somaDe6(int x, int contador, int soma) // method08
{
    int M = 0; // variavel de multiplicação

    if (contador <= x)
    {
        M = contador * 6;
        printf("%d + ", M);
        soma = soma + M;
        somaDe6(x, contador + 1, soma);
    }
    else
    {
        printf("\nSoma = %d", soma);
    }
}

void method08()
{
    // identificar
    IO_id("Exercicio0508 - Method08 - v0.0");

    // definir dado
    int x = 0;

    // executar
    printf("Quantos valores somar: ");
    scanf("%d", &x);

    int soma = 0;
    somaDe6(x, 1, soma);

    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method08 ( )

/**
Method09.
*/

void calcularSomaQuadrados(int x, int contador, int soma, int numero) // method09
{
    double M = pow(numero, 2);
    if (contador <= x)
    {
        printf(" %1.0lf + ", M);
        soma = soma + M;
        calcularSomaQuadrados(x, contador + 1, soma, numero + 1); // numero + 1 para passar ao próximo valor
    }
    else
    {
        printf("\nSoma = %d", soma);
    }
}

void method09()
{
    // identificar
    IO_id("Exercicio0509 - Method09 - v0.0");

    // definir dado
    int x = 0;

    // executar
    printf("Entrar com a quantidade para ser somada seus quadrados: ");
    scanf("%d", &x);

    calcularSomaQuadrados(x, 1, 0, 6); // 6 para a variavel numero, indicará que deverá começar do 6
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim method09 ( )

/**
Method10.
*/

void calcularSomaInversos(int x, int contador, double soma, double numero) //method10
{
    double denominador = 1;
    if(contador <= x)
    {
        printf("%1.0lf / %1.0lf\n", denominador, numero);
        soma = soma + (denominador / numero);
        calcularSomaInversos(x, contador + 1, soma, numero + 1 );
    }
    else{
        printf("soma = %lf", soma );
    }
}

void method10()
{
    // identificar
    IO_id("Exercicio0510 - Method10 - v0.0");

    // definir dados
    int x = 0;

    // executar
    printf("Quantos numeros calcular no denominador: ");
    scanf("%d", &x);

    calcularSomaInversos(x, 1, 0, 6.0);

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
        IO_id("Exercicio0501 - Programa - v0.0");
        // ler do teclado
        IO_println("Opcoes");
        IO_println(" 0 - parar");
        IO_println(" 1 - Multiplos de 6 em ordem crescente");
        IO_println(" 2 - Multiplos de 6 e 4");
        IO_println(" 3 - Impares multiplos de 9 decrescentes");
        IO_println(" 4 - Denominadores multiplos de 6");
        IO_println(" 5 - Denominadores crescentes");
        IO_println(" 6 - Soma a partir de 6 e nao multiplos de 5");
        IO_println(" 7 - Soma dos inversos a partir de 6 e nao multiplos de 5");
        IO_println(" 8 - Adicao dos naturais a partir de 6");
        IO_println(" 9 - Soma dos quadrados da adicao a partir de 6");
        IO_println("10 - Soma do inverso dos naturais a partir de 6");
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