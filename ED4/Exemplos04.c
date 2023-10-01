#include "io.h"

void exemplo00()
{

}

void exemplo01()
{

// definir dado
int quantidade = 0;
int valor = 0;
int controle = 0;
// identificar
IO_id ( "EXEMPLO0401 - Method01 - v0.0" );
// ler do teclado
quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
controle = 1;
while ( controle <= quantidade )
{
// ler valor do teclado
valor = IO_readint ( IO_concat (IO_concat ("",  IO_toString_d ( controle ) ),": " ) );
// passar ao proximo valor
controle = controle + 1;
} // fim repetir
// encerrar
IO_pause ( "Apertar ENTER para continuar" );


}

/**
Funcao para determinar se valor inteiro e' positivo.
@return true, se positivo; false, caso contrario
@param x - valor a ser testado
*/

bool positive ( int x ) //definir a funcao
{
  bool result = false;

  if (x > 0)
  {
     result = true;
  }
  return(result);
}

void exemplo02()
{

// definir dado
int quantidade = 0;
int valor = 0;
int controle = 0;
int contador = 0;
// identificar
IO_id ( "EXEMPLO0402 - Method02 - v0.0" );
// ler do teclado
quantidade = IO_readint ( "Entrar com uma quantidade: " );
// repetir para a quantidade de vezes informada
controle = 1;

while ( controle <= quantidade )
{
// ler valor do teclado
valor = IO_readint ( IO_concat (
IO_concat ( "", IO_toString_d ( controle ) ),
": " ) );
// testar e contar se valor for positivo
if ( positive ( valor ) )
{
contador = contador + 1;
} // fim se
// passar ao proximo valor
controle = controle + 1;
} // fim repetir

// mostrar a quantidade de valores positivos
IO_printf ( "%s%d\n", "Positivos = ", contador );
// encerrar
IO_pause ( "Apertar ENTER para continuar" );

}

/**
Funcao para determinar se valor inteiro pertence a intervalo aberto.
@return true, se pertencer; false, caso contrario
@param x - valor a ser testado
*/   
 
 bool belongsTo(int x, int inferior, int superior) //definir a funcao
 {
     bool result = false;
     
     if (inferior < x && x < superior)
     {
       result = true;
     }
     return(result);
 }

void exemplo03()
{
int quantidade = 0;
int valor = 0;
int controle = 0;
int contador = 0;

IO_id("EXEMPLO0403-Method03- v0.0");

quantidade = IO_readint("Entrar com uma quantidade: ");

controle = 1;
while(controle <= quantidade)
{
     valor = IO_readint (IO_concat (IO_concat ("", IO_toString_d (controle)),":"));
     if(belongsTo(valor, 0, 100))
     {
          contador = contador + 1;
     }
     controle = controle + 1;
}// fim while
IO_printf("%s%d\n", "Positivos menores que 100 = ", contador);

IO_pause("Apertar ENTER para continuar");
}//fim exemplo 03

/**
Funcao para determinar se valor inteiro e' par.
@return true, se par; false, caso contrario
@param x - valor a ser testado
*/

bool even ( int x )
{
     bool result = false;

     if ( x % 2 == 0 )
     {
          result = true;
     }
     return (result);
}// fim def even

void exemplo04()
{
int quantidade = 0;
int valor = 0;
int controle = 0;
int contador = 0;

IO_id("EXEMPLO0404- v0.0");

quantidade = IO_readint("Entrar com uma quantidade: ");

controle = 1;
while (controle <= quantidade)
{
     valor = IO_readint(IO_concat(IO_concat("", IO_toString_d(controle)),":"));
     if (belongsTo (valor, 0, 100) && even (valor))
     {
          contador++;
     }
     controle++;
}
 IO_printf("\nNumeros que sao pares e menores que 100: %d", contador);

 IO_pause("Apertar ENTER para continuar");

}

//Exemplo 5- Ler valores e contar positivos menores que 100 e pares(alternativo do 4)
void exemplo05()
{
// definir dado
int quantidade = 0;
int valor = 0;
int controle = 0;
int contador = 0;
bool ok = false;

// identificar
IO_id ( "EXEMPLO0405 - Method05 - v0.0" );
// ler do teclado
quantidade = IO_readint ( "Entrar com uma quantidade: " );

// repetir para a quantidade de vezes informada
controle = 1;
while ( controle <= quantidade )
{
// ler valor do teclado
valor = IO_readint ( IO_concat (
IO_concat ( "", IO_toString_d ( controle ) ),
": " ) );
// testar e contar se valor for positivo menor que 100 e par
ok = belongsTo ( valor, 0, 100 );
ok = ok && even ( valor );
if ( ok )
{
contador = contador + 1;
} // fim se
// passar ao proximo valor
controle = controle + 1;
} // fim repetir
// mostrar a quantidade de valores que satisfazem a condicao
IO_printf("%s%d\n", "Positivos menores que 100 e pares: ", contador);

IO_pause("Aperte ENTER para continuar");
}


/*Funcao para determinar se caractere e´letra minuscula.
*/
 bool isLowerCase (char x)
 {
     bool result = false;

     if('a' <= x && x <= 'z')
     {
          result = true;
     }
     return(result);
 }//fim IslowerCase

void exemplo06()
{
     
// definir dado
chars palavra = IO_new_chars ( STR_SIZE );
int tamanho = 0;
int posicao = 0;
char simbolo = '_';
int contador = 0;

// identificar
IO_id ( "EXEMPLO0406 - Method06 - v0.0" );
// ler do teclado
palavra = IO_readstring ( "Entrar com uma palavra: " );

// determinar a quantidade de simbolos na palavra
tamanho = strlen ( palavra );

// repetir para a quantidade de caracteres lidos de palavra
for ( posicao = 0; posicao < tamanho; posicao = posicao + 1 )
{
// isolar um simbolo por vez
simbolo = palavra [ posicao ];

// testar e contar se caractere e' letra minuscula
if ( isLowerCase ( simbolo ) )
{
contador = contador + 1;
} // fim se
} // fim repetir
// mostrar a quantidade de minusculas
IO_printf ( "%s%d\n", "Minusculas = ", contador );
// encerrar
IO_pause ( "Apertar ENTER para continuar" );

} // fim method06 ( )


//Method 7 - Ler palavra, contar e mostrar letras minusculas
void exemplo07()
{
chars palavra = IO_new_chars ( STR_SIZE );
int tamanho = 0;
int posicao = 0;
char simbolo = '_';
int contador = 0;

IO_id ( "EXEMPLO0407 - Method07 - v0.0" );

palavra = IO_readstring("Entrar com uma palavra: ");

// quantidade de simbolos
tamanho = strlen(palavra);

for(posicao = 0; posicao < tamanho; posicao++)
{
     simbolo = palavra[posicao]; //isolar um simbolo por vez
     if (isLowerCase(simbolo))
     {
        IO_printf("%c", simbolo);
        contador++;
     }
}
IO_printf("\n%s%d\n", "Minusculas = ", contador);

IO_pause("Apertar ENTER para continuar");

}

//Ler palavra, contar e mostrar letras maisculas(alternativo)
void exemplo08()
{
chars palavra = IO_new_chars(STR_SIZE);
int tamanho = 0;
int posicao = 0;
int simbolo = '_';
int contador = 0;
chars minusculas = IO_new_chars(STR_SIZE);

strcpy(minusculas, STR_EMPTY); //vazio

IO_id("EXEMPLO0408 - Method08-v0.0");

palavra = IO_readstring("Entrar com uma palavra: ");

tamanho = strlen(palavra);

for(posicao = 0; posicao <= tamanho; posicao++)
{
  simbolo = palavra[posicao];

  if(isLowerCase(simbolo))
  {
     //concatenar simbolo encontrado
     minusculas = IO_concat(minusculas, IO_toString_c(simbolo));
     //contar
     contador++;
  }//fim if
}//fim for

IO_printf("\nMinusculas = %d [%s]\n",contador, minusculas);

IO_pause("Apertar ENTER para continuar");
}


/*Method09 - Ler palavra e contar os algarismos.
Funcao para determinar se caractere e´digito */
bool isDigit(char x)
{
bool result = false;

if (x >= '0' && x <= '9')
{
     result = true;
}
 return(result);
}

void exemplo09()
{
chars palavra = IO_new_chars(STR_SIZE);
int tamanho = 0; //lido no strlen
int posicao = 0; //contada no for
char simbolo = '_'; //receber atribuicao de palavra
int contador = 0; //contar no if, a quantidade de vezes que for verdadeira

//identificar
IO_id("EXEMPLO0409-Method09_v0.0");
//ler do teclado
palavra = IO_readstring("Entrar com caracteres: ");
//ler tamanho(quantidade)
tamanho = strlen(palavra);

//for para percorrer o vetor e verificar a condicao no if
for (posicao = 0; posicao < tamanho; posicao++)
{
     simbolo = palavra[posicao]; //atribuir a var o caracter dentro do vetor em dada posicao

     if(isDigit(simbolo))
     {
          //mostrar o caracter que e´digito
          IO_printf("%c\n", simbolo);
          contador++; //para continuar verificando todos os carcteres
     }
}// fim for

     //mostrar a quantidade dos digitos 
     IO_printf("\nQuantiade de algarismos(digitos): %d", contador);
     //encerrar
     IO_pause("Aperte ENTER para continuar");
}//fim metodo09()

/* Funcao para concatenar a cadeia de caracteres mais um digito*/

chars concatADigit(chars string, char digit)
{
     return(IO_concat (string, IO_toString_c (digit)));
}//fim de concatADigit


bool isADigit ( char x )
{
return ( '0' <= x && x <= '9' );
} // fim isADigit ( )

void exemplo10()
{
chars palavra = IO_new_chars (STR_SIZE);
int tamanho = 0;
int posicao = 0;
char simbolo = '_';
chars digitos = IO_new_chars(STR_SIZE);

strcpy(digitos, STR_EMPTY); //vazio

//identificar
IO_id("EXEMPLO0410-Method10-v0.0");
//ler do teclado

palavra = IO_readstring("Entrar com caracteres: ");
//determinar tamanho
tamanho = strlen(palavra);

for(posicao = 0; posicao < tamanho; posicao++)
{
   //isolar um simbolo por vez
   simbolo = palavra[posicao];
   if (isADigit(simbolo))
   {
     digitos = concatADigit(digitos, simbolo);
   }
}//fim for

//mostrar a quantidade de digitos
IO_printf("Quantidade de algarismos: %d: Sao eles : %s", strlen(digitos), digitos);

//encerrar
IO_pause("Apertar ENTER para continuar");
}//fim metodo10

int main()
{
    int x = 0;

    do
    {
        //escolher exemplo com o readint
        IO_println("Exemplo 00");
        IO_println("Exemplo 01");
        IO_println("Exemplo 02");
        IO_println("Exemplo 03");
        IO_println("Exemplo 04");
        IO_println("Exemplo 05");
        IO_println("Exemplo 06");
        IO_println("Exemplo 07");
        IO_println("Exemplo 08");
        IO_println("Exemplo 09");
        IO_println("Exemplo 10");

        x = IO_readint("Ir para exemplo: ");

        //escolher exemplo

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
            break;
        }

    } while (x != 0);
    IO_pause("Aperte ENTER para sair");
}