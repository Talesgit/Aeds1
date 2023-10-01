/*
Ed-13 - v0.0. - __ / __ / _____
Author: ________________________
*/
// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <fstream>
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
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

class contato
{
private:
    string nome;
    string fone;

    string fone2;

    bool isValidFone(string fone)
    {
        bool valid = true;
        for (int i = 0; i < fone.size(); i++)
        {
            if ((fone[i] < '0' || fone[i] > '9') && fone[i] != '-')
            {
                valid = false;
            }
        }
        return (valid);
    }

public:
    contato()
    {
    }

    contato(string fone1, string fone2)
    {
    }

    void tel2(string name, string num1, string num2)
    {
        nome = name;
        fone = num1;
        fone2 = num2;
        if (isValidFone(fone2))
        {
            cout << "segundo telefone lido" << endl;
        }
        else
        {
            cout << "Erro na leitura do 2 telefone" << endl;
        }
    }

    void printfTel2()
    {
        cout << endl;
        cout << "fone(anterior): " << fone2 << endl;
    }
    void readNome(string message)
    {
        cout << message;
        getchar();
        getline(cin, nome);

        if (nome.empty())
        {
            cout << "O nome esta vazio" << endl;
        }
        else
        {
            cout << "O nome foi lido" << endl;
        }
    }

    void readFone(string message)
    {
        cout << message;
        cin >> fone;

        if (fone.size() == 0)
        {
            cout << "O numero esta vazio";
        }
        else
        {
            cout << "O numero foi lido" << endl;
        }

        if (isValidFone(fone) == false)
        {
            cout << endl;
            cout << "Valor invalido, diferente de algarismo e '-'";
        }
    }

    void fromFile(string arquivo)
    {
        ifstream file(arquivo);
        if (!file)
        {
            cout << "Erro ao abrir o arquivo";
        }

        file >> nome;
        file >> fone;

        if (!nome.empty())
        {
            cout << nome << endl;
        }
        else
        {
            cout << "Nome vazio" << endl;
        }

        if (!fone.empty())
        {
            cout << fone << endl;
        }
        else
        {
            cout << "Fone vazio" << endl;
        }

        file.close();
    }

    void numTels()
    {
        tel2("Tales", "22-482813", "000000");

        if (isValidFone(fone) && isValidFone(fone2))
        {
            printf("\nHa dois numeros lidos\n");
        }
        else
        {
            printf("\nSomente um numero foi lido");
        }
    }

    void toFile(string arquivo)
    {
        ofstream file(arquivo);

        if (!file)
        {
            cout << "Erro ao abrir o arquivo";
        }

        file << nome;
        file << endl;

        if (isValidFone(fone) == true)
        {
            file << fone;
        }

        if (file.fail())
        {
            cout << "Erro em ler os dados";
        }

        file.close();
    }

    void setFone2(string fone)
    {
        if (isValidFone(fone) == true)
        {
            fone2 = fone;
        }
        cout << endl;
        cout << fone2;
    }

    void changeFone2(string fone)
    {
        if (isValidFone(fone) == true)
        {
            fone2 = fone;
        }
        cout << endl;
        cout << fone2;
    }

    void removeFone2()
    {
        string null = "";
        fone2 = null;

        cout << "fone2(removed): " << fone2;
    }
};

void exercicio01()
{
    contato var("31-97641", "21-9865");
    contato var2;
    var2.readFone("Fone: ");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio02 ( )

/**
exercicio03.
*/
void exercicio03()
{
    contato var3;
    var3.readFone("Fone: ");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio03 ( )

/**
exercicio04.
*/
void exercicio04()
{
    contato var4;
    var4.fromFile("contato.txt");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio04 ( )

/**
exercicio05.
*/
void exercicio05()
{
    contato var5;
    var5.readNome("Nome: ");
    var5.readFone("Fone: ");

    var5.toFile("toContato.txt");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio05 ( )

/**
exercicio06.
*/
void exercicio06()
{
    contato var6;
    var6.tel2("Tales", "55-87361777", "11-3562765");
    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio06 ( )

/**
exercicio07.
*/
void exercicio07()
{
    contato var7;
    var7.numTels();

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio07 ( )

/**
exercicio08.
*/
void exercicio08()
{
    contato ex8;
    string tel;
    cout << "Deseja adicionar mais um numero?(digite o numero) " << endl;
    cin >> tel;

    ex8.setFone2(tel);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio08 ( )

/**
exercicio09.
*/
void exercicio09()
{
    contato ex9;
    string num;
    cout << "Mudar o telefone 2: " << endl;
    cin >> num;

    ex9.changeFone2(num);

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio09 ( )

/**
exercicio10.
*/
void exercicio10()
{
    contato ex10;

    ex10.tel2("Tales", "22-3326243", "13-9718264");
    ex10.printfTel2();
    ex10.removeFone2();

    // encerrar
    pause("Apertar ENTER para continuar");
} // fim exercicio10 ( )

class extra1
{
private:
    string nome;
    int numTelefones;
    string telefones[10];

public:
    void dados(string name, int quantidadeTelefones, const int fones[])
    {
        nome = name;
        numTelefones = quantidadeTelefones;

        for (int i = 0; i < numTelefones; i++)
        {
            telefones[i] = to_string(fones[i]);
        }
    }

    void imprimirFones()
    {
        for (int i = 0; i < numTelefones; i++)
        {
            cout << "Numero " << i << ": " << telefones[i] << endl;
        }
    }
};

void extra01()
{
    extra1 var11;
    int quantidade = 3;

    cout << "3 telefones serao testados  ";

    int fones[3];

    for (int i = 0; i < quantidade; i++)
    {

        cout << " fone: ";
        cin >> fones[i];
    }

    var11.dados("Aluno", quantidade, fones);
    var11.imprimirFones();
}

void extra02()
{
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