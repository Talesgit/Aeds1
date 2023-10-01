/*
RECUPERACAO01 - Tales Rocha Moreira - 08/05/2023
*/
#include "io.h"

void exercicio00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

/*
Tales Rocha Moreira - 808455
exercicio01
- Calcular a soma dos divisores de cada numero lido
@param quantidade = quantos numeros calcular
@param numeros[quantidade] = vetor de inteiros para armazenar os numeros lidos, de tamanho quantidade
@param soma = soma dos divisores do numero
*/

int calcularSomaDivisores(int numero) // exercicio01
{
    // definir dado
    int soma = 0;

    // executar

    for (int i = 1; i <= numero; i++)
    {
        if (numero % i == 0)
        {
            soma = soma + i;
        }
    }

    return (soma);

} // fim calcularSoma

void exercicio01()
{
    // definir dados
    int quantidade = 0;

    printf("Quantos numeros calcular a soma dos divisores? ");
    scanf("%d", &quantidade);

    int numeros[quantidade];
    // executar
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nEntrar com um numero para calcular seus divisores: ");
        scanf("%d", &numeros[i]);

    } // fim for

    // mostrar a soma dos divisores
    for (int i = 0; i < quantidade; i++)
    {
        printf("A soma dos divisores de %d e: %d\n", numeros[i], calcularSomaDivisores(numeros[i]));
    }

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");

} // fim exercicio01

/*
Tales Rocha Moreira - 808455
exercicio02
- Dizer se cada valor lido e primo ou nao
@param
*/

int verificarPrimo(int numero) // exercicio02
{
    bool primo = false;
    for (int i = 1; i <= numero; i++)
    {
        if (numero % i != 0)
        {
            primo = false;
            break;
        }
        else if (numero % 1 == 0 && numero % numero == 0)
        {
            primo = true;
        }
    } // fim for

    return (primo);

} // fim verificar primo

void exercicio02()
{
    // definir dados
    int quantidade = 0;

    printf("Quantos numeros testar se sao primos? ");
    scanf("%d", &quantidade);

    int numeros[quantidade];
    // executar
    for (int i = 0; i < quantidade; i++)
    {
        printf("\nQual numero testar se e primo? ");
        scanf("%d", &numeros[i]);

    } // fim for

    for (int i = 0; i < quantidade; i++)
    {
        if (verificarPrimo(numeros[i]) == true)
        {
            printf("O valor %d, e primo\n", numeros[i]);
        }
        else
        {
            printf("O valor %d, nao e primo\n", numeros[i]);
        }

    } // fim for

    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio02

/* Tales Rocha Moreira - 808455
-exercicio02
-dizer se cada símbolo é um operador lógico (&,|,!), aritmético (+,-,*,/,%), relacional (>,<,=),
separadores (espaço, ponto, vírgula, ponto-e-vírgula, dois-pontos, sublinha)
ou outro símbolo qualquer.
@param
@param

CADA UMA DAS FUNCOES VERIFICA UM TIIPO DE SIMBOLO
 */

int operadorLogico(char simbolo) // exercicio03
{
    // definir dados
    bool eOperador = false;
    // testar
    if (simbolo == '&' || simbolo == '|' || simbolo == '!')
    {
        eOperador = true;
    } // fim teste

    // enviar resultado
    return (eOperador);

} // fim operadorLogico

int operadorAritmetico(char simbolo) // exercicio03
{
    // definir dados
    bool eOperador = false;
    // testar
    if (simbolo == '+' || simbolo == '-' || simbolo == '*' || simbolo == '/' || simbolo == '%')
    {
        eOperador = true;
    } // fim teste

    return (eOperador);

} // fim operadorAritmetico

int operadorRelacional(char simbolo) // exercicio03
{
    // definir dados
    bool eOperador = false;
    // testar
    if (simbolo == '>' || simbolo == '<' || simbolo == '=')
    {
        eOperador = true;
    } // fim teste

    return (eOperador);

} // fim operadorRelacional

int separadores(char simbolo) // exercicio03
{
    // definir dados
    bool eSeparador = false;
    // teste
    if (simbolo == ',' || simbolo == '_' || simbolo == ':' || simbolo == ';' || simbolo == '.' || simbolo == ' ')
    {
        eSeparador = true;
    } // fim teste

    return (eSeparador);

} // fim separadores

int simbolos(char simbolo) // exercicio03
{
    // definir dados
    bool eSimbolo = false;
    // teste
    if (simbolo == '@' || simbolo == ' " ' || simbolo == '^' || simbolo == '~' || simbolo == '¨' || simbolo == '$' || simbolo == '?')
    {
        eSimbolo == false;
    } // fim teste

    return (eSimbolo);

} // fim simbolos

void exercicio03()
{
    // definir dados
    int tamanho = 0;
    char palavra[80];

    // executar
    printf("Qual palavra testar cada simbolo? ");
    scanf("%s", palavra);
    // redefinir
    tamanho = strlen(palavra);

    // enviar simbolo para teste
    for (int i = 0; i < tamanho; i++)
    {
        char simbolo = palavra[i];
        // enviar para cada funcao testar e mostrar resultado
        if (operadorLogico(simbolo))
        {
            printf("%c se trata de operador logico\n", simbolo);
        } // fim teste

        if (operadorAritmetico(simbolo))
        {
            printf("%c se trata de operador aritmetico\n", simbolo);
        } // fim teste

        if (operadorRelacional(simbolo))
        {
            printf("%c se trata de operador relacional\n", simbolo);
        } // fim teste

        if (separadores(simbolo))
        {
            printf("%c se trata de um separdor\n", simbolo);
        } // fim teste

        if (simbolos(simbolo))
        {
            printf("%c se trata de um simbolo\n", simbolo);
        } // fim teste

    } // fim for que mostrara os resultados

    // encerrar
    getchar(); // POR QUE SÓ DEU CERTO COM DOIS GETCHAR??
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio03

/*
  -Tales Rocha Moreira - Matricula 808455
  -exercicio04
- ler um cadeia de caracteres do teclado;
- testar cada símbolo na cadeia, um por vez,
e contar separadamente quantos desses são letras maiúsculas, minúsculas, dígitos e
operadores (lógicos, aritméticos e relacionais) e separadores.
*/

int verificarMaiusculasouM(char simbolo) // exercicio04
{
    // definir dados
    bool maiusculas = false;
    // testar
    if (simbolo >= 'A' && simbolo <= 'Z')
    {
        maiusculas = true;
    }
    return (maiusculas);
} // fim verificar ex 04

int IsDigit(char simbolo) // exercicio04
{
    // definir dados
    bool digito = false;
    // testar
    if (simbolo >= '1' && simbolo <= '9')
    {
        digito = true;
    } // fim teste

    return (digito);
} // fim isDigit

int VerificarMinusculas(char simbolo)
{
    bool minuscula = false;
    if (simbolo >= 'a' && simbolo <= 'z')
    {
        minuscula = true;
    } // fim teste
    return (minuscula);
}

void exercicio04()
{
    // definir dados
    char palavra[80];
    char simbolo;
    int tamanho = 0;
    int maiusculas = 0;
    int minusculas = 0;
    int digitos = 0;
    int aritmeticos = 0;
    int relacionais = 0;
    int countSeparadores = 0;

    printf("Qual palavra testar cada caracter?(se Maiusculo, Minusculou ou simbolo) ");
    scanf("%s", &palavra);

    // redefinir
    tamanho = strlen(palavra);
    // executar e enviar para teste
    for (int i = 0; i < tamanho; i++)
    {
        simbolo = palavra[i];

        if (verificarMaiusculasouM(simbolo))
        {
            maiusculas++;
        }
        if (VerificarMinusculas(simbolo))
        {
            minusculas++;
        }
        if (operadorAritmetico(simbolo))
        {
            aritmeticos++;
        }
        if (operadorRelacional(simbolo))
        {
            relacionais++;
        }
        if (separadores(simbolo))
        {
            countSeparadores++;
        }
        if (isdigit(simbolo))
        {
            digitos++;
        }
        // fim testes

    } // fim envio para funcoes

    // mostrar resultados
    printf("A palavra '%s' , possui %d maiusculas, %d minusculas, %d operadores aritmeticos, %d relacionais, %d separadores e %d digitos\n", palavra, maiusculas, minusculas, aritmeticos, relacionais, countSeparadores, digitos);

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio04

/*
- Tales Rocha Moreira - Matricula 808455
- ler um valor inteiro (n) do teclado;
- ler outros (n) valores reais (x) do teclado, um por vez;
- calcular e mostrar a média dos valores menores que -32.25;
a média dos que estão entre -32.25 e 63.75, inclusive esses;
e a média dos maiores que 63.75. Dizer qual a maior média de todas.
DICA: Definir e usar função para calcular o maior dentre três valores.
*/

double calcularMediaMenores(double numero[], int tamanho) // exercicio05
{
    // definir dados
    double soma = 0.0;
    double media = 0.0;

    // percorrer para acumular soma
    for (int i = 0; i < tamanho; i++)
    {
        // printf("funcMenores%lf\n", numero[i]);
        soma = soma + numero[i];
        // printf("soma: %lf\n", soma);
    }
    // printf("tamanho: %d\n", tamanho);

    //  dividir pelo tamanho para achar media
    media = soma / tamanho;

    // enviar resultados
    return (media);

} // fim calcularMenores

double calcularMediaEntre(double numero[], int tamanho) // exercicio05
{
    // definir dados
    double soma = 0.0;
    double media = 0.0;
    // percorrer para acumular soma
    for (int i = 0; i < tamanho; i++)
    {
        // printf("funcEntre%lf\n", numero[i]);
        soma = soma + numero[i];
    }
    // dividir pelo tamanho para achar media
    media = soma / tamanho;

    // enviar resultados
    return (media);

} // fim calcularEntre

void exercicio05()
{
    // definir dados
    int quantidade = 0;
    int contadorMenores = 0; // definir tamanho para vetor dos menores
    int contadorEntre = 0;   // definir tamanho do vetor dos numero que estao ENTRE

    printf("Quantos valores calcular? ");
    scanf("%d", &quantidade);

    double numeros[quantidade];
    double menores[quantidade];
    double entre[quantidade];

    // adicionar valores para calcular
    for (int i = 0; i < quantidade; i++)
    {
        printf("Entrar com numero para testar: ");
        scanf("%lf", &numeros[i]);
        // printf("Na posicao numeros[%d], esta o %lf\n", i, numeros[i]);

    } // fim adicionar valores

    for (int i = 0; i < quantidade; i++)
    {

        if (numeros[i] < -32.25)
        {
            menores[contadorMenores] = numeros[i];
            // printf("numeros[%d] if(segundo for) = %lf\n", i, numeros[i]);
            // printf("contador menores: %i\n", contadorMenores);
            contadorMenores++;
            // printf("menores[0] = %lf\n", menores[0]);
        }

        if (numeros[i] >= -32.25 && numeros[i] <= 63.75)
        {
            entre[contadorEntre] = numeros[i];
            contadorEntre++;
            // printf("entre%lf\n", numeros[i]);
        }
    }

    // enviar para teste e motrar resultados
    printf("A media entre os numeros menores que -32.25 e: %lf\n", calcularMediaMenores(menores, contadorMenores));
    printf("A media dos numeros entre -32.35 e 63.75 e : %lf\n", calcularMediaEntre(entre, contadorEntre));

    // executar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();

} // fim exercicio05

/*
-Tales Rocha Moreira - Matrícula 808455
- ler dois valores inteiros (a) e (b) do teclado,
- ler outros valores inteiros do teclado, um por vez,
até que o último valor seja igual a (-1).
- para cada valor lido que estiver no intervalo aberto ]a:b[;
calcular e mostrar a soma dos cubos dos inversos (1/x3) dos ímpares.
*/

double verificarIntervaloECalcular(int a, int b, int x) // exercicio06
{
    // definir dados
    double resultado = 0;

    // verificar
    if (x > a && x < b)
    {
        resultado = 1 / pow(x, 3);
    }

    return (resultado);
} // fim verificarIntervalo

void exercicio06()
{
    // definir dados
    int a = 0;
    int b = 0;
    int x = 0; // numero a ser enviado para funcao
    double somaInversos = 0;

    // atribuir dados
    printf("Qual o primeiro valor? ");
    scanf("%d", &a);

    printf("Qual o segundo valor? ");
    scanf("%d", &b);

    // ler outros valores
    do
    {
        printf("\nEntrar com numero para testar e calcular: ");
        scanf("%d", &x);
        if (x % 2 != 0)
        {
            somaInversos = somaInversos + verificarIntervaloECalcular(a, b, x);
        }
    } while (x != -1); // condição de parada
    printf("A soma dos inversos dos cubos das potencias e: %lf\n", somaInversos);

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();

} // fim exercicio06

/*
- Tales Rocha Moreira - Matricula 808455
 - ler dois valores reais (a) e (b) do teclado,
- ler outros valores reais do teclado, um por vez,
até que o último valor seja igual a zero,
e não considerá-lo para os cálculos.
- contar quantos desses valores estão dentro ou fora
do intervalo definido pelo intervalo aberto ]a:b[;
- para os valores fora do intervalo, calcular separadamente
as porcentagens dos que estiverem acima e abaixo do intervalo, nessa ordem.
*/

double CalcularPorcentagem(double contadorIntervalo, double contadorQuantidade) // exercicio07
{
    // definir dados
    double PerCent = 0;
    int x = 0;
    // calcular porcentagem de valors abaico ou acima da quantidade testada
    PerCent = contadorIntervalo / contadorQuantidade * 100;

    // enviar resultados
    return (PerCent);
}

void exercicio07()
{
    // definir dados
    double a = 0;
    double b = 0;
    int quantidade = 0;
    int countAcimaA = 0;
    int countAbaixoB = 0;
    int countDentroAB = 0;
    int countNumeros = 0;
    double x;

    // atribuir
    printf("Qual o limite superior do intervalo? ");
    scanf("%lf", &a);
    printf("Qual o limite inferior do intervalo? ");
    scanf("%lf", &b);

    while (x != 0)
    {
        printf("\nEntrar com valor real para testar: ");
        scanf("%lf", &x);

        if (x < a && x > b)
        {
            countDentroAB++;
        }
        else if (x > a)
        {
            countAcimaA++;
        }
        else if (x < b && x != 0)
        {
            countAbaixoB++;
        }
        countNumeros++;
    }

    printf("Valores dentro do intervalo: %d\n", countDentroAB);
    printf("Porcentagem de valores acima do intevralo: %1.0lf/100\n", CalcularPorcentagem(countAcimaA, countNumeros - 1));
    printf("Porcentagem de valores abaixo do intevalo: %1.0lf/100\n", CalcularPorcentagem(countAbaixoB, countNumeros - 1));

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio07

/*
- ler três valores reais (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens e, nesse caso, o menor e o maior.
*/

int verificarOrdem(double a, double b, double c)
{

    int ordem = 0;
    if (a > b && b > c)
    {
        ordem = 1;
    }
    else if (a < b && b < c)
    {
        ordem = 2;
    }
    else if (a == b && b == c)
    {
        ordem = 3;
    }

    return (ordem);
}

void exercicio08()
{
    // definir dados
    double x = 0;
    double y = 0;
    double z = 0;
    // ler valores
    printf("\nEntrar com primeiro valor: ");
    scanf("%lf", &x);
    printf("Entrar com segundo valor: ");
    scanf("%lf", &y);
    printf("Entrar com terceirto valor: ");
    scanf("%lf", &z);

    switch (verificarOrdem(x, y, z))
    {
    case 0:
        printf("\nOs valores nao estao em nenhuma ordem\n");
        break;
    case 1:
        printf("\nOs valores estao em ordem decrescente\n");
        break;
    case 2:
        printf("\nOs valores estao em ordem crescente\n");
        break;
    case 3:
        printf("\nOs tres valores sao iguais\n");
        break;
    }

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio08

bool verificarCrescente(char a, char b, char c) // exercicio09
{
    // definir dado
    bool crescente = false;
    if (a < b && b < c)
    {
        crescente = true;
    }
    return (crescente);
} // fim

bool verificarDecrescente(char a, char b, char c)
{
    // definir dado
    bool decrescente = false;
    if (a > b && b > c)
    {
        decrescente = true;
    }
    return (decrescente);
} // fim

bool verificarForaOrdem(char a, char b, char c)
{
    // definir dado
    bool outOrdem = false;
    if (a > b && a < b || a < b && b > c || a == b && b == c)
    {
        outOrdem = true;
    }
    return (outOrdem);
} // fim

/*
- Tales Rocha Moreira - Matricula 808455
- ler três caracteres (x,y,z) do teclado, um por vez;
- dizer se esses valores estão em ordem crescente,
decrescente ou em nenhuma dessas ordens.
*/

void exercicio09()
{
    // definir dados
    char a;
    char b;
    char c;
    int nenhuma = 0;

    // ler valores
    printf("\nEntrar com primeiro caractere: ");
    scanf("%c", &a);
    getchar();
    printf("\nEntrar com segundo caractere: ");
    scanf("%c", &b);
    getchar();
    printf("\nEntrar com terceiro caractere: ");
    scanf("%c", &c);
    getchar();

    // realizar testes
    if (a + 1 == b)
    {
        printf("O segundo caractere sucede o primeiro\n");
    }

    if (verificarCrescente(a, b, c))
    {
        printf("Os valores estao em ordem crescente\n");
    }

    if (verificarDecrescente(a, b, c))
    {
        printf("Os valores estao em ordem decrescente\n");
    }
    if (verificarForaOrdem(a, b, c))
    {
        printf("Os valores estao fora de ordem ou sao iguais\n");
    } // fim testes

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim exercicio09

bool compararCadeiasCrescente(char cadeia1[], char cadeia2[], char cadeia3[]) // exercicio10
{
    bool crescente = false;
    if (strcmp(cadeia1, cadeia2) && strcmp(cadeia2, cadeia3) < 0)
    {
        crescente = true;
    }

    return (crescente);

} // fim

bool compararCadeiasDecrescente(char cadeia1[], char cadeia2[], char cadeia3[])
{
    bool decrescente = false;
    if (strcmp(cadeia1, cadeia2) && strcmp(cadeia2, cadeia3) > 0)
    {
        decrescente = true;
    }
    return (decrescente);
} // fim

bool verificarFora(char cadeia1[], char cadeia2[], char cadeia3[])
{
    bool fora = false;
    if (strcmp(cadeia1, cadeia2) < 0 && strcmp(cadeia2, cadeia3) > 0)
    {
        fora = true;
    }
    return (fora);
} // fim

void exercicio10()
{
    // definir dados
    char palavra1[80];
    char palavra2[80];
    char palavra3[80];

    // ler
    printf("Entrar com cadeia 1: ");
    scanf("%s", &palavra1);
    getchar();
    printf("\nEntrar com cadeia 2: ");
    scanf("%s", &palavra2);
    // getchar();
    printf("\nEntrar com cadeia 3: ");
    scanf("%s", &palavra3);
    getchar();

    if (compararCadeiasCrescente(palavra1, palavra2, palavra3))
    {
        printf("As cadeias estao em ordem crescente\n");
    }
    if (compararCadeiasDecrescente(palavra1, palavra2, palavra3))
    {
        printf("As cadeias estao em ordem decrescente\n");
    }
    if (verificarForaOrdem(palavra1, palavra2, palavra3))
    {
        printf("As cadeias estao fora de ordem\n");
    } // fim

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

int main()
{
    printf("R01 - recuperacao01 - Tales Rocha Moreira");

    int x = 0;

    do
    {
        IO_println(" 0 - exercicio00(SAIR)");
        IO_println(" 1 - exercicio01");
        IO_println(" 2 - exercicio02");
        IO_println(" 3 - exercicio03");
        IO_println(" 4 - exercicio04");
        IO_println(" 5 - exercicio05");
        IO_println(" 6 - exercicio06");
        IO_println(" 7 - exercicio07");
        IO_println(" 8 - exercicio08");
        IO_println(" 9 - exercicio09");
        IO_println("10 - exercicio10");

        x = IO_readint("Entrar com a opcao: ");
        printf("\n");

        switch (x)
        {
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}