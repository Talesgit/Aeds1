#include "io.h"
/*
Exercícios ED04
Tales Rocha Moreira - 14/04/2023
*/

void exercicio00()//Nao faz nada
{
}

int estaNoIntervalo(double x, double y, double num)
{
     bool NoIntervalo = false;
     if (num >= y && num <= x)
     {
          NoIntervalo = true;
     }
     return (NoIntervalo);
} // fim funcao estaNoIntervalo

void exercicio01()
{
     double num1 = 0; // limite superior
     double num2 = 0; // limite inferior
     int valores = 0; // numeros lidos para serem testados
     int i = 0;       // contador for
     double numero = 0;
     int contador = 0;  // contar a quantidade de vezes que o if e verdadeiro
     int contador2 = 0; // contar o else

     printf("Entrar com o limite superior do intevalo: ");
     scanf("%lf", &num1);

     printf("Entrar com o limite inferior do intevalo: ");
     scanf("%lf", &num2);

     printf("Quantos valores serao testados?: ");
     scanf("%d", &valores);

     double testes[valores]; // os numeros do teste

     for (i = 0; i < valores; i++)
     {
          numero = testes[i];
          printf("Numero a ser testado: ");
          scanf("%lf", &numero);

          if (estaNoIntervalo(num1, num2, numero))
          {
               contador++;
          }
          else
          {
               contador2++;
          }
     }
     printf("Numeros que estao no intervalo: %d\n ", contador);
     printf("\nNumeros que estao FORA do intervalo: %d\n ", contador2);

} // fim exercicio01

bool MenorQueK(char letra)
{
     bool result = false;
     if ((letra >= 'A' && letra <= 'Z') && letra < 'K')
     {
          result = true;
     }

     return (result);
} // fim funcao MenorQueK

void exercicio02()
{
     int tamanho = 0;  // quantidade de letras da palavra
     int i = 0;        // caractere da posicao analisada pelo for (ou while)
     char letra = 'a'; // isolar a letra
     int contador = 0; // contar quantas fazem a condicao

     char palavra[tamanho];
     printf("Entrar com uma palavra: ");
     scanf("%s", palavra);

     tamanho = strlen(palavra);

     for (i = 0; i < tamanho; i++)
     {
          if (MenorQueK(palavra[i]))
          {
               printf("%c\n", palavra[i]);
               contador++;
          }
     }

     printf("Quantas letras maiusculas sao menores que 'K' : %d\n", contador);
} // Fim Exercicio 2

bool MenorQueKComVetor(char palavra[])
{
     bool result = false;

     int tamanho = strlen(palavra); // quantidade de letras da palavra
     int contador = 0;              // contar quantas fazem a condicao

     for (int i = 0; i < tamanho; i++)
     {
          if (MenorQueK(palavra[i]))
          {
               result = true;
               contador++;
          }
     }
     printf("Ha %d letras maiusculas menores que K na palavra: %s\n", contador, palavra);
} // fim funcao menor que k com vetor

void exercicio03()
{
     char palavra[100];

     printf("Entrar com uma palavra: ");
     scanf("%s", &palavra);

     if (MenorQueKComVetor(palavra))
     {
     
     }
} // fim exercicio03

bool MenorQueKComVetorLetras(char palavra[])
{
     bool result = false;

     int tamanho = strlen(palavra); // quantidade de letras da palavra
     int contador = 0;              // contar quantas fazem a condicao

     printf("As letras maiusculas menores que K na palavra sao: ");

     for (int i = 0; i < tamanho; i++)
     {
          if (MenorQueK(palavra[i]))
          {
               result = true;
               contador++;
               printf("%c ", palavra[i]);
          }
     }
     return (MenorQueKComVetorLetras);

} // fim funcao menor que k com vetor

void exercicio04()
{
     char palavra[100];

     printf("Entrar com a palavra: ");
     fgets(palavra, 100, stdin);

     if (MenorQueKComVetorLetras(palavra))
     {

     }
} // fim exercicio04

bool MenorQueKk(char palavra[])
{
     bool result = false;
     int tamanho = strlen(palavra); // ler a quantidade de carcateres da palavra
     int contador = 0;              // contar a quantidade de vezes que o if e executado

     printf("A quantidade de letras menores que k ou K e: ");

     for (int i = 0; i < tamanho; i++)
     {
          char letra = palavra[i];
          if  ( (letra >= 'a' && letra <'k') || (letra >= 'A' && letra < 'K') )
          {
               result = true;
               contador++;
          }
     }//fim for

     printf("%d", contador);
     return(result);

}//fim funcao MenorQueKk

void exercicio05()
{
     char palavra[100];

     printf("Entrar com a palavra: ");
     fgets(palavra, 100, stdin);

     if (MenorQueKk(palavra))
     {

     }//fim if

}//fim exercicio05


bool MostrarMenorQueKk(char palavra[])
{
     bool result = false;
     int tamanho = strlen(palavra); // ler a quantidade de carcateres da palavra
     int contador = 0;              // contar a quantidade de vezes que o if e executado

     printf("As letras menores que k ou K sao: ");

     for (int i = 0; i < tamanho; i++)
     {
          char letra = palavra[i];
          if  ( (letra >= 'a' && letra <'k') || (letra >= 'A' && letra < 'K') )
          {
               result = true;
               contador++;
               printf("%c", letra);
          }
     }//fim for

     return(result);

}//fim funcao MostrarMenorQueKk

void exercicio06()
{
     char palavra[100];

     printf("Entrar com a palavra para mostrar maiores que K: ");
     fgets(palavra, 100, stdin);

     if(MostrarMenorQueKk(palavra))
     {

     }

}//fim exercicio06



bool isDigitimpar(char x)
{
bool result = false;

if (x >= '0' && x <= '9')
{
     if(x % 2 != 0)
     {
          result = true;
     }
}
 return(result);
}

void exercicio07()
{
chars palavra = IO_new_chars(STR_SIZE);
int tamanho = 0; //lido no strlen
int posicao = 0; //contada no for
char simbolo = '_'; //receber atribuicao de palavra
int contador = 0; //contar no if, a quantidade de vezes que for verdadeira

//ler do teclado
palavra = IO_readstring("Entrar com caracteres: ");
//ler tamanho(quantidade)
tamanho = strlen(palavra);

//for para percorrer o vetor e verificar a condicao no if
for (posicao = 0; posicao < tamanho; posicao++)
{
     simbolo = palavra[posicao]; //atribuir a var o caracter dentro do vetor em dada posicao

     if(isDigitimpar(simbolo))
     {
          contador++; //para continuar verificando todos os carcteres
     }
}// fim for

     //mostrar a quantidade dos digitos 
     IO_printf("\nQuantiade de digitos impares: %d", contador);
     //encerrar
     IO_pause("Aperte ENTER para continuar");
}//fim exercicio07()

bool NaoAlfanum(char x)
{
     bool result = false;
     
        if ((x < 'A' || x > 'Z') && (x < 'a' || x > 'z') && (x < '0' || x > '9'))
        {
          result = true;
        }

}

void exercicio08()
{
     char palavra[100];
     int tamanho = 0;
     int i = 0;//contador
     int simbolo = 0;

     printf("Entrar com a palavra: ");
     fgets(palavra, 100, stdin);

     tamanho = strlen(palavra);

     printf("Digitos nao alfanumericos sao: ");
     for ( i = 0; i < tamanho; i++)
     {
          simbolo = palavra[i];
          if(NaoAlfanum(simbolo))
          {
            printf("[%c]\n:", palavra[i]);
          }
     }
}

bool IsAlfanum(char x)
{
     bool result = false;
     
        if ((x > 'A' || x < 'Z') && (x > 'a' || x < 'z') && (x > '0' || x < '9'))
        {
          result = true;
        }
        else
        {
          result = false;
        }

}

void exercicio09()
{
     char palavra[100];
     int tamanho = 0;
     int i = 0;//contador
     int simbolo = 0;

     printf("Entrar com a palavra: ");
     fgets(palavra, 100, stdin);

     tamanho = strlen(palavra);

     printf("Digitos que sao alfanumericos sao: ");
     for ( i = 0; i < tamanho; i++)
     {
          simbolo = palavra[i];
          if(IsAlfanum(simbolo))
          {
            printf("[%c]\n:", palavra[i]);
          }
     }
}

void exercicio10()
{
}
int main()
{
     int x = 0;

     do
     {
          // escolher exercicio com o readint
          IO_println("\nexercicio 00");
          IO_println("exercicio 01");
          IO_println("exercicio 02");
          IO_println("exercicio 03");
          IO_println("exercicio 04");
          IO_println("exercicio 05");
          IO_println("exercicio 06");
          IO_println("exercicio 07");
          IO_println("exercicio 08");
          IO_println("exercicio 09");
          IO_println("exercicio 10");

          x = IO_readint("Ir para exercicio: ");

          // escolher exercicio

          switch (x)
          {
          case 0:
               exercicio00();
               break;
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
               break;
          }

     } while (x != 0);
     IO_pause("Aperte ENTER para sair");
}