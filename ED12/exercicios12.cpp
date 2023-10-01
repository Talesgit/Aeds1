/*
Exemplo1101 - v0.0. - __ / __ / _____
Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
#include <fstream>  // para arquivos
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
using namespace std;
// ----------------------------------------------- metodos
/**
Method00 - nao faz nada.
*/
void exercicio00()
{
    // nao faz nada
} // fim exercicio00 ( )
/**
exercicio01 - Mostrar certa quantidade de valores.
*/

class ex1
{
private:
    int **matriz;
    int rows;
    int columns;
    int tales;

public:
    ex1(int rows, int columns)
    {
        this->rows = rows;
        this->columns = columns;

        this->matriz = (int **)malloc(rows * sizeof(int *));
        for (int i = 0; i < columns; i++)
        {
            this->matriz[i] = (int *)malloc(columns * sizeof(int *));
        }
    }

    void gerarAleatoriosMatriz(int rows, int columns)
    {

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                matriz[j][i] = rand() % 100;
            }
        }
    }

    void adicionarArquivo(char *nome, int rows, int columns)
    {
        ofstream arquivo;
        arquivo.open(nome);
        arquivo << rows * columns << endl;

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arquivo << matriz[j][i] << endl;
            }
        }
        arquivo.close();
    }

    void escalarMatrizArq(char *nome, int cons)
    {
        ifstream arq;
        arq.open(nome);

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arq >> matriz[j][i];
                cout << " " << matriz[j][i] * cons;
            }
            printf("\n");
        } // fim for
        arq.close();
    }

    bool testarIdentidade(char *nome)
    {
        ifstream arquivo;
        arquivo.open(nome);
        int contador = 0;
        bool destiny = false;

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arquivo >> matriz[j][i];
                if (matriz[i][i] == 1 && matriz[j][i] == 0)
                {
                    contador++;
                }
            }
        } // fim for

        if (contador == rows * columns)
        {
            destiny = true;
        }
        return (destiny);
    }

    bool testarIgualdade(char *arquivo1, char *arq2)
    {
        ifstream arquivo;
        ifstream arquivo2;
        arquivo.open(arquivo1);
        arquivo2.open(arq2);

        int matriz2[rows][columns];
        int contador = 0;
        bool igualdade = false;

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arquivo >> matriz[j][i];
                arquivo2 >> matriz2[j][i];

                if (matriz[j][i] == matriz2[j][i])
                {
                    contador++;
                }
            }
        } // fim for
        arquivo.close();
        arquivo2.close();

        if (contador == rows * columns)
        {
            igualdade = true;
        }
        return (igualdade);
    }

    void somarMatrizes(char *arq1, char *arq2)
    {
        ifstream arquivo1;
        ifstream arquivo2;
        int matriz2[rows][columns];

        arquivo1.open(arq1);
        arquivo2.open(arq2);

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arquivo1 >> matriz[j][i];
                arquivo2 >> matriz2[j][i];

                cout << " " << matriz[j][i] + matriz2[j][i];
            }
            cout << endl;
        } // fim for
        arquivo1.close();
        arquivo2.close();
    }

    void operarLinhas(char *nome, int cons)
    {
        ifstream arquivo;
        arquivo.open(nome);

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arquivo >> matriz[j][i];
                // matriz[j][i] = matriz[j][i] + matriz[j + 1][i] * cons;
                cout << " " << matriz[j][i] + matriz[j + 1][i] * cons;
            }
            cout << endl;
        }
        arquivo.close();
    }

    void subtrairLinhas(char *arquivo, int cons)
    {
        ifstream arq;
        arq.open(arquivo);

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arq >> matriz[j][i];
                cout << " " << matriz[j][i] - matriz[j + 1][i] * cons;
            }
            cout << endl;
        }
        arq.close();
    }

    void procurarValorRows(char *arquivo, int num)
    {
        ifstream ar1;
        ar1.open(arquivo);
        int linha = 0;
        bool verify = false;

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                ar1 >> matriz[j][i];
                if (matriz[j][i] == num)
                {
                    verify = true;
                    linha = j;
                }
            }
        } // fim for

        if (verify)
        {
            cout << "O valor foi encontrado na linha: " << linha;
        }
        else
        {
            cout << "Valor nao encontrado";
        }
    }

    void procurarValorColumns(char *arquivo, int valor)
    {
        ifstream ar1;
        ar1.open(arquivo);
        int coluna = 0;
        bool verify = false;

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                ar1 >> matriz[j][i];
                if (matriz[j][i] == valor)
                {
                    verify = true;
                    coluna = j;
                }
            }
        } // fim for

        if (verify)
        {
            cout << "O valor foi encontrado na coluna: " << coluna;
        }
        else
        {
            cout << "Valor nao encontrado";
        }
    }

    void matrizTransporsta(char *nome)
    {
        ifstream arq1;
        arq1.open(nome);
        int matriz2[rows][columns];

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                arq1 >> matriz[j][i];
                matriz2[j][i] = matriz[i][j];
                printf(" %d ", matriz[j][i]);
            }
            printf("\n");
        }

        for (int j = 0; j < rows; j++)
        {
            for (int i = 0; i < columns; i++)
            {
                printf(" %d ", matriz2[j][i]);
            }
            printf("\n");
        }
    }

    bool verificarMatriz(int matrix[][3])
    {
        int num = 1;
        bool destiny = false;
        int contador = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (matrix[j][i] == num)
                {
                    contador++;
                }
                num++;
            }
        } // fim for

        if (contador == 3 * 3)
        {
            destiny = true;
        }
        return (destiny);
    }

    bool verificarMatriz2(int matrix[][3])
    {
        bool destiny = false;
        int contador = 0;
        int num = 1;

        for(int j = 0; j < 3; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                if(matrix[j][i] == num)
                {
                    contador++;
                }
                num+=3;
            }
            num = j + 1;
        }
        
        if(contador = 3 * 3)
        {
            destiny = true;
        }
        return destiny;
    }
};

void exercicio01()
{
    ex1 var(3, 3);

    var.gerarAleatoriosMatriz(3, 3);
    var.adicionarArquivo("ex1.txt", 3, 3);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio01 ( )

/**
exercicio02.
*/
void exercicio02()
{
    ex1 data(3, 3);

    data.gerarAleatoriosMatriz(3, 3);
    data.escalarMatrizArq("ex1.txt", 3);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio02 ( )

/**
exercicio03.
*/
void exercicio03()
{
    ex1 ex3(3, 3);

    ex3.gerarAleatoriosMatriz(3, 3);
    if (ex3.testarIdentidade("ex1.txt") == true)
    {
        cout << "E identidade";
    }
    else
    {
        cout << "Nao e identidade";
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio03 ( )

/**
exercicio04.
*/
void exercicio04()
{
    ex1 ex4(3, 3);

    ex4.gerarAleatoriosMatriz(3, 3);
    if (ex4.testarIgualdade("ex1.txt", "matriz2.txt") == true)
    {
        cout << "As matrizes sao iguais";
    }
    else
    {
        cout << "As matrizes sao diferentes";
    }

    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exercicio04 ( )

/**
exercicio05.
*/
void exercicio05()
{
    ex1 ex5(3, 3);

    ex5.gerarAleatoriosMatriz(3, 3);
    ex5.somarMatrizes("ex1.txt", "matriz2.txt");

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio05 ( )

/**
exercicio06.
*/
void exercicio06()
{
    ex1 ex6(3, 3);

    ex6.gerarAleatoriosMatriz(3, 3);
    ex6.operarLinhas("ex1.txt", 3);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio06 ( )

/**
exercicio07.
*/
void exercicio07()
{
    ex1 ex7(3, 3);

    ex7.gerarAleatoriosMatriz(3, 3);
    ex7.subtrairLinhas("ex1.txt", 3);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio07 ( )

/**
exercicio08.
*/
void exercicio08()
{
    ex1 ex8(3, 3);
    int procurado = 0;

    cout << "Valor a ser procurado: " << endl;
    cin >> procurado;

    ex8.gerarAleatoriosMatriz(3, 3);
    ex8.procurarValorRows("ex1.txt", procurado);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio08 ( )

/**
exercicio09.
*/
void exercicio09()
{
    ex1 ex9(3, 3);
    int numero = 0;

    cout << "Numero a ser procurado: " << endl;
    cin >> numero;

    ex9.gerarAleatoriosMatriz(3, 3);
    ex9.procurarValorColumns("ex1.txt", numero);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio09 ( )

/**
exercicio10.
*/
void exercicio10()
{
    ex1 ex10(3, 3);

    ex10.gerarAleatoriosMatriz(3, 3);
    ex10.matrizTransporsta("ex1.txt");

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio10 ( )

// extra01

void extra01()
{
    ex1 extra1(3, 3);
    int matriz[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};

    if(extra1.verificarMatriz(matriz))
    {
        cout << "A Matriz satisfaz" << endl;
    }
    else{
        cout << "Nao satisfaz" << endl;
    }

    pause("Aperte ENTER para sair");
}

void extra02()
{
    ex1 extra2(3, 3);
    int matriz[3][3] = {{1, 4, 7},
                        {2, 5, 8},
                        {3, 6, 9}};

   if(extra2.verificarMatriz2(matriz))
   {
    cout << "Satizfaz a condicao" << endl;
   }
   else{
    cout << "Nao satisfaz" << endl;
   }

   pause("Aperte ENTER para sair");

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
        cout << "exercicio1101 - Programa - v0.0\n " << endl;
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