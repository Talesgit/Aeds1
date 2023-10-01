/*
Exemplo1101 - v0.0. - __ / __ / _____
Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause(std::string text)
{
    std::string dummy;
    std::cin.clear();
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy);
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myarray.hpp"
using namespace std;
// ----------------------------------------------- metodos
/**
exercicio00 - nao faz nada.
*/
void exercicio00()
{
    // nao faz nada
} // fim exercicio00 ( )

/**
exercicio01 - Mostrar certa quantidade de valores.
*/

void gerarInt(int quantidade, int inferior, int superior)
{
    int numeros[quantidade];

    for (int i = 0; i < quantidade; i++)
    {
        numeros[i] = rand() % (superior - inferior + 1) + inferior;
    }

    ofstream afile;
    afile.open("exercicio01.txt");
    afile << quantidade << endl;

    for (int i = 0; i < quantidade; i++)
    {
        afile << numeros[i] << endl;
    }
    afile.close();
}

void exercicio01()
{ // identificar
    cout << "\nEXEMPLO1101 - exercicio01 - v0.0\n";
    // definir dados
    int inferior = 0;
    int superior = 0;
    int quantidade = 0;

    cout << "Quantidade: " << endl;
    cin >> quantidade;
    cout << "inferior: " << endl;
    cin >> inferior;
    cout << "superior: " << endl;
    cin >> superior;

    gerarInt(quantidade, inferior, superior);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio01 ( )
/**
exercicio02. procurar o menor impar de um arranjo em um arquivo
*/

void procurarMenorImpar(char *arquivo)
{
    ifstream file;
    file.open(arquivo);
    int tamanho = 0;

    file >> tamanho;

    int arranjo[tamanho];

    int menor = tamanho;
    for (int i = 0; i < tamanho; i++)
    {
        file >> arranjo[i];
        if (arranjo[i] < menor)
        {
            menor = arranjo[i];
        }
    }

    cout << "Menor: " << menor;
}

void exercicio02()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio02 - v0.0" << endl;

    procurarMenorImpar("exercicio01.txt");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio02 ( )
/**
exercicio03.
*/
int procurarMenorPar(char *arquivo)
{
    ifstream file;
    file.open(arquivo);
    int tamanho = 0;

    file >> tamanho;
    int array[tamanho];

    int menor = tamanho;
    for (int i = 0; i < tamanho; i++)
    {
        file >> array[i];
        if (array[i] % 2 == 0)
        {
            if (array[i] < menor)
            {
                menor = array[i];
            }
        } // fim if's
    }     // fim for
    return menor;
}

void exercicio03()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio03 - v0.0" << endl;

    cout << procurarMenorPar("exercicio01.txt");

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio03 ( )
/**
exercicio04.
*/

class arrayEX4
{
public:
    int *arranjo;
    int *arranjo2;
    int tamanho;
    ifstream file;

    arrayEX4()
    {
        arranjo = nullptr;
        tamanho = 0;
    }

    void popularArranjo(char *arquivo)
    {
        file.open(arquivo);

        file >> tamanho;
        arranjo = new int[tamanho];
        for (int i = 0; i < tamanho; i++)
        {
            file >> arranjo[i];
        }
    }

    void popularSegundoArray(int quantidade)
    {
        arranjo2 = new int[quantidade];
        for (int i = 0; i < quantidade; i++)
        {
            cout << i << " : ";
            cin >> arranjo2[i];
        }
    }
};

void somarDoisValores(int pos1, int pos2)
{
    arrayEX4 var;
    int soma = 0;
    var.popularArranjo("exercicio01.txt");

    for (int i = pos1; i <= pos2; i++)
    {
        soma = soma + var.arranjo[i];
    }
    cout << "soma: " << soma;
}

void exercicio04()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio04 - v0.0" << endl;

    int a, b = 0;

    cout << "Primeira posicao a somar(0-4): ";
    cin >> a;
    cout << "Segunda posicao a somar(0-4): ";
    cin >> b;

    somarDoisValores(a, b);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio04 ( )

/**
exercicio05.
*/

void acharMedia(int pos1, int pos2)
{
    // definir dados
    arrayEX4 dados;
    int media = 0;
    int soma = 0;
    int tamanho = pos2 - pos1;

    if (pos1 == 0)
    {
        pos1 = 1;
    }

    dados.popularArranjo("exercicio01.txt");

    for (int i = pos1; i <= pos2; i++)
    {
        soma = soma + dados.arranjo[i];
    }
    media = soma / tamanho;
    cout << "media: " << media;
}

void exercicio05()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio05 - v0.0" << endl;

    int a, b = 0;

    cout << "Posicao 1(0-4): ";
    cin >> a;
    cout << "Posicao 2(0-4): ";
    cin >> b;

    acharMedia(a, b);

    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exercicio05 ( )

/**
exercicio06.
*/
void exercicio06()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio06 - v0.0" << endl;

    int positivos = 0;
    arrayEX4 obj;
    obj.popularArranjo("exercicio01.txt");

    for (int i = 0; i < obj.tamanho; i++)
    {
        if (obj.arranjo[i] >= 0)
        {
            positivos++;
        }
    } // fim for

    if (positivos == obj.tamanho)
    {
        cout << "Todos os valores sao positivos";
    }
    else
    {
        cout << "Ha valores negativos";
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio06 ( )

/**
exercicio07.
*/
void exercicio07()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio07 - v0.0" << endl;
    arrayEX4 dados;
    bool decrescente = true;

    dados.popularArranjo("exercicio01.txt");

    for (int i = 0; i < dados.tamanho; i++)
    {
        if (dados.arranjo[i] < dados.arranjo[i + 1])
        {
            decrescente = false;
        }
    } // fim for

    if (decrescente)
    {
        cout << "Os valores estao em ordem decrescente";
    }
    else
    {
        cout << "Os valores estao em ordem crescente";
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio07 ( )

/**
exercicio08.
*/
void exercicio08()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio08 - v0.0" << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio08 ( )

/**
exercicio09.
*/
// dentre duas posicoes indicadas, verificar se valor existe em arranjo

void procurarIntPos(int pos1, int pos2, int valor)
{
    arrayEX4 obj;
    int isPresent = 0;
    obj.popularArranjo("exercicio01.txt");

    for (int i = 0; i < obj.tamanho; i++)
    {
        if (obj.arranjo[i] == valor)
        {
            isPresent = 1;
        }
    } // fim for
    if (isPresent > 0)
    {
        cout << "O valor esta presente no arranjo ";
    }
    else
    {
        cout << "Nao esta presente ";
    }

} // fim

void exercicio09()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio09 - v0.0" << endl;
    arrayEX4 var;
    int valor = 0;
    int a, b = 0;

    cout << "Qual valor procurar no arranjo: ";
    cin >> valor;
    cout << "1 posicao(0-4): ";
    cin >> a;
    cout << "2 posicao(0-4): ";
    cin >> b;

    procurarIntPos(a, b, valor);

    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exercicio09 ( )

/**
exercicio10.
*/

// colocar valores em ordem crescente

void ordemCrescente(char *arquivo)
{
    arrayEX4 vars;
    vars.popularArranjo(arquivo);

    for (int i = 0; i < vars.tamanho - 1; i++)
    {
        for (int j = 0; j < vars.tamanho - i - 1; j++) // a cada iteracao de i ordena ate i
        {
            if (vars.arranjo[j] > vars.arranjo[j + 1])
            {
                // Trocar os elementos
                int maior = vars.arranjo[j];
                vars.arranjo[j] = vars.arranjo[j + 1];
                vars.arranjo[j + 1] = maior;
            }
        }
    }

    for (int i = 0; i < vars.tamanho; i++)
    {
        printf("%d\n", vars.arranjo[i]);
    }
}

void exercicio10()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exercicio10 - v0.0" << endl;

    ordemCrescente("exercicio01.txt");

    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exercicio10 ( )

void extra01()
{
    arrayEX4 vars;
    int pos = 0;

    vars.popularArranjo("exercicio01.txt");
    cout << "popular segundo arranjo" << endl;
    vars.popularSegundoArray(vars.tamanho);

    cout << "qual posicao verificar se sao diferentes: ";
    cin >> pos;

    if (vars.arranjo2[pos] != vars.arranjo[pos])
    {
        cout << "Nesta posicao sao diferentes: " << endl;
        cout << vars.arranjo2[pos] << endl;
        cout << vars.arranjo[pos];
    }
    else
    {
        cout << "Nesta posicao sao iguais" << endl;
        cout << vars.arranjo2[pos] << endl;
        cout << vars.arranjo[pos];
    }

    pause("Aperte ENTER para continuar");
}

// calcular a diferenca de pos por pos
void extra02()
{
    arrayEX4 vars;
    int result = 0;

    vars.popularArranjo("exercicio01.txt");
    cout << "popular segundo arranjo" << endl;
    vars.popularSegundoArray(vars.tamanho);

    cout << endl;
    cout << "Subtracoes: " << endl;
    for (int i = 0; i < vars.tamanho; i++)
    {
        result = vars.arranjo[i] - vars.arranjo2[i];
        cout << i << " : " << result << endl;
    }

    pause("Aperte ENTER para continuar");
}

// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/

int main(int argc, char **argv)
{
    // definir dado
    int x = 0; // definir variavel com valor inicial
    // repetir até desejar parar
    do
    {
        // identificar
        cout << "EXEMPLO1101 - Programa - v0.0\n " << endl;
        // mostrar opcoes
        cout << "Opcoes " << endl;
        cout << " 0 - parar " << endl;
        cout << " 1 - mostrar dados inteiros em arranjo " << endl;
        cout << " 2 - " << endl;
        cout << " 3 - " << endl;
        cout << " 4 - " << endl;
        cout << " 5 - " << endl;
        cout << " 6 - " << endl;
        cout << " 7 - " << endl;
        cout << " 8 - " << endl;
        cout << " 9 - " << endl;
        cout << "10 - " << endl;
        cout << "11 - " << endl;
        cout << "12 - " << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
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
            extra01();
            break;
        case 12:
            extra02();
            break;
        default:
            cout << endl
                 << "ERRO: Valor invalido." << endl;
        } // fim escolher
    } while (x != 0);
    // encerrar
    pause("Apertar ENTER para terminar");
    return (0);
} // fim main( )
  /*
  ---------------------------------------------- documentacao complementar
  ---------------------------------------------- notas / observacoes / comentarios
  ---------------------------------------------- previsao de testes
  ---------------------------------------------- historico
  Versao Data Modificacao
  0.1 __/__ esboco
  ---------------------------------------------- testes
  Versao Teste
  0.1 01. ( OK ) identificacao de programa
  */