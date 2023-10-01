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
    std::cin.clear(); // getchar
    std::cout << std::endl
              << text;
    std::cin.ignore();
    std::getline(std::cin, dummy); // scanf
    std::cout << std::endl
              << std::endl;
} // end pause ( )
// ----------------------------------------------- classes / pacotes
#include "myArray.hpp"

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
    // definir dados
    Array<int> int_array(5, 0);
    int_array.set(0, 1);
    int_array.set(1, 2);
    int_array.set(2, 3);
    int_array.set(3, 4);
    int_array.set(4, 5);
    // identificar
    cout << "\nEXEMPLO1101 - exemplo01 - v0.0\n"
         << endl;
    // mostrar dados
    int_array.print();
    // reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo01 ( )

/**
exemplo02.
*/
void exemplo02()
{
    // definir dados
    Array<int> int_array(5, 0);
    // identificar
    cout << endl
         << "EXEMPLO1110 - exemplo02 - v0.0" << endl;
    // ler dados
    int_array.read();
    // mostrar dados
    int_array.print();
    // reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo02 ( )
/**
exemplo03.
*/
void exemplo03()
{
    // definir dados
    Array<int> int_array(5, 0);
    // identificar
    cout << endl
         << "EXEMPLO1110 - exemplo03 - v0.0" << endl;
    // ler dados
    int_array.read();
    // int_array.length
    //  mostrar dados
    int_array.fprint("INT_ARRAY1.TXT");
    // reciclar espaco
    int_array.free();
    // encerrar
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo03 ( )

/**
exemplo04.
*/

void exemplo04()
{
    // definir dados
    Array<int> int_array(5, 0);
    // identificar
    cout << endl
         << "EXEMPLO1110 - exemplo04 - v0.0" << endl;
    // ler dados
    int_array.fread("INT_ARRAY1.TXT");
    // mostrar dados
    int_array.print();
    // reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo04 ( )

/**
exemplo05.
*/

void exemplo05()
{
    // definir dados
    int other[] = {1, 2, 3, 4, 5};
    Array<int> int_array(5, other);
    // identificar
    cout << endl
         << "EXEMPLO1110 - Method05 - v0.0" << endl;
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_array.print();
    // reciclar espaco
    int_array.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim method05 ( )

/**
exemplo06.
*/

void exemplo06()
{
    // identificar
    cout << endl
         << "EXEMPLO1101 - exemplo06 - v0.0" << endl;

    // definir dados
    Array<int> int_array1(1, 0);

    // ler dados
    int_array1.fread("INT_ARRAY1.TXT");
    // mostrar dados
    cout << "\nOriginal\n"
         << endl;
    int_array1.print();
    // criar copia
    Array<int> int_array2(int_array1);
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_array2.print();
    // reciclar espaco
    int_array1.free();
    int_array2.free();

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo06 ( )

/**
exemplo07.
*/
void exemplo07()
{
    // definir dados
    Array<int> int_array1(1, 0);
    Array<int> int_array2(1, 0);
    // identificar
    cout << endl
         << "EXEMPLO1110 - Method07 - v0.0" << endl;
    // ler dados
    int_array1.fread("INT_ARRAY1.TXT");
    // mostrar dados
    cout << "\nOriginal\n"
         << endl;
    int_array1.print();
    // copiar dados
    int_array2 = int_array1;
    // mostrar dados
    cout << "\nCopia\n"
         << endl;
    int_array2.print();
    // reciclar espaco
    int_array1.free();
    int_array2.free();
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo07 ( )
/**
exemplo08.
*/
void exemplo08()
{

    // definir dados
    int other[] = {1, 2, 3};
    Array<int> int_array1(3, other);
    Array<int> int_array2(3, other);
    int x;
    // identificar
    cout << endl
         << "EXEMPLO1110 - Method08 - v0.0" << endl;
    // mostrar dados
    cout << endl;
    cout << "Array_1";
    int_array1.print();
    // mostrar dados
    cout << "Array_2";
    int_array2.print();
    // mostrar comparacao
    cout << "Igualdade = " << (int_array1 == int_array2) << endl;
    // alterar dado
    int_array2.set(0, (-1));
    // mostrar dados
    cout << endl;
    cout << "Array_1" << endl;
    int_array1.print();
    // mostrar dados
    cout << "Array_2" << endl;
    int_array2.print();
    // mostrar comparacao
    cout << "Igualdade = " << (int_array1 == int_array2) << endl;
    // reciclar espaco
    int_array1.free();
    int_array2.free();
    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exemplo08 ( )

/**
exemplo09.
*/

void exemplo09()
{
    // definir dados
    Array<int> int_array1(1, 0);
    Array<int> int_array2(1, 0);
    Array<int> int_array3(1, 0);
    // identificar
    cout << endl
         << "EXEMPLO1110 - Method09 - v0.0" << endl;
    // ler dados
    int_array1.fread("INT_ARRAY1.TXT");
    // copiar dados
    int_array2 = int_array1;
    // somar dados
    int_array3 = int_array2 + int_array1;
    // mostrar dados
    cout << endl;
    cout << "Original" << endl;
    int_array1.print();
    // mostrar dados
    cout << "Copia" << endl;
    int_array2.print();
    // mostrar dados
    cout << "Soma" << endl;
    int_array3.print();
    // reciclar espaco
    int_array1.free();
    int_array2.free();
    int_array3.free();
    // encerrar
    pause("Apertar ENTER para continuar");

} // fim exemplo09 ( )
/**
exemplo10.
*/
void exemplo10()
{

    // definir dados
    int other[] = {1, 2, 3, 4, 5};
    Array<int> int_array(5, other);
    int x;
    // identificar
    cout << endl
         << "EXEMPLO1110 - Method10 - v0.0" << endl;
    // mostrar dados
    cout << "\nAcesso externo" << endl;
    for (x = 0; x < int_array.getLength(); x = x + 1)
    {
        cout << endl
             << setw(3) << x << " : " << int_array[x];
    } // fim repetir
    cout << endl
         << "\nFora dos limites:";
    cout << endl
         << "[-1]: " << int_array.get(-1) << endl;
    cout << endl
         << "[" << int_array.getLength() << "]: "
         << int_array[int_array.getLength()] << endl;
    // reciclar espaco
    int_array.free();

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
