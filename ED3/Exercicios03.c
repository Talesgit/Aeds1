#include "io.h"
#include <string.h>
#define STR_SIZE 100

void exercicio00()
{
    // nenhuma ação
} // fim metodo00

void exercicio01() // Repetição com teste no início
{

    char palavra[STR_SIZE]; // armazenar uma cadeia de caracteres STR_SIZE - 1
    int tamanho = 0;        // quantidade de caracteres da palavra
    char x = 'A';           // o caractere da palavra
    int y = 0;              // posicao do caractere

    printf("Digitar palavra: ");
    scanf("%s", palavra);

    getchar();

    tamanho = strlen(palavra); // strlen conta caractere por caractere
                               // da cadeia até achar o caractere final, e armazena em tamanho

    for (y >= 0; y < tamanho; y++) // um for para conferir caractere por caractere, se é maiusculo
    // y (a pos do car), tem que ser>= 0, a pos inicial y, tem que ser menor que tamanho, pois o ultimo caractere
    // estoura a memoria e, y++ para adicionar mais uma repetição até que seja verificada o car na pos 0 e fim do loop
    {
        x = palavra[y]; // atribui a x, o valor do caractere que está na posição y,
                        // no caso de y = 0, x será o caractere da palavra na posição 0 da cadeia

        if (('A' <= x) && (x <= 'Z')) // conferir se o caractere x está no intervalo de A e Z maiusculos
        {
            printf("%d: [%c]\n", y, x); // printar o inteiro y que é a posição na cadeia de caracteres, e o caractere maiúsculo x
        }
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");

} // fim exercicio01

void exercicio02()
{

    char palavra[STR_SIZE]; // armazenar uma cadeia de caracteres STR_SIZE - 1
    int tamanho = 0;        // quantidade de caracteres da palavra
    char x = 'A';           // o caractere da palavra
    int y = 0;              // posicao do caractere
    int quantidadeCar = 0;

    printf("Digitar palavra: ");
    scanf("%s", palavra);

    getchar();

    tamanho = strlen(palavra); // strlen conta caractere por caractere
                               // da cadeia até achar o caractere final, e armazena em tamanho

    for (y = 0; y < tamanho; y++) // um for para conferir caractere por caractere, se é maiusculo
    // y (a pos do car), tem que ser>= 0, a pos inicial y, tem que ser menor que tamnho, pois o ultimo caractere
    // estoura a memoria e, y++ para adicionar mais uma repetição até que seja verificada o car na pos 0 e fim do loop
    {
        x = palavra[y]; // atribui a x, o valor do caractere que está na posição y,
                        // no caso de y = 0, x será o caractere da palavra na posição 0 da cadeia

        if (('A' <= x) && (x <= 'Z')) // conferir se o caractere x está no intervalo de A e Z maiusculos
        {
            printf("%d: [%c]\n", y, x); // printar o inteiro y que é a posição na cadeia de caracteres, e o caractere maiúsculo x
            quantidadeCar++;
        }
    }
    printf("Quantidade de letras maiusculas %d\n", quantidadeCar);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio03()
{

    char palavra[STR_SIZE]; // armazenar uma cadeia de caracteres STR_SIZE - 1
    int tamanho = 0;        // quantidade de caracteres da palavra
    char x = 'A';           // o caractere da palavra
    int y = 0;              // posicao do caractere
    int quantidadeCar = 0;

    printf("Digitar palavra: ");
    scanf("%s", palavra);

    getchar();

    tamanho = strlen(palavra); /* strlen conta caractere por caractere
                                da cadeia até achar o caractere final, e armazena em tamanho*/

    for (y = tamanho - 1; y >= 0; y--) /* um for para conferir caractere por caractere, se é maiusculo
  y(pos inicial), teve de ser = ao tamanho - 1 pois, se x = 0, começaria do primeiro caractere,
  y = tamanho -1, significa que está começando do último caractere, e y>=0, para parar caso chegue nesse valor*/
    {
        x = palavra[y]; /* atribui a x, o valor do caractere que está na posição y,
                         no caso de y = 0, x será o caractere da palavra na posição 0 da cadeia*/

        if ((x <= 'Z') && ('A' <= x)) // conferir se o caractere x está no intervalo de A e Z maiusculos
        {
            printf("%d: [%c]\n", y, x); // printar o inteiro y que é a posição na cadeia de caracteres, e o caractere maiúsculo x
            quantidadeCar++;
        }
    }
    printf("Quantidade de letras maiusculas %d\n", quantidadeCar);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio04()
{

    char palavra[STR_SIZE]; // armazenar uma cadeia
    int tamanho = 0;        // o numero de caracteres da palavra
    char x = 'A';           // o caractere a ser analisado
    int y = 0;              // a posicao de 0 a tamanho -1 do caractere
    int contador = 0;       // ira dentro do if para repetir e printar e a quantidade de vezes que forem verdadeiras o loop(no caso quantas maius ou min)

    printf("Digitar palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra); /*para que tamanho seja o num de carac da palavra, e necessario contar
    a quantidade de carac com o strlen*/

    /*FOR COM IF PARA PERCORRER ANALISANDO CARACTERE P/ CARACTERE*/

    /*for(POS INICIAL; CONDICAO DE PARADA; REPETIR CRESCER OU DECRESCER)*/
    for (y = 0; y < tamanho; y++)
    {
        /*É NECESSÁRIO DEFINIR QUE x E QUAL CARACTERE QUE ESTA NA POSICAO y*/
        x = palavra[y]; // no caso de y = 0, primeiro caractere, y = 1, segundo caractere, e assim por diante

        if (('A' <= x) && (x <= 'Z') || ('a' <= x) && (x <= 'z')) // se x está entre A e Z ou entre a e z, para printar tanto maiusculas quanto minusculas
        // nesse if, automaticamente ele ignorará os caracteres especiais como num ou @
        {
            printf("%d: [%c]\n", y, x); // printar y(pos): x(caractere da posicao)
            contador++;                 // ele adicionara um valor a cada vez que for verdadeiro e executado o if
        }
    }
    printf("A quantidade de maiusculas e minusculas e %d", contador); // printar o contador com a quantidade de vezes que o if foi true, fora do loop para nao repetir o print

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio05()
{

    char palavra[STR_SIZE];
    int tamanho = 0;
    int y = 0; // posicao do caracter

    printf("Palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    for (y = tamanho - 1; y >= 0; y--)
    {
        printf("%d: [%c]\n", y, palavra[y]);
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio06()
{

    char palavra[STR_SIZE];
    int tamanho = 0;
    int y = 0; // posicao do caracter
    int x = 0; // palavra[y]

    printf("Palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);

    for (y = tamanho - 1; y >= 0; y--)
    {
        x = palavra[y];
        if ((x < 'A' || x > 'Z') && (x < 'a' || x > 'z') && (x < '0' || x > '9'))
        {
            printf("%d: [%c]\n", y, palavra[y]);
        }
    }
    // encerrar
    IO_pause("Apertar ENTER para continuar");
} // fim ex 6

void exercicio07()
{
    int superior = 0;
    int inferior = 0;

    int tamanho = 0;  // a quantidade de valores no seu vetor(espaco)
    int x = 0;        // armazenar os valores lidos de quantidade do vetor (valor a ser testado)
    int y = 0;        // a posicao do valor detro do vetor
    int contador = 0; // contar quantos valores se repetem

    printf("Limite superior: ");
    scanf("%d", &superior);

    printf("Limite inferior: ");
    scanf("%d", &inferior);

    printf("Quantidade de elementos dentro vetor(tamanho do vetor): ");
    scanf("%d", &tamanho);
    // declarar vetor reservando espaço na memoria para tamanho elementos que o usuario quiser
    int numero[tamanho]; // declaracao de vetor (apenas inteiros no caso)  OBS: o tamanho do meu vetor será lido no scanf

    for (y = 0; y < tamanho; y++) // o for percorre todas as posicoes do vetor, e com o printf e scanf, adiciona o dado a uma posicao
    {
        printf("\nDigite um valor para x: ");
        scanf("%d", &x);
        numero[y] = x; // o valor lido de x, é igual a uma posicao dentro do vetor, no caso de y = 0, e' na posicao 0
        // nao e necessario colocar numero[tamanho], pois o for executara e armazenara x em numero tamanho vezes

        printf("\nvalor de x na posicao %d: %d", y, numero[y]);
    }
    // ate aqui, populou as 7 posicoes dentro do vetor (para verificar quais sao multiplos de 3 e, dentro do intervalo)

    for (y = 0; y < tamanho; y++) // para percorrer todas as posicoes do vetor
    {
        x = numero[y]; // x e igual a uma posicao dentro do vetor

        // o if a seguir estara se repetindo tamanho vezes, para verificar cada valor de x(posicao dentro do vetor numero) para verificar a condicao de cada dado

        if ((x % 3 == 0) && (x >= inferior && x <= superior)) // verficar IF x e multiplo de 3 e, se x esta no intervalo
        {
            printf("\nE multiplo de 3, e esta no intervalo entre lim superior e inferior o valor que esta na posicao %d: %d", y, x);
            contador++; // contador para mostrar quantos dos valores lidos passaram no teste de condicao
        }
    }

    printf("\nA quantidade de valores lidos que satisfazem a condicao foram %d:", contador);
    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio08()
{
    int Lsuperior = 0;
    int Linferior = 0;
    int quantidade = 0; // ler do teclado a quantidade de numeros a serem testados, e´o tamanho (a quantidade de espacos) do array
    int x = 0;          // numero lido a ser adicionado dentro do vetor

    printf("Limite superior: ");
    scanf("%d", &Lsuperior);
    printf("Limite inferior: ");
    scanf("%d", &Linferior);

    printf("Quantos numeros testar(tamanho do vetor): ");
    scanf("%d", &quantidade);

    int cadeia_de_num_para_testes[quantidade]; // a quantidade de valores da cadeia de num sera dada na leitura de quantidade

    // for para popular (ler) com numeros do teclado cada posicao do vetor

    for (int y = 0; y < quantidade; y++) // int y foi necessario pq ele percorre cada pos do vetor armazenando o valor lido
    {

        printf("\nNumero %d para ser adicionado dentro do vetor: ", y + 1); // troquei por y para testar colocar direto no vetor, sem precisar atribuir a x, +1 para nao aparecer numero 0 do vetor
        scanf("%d", &cadeia_de_num_para_testes[y]);
        // cadeia_de_num_para_testes[y] = x; // x (o numero lido do teclado) foi armazenado em uma posicao dentro do vetor quantidade

        printf("\nO valor de x na posicao %d e : %d", y, cadeia_de_num_para_testes[y] /*pois x foi armazenado nessa posicao*/);
        // o printf sera repetido para todas as posicoes de todos os numeros pois o for sera repetido tamanho vezes
    }

    // E NECESSARIO OUTRO FOR PARA TESTAR AS CONDICOES NO IF, POIS TERA DE SER TESTADO CADA NUMERO DO VETOR

    for (int y = 0; y < quantidade; y++)
    {
        if ((cadeia_de_num_para_testes[y] % 2 == 0) && (cadeia_de_num_para_testes[y] % 5 != 0) && (cadeia_de_num_para_testes[y] >= Linferior && y <= Lsuperior))
        {
            printf("\nOs numeros que sao multiplos de 2 e nao multiplos de 5 e estao no intervalo sao:, %d: na posicao: %d", cadeia_de_num_para_testes[y], y);
        }
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio09()
{
    double a = 0;
    double b = 0;
    int quantidade_numeros; // tamanho, capacidade de armazenamento
    int y = 0;              // posicao dentro do vetor

    printf("Qual o valor de a?: ");
    scanf("%lf", &a);

    printf("Qual o valor de b?: ");
    scanf("%lf", &b);

    printf("Quantidade de numeros(quantidade dentro do vetor): ");
    scanf("%d", &quantidade_numeros);

    double cadeia_numeros[quantidade_numeros]; // teve de ser definido depois, pois quantidade já tem um valor atribuido

    if (a < b) // para so executar caso a < b , caso contrario (else), printar invalido
    {
        for (y = 0; y < quantidade_numeros; y++) // para popular cada posicao do tamanho da cadeia_numeros de acordo com quantidade_numeros4
        {
            printf("\nNumero para ser testado e adicionado dentro do vetor: ");
            scanf("%lf", &cadeia_numeros[y]); // armazenar o valor lido na cadeia de numeros, em uma posicao de acordo com o y, que esta percorrendo uma posicao a cada rep

            printf("\nO numero da posicao %d e : %lf", y, cadeia_numeros[y]);
        }

        for (y = 0; y < quantidade_numeros; y++)
        {

            int x = floor(cadeia_numeros[y]);

            if ((x % 2 == 0) && (x >= a && x <= b))
            {
                printf("\nOs valores cujas partes inteiras sao pares e fazem parte do intervalo sao: %d ", x);
            }
        }
    }
    else
    {
        printf("Opcao invalida para a e b\n");
        printf("\na tem de ser menor que b");
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

void exercicio10()
{
    float num1 = 0;
    float num2 = 0;
    int quantos = 0;

    printf("Qual o valor do Num 1(superior)?: ");
    scanf("%f", &num1);

    printf("\nE o Num 2(inferior?): ");
    scanf("%f", &num2);

    printf("\nQuantos numeros serao testados(tamanho do vetor)?: ");
    scanf("%d", &quantos);

    float caixa[quantos];

    if (num1 >= 0 && num2 <= 1)
    {
       for(int i = 0; i < quantos; i++)
       {
        //popular o vetor(caixa de numeros)
        printf("\nQual o %d valor a ser adicionado para ser testado?: ", i + 1);
        scanf("%f", &caixa[i]);

        printf("Esta na posicao %d do vetor, o numero %f", i, caixa[i]); //printf colocado aqui para não repetir o texto no loop, apenas os numeros
       }

       printf("\nOs numeros que satisfazem o pedido(parte fracionaria fora do intervalo do num1 e num2) sao: ");
      
      for (int i = 0; i < quantos; i++)
      {
       int parte_inteira = floor(caixa[i]);
       float parte_fracionaria = caixa[i] - parte_inteira;

       if(parte_fracionaria > num1 || parte_fracionaria < num2 )
       {
        printf("\n%f" , caixa[i]);
       }

      }
    }
    else
    {
        printf("Valores invalidos, num1 deve ser >= 0, e num2 <= 1");
    }
    IO_pause("Aperte ENTER para continuar");
}

void exercicio03E1()
{

int i = 0; //contador for
char linha[50];
printf("Insira uma linha de texto (max 49 caracteres): ");
fgets(linha, 50, stdin); //pois scanf para de ler quando encontra um espaço em branco
 
 printf("Todos os simbolos nao alfanumericos sao: ");

for ( i = 0; i < 50; i++)
{
  if ((linha[i] < '0' || linha[i] > '9') && (linha[i] < 'a' || linha[i] > 'z') && (linha[i] < 'A' || linha[i] > 'Z'))// poderia ser substituido por !isalnum
  {
    printf("%c", linha[i]);
  }
}

}

void exercicio03E2()
{
    int i = 0; //contador
    char frase[80];
    printf("Digite uma sequencia que contem apenas simbolos que nao sao letras: ");
    fgets(frase, 80, stdin);

    bool sem_letras = false;

    for(i = 0; i < strlen(frase); i++)
    {
        if (!(frase[i] >= 'a' || frase[i] <= 'z') && !(frase[i] >= 'A' || frase[i] <= 'Z'))
        {
            sem_letras = true;
        }
    }

    if (sem_letras)
    {
        printf("A sequencia nao possui letras, esta correta");
    }
    else
    {
      printf("A sequencia possui letras");
    }
}

void exercicioAleatorio()
{
    // ler e calcular a media de 8 notas de uma aluno de física
    float notas[8];
    float soma = 0.00;
    float media;
    int ct = 0;
    // popular o vetor informando as notas
    for (ct = 0; ct < 8; ct++)
    {
        printf("Nota da %d prova: ", ct + 1);
        scanf("%f", &notas[ct]);
        getchar();
        // para somar, fazer na repeticao soma + a nota
        soma = soma + notas[ct]; // igual a soma += notas[ct]
    }

    media = soma / 8;

    printf("Media para ser aprovado: ");
    scanf("%d", &ct);

    if (media > ct)
    {
        printf("Aprovado em fisica");
        printf("\nMedia: %f", media);
    }
    else
    {
        printf("Reprovado");
        printf("\nMedia: %f", media);
    }

    // encerrar
    IO_pause("Apertar ENTER para continuar");
}

int main()
{
    int x = 0;

    // método para repetição até parar "do-while"
    do
    {
        IO_id("\nEXERCICIOS-Programa - v0.0");

        // ler do telcado
        IO_println("Opcoes");
        IO_println("0-parar");
        IO_println("Exercicio 1");
        IO_println("Exercicio 2");
        IO_println("Exercicio 3");
        IO_println("Exercicio 4");
        IO_println("Exercicio 5");
        IO_println("Exercicio 6");
        IO_println("Exercicio 7");
        IO_println("Exercicio 8");
        IO_println("Exercicio 9");
        IO_println("Exercicio 10");
        IO_println("Exercicio 03E1(11)");
        IO_println("Exercicio 03E2(12)");
        IO_println("Exercicio Aleatorio(13)");

        x = IO_readint("Ir para exercicio:");

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
        case 11:
            exercicio03E1();
            break;
        case 12:
            exercicio03E2();
            break;
        case 13:
            exercicioAleatorio();
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