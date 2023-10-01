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

using namespace std;
// ----------------------------------------------- metodos
/**
Method00 - nao faz nada.
*/
void exemplo00()
{
    // nao faz nada
} // fim exemplo00 ( )
/**
exemplo01 - Mostrar certa quantidade de valores.
*/
void exemplo01()
{
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo01 ( )
/**
exemplo02.
*/
void exemplo02()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo02 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo02 ( )
/**
exemplo03.
*/
void exemplo03()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo03 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo03 ( )
/**
exemplo04.
*/
void exemplo04()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo04 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo04 ( )
/**
exemplo05.
*/
void exemplo05()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo05 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo05 ( )
/**
exemplo06.
*/
void exemplo06()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo06 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo06 ( )
/**
exemplo07.
*/
void exemplo07()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo07 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo07 ( )
/**
exemplo08.
*/
void exemplo08()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo08 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo08 ( )
/**
exemplo09.
*/
void exemplo09()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo09 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo09 ( )
/**
exemplo10.
*/
void exemplo10()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo10 - v0.0" << endl;
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo10 ( )
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
        cout << " 1 - " << endl;
        cout << " 2 - " << endl;
        cout << " 3 - " << endl;
        cout << " 4 - " << endl;
        cout << " 5 - " << endl;
        cout << " 6 - " << endl;
        cout << " 7 - " << endl;
        cout << " 8 - " << endl;
        cout << " 9 - " << endl;
        cout << "10 - " << endl;
        // ler do teclado
        cout << endl
             << "Entrar com uma opcao: ";
        cin >> x;
        // escolher acao
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