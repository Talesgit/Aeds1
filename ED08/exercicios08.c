// ED08 Exercicios - Tales Rocha Moreira

#include "io.h"

void exercicio00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exercicio01()
{
    // definir dados
    int x = 0;
    int n = 0; // para ser testado antes de entrar no arranjo

    // definir tamanho de um vetor
    printf("Qual o tamanho do arranjo?(positivo e par) ");
    scanf("%d", &x);

    // definir dado
    int arranjo[x];

    // executar
    if (x > 0 && x % 2 == 0)
    {
        for (int i = 0; i < x; i++) // percorrer o arranjo
        {
            printf("Entrar com numero par e positivo dentro do arranjo: ");
            scanf("%d", &n); // atribuir a n

            if (n >= 0 && n % 2 == 0) // verificar se satisfaz condicao
            {
                arranjo[i] = n; // preencher a posicao
            }
            else
            {
                printf("Valor invalido, deve ser positivo e par\n");
                i = i - 1; // para voltar uma posicao e popular corretamente a posicao
            }
        } // fim for

        // mostrar arranjo
        printf("Valores dentro do arranjo:\n");
        for (int i = 0; i < x; i++)
        {
            printf("%d\n", arranjo[i]);

        } // fim for para mostrar arranjo
    }
    else
    {
        printf("Valor invalido, digite par ou negativo\n");
        getchar();
    }

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio01

void exercicio02()
{
    // definir dados
    FILE *arquivo = fopen("EscreverArranjo.txt", "wt");
    int x = 0; // tamanho do arranjo
    int n = 0; // testar antes de adicionar no arranjo

    printf("Qual o tamanho do arranjo? ");
    scanf("%d", &x);

    fprintf(arquivo, "%d\n", x);
    int arranjo[x];

    // executar
    for (int i = 0; i < x; i++)
    {
        printf("\nEntrar com o valor da posicao %d do arranjo: ", i);
        scanf("%d", &n);
        if (n >= 0 && n % 2 == 0)
        {
            arranjo[i] = n; // adicionar a posicao i do arranjo, o numero n dentro da condicao
            fprintf(arquivo, "%d\n", arranjo[i]);
        }
        else
        {
            printf("Valor invalido, entrar com numero positivo e par\n");
            i = i - 1; // voltar uma posicao para adicionar o valor correto naquela posicao
        }
    }
    fclose(arquivo);

    // guardar em outro arquivo
    FILE *guardar = fopen("guardarArranjo.txt", "wt");
    FILE *lerArranjo = fopen("EscreverArranjo.txt", "rt");
    int numeros = 0;  // valores a serem copiados para arquivo que ira guardar
    int controle = 0; // controle para o while de leitura

    fscanf(lerArranjo, "%d\n", &numeros);
    while (controle <= x)
    {
        fprintf(guardar, "%d\n", numeros);
        fscanf(lerArranjo, "%d", &numeros);
        controle++;
    }
    fclose(lerArranjo);
    fclose(guardar);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio02

void gerarIntIntervalo(int Lsuperior, int Linferior, int quantidade) // exercicio03
{
    // definir dados
    int valoresAleatorios[quantidade];
    FILE *saida = fopen("dadosEX03.txt", "wt");

    // executar
    fprintf(saida, "Quantidade gerada: %d\n", quantidade);

    for (int i = 0; i < quantidade; i++)
    {
        valoresAleatorios[i] = rand() % (Lsuperior - Linferior) + Linferior;
        fprintf(saida, "%d\n", valoresAleatorios[i]);
    }
    fclose(saida);
    getchar();

} // fim funcao gerarInt

void exercicio03()
{
    // definir limites
    int x = 0; //  superior
    int y = 0; //  inferior
    int n = 0; // quantidade a ser gerada

    // atribuir
    printf("Quantos valores gerar? ");
    scanf("%d", &n);

    printf("Qual o limite superior do intervalo a ser gerado numeros dentro? ");
    scanf("%d", &x);

    printf("E o limite inferior? ");
    scanf("%d", &y);

    gerarIntIntervalo(x, y, n); // chamar funcao

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

void procurarParArranjo(char *entrada) // exercicio04
{
    // definir dados
    FILE *arquivo = fopen(entrada, "rt");
    int x = 0; // ler do arquivo o primeiro valor(quantidade)
    int controle = 0;
    int menorPar = 0;
    int n = 0; // numeros dentro do arquivo
    int pares = 0;
    int arranjoPares[pares];

    fscanf(arquivo, "%d", &x); // ler o primeiro termo do arquivo(se refere a quantidade de numeros abaixo dele)
    int inteiros[x];

    // executar
    while (controle < x)
    {
        fscanf(arquivo, "%d", &n);
        inteiros[controle] = n;

        if (n % 2 == 0)
        {
            arranjoPares[controle] = n;
            pares++;

        } // fim if

        controle++;

    } // fim while

    // printf("pares: %d\n", pares);
    int i = 0; // contador segundo while
    while (i < pares)
    {
        // printf("while arranjo[i]:%d\n", arranjoPares[i]);
        if (arranjoPares[i] < arranjoPares[i - 1])
        {
            // printf("arranjo[i]: %d\n", arranjoPares[i]);
            menorPar = arranjoPares[i];
            // printf("menor par: %d\n", menorPar);
        }
        i++;
    }

    printf("Menor Par do arranjo: %d\n", menorPar);
    fclose(arquivo);

} // fim procurarPar

void exercicio04()
{
    printf("Exercicio04 - ed08 - Mostrar menor par de um vetor\n\n");
    // chamar funcao auxiliar, mostrar menor par do vetor
    procurarParArranjo("guardarArranjo.txt");

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio04

void procurarMenorImpar(char *entrada) // exercicio05
{
    FILE *arquivo = fopen(entrada, "rt");
    int x = 0; // ler o primeiro valor
    int controle = 0;
    int n = 0; // numeros dentro do arranjo
    int impares = 0;
    int menorImpar = 0;

    fscanf(arquivo, "%d", &x);

    int arranjo[x];

    while (controle < x)
    {
        fscanf(arquivo, "%d", &n);

        if (n % 2 != 0)
        {
            arranjo[impares] = n;
            impares++;
        }

        controle++;
    }

    int i = 0; // contador segundo while
    while (i < impares)
    {
        if (arranjo[i] < arranjo[i - 1])
        {
            menorImpar = arranjo[i];
        }
        i++;
    }

    fclose(arquivo);
    // mostrar resultado
    printf("Menor impar no vetor: %d\n", menorImpar);
    getchar();

} // fim procurarMenorImpar

void exercicio05()
{
    // identificar
    printf("Exercicio05 - ed08 - Mostrar menor impar de um vetor\n\n");
    // chamar funcao auxiliar
    procurarMenorImpar("guardarArranjo.txt");

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio05

void armazenarMaioresEMenoresMedia(char *input) // exercicio06
{
    // definir dados
    FILE *leitura = fopen(input, "rt");
    FILE *guardarMaiores = fopen("MaioresQueMedia.txt", "wt");
    FILE *guardarMenores = fopen("MenoresQueMedia.txt", "wt");
    int x = 0; // ler valores
    int tamanho = 0;
    int controle = 0;
    double soma = 0; // soma dos valores do arranjo

    fscanf(leitura, "%d", &tamanho);
    int numeros[tamanho];

    // executar
    while (controle < tamanho)
    {
        fscanf(leitura, "%d", &x);
        numeros[controle] = x;

        controle++;
    }

    fclose(leitura);

    // calcular a media dos valores do arranjo
    for (int i = 0; i < tamanho; i++)
    {
        soma = soma + numeros[i];
    }

    double mediaArranjo = soma / tamanho; // media dos valores do arranjo e a soma dos valores / tamanho

    // verificar os valores do arranjo maiores  ou menores que a media
    for (int i = 0; i < tamanho; i++)
    {
        if (numeros[i] > mediaArranjo) // armazena os maiores em um arquivo
        {
            fprintf(guardarMaiores, "%d\n", numeros[i]);
        }
        else // armazena os menores em outro arquivo
        {
            fprintf(guardarMenores, "%d\n", numeros[i]);
        }
    }
    fclose(guardarMaiores);
    fclose(guardarMenores);

} // fim armazenar

void exercicio06()
{
    // identificar
    printf("Exercicio06 - ED08 - Separar em dois arquivos, os menores e maiores que a media de um arranjo\n\n");
    printf("Para ver as saidas, verificar arquivos MenoresQueMedia.txt, ou maiores.txt\n\n");

    // executar
    armazenarMaioresEMenoresMedia("guardarArranjo.txt");

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio06

void verificarOrdenacaoArranjo(int vetor[], int tamanho) // exercicio07
{
    // definir dados
    int decrescente = 0;
    int crescente = 0;

    // executar
    for (int i = 0; i < tamanho - 1; i++)
    {
        if (vetor[i + 1] > vetor[i])
        {
            crescente++;
        }
        else
        {
            decrescente++;
        }
    } // fim for

    // verificar e mostrar se esta decrescente ou nao
    if (decrescente > crescente)
    {
        printf("\nO arranjo esta decrescente\n\n");
    }
    else
    {
        printf("\nO arranjo nao esta decrescente\n\n");
    }

} // fim verificarArranjo

void exercicio07()
{
    // identificar
    printf("Exercicio07 - ED08 _ Verificar se o arranjo está ordenado em ordem decrescente\n\n");

    // definir dados
    int tamanho = 0;

    printf("Qunatos valores tera no arranjo para testar? ");
    scanf("%d", &tamanho);
    // definir arranjo
    int arranjo[tamanho];

    // executar
    for (int i = 0; i < tamanho; i++)
    {
        printf("Entrar com valor no arranjo: ");
        scanf("%d", &arranjo[i]);

    } // fim for

    // chamar funcao para verificar
    verificarOrdenacaoArranjo(arranjo, tamanho);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio07

void procurarValorArranjo(char *entrada, int n) // exercicio08
{
    // definir dados
    FILE *arquivo = fopen(entrada, "rt");
    int controle = 0;
    int tamanho = 0;         // primeiro valor a ser lido
    int numero = 0;          // isolar cada valor lido
    bool existencia = false; // verificar se o valor existe no arranjo
    int contador = 0;        // contar quantas vezes aparece o valor no arranjo

    fscanf(arquivo, "%d", &tamanho);
    int arranjo[tamanho];

    // executar
    while (controle < tamanho)
    {
        fscanf(arquivo, "%d", &numero);
        arranjo[controle] = numero;

        controle++;
    }
    // fechar arquivo
    fclose(arquivo);

    // verificar se valor existe dentro do arranjo
    for (int i = 0; i < tamanho; i++)
    {
        if (n == arranjo[i])
        {
            existencia = true;
            contador++;
        }
    } // fim for

    // mostrar resultados
    if (existencia)
    {
        printf("\nO valor aparece no arranjo, e aparece %d vezes\n\n", contador);
    }
    else
    {
        printf("\nDesculpe, o valor nao aparece no arranjo\n\n");
    }

    getchar();

} // fim procurarValor

void exercicio08()
{
    // identificar
    printf("Exercicio08 - ED08 - Verificar se existe valor no arrajo\n\n");

    // definir dado
    int x = 0; // valor a ser procurado

    // executar
    printf("Qual valor verificar se existe no arrajo? ");
    scanf("%d", &x);

    // chamar metodo
    procurarValorArranjo("guardarArranjo.txt", x);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio08

void procurarPosicaoArranjo(char *input, int valor) // exercicio09
{
    // definir dados
    FILE *arquivo = fopen(input, "rt");
    int tamanho = 0; // quantidade de elementos, primeira posicao
    int n = 0;       // atribuir a ele, valores lidos
    int controle = 0;

    fscanf(arquivo, "%d", &tamanho);
    int arranjo[tamanho];

    // executar
    while (controle < tamanho)
    {
        fscanf(arquivo, "%d", &n);
        arranjo[controle] = n;

        controle++;
    }
    fclose(arquivo);

    // indicar posicao do valor no arranjo
    for (int i = 0; i < tamanho; i++)
    {
        // printf("%d\n", arranjo[i]);
        if (arranjo[i] == valor)
        {
            printf("O valor aparece na posicao %d do arrajo\n", i);
        }
    } // fim for

    getchar();

} // fim procurarPosicaoArranjo

void exercicio09()
{
    // identificar
    printf("Exercicio09 - ED08 - indicar posicao do valor no arranjo\n\n");

    // definir dados
    int x = 0;
    // executar
    printf("Qual valor indicar posicao o arranjo? ");
    scanf("%d", &x);

    procurarPosicaoArranjo("guardarArranjo.txt", x);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim exercicio09

void verificarQuantasVezesAparece(char *arquivo, int valor) // exercicio10
{
    // definir dados
    FILE *entrada = fopen(arquivo, "rt");
    int tamanho = 0; // primeiro valor, que indica o tamanho
    int n = 0;       // cada valor lido
    int controle = 0;
    int contador = 0; // contar quantas vezes aparece no arranjo

    fscanf(entrada, "%d", &tamanho);
    int arranjo[tamanho];

    // executar
    while (controle < tamanho)
    {
        fscanf(entrada, "%d", &n);
        arranjo[controle] = n;

        controle++;
    }

    // verificar quantas vezes aparece valor
    for (int i = 0; i < tamanho; i++)
    {
        if (arranjo[i] == valor)
        {
            contador++;
        }
    } // fim for

    // mostrar quantidade
    printf("O valor digitado aparece: %d vezes\n", contador);

    getchar();

} // fim verificarQuantasVezes

void exercicio10()
{
    // identificar
    printf("Exercicio10 - ED08 - indicar quantas vezes o valor aparece no arranjo\n\n");

    // definir dado
    int x = 0;

    // executar
    printf("Qual valor verificar quantas vezes aparece no arranjo? ");
    scanf("%d", &x);

    verificarQuantasVezesAparece("guardarArranjo.txt", x); // chamar metodo auxiliar

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio10

void guardarEExibirDivisores(char *output, int valor) // exercicioEXTRA01
{
    // definir dados
    FILE *arquivo = fopen(output, "wt");
    int tamanho = valor;
    int arranjoDivisores[tamanho];

    // executar
    printf("Os divisores sao:\n");
    fprintf(arquivo, "Os divisores sao:\n");

    for (int i = 1; i <= valor; i++)
    {
        if (valor % i == 0)
        {
            arranjoDivisores[i] = i;
            printf("%d\n", arranjoDivisores[i]);
            fprintf(arquivo, "%d\n", arranjoDivisores[i]);
        }
    } // fim for

    // fechar arquivo para gravacao
    fclose(arquivo);

    getchar();

} // fim guardarEExibirDivisores

void EXTRA01()
{
    // identificar
    printf("ExercicioEXTRA01 - ED08 - mostrar e gravar divisores de um valor\n\n");
    // definir dados
    int x = 0; // valor para calcular os divisores

    // executar
    printf("Qual valor calcular, mostrar e gravar os divisores? ");
    scanf("%d", &x);

    // chamar metodo auxiliar
    guardarEExibirDivisores("divisoresE1.txt", x);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim EXTRA01

void retornarPalavrasC(char *input, int quantidade) // EXTRA02
{
    //definir dados
    FILE *entrada = fopen(input, "rt");
    int controle = 0; 
    char palavras[100];
    
    // executar
    printf("Nao comecam nem terminam com c ou C as palavras:\n");

    while(controle < quantidade)
    {
        fscanf(entrada, "%s", palavras);
        if( (palavras[0] != 'c' && palavras[0] != 'C') && (palavras[strlen(palavras) - 1] != 'c' && palavras[strlen(palavras) - 1] != 'C') )
        {
            printf("%s\n", palavras);
        }
        controle++;
    }
    fclose(entrada);

} // fim retornarPalavrasC

void EXTRA02()
{
    // identificar
    printf("ExercicioEXTRA02 - ED08 - mostrar palavras com inicio e fim diferentes de C\n\n");

    // definir dados
    FILE *arquivo = fopen("escreverPalavras.txt", "wt");
    int quantidade = 0; // quantas palavras adicionar
    char palavra[100];

    // executar
    printf("Quantas palavras escrever para testar?(mais que 10) ");
    scanf("%d", &quantidade);
    getchar();

    for (int i = 1; i <= quantidade; i++)
    {
        printf("\nQual palavra adicionar?");
        scanf("%s", palavra);
        getchar();

        fprintf(arquivo, "%s\n", palavra);
    }
    fclose(arquivo);
    
    retornarPalavrasC("escreverPalavras.txt", quantidade);
    // encerrar
    printf("Aperte ENTER para sair");
    getchar();

} // fim EXTRA02

int main()
{
    printf("ED08 - Exercicios - Tales Rocha Moreira");

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
        IO_println("11 - EXTRA01");
        IO_println("12 - EXTRA02");

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
        case 11:
            EXTRA01();
            break;
        case 12:
            EXTRA02();
            break;

        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}
