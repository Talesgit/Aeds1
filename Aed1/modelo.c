/*
ED07 - Tales Rocha Moreira - 27/04/2023
*/
#include "io.h"

void exemplo00()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo01() // mostrar certa quantidade de valores
{

    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo02()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo03()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo04()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo05()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo06()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo07()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo08()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo09()
{
    printf("Aperte ENTER para sair");
    getchar();
}

void exemplo10()
{
    printf("Aperte ENTER para sair");
    getchar();
}

int main()
{
    printf("ED07 - EXEMPLOS - Tales Rocha Moreira");

    int x = 0;

    do
    {
        IO_println(" 0 - exemplo00(SAIR)");
        IO_println(" 1 - exemplo01");
        IO_println(" 2 - exemplo02");
        IO_println(" 3 - exemplo03");
        IO_println(" 4 - exemplo04");
        IO_println(" 5 - exemplo05");
        IO_println(" 6 - exemplo06");
        IO_println(" 7 - exemplo07");
        IO_println(" 8 - exemplo08");
        IO_println(" 9 - exemplo09");
        IO_println("10 - exemplo10");

        x = IO_readint("Entrar com a opcao: ");
        printf("\n");

        switch (x)
        {
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
            printf("Valor invalido");
        }
    } while (x != 0);
}