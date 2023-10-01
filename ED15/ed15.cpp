/*
Ed-15 - v0.0. - __ / __ / _____
Author: ________________________
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits>   // std::numeric_limits
#include <string>   // para cadeias de caracteres
#include <cstring>
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

class ed15
{
private:
    int *array;
    int *array2;
    int lenght;

public:
    ed15()
    {
    }

    ed15(int *array, int lenght)
    {
        this->array = array;
        this->lenght = lenght;
    }

    ed15(int *array, int *array2, int lenght)
    {
        this->array = array;
        this->array2 = array2;
        this->lenght = lenght;
    }

    void addCaracFinal(int tamanho, char *cadeia, char c)
    {
        cout << endl;
        cout << "Antes: " << cadeia;
        *(cadeia + tamanho) = c;
        *(cadeia + tamanho + 1) = 0;

        cout << endl;
        cout << "Depois: " << cadeia;

        pause("Aperte ENTER");
    }

    void removeChar(char *s)
    {
        cout << "Antes: " << s;
        int len = strlen(s);
        *(s + len - 1) = '\0';

        cout << endl;
        cout << "Depois: " << s;
        pause("Aperte ENTER");
    }

    void addBegChar(char *s, char c)
    {
        cout << "Antes: " << s;
        int len = strlen(s);

        for (int i = len; i >= 0; i--)
        {
            *(s + i + 1) = *(s + i);
        }

        s[0] = c;
        s[len + 1] = '\0';

        cout << endl;
        cout << "Depois: " << s;
        pause("Aperte ENTER");
    }

    void removeBegChar(char *s)
    {
        cout << "Antes: " << s;
        int len = strlen(s);

        for (int i = 1; i <= len; i++)
        {
            s[i - 1] = s[i];
        }

        cout << endl;
        cout << "Depois: " << s;
        pause("Aperte ENTER para sair");
    }

    void firstAppearCarac(char *s, char c)
    {
        int length = strlen(s);
        int pos = 0;

        for (int i = 0; i < length; i++)
        {
            if (c == *(s + i))
            {
                pos = i;
            }
        }

        cout << "Caracatere apareceu na pos: " << pos;
        pause("Aperte ENTER para sair");
    }

    void separarUntilDel(char *s, char delimitador)
    {
        int len = strlen(s);
        char *s2 = (char *)malloc(len + 1 * sizeof(char));

        for (int i = 0; i < len; i++)
        {
            if (*(s + i) == delimitador)
            {
                break;
            }
            *(s2 + i) = *(s + i);
        }
        int tam = strlen(s2);
        *(s2 + tam - 1) = '\0';
        cout << "Separada: " << s2;
        free(s2);
        pause("Aperte ENTER para sair");
    }

    int cmpArray()
    {
        int count = 0;
        for (int i = 0; i < lenght; i++)
        {
            cout << array[i] << endl;
            cout << array2[i] << endl;
            if (*(array + i) == *(array2 + i))
            {
                count++;
            }
            else if (*(array + i) < *(array2 + i))
            {
                return -1;
            }
            else if (*(array + i) > *(array2 + i))
            {
                return 1;
            }
        }

        if (count == lenght)
        {
            return 0;
        }
    }

    int *cat_Array()
    {
        int *arrayCpy = (int *)malloc((lenght * 2) * sizeof(int));

        int k = 0;
        for (int i = 0; i < lenght; i++)
        {
            *(arrayCpy + k) = *(array + i);
            k++;
        }
        for (int i = 0; i < lenght; i++)
        {
            *(arrayCpy + k) = *(array2 + i);
            k++;
        }

        return arrayCpy;
    }

    int *array_Seek(int x)
    {
        int *result = (int *)malloc(1 * sizeof(int));
        for (int i = 0; i < lenght; i++)
        {
            if (*(array + i) == x)
            {
                *result = *(array + i);
                return result;
            }
        }
        return NULL;
    }

    int *separarArray(int start)
    {
        int *arraySpr = (int *)malloc((lenght - start + 1) * sizeof(int));
        int k = 0;

        for (int i = start; i < lenght; i++)
        {
            *(arraySpr + k) = *(array + i);
            k++;
        }
        return arraySpr;
    }

    int *intercalarArray(int start1, int start2)
    {
        int lenght3 = (lenght - start1) + (lenght - start2) + 1;
        int *array3 = (int *)malloc(lenght3 * sizeof(int));

        int k = 0;
        for (int i = start1; i < lenght; i++)
        {
            *(array3 + k) = *(array + i);
            k++;
        }
        for (int i = start2; i < lenght; i++)
        {
            *(array3 + k) = *(array2 + i);
            k++;
        }

        return array3;
    }

    int *intercalarArrayCrescentes()
    {
        int* array3 = new int[lenght * 2];

        int k  = 0;
        for(int i = 0; i < lenght; i++)
        {
            *(array3 + k) = *(array + i);
            k++;
        }
        for(int i = 0; i < lenght; i++)
        {
            *(array3 + k) = *(array2 + i);
            k++;
        }
        return array3;
    }
};

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
    ed15 obj;
    char cadeia[80];
    char carac;
    cout << "Digite a cadeia de carac a adicionar: ";
    cin >> cadeia;

    cout << endl;
    cout << "Qual caractere add no fim na cadeia: ";
    cin >> carac;

    int tamanho = strlen(cadeia);

    obj.addCaracFinal(tamanho, cadeia, carac);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo01 ( )

/**
exemplo02.
*/
void exemplo02()
{
    ed15 obj;
    char cadeia[80];
    cout << "Palavra para remover ultimo caractere: ";
    cin >> cadeia;

    obj.removeChar(cadeia);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo02 ( )

/**
exemplo03.
*/
void exemplo03()
{
    ed15 obj;
    char cadeia[50];
    char carac;
    cout << "Palavra a adicionar carac no inicio: ";
    cin >> cadeia;

    cout << endl;
    cout << "Caractere a adicionar: ";
    cin >> carac;

    obj.addBegChar(cadeia, carac);
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo03 ( )

/**
exemplo04.
*/
void exemplo04()
{
    ed15 obj;
    char cadeia[80];
    cout << "Palavra a remover carac no inicio: ";
    cin >> cadeia;

    obj.removeBegChar(cadeia);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo04 ( )

/**
exemplo05.
*/
void exemplo05()
{
    ed15 obj;
    char cadeia[80];
    char c;

    cout << "Qual cadeia de carac analisar: ";
    cin >> cadeia;

    cout << endl;
    cout << "Qual caractere procurar: ";
    cin >> c;

    obj.firstAppearCarac(cadeia, c);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo05 ( )

/**
exemplo06.
*/
void exemplo06()
{
    ed15 obj;
    char cadeia[80];
    char limit;

    cout << "Qual cadeia de carac separar: ";
    cin >> cadeia;

    cout << endl;
    cout << "Qual o delimitador?: ";
    cin >> limit;

    obj.separarUntilDel(cadeia, limit);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo06 ( )

/**
exemplo07.
*/
void exemplo07()
{
    int tamanho = 0;
    cout << "Quantos valores colocar dentro do vetor? ";
    cin >> tamanho;
    int array1[tamanho];
    int array2[tamanho];

    cout << "popular primeiro array: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *(array1 + i);
    }

    cout << "popular segundo array: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *(array2 + i);
    }

    ed15 obj(array1, array2, tamanho);

    if (obj.cmpArray() == 0)
    {
        cout << "Arrays iguais" << endl;
    }
    else if (obj.cmpArray() == -1)
    {
        cout << "Valor da diferenca menor" << endl;
    }
    else if (obj.cmpArray() == 1)
    {
        cout << "Valor da diferenca maior" << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo07 ( )

/**
exemplo08.
*/
void exemplo08()
{
    int tamanho = 0;
    cout << "Qual o tamanho dos dois arrays para juntar? ";
    cin >> tamanho;
    int array1[tamanho];
    int array2[tamanho];
    cout << endl;

    cout << "Popular primeiro array: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *(array1 + i);
    }
    cout << "Popular segundo array: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *(array2 + i);
    }

    ed15 obj(array1, array2, tamanho);

    printf("\nArray copy:\n");
    int *result = obj.cat_Array();
    for (int i = 0; i < tamanho * 2; i++)
    {
        cout << *(result + i) << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo08 ( )

/**
exemplo09.
*/
void exemplo09()
{
    int tamanho = 0;
    int x;
    cout << "Tamanho do array: " << endl;
    cin >> tamanho;
    int array[tamanho];

    cout << "Popular array: " << endl;
    for (int i = 0; i < tamanho; i++)
        cin >> *(array + i);
    cout << "Qual valor procurar ocorrencia: " << endl;
    cin >> x;

    ed15 obj(array, tamanho);

    int *result = obj.array_Seek(x);

    if (result != NULL)
    {
        cout << "Numero encontrado: " << result[0] << endl;
    }
    else
    {
        cout << "Numero nao encontrado." << endl;
    }

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo09 ( )

/**
exemplo10.
*/
void exemplo10()
{
    int tamanho = 0;
    int num = 0;
    cout << "Tamanho do array a separar: " << endl;
    cin >> tamanho;
    int array[tamanho];

    cout << "Popular array: " << endl;
    for (int i = 0; i < tamanho; i++)
    {
        cin >> *(array + i);
    }
    cout << "A partir de qual numero separar: " << endl;
    cin >> num;

    ed15 obj(array, tamanho);
    int *result = obj.separarArray(num);
    cout << "Array separado: " << endl;
    for (int i = 0; i < tamanho - num; i++)
        cout << *(result + i) << endl;

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exemplo10 ( )

void extra01()
{
    int tamanho1 = 0;
    cout << "Tamanho do primeiro array a intercalar: " << endl;
    cin >> tamanho1;

    int array1[tamanho1], array2[tamanho1];
    cout << "Popular primeiro array: " << endl;
    for (int i = 0; i < tamanho1; i++)
    {
        cin >> *(array1 + i);
    }
    cout << "Popular segundo array: " << endl;
    for (int i = 0; i < tamanho1; i++)
    {
        cin >> *(array2 + i);
    }

    int start1 = 0, start2 = 0;
    cout << "A partir de qual valor intercalar do array1: " << endl;
    cin >> start1;
    cout << "A partir de qual do array2: " << endl;
    cin >> start2;

    ed15 obj(array1, array2, tamanho1);
    int *result = obj.intercalarArray(start1, start2);
    cout << "Array novo intercalado: " << endl;
    for (int i = 0; i < (tamanho1 - start1) + (tamanho1 - start2); i++)
    {
        cout << *(result + i) << endl;
    }

    pause("Aperte ENTER para continuar");
}

void extra02()
{
    int tamanho = 0;
    cout << "Qual o tamanho dos arranjos? :" << endl;
    cin >> tamanho;
    int array[tamanho];
    int array2[tamanho];

    cout << "Popular primeiro array, crescente: "<< endl;
    for(int i = 0; i < tamanho; i++)
    {
        cin >> *(array + i);
    }
    cout << "Popular segundo array, crescente a partir do primeiro: " << endl;
    for(int i = 0; i < tamanho; i++)
    {
        cin >> *(array2 + i);
    }
    bool falso = false;
    for(int i = 1; i < tamanho; i++)
    {
        if(*(array + i) < *(array + i - 1))
        {
            cout << "Erro nao esta em ordem crescente" << endl;
            falso = true;
        }

        if(*(array2 + i) < *(array2 + i - 1))
        {
            cout << "Erro nao esta em ordem crescente" << endl;
            falso = true;
        }
    }

    ed15 obj(array, array2, tamanho);
    if(falso == false)
    {
        cout << "Array intercalado: " << endl;
        int *result = obj.intercalarArrayCrescentes();
        for(int i = 0; i < tamanho * 2; i++)
        {
            cout << *(result + i) << endl;
        }
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
        cout << "Ed15\n " << endl;
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
        cout << "11(extra01) - " << endl;
        cout << "12(extra02) - " << endl;
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