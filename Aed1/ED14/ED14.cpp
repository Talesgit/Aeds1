#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

class ed14
{
private:
public:
    ed14()
    {
    }

    //-------------------ex1------------------//
    int convertToInt(double x)
    {
        int num = static_cast<int>(x);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return -1;
        }
    }

    int convertToInt(float x)
    {
        int num = static_cast<int>(x);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return -1;
        }
    }

    int convertToInt(char x)
    {
        string str(1, x);
        int num = stoi(str);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return num;
        }
    }

    int convertToInt(int x)
    {
        int num = x;
        return x;
    }

    int convertToInt(string x)
    {
        int num = stoi(x);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return -1;
        }
    }

    //---------------ex2---------------//
    double convertToReal(int x)
    {
        int num = static_cast<double>(x);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return -1;
        }
    }

    double convertToReal(char x)
    {
        string str(1, x);

        double num = stod(str);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return (0.0);
        }
    }

    double convertToReal(string x)
    {
        double num = stod(x);

        if (num != 0)
        {
            return num;
        }
        else
        {
            return -1;
        }
    }

    double convertToReal(double x)
    {
        if (x != 0)
        {
            return x;
        }
        else
        {
            return -1;
        }
    }

    //------------------------------ex3--------------------------//

    bool convertToBool(int x)
    {
        if (x == 0)
        {
            return false;
        }
        else if (x == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool convertToBool(char x)
    {
        if (x == 'T')
        {
            return true;
        }
        else if (x == 'F')
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    bool convertToBool(string x)
    {
        if (x == "true")
        {
            return true;
        }
        else if (x == "false")
        {
            return false;
        }
        else
        {
            return false;
        }
    }

    //------------------------------------------------ex4---------------------------------------------//

    bool contains(string text, int tamanhoVetor, string vetor[])
    {
        bool verify = false;
        for (int i = 0; i < tamanhoVetor; i++)
        {
            if (text == vetor[i])
            {
                verify = true;
            }
        }
        return verify;
    }

    //----------------------------------------------ex5----------------------------------------//

    char *maiusculas(int tamanho, char text[80])
    {
        char *c = new char[tamanho + 1];

        for (int i = 0; i < tamanho; i++)
        {
            c[i] = toupper(text[i]);
        }

        c[tamanho] = '\0';

        if (c[0] != 0)
        {
            return c;
        }
        else
        {
            return text;
        }
    }

    //-------------------------------------------ex6----------------------------------------------//

    char *minusculas(int tamanho, char text[80])
    {
        char *c = new char[tamanho + 1];

        for (int i = 0; i < tamanho; i++)
        {
            c[i] = tolower(text[i]);
        }

        c[tamanho] = '\0';

        if (c[0] != 0)
        {
            return c;
        }
        else
        {
            return text;
        }
    }

    //------------------------------------------ex7---------------------------------------//
    char *replace(int tamanho, char text[80], char original, char novo)
    {
        char *result = new char[tamanho + 1];
        strcpy(result, text);

        for (int i = 0; i < tamanho; i++)
        {
            if (result[i] == original)
            {
                result[i] = novo;
            }
        }

        return result;
    }

    //------------------------------------------ex8------------------------------------------//
    char *criptCesar(int tamanho, char text[])
    {
        char *result = new char[tamanho + 1];
        strcpy(result, text);

        for (int i = 0; i < tamanho; i++)
        {
            if (result[i] >= 'a' && result[i] < 'x')
            {
                result[i] = result[i] + 3;
            }
            else if (result[i] == 'x')
            {
                result[i] = 'a';
                result[i] = result[i] + 3;
            }
            else if (result[i] == 'y')
            {
                result[i] = 'b';
                result[i] = result[i] + 3;
            }
            else if (result[i] == 'z')
            {
                result[i] = 'c';
                result[i] = result[i] + 3;
            }
        }

        if (result[0] != 0)
        {
            return result;
        }
        else
        {
            return text;
        }
    }

    //------------------------------------------------------ex9--------------------------------------------------//

    char *decodificar(int tamanho, char text[])
    {
        char *texto = criptCesar(tamanho, text);

        for(int i  = 0; i < tamanho; i++)
        {
            if(texto[i] >= 'c' && texto[i] <= 'z' )
            {
                texto[i] = texto[i] - 3;
            }
            else if(texto[i] == 'b')
            {
                texto[i] = 'z';
                texto[i] = texto[i] - 3;
            }
            else if(texto[i] == 'a')
            {
                texto[i] = 'y';
                texto[i] = texto[i] - 3;
            }
        }

        return texto;
    }
};

int main()
{
}
