/*
   Algoritmos e estruturas de dados - ED06 - Exemplos06
   Autor: Tales Rocha Moreira - Data: 21/04/2023
   Funções e procedimenros recursivos em C
*/

#include "io.h"

void exemplo00()
{
}

/*
Method01a- Mostrar certa quantidade de valores recursivamente.
@param x - quantidade de valores a serem mostrados
*/

void exemplo01a(int x) // funcao recursiva
{
    // repetir enquanto for maior que zero
    if (x > 0)
    {
        // mostrar valor
        IO_printf("%s%d\n", "Valor = ", x); // PRIMEIRO MOSTRA O VALOR E DEPOIS SUBTRAI 1
        exemplo01a(x - 1);                  // motor da recursividade
    }                                       // fim if
} // fim funcao de metodo auxiliar

void exemplo01() // funcao chamadora
{
    // executar o metodo auxiliar
    exemplo01a(5); // motor da recursividade, devera mostrar de 0 a 5

    printf("\n\nAperte ENTER para sair");
    getchar();
}
// ** APENAS ALTEROU A ORDEM DO EX 1 PARA O 2 **
void exemplo02a(int x)
{
    if (x > 0)                              // A IMPRESSAO OCORRE "DE BAIXO PARA CIMA", POIS PRIMEIRO TIRA 1, E DEPOIS EXECUTA
    {                                       // durante o retorno é que imprime o valor anterior de x - 1
        exemplo02a(x - 1);                  // motor da recursividade, passar ao proximo
        IO_printf("%s%d\n", "Valor = ", x); // mostrar valor
    }                                       // fim if
} // fim funcao auxiliar

void exemplo02()
{
    exemplo02a(5);
    printf("\n\nAperte ENTER para sair");
    getchar();
}

// Mostrar certa quantidade de valores recursivamente
void exemplo03a(int x)
{
    if (x > 1)
    {
        exemplo03a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%s%d\n", "Valor =", x);
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1"); // FOI NECESSARII POIS O IF, NAO ESTA = A 1, ENTAO O 1 CAIU NO ELSE

    } // fim else
} // fim funcao auxiliar

void exemplo03()
{
    exemplo03a(5);
    printf("\n\nAperte ENTER para sair");
    getchar();
}

// EXEMPLO04 mostrar certa quantidade de valores recursivamente
void exemplo04a(int x)
{
    if (x > 1)
    {
        exemplo04a(x - 1); // motor
        IO_printf("%s%d\n", "Valor= ", 2 * (x - 1));
    }
    else
    {
        // mostrar o ultimo
        IO_printf("%s\n", "Valor = 1"); // Como if não é = 1, caiu no else
    }                                   // fim if
} // fim funcao ex04a

void exemplo04()
{
    exemplo04a(5);
    printf("\n\nAperte ENTER para sair");
    getchar();
}

void exemplo05a(int x)
{
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // passar ao proximo
        exemplo05a(x - 1); // motor da recursividade
        // mostrar valor
        IO_printf("%d: %d/%d\n", x, (2 * (x - 1)), (2 * (x - 1) + 1));
    }
    else
    { // base da recursividade
        // mostrar o ultimo
        IO_printf("%d; %d\n", x, 1);
    }
}
void exemplo05()
{
    exemplo05a(5);
    printf("\n\nAperte ENTER para sair");
    getchar();
}

double somarFracoes(int x, double soma) // exemplo06
{
    // definir dado local
    // double soma = 0.0;
    // repetir enquanto valor maior que zero
    if (x > 1)
    {
        // separar um valor e passar ao proximo (motor da recursividade)
        soma = (2.0 * (x - 1)) / (2.0 * (x - 1) + 1) + somarFracoes(x - 1, soma);
        // mostrar valor
        IO_printf("%d: %lf/%lf\n", x, (2.0 * (x - 1)), (2.0 * (x - 1) + 1));
    }
    else
    {
        // base da recursividade
        soma = 1.0;
        // mostrar o ultimo
        IO_printf("%d %lf\n", x, 1.0);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracoes ( )

void exemplo06()
{
    // definir dado
    double soma = 0.0;

    // chamar a função e receber o resultado
    soma = somarFracoes(5, 1.0);

    // mostrar o resultado
    printf("soma = %lf\n", soma);
    printf("\n\nAperte ENTER para sair");
    getchar();
}

// EXEMPLO07
/**
somarFracoes2b - Somar certa quantidade de fracoes recursivamente.
@return soma de valores
@param x - quantidade de valores a serem mostrados (controle)
@param soma - valor atual da soma (historia = memoria)
@param numerador - numerador da parcela a ser somada
@param denominador - denominador da parcela a ser somada
*/
double somarFracoes2b(int x, double soma, double numerador, double denominador) // Exemplo07
{
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar valores atuais
        IO_printf("%d: %lf/%lf\n", x, numerador, denominador);
        // somar o termo atual e passar ao proximo (motor da recursividade)
        soma = somarFracoes2b(x - 1,                                    // proximo
                              soma + ((1.0 * numerador) / denominador), // atualizar
                              numerador + 2.0,                          // proximo
                              denominador + 2.0);                       // proximo
    }
    // retornar resultado
    return (soma);
} // fim somarFracoes2b ( )

/**
somarFracoes2a - Somar certa quantidade de fracoes.
Funcao de servico para preparar e
disparar o mecanismo recursivo.
@return soma de valores
@param x - quantidade de valores a serem mostrados
*/

double somarFracoes2a(int x)
{
    // definir dado local
    double soma = 0.0;
    // repetir enquanto valor maior que zero
    if (x > 0)
    {
        // mostrar o ultimo
        IO_printf("%d: %lf\n", x, 1.0);
        // preparar a soma do valor atual e o proximo
        soma = somarFracoes2b(x - 1, 1.0, 2.0, 3.0);
    } // fim se
    // retornar resultado
    return (soma);
} // fim somarFracoes2a ( )

void exemplo07()
{
    // definir dado
    double soma = 0.0;

    // chamar a funcao e receber o resultado
    soma = somarFracoes2a(5);

    // mostrar resultado
    IO_printf("soma = %lf\n", soma);

    printf("\n\nAperte ENTER para sair");
    getchar();
}

// EXEMPLO08
/**
contarDigitos - Contar digitos recursivamente.
@return quantidade de digitos
@param x - numero cuja quantidade de digitos sera' calculada
*/
int contarDigitos(int x) // exemplo08
{
    // definir dado
    int resposta = 1; // base
    // testar se contador valido
    if (x >= 10)
    {
        // tentar fazer de novo com valor menor
        resposta = 1 + contarDigitos(x / 10); // motor 1
    }
    else
    {
        if (x < 0)
        {
            // fazer de novo com valor absoluto
            resposta = contarDigitos(-x); // motor 2
        }                                 // fim se
    }                                     // fim se
    // retornar resposta
    return (resposta);
} // fim contarDigitos ( )

void exemplo08()
{

    IO_printf("digitos (%3d) = %d\n", 123, contarDigitos(123));
    IO_printf("digitos (%3d) = %d\n", 1, contarDigitos(1));
    IO_printf("digitos (%3d) = %d\n", -10, contarDigitos(-10));

    printf("\n\nAperte ENTER para sair");
    getchar();
}

/**
fibonacci - Gerador de numero de Fibonacci.
@return numero de Fibonacci
@param x - numero de ordem cujo valor sera' calculado
*/
int fibonacci(int x) // Exemplo09
{
    // definir dado
    int resposta = 0;
    // testar se contador valido
    if (x == 1 || x == 2)
    {
        // primeiros dois valores iguais a 1
        resposta = 1; // bases
    }
    else
    {
        if (x > 1)
        {
            // fazer de novo com valor absoluto
            resposta = fibonacci(x - 1) + fibonacci(x - 2);
        } // fim se
    }     // fim se
    // retornar resposta
    return (resposta);
} // fim fibonacci ( )

void exemplo09()
{

    // calcular numero de Fibonacci
    IO_printf("fibonacci (%d) = %d\n", 1, fibonacci(1));
    IO_printf("fibonacci (%d) = %d\n", 2, fibonacci(2));
    IO_printf("fibonacci (%d) = %d\n", 3, fibonacci(3));
    IO_printf("fibonacci (%d) = %d\n", 4, fibonacci(4));
    IO_printf("fibonacci (%d) = %d\n", 5, fibonacci(5));

    printf("\n\nAperte ENTER para sair");
    getchar();
}

// EXEMPLO10

/**
contarMinusculas - Contador de letras minusculas.
@return quantidade de letras minusculas
@param x - cadeia de caracteres a ser avaliada
*/
int contarMinusculas(chars cadeia, int x) // Exemplo10
{
    // definir dado
    int resposta = 0;
    // testar se contador valido
    if (0 <= x && x < strlen(cadeia))
    {
        // testar se letra minuscula
        if (cadeia[x] >= 'a' &&
            cadeia[x] <= 'z')
        {
            // fazer de novo com valor absoluto
            resposta = 1;
        } // fim se
        resposta = resposta + contarMinusculas(cadeia, x + 1);
    } // fim se
    // retornar resposta
    return (resposta);
} // fim contarMinusculas ( )

void exemplo10()
{
    // contar minusculas em cadeias de caracteres
    IO_printf("Minusculas (\"abc\",0) = %d\n", contarMinusculas("abc", 0));
    IO_printf("Minusculas (\"aBc\",0) = %d\n", contarMinusculas("aBc", 0));
    IO_printf("Minusculas (\"AbC\",0) = %d\n", contarMinusculas("AbC", 0));
    printf("\n\nAperte ENTER para sair");
    getchar();
}

int main()
{
    int x = 0;

    do
    {
        IO_id("\nExemplos06 - ED06 - Tales Rocha Moreira");

        IO_println(" 0 - Sair");
        IO_println(" 1 - Exemplo01");
        IO_println(" 2 - Exemplo02");
        IO_println(" 3 - Exemplo03");
        IO_println(" 4 - Exemplo04");
        IO_println(" 5 - Exemplo05");
        IO_println(" 6 - Exemplo06");
        IO_println(" 7 - Exemplo07");
        IO_println(" 8 - Exemplo08");
        IO_println(" 9 - Exemplo09");
        IO_println("10 - Exemplo10");

        x = IO_readint("Entrar com uma opcao: ");
        printf("\n");

        switch (x)
        {
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
        case 10:
            exemplo10();
            break;

        default:
            IO_println("ERRO: Valor invalido.");

        } // fim switch
    } while (x != 0);
    // encerrar
    IO_pause("Apertar ENTER para terminar");
    return (0);
}
