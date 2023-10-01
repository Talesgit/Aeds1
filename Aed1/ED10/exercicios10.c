/*
ED10 - Tales Rocha Moreira - 17/05/2023
*/
#include "io.h"
#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

void exercicio00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

struct ex1
{
    int superior;
    int inferior;
    int *arranjo; // POR QUE PRECISA SER PONTEIRO??
    int quantidade;
    FILE *arquivo;
};

void popularVetorRand(struct ex1 dados)
{
    for (int i = 0; i < dados.quantidade; i++)
    {
        dados.arranjo[i] = RANDOM(dados.inferior, dados.superior);
    }
} // fim popular

void exercicio01()
{
    struct ex1 limites;
    printf("Entrar com o limite superior do intervalo: ");
    scanf("%d", &limites.superior);

    printf("\nEntrar com o limite inferior do intervalo: ");
    scanf("%d", &limites.inferior);

    printf("\nQuantos numeros aleatorios gerar? ");
    scanf("%d", &limites.quantidade);

    limites.arranjo = (int *)malloc(limites.quantidade * sizeof(int));
    popularVetorRand(limites);

    // MOSTRAR CADA VALOR DO VETOR NO ARQUIVO
    limites.arquivo = fopen("dadosEx1.txt", "wt");
    fprintf(limites.arquivo, "%d\n", limites.quantidade); // imprimir como primeiro dado a quantidade
    for (int i = 0; i < limites.quantidade; i++)
    {
        fprintf(limites.arquivo, "%d\n", limites.arranjo[i]);
    } // fim colocar arquivo
    fclose(limites.arquivo);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio01

//-----------------------------------//----------------------------------------------//
// EXERCICIO02

struct ex2
{
    int x;         // valor a procurar dentro do arranjo
    FILE *arquivo; // arquivo para coletar os num do arranjo
    int *vetor;
    int n1; // numero 1 (se refere ao tamanho) dentro do arquivo
};

bool ProcurarArranjo(struct ex2 vars)
{
    // ler do arquivo para o arranjo
    int contador = 0;
    bool encontrou = false;

    vars.arquivo = fopen("ARRAY1.txt", "rt");
    fscanf(vars.arquivo, "%d", &vars.n1);
    vars.vetor = (int *)malloc(vars.n1 * sizeof(int));

    while (contador < vars.n1)
    {
        fscanf(vars.arquivo, "%d", &vars.vetor[contador]);
        contador++;
    }
    fclose(vars.arquivo);

    // procurar o valor indicado
    for (int i = 0; i < vars.n1; i++)
    {
        if (vars.vetor[i] == vars.x)
        {
            encontrou = true;
        }
    }
    return encontrou;
} // fim procurarArranjo

void exercicio02()
{
    struct ex2 dados;

    printf("Qual valor procurar dentro do arranjo? ");
    scanf("%d", &dados.x);
    bool encontrou = ProcurarArranjo(dados);

    if (encontrou)
    {
        printf("\nO valor foi encontrado: %d\n", dados.x);
    }
    else
    {
        printf("\nO numero nao foi encontrado\n");
    }

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
}

//------------------------------------------------//-------------------------------------------//

struct dadosEX3
{
    int *arranjo1; // POR QUE TEM QUE SER PONTEIRO // ANTES DEU ERRO NO vars.arranjo[i]
    int *arranjo2;
    FILE *arquivo;  // primeiro arquivo lido
    FILE *arqcmp;   // segundo arquivo lido
    char *arquivo1; // POR QUE PRECISA SER PONTEIRO? ERRO NA LEITURA DO TECLADO
    char *arquivo2;
    int tamanho1; // arq1
    int tamanho2; // arq2
    int iguais;   // contar valores iguais no arranjo
    bool procede; // retorna se todos os valores sao iguais
};

// criar copia do arquivo
int comparar(struct dadosEX3 vars)
{
    // definir
    int controle = 0;
    vars.arquivo = fopen(vars.arquivo1, "rt");
    vars.arqcmp = fopen(vars.arquivo2, "rt");

    fscanf(vars.arquivo, "%d", &vars.tamanho1); // LER PRIMEIRO VALOR, REFERENTE AO TAMANHO
    fscanf(vars.arqcmp, "%d", &vars.tamanho2);

    // executar
    if (vars.tamanho1 == vars.tamanho2)
    {
        vars.arranjo1 = (int *)malloc(vars.tamanho1 * sizeof(int));
        vars.arranjo2 = (int *)malloc(vars.tamanho2 * sizeof(int));

        while (controle < vars.tamanho1)
        {
            fscanf(vars.arquivo, "%d", &vars.arranjo1[controle]);
            fscanf(vars.arqcmp, "%d", &vars.arranjo2[controle]);
            controle++;
        }

        // comparar
        vars.iguais = 0;
        for (int i = 0; i < vars.tamanho1; i++)
        {
            if (vars.arranjo1[i] == vars.arranjo2[i])
            {
                vars.iguais++;
            }
        } // fim for
    }
    else
    {
        printf("\nErro");
    }

    if (vars.iguais == vars.tamanho1)
    {
        vars.procede = true;
    }
    return (vars.procede);
}

void exercicio03()
{
    // defnir dados
    struct dadosEX3 dados;
    dados.arquivo1 = (char *)malloc(100 * sizeof(char));
    dados.arquivo2 = (char *)malloc(100 * sizeof(char));

    printf("Entrar com arquivo para comparar(testar arquivos na pasta): ");
    scanf("%s", dados.arquivo1); // POR QUE SO FUNCIONA COM %S??
    printf("\nEntrar com segundo arquivo: ");
    scanf("%s", dados.arquivo2);

    if (comparar(dados) == 1)
    {
        printf("\nOs arranjos estao iguais\n");
    }
    else
    {
        printf("\nOs arranjos nao estao iguais\n");
    }

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicio03

//----------------------------------------------------------------------//---------------------------------------------------------//

struct dadosEX4
{
    int *arranjo1; // POR QUE TEM QUE SER PONTEIRO // ANTES DEU ERRO NO vars.arranjo[i]
    int *arranjo2;
    FILE *arquivo;  // primeiro arquivo lido
    FILE *arqcmp;   // segundo arquivo lido
    char *arquivo1; // POR QUE PRECISA SER PONTEIRO? ERRO NA LEITURA DO TECLADO
    char *arquivo2;
    int tamanho1; // arq1
    int tamanho2; // arq2
    int iguais;   // contar valores iguais no arranjo
    bool procede; // retorna se todos os valores sao iguais
};

int somar(struct dadosEX4 dados) // ??
{
    // definir
    int controle = 0;
    dados.arquivo = fopen(dados.arquivo1, "rt");
    dados.arqcmp = fopen(dados.arquivo2, "rt");
    int soma = 0;

    fscanf(dados.arquivo, "%d", &dados.tamanho1); // LER PRIMEIRO VALOR, REFERENTE AO TAMANHO
    fscanf(dados.arqcmp, "%d", &dados.tamanho2);
    printf("%d\n", dados.tamanho1);
    // executar
    if (dados.tamanho1 == dados.tamanho2)
    {
        dados.arranjo1 = (int *)malloc(dados.tamanho1 * sizeof(int));
        dados.arranjo2 = (int *)malloc(dados.tamanho2 * sizeof(int));
        printf("%d\n", dados.tamanho1);

        while (controle < dados.tamanho1)
        {
            fscanf(dados.arquivo, "%d", &dados.arranjo1[controle]);
            fscanf(dados.arqcmp, "%d", &dados.arranjo2[controle]);
            controle++;
        }

        for (int i = 0; i < dados.tamanho1; i++)
        {
            soma = soma + (dados.arranjo1[i] + dados.arranjo2[i]);
        } // fim for
    }
    else
    {
        printf("\nerro");
    }
    return (soma);
}

void exercicio04()
{
    struct dadosEX4 value;
    value.arquivo1 = (char *)malloc(100 * sizeof(char));
    value.arquivo2 = (char *)malloc(100 * sizeof(char));

    printf("De qual arquivo somar os valores dos arranjos? ");
    scanf("%s", value.arquivo1);
    printf("\nQual o outro arquivo: ");
    scanf("%s", value.arquivo2);

    printf("\nA soma de todos os valores dos dois arranjos e %d\n", somar(value)); // POR QUE PONTEIRO?

    getchar();
    printf("Aperte ENTER para sair");
    getchar();
}

//--------------------------------------------------------------------------------//----------------------------------------------------------------------//
struct decrec
{
    bool eDecrec;
    int *vetor;
    FILE *arquivo;
    int tamanho; // primeiro numero do arquivo
    char *nome;
    int contador; // contar quantos estao menores para verificacao
};

int isDecrec(struct decrec dados)
{
    int menor = 0;
    int controle = 0;
    int contador = 1;
    dados.eDecrec = false;
    dados.arquivo = fopen(dados.nome, "rt");
    fscanf(dados.arquivo, "%d", &dados.tamanho);
    dados.vetor = (int *)malloc(dados.tamanho * sizeof(int));

    while (controle < dados.tamanho)
    {
        fscanf(dados.arquivo, "%d", &dados.vetor[controle]);
        printf("%d\n", dados.vetor[controle]);
        controle++;
    } // fim popular vetor

    menor = dados.vetor[0];
    for (int i = 0; i < dados.tamanho; i++)
    {

        if (menor > dados.vetor[i])
        {
            menor = dados.vetor[i];
            contador++;
        }
    } // fim for

    if (contador == dados.tamanho)
    {
        dados.eDecrec = true;
    }
    return (dados.eDecrec);
}

void exercicio05()
{

    struct decrec vars;
    vars.nome = (char *)malloc(100 * sizeof(char));
    printf("Entrar com o nome do arquivo para verificar se e decrescente: ");
    scanf("%s", vars.nome);

    if (isDecrec(vars) == 1)
    {
        printf("\nOs valores estao em ordem decrescente");
    }
    else
    {
        printf("\nOs valores nao estao em ordem decrescente");
    }

    getchar();
    printf("\nAperte ENTER para sair");
    getchar();
} // fim ex05

//--------------------------------------------------------------//----------------------------------------------------------------//

struct matrix
{
    int rows;
    int columns;
    int **matriz; // POR QUE SO FUNCIONOU O SCANF QUANDO COLOQUEI PONTEIRO DUPLO???
    FILE *arquivo;
    char *nome;
};

void escreverTrasposta(struct matrix dados)
{
    dados.arquivo = fopen(dados.nome, "rt");
    for (int j = 0; j < dados.rows; j++)
    {
        for (int i = 0; i < dados.columns; i++)
        {
            fscanf(dados.arquivo, "%d", &dados.matriz[j][i]);
            printf(" %d ", dados.matriz[i][j]);
        }
        printf("\n");
    } // fim for
    fclose(dados.arquivo);
} // fim escrever

void exercicio06()
{
    // definir dados
    struct matrix vars;
    // colocar em arquivo matriz
    vars.nome = IO_readstring("Qual o nome do arquivo para criar a matriz?: ");
    vars.rows = IO_readint("\nQual o numero de linhas colocar? ");
    vars.columns = IO_readint("\nQual numero de colunas? ");
    vars.arquivo = fopen(vars.nome, "wt");
    // definir
    vars.matriz = (int **)malloc(vars.rows * sizeof(int));

    for (int i = 0; i < vars.rows; i++)
    {
        vars.matriz[i] = (int *)malloc(vars.columns * sizeof(int)); // PARA CADA POSICAO JA ALOCADA DO VETOR, ELE CRIA OUTRAS X COLUNAS
    }
    // popular
    for (int j = 0; j < vars.rows; j++)
    {
        for (int i = 0; i < vars.columns; i++)
        {
            printf("[%d], [%d]: ", j, i);
            scanf("%d", &vars.matriz[j][i]);
            fprintf(vars.arquivo, " %d ", vars.matriz[j][i]);
        }
        fprintf(vars.arquivo, "\n");
    } // fim for
    fclose(vars.arquivo);

    // enviar para func
    escreverTrasposta(vars);

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
} // fim

//--------------------------------------------------------------------------------------//-----------------------------------------------------------------------//
// VERIFICAR SE UMA MATRIZ SO POSSUI VALORES IGUAIS A ZERO
struct zeros
{
    int *vetor;
    int x;
    int contador;
};

int testarZeros(struct zeros dados)
{
    bool allZeros = true;
    for (int i = 1; i < dados.contador; i++)
    {
        printf("%d\n", dados.vetor[i]);
        if (dados.vetor[i] != 0)
        {
            allZeros = false;
        }
    }
    return (allZeros);
} // fim

void exercicio07()
{
    struct zeros dados;
    dados.contador = 0;
    char nome[100];
    int controle = 1; // controlar while leitura arquivo

    printf("Qual arquivo testar: ");
    scanf("%s", nome);
    // printf("\nQuantos numeros ha na matriz? ");
    // scanf("%d", &dados.contador); // ******** alternativa pois o contador dos numeros do arquivo nao deu certo

    FILE *arquivo = fopen(nome, "rt");
    // verificar tamanho

    while (fscanf(arquivo, "%d", &dados.x) == 1)
    {
        dados.contador++; // definir tamanho do vetor para armazenar
    }
    fclose(arquivo);
    // NAO DEU CERTO
    dados.vetor = (int *)malloc(dados.contador * sizeof(int)); // para armazenar os valores e testar se == 0

    FILE *arquivo2 = fopen(nome, "rt");
    // popular o vetor
    while (controle < dados.contador)
    {
        fscanf(arquivo2, "%d", &dados.vetor[controle]);
        controle++;
    }
    fclose(arquivo2);

    if (testarZeros(dados) == 1)
    {
        printf("\nA matriz so possui valores iguais a 0\n");
    }
    else
    {
        printf("\nA matriz possui valores diferentes de 0\n");
    }

    // encerrar
    getchar();
    printf("Aperte ENTER para sair");
    getchar();
}

//----------------------------------------------------------------------------------//-----------------------------------------------------------------------//
struct ex8
{
    int *matriz1;
    int *matriz2;
    int rows;
    int cols;
};

int testarIgualdade(char *arquivo1, char *arquivo2, int quantidade)
{
    // definir
    struct ex8 obj;
    int controle = 0;
    int equal = 1;
    FILE *arquivo = fopen(arquivo1, "rt");
    FILE *arq2 = fopen(arquivo2, "rt");
    obj.matriz1 = (int *)malloc(quantidade * sizeof(int));
    obj.matriz2 = (int *)malloc(quantidade * sizeof(int));

    while (controle < quantidade)
    {
        fscanf(arquivo, "%d", &obj.matriz1[controle]);
        fscanf(arq2, "%d", &obj.matriz2[controle]);
        printf("1: %d\n", obj.matriz1[controle]);
        printf("2: %d\n", obj.matriz2[controle]);
        controle++;
    } // fim while
    fclose(arquivo);
    fclose(arq2);

    // testar igualdade
    for (int i = 0; i < quantidade; i++)
    {
        if (obj.matriz1[i] != obj.matriz2[i])
        {
            equal = 0;
        }
    } // fim for
    return (equal);
}

void exercicio08()
{
    int tamanho = 0;
    tamanho = IO_readint("Quantos numeros ha nas matrizes? ");

    if (testarIgualdade("testeMATRIXEX6.TXT", "MATRIXEX6.TXT", tamanho) == 1)
    {
        printf("\nAs matrizes sao iguais\n");
    }
    else
    {
        printf("\nAs matrizes nao sao iguais\n");
    }

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

//--------------------------------------------------------------------------------//-----------------------------------------------------------------------//
struct ex9
{
    int **matriz1;
    int rows1;
    int cols1;
    //----//----//
    int **matriz2;
    //-----//----//
    int **matrizSoma;
    FILE *cmp1;
    FILE *cmp2;
};

void somarMatriz(struct ex9 dados)
{
    // abrir
    dados.cmp1 = fopen("MATRIXEX6.TXT", "rt");
    dados.cmp2 = fopen("testeMATRIXEX6.TXT", "rt");

    dados.matriz1 = (int **)malloc(dados.rows1 * sizeof(int));
    for (int i = 0; i < dados.rows1; i++)
    {
        dados.matriz1[i] = (int **)malloc(dados.cols1 * sizeof(int));
    }

    dados.matriz2 = (int **)malloc(dados.rows1 * sizeof(int));
    for (int i = 0; i < dados.rows1; i++)
    {
        dados.matriz2[i] = (int **)malloc(dados.cols1 * sizeof(int));
    }

    // ler matrizes
    for (int j = 0; j < dados.rows1; j++)
    {
        for (int i = 0; i < dados.cols1; i++)
        {
            fscanf(dados.cmp1, "%d", &dados.matriz1[j][i]);
            fscanf(dados.cmp2, "%d", &dados.matriz2[j][i]);
        }
        printf("\n");
    }

    dados.matrizSoma = (int **)malloc(dados.rows1 * sizeof(int));
    for (int i = 0; i < dados.rows1; i++)
    {
        dados.matrizSoma[i] = (int **)malloc(dados.cols1 * sizeof(int));
    }

    // somar
    printf("Soma das matrizes: \n");
    for (int j = 0; j < dados.rows1; j++)
    {
        for (int i = 0; i < dados.cols1; i++)
        {
            dados.matrizSoma[j][i] = dados.matriz1[j][i] + dados.matriz2[j][i];
            printf(" %d ", dados.matrizSoma[j][i]);
        }
        printf("\n");
    }

} // fim somar

void exercicio09()
{
    struct ex9 get;
    get.rows1 = IO_readint("Quantas linhas ha nas matrizes para somar(devem ser iguais): ");
    get.cols1 = IO_readint("\nQuantas colunas?(devem ser iguais) ");

    somarMatriz(get);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
}

//----------------------------------------------------------------------------//------------------------------------------------------------------------------//

struct ex10
{
    int **matriz1;
    int rows1;
    int cols1;
    //----//----//
    int **matriz2;
    //-----//----//
    int **matrizProduct;
    FILE *mult1;
    FILE *mult2;
};

void multiplicarMatriz(struct ex10 objs)
{
    // abrir
    objs.mult1 = fopen("MATRIXEX6.TXT", "rt");
    objs.mult2 = fopen("testeMATRIXEX6.TXT", "rt");

    objs.matriz1 = (int **)malloc(objs.rows1 * sizeof(int));
    for (int i = 0; i < objs.rows1; i++)
    {
        objs.matriz1[i] = (int *)malloc(objs.cols1 * sizeof(int));
    }

    objs.matriz2 = (int **)malloc(objs.rows1 * sizeof(int));
    for (int i = 0; i < objs.rows1; i++)
    {
        objs.matriz2[i] = (int *)malloc(objs.cols1 * sizeof(int));
    }

    // ler matrizes
    for (int j = 0; j < objs.rows1; j++)
    {
        for (int i = 0; i < objs.cols1; i++)
        {
            fscanf(objs.mult1, "%d", &objs.matriz1[j][i]);
            fscanf(objs.mult2, "%d", &objs.matriz2[j][i]);
        }
        printf("\n");
    }

    objs.matrizProduct = (int **)malloc(objs.rows1 * sizeof(int));
    for (int i = 0; i < objs.rows1; i++)
    {
        objs.matrizProduct[i] = (int *)malloc(objs.cols1 * sizeof(int));
    }

    // somar
    printf("Multiplicacao das matrizes: \n");
    for (int j = 0; j < objs.rows1; j++)
    {
        for (int i = 0; i < objs.cols1; i++)
        {
            objs.matrizProduct[j][i] = objs.matriz1[j][i] * objs.matriz2[j][i];
            printf(" %d ", objs.matrizProduct[j][i]);
        }
        printf("\n");
    }

} // fim somar

void exercicio10()
{
    struct ex10 vars;

    vars.rows1 = IO_readint("Qual o numero de linhas das matrizes(devem ser iguais): ");
    vars.cols1 = IO_readint("\nE colunas? ");

    multiplicarMatriz(vars);

    // encerrar
    printf("Aperte ENTER para sair");
    getchar();
} // fim exercicios

//--------------------------------------------------------------------------------EXTRAS-----------------------------------------------------------------------------//

struct extra1
{
    int *arranjo;
    int tamanho;
};

void ordenarArranjo(char *arquivo, struct extra1 data)
{
    FILE *arq = fopen(arquivo, "rt");
    int controle = 0;

    data.arranjo = (int *)malloc(data.tamanho * sizeof(int));

    printf("Anterior: \n");
    while (controle < data.tamanho)
    {
        fscanf(arq, "%d", &data.arranjo[controle]);
        printf("%d\n", data.arranjo[controle]);
        controle++;
    }
    fclose(arq);
    printf("\n");

    // ordenar
    for (int j = 0; j < data.tamanho - 1; j++)
    {
        for (int i = 0; i < data.tamanho - j - 1; i++)
        {

            if (data.arranjo[i] > data.arranjo[i + 1])
            {
                int aux = data.arranjo[i];
                data.arranjo[i] = data.arranjo[i + 1];
                data.arranjo[i + 1] = aux;
            }
        }
    }

    printf("Ordenado: \n");
    for (int i = 0; i < data.tamanho; i++)
    {
        printf("%d\n", data.arranjo[i]);
    }
}

void extra01()
{
    struct extra1 man;
    char nome[80];

    printf("Qual o arquivo pegar o vetor? ");
    scanf("%s", nome);
    printf("\nQuantidade de numeros no arquivo: ");
    scanf("%d", &man.tamanho);

    ordenarArranjo(nome, man);

    getchar();
}

void extra02()
{
}

int main()
{
    printf("ED10 - EXERCICIOS - Tales Rocha Moreira");

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
        IO_println("11 - extra1");
        IO_println("12 - extra2");

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
            extra01();
            break;
        case 12:
            extra02();
            break;
        default:
            printf("Valor invalido");
        }
    } while (x != 0);
}
