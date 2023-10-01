/*#include <iostream>
using namespace std;

class cell
{
private:
    int valor;
    cell *linkE;
    cell *linkD;

public:
    cell(int x)
    {
        valor = x;
        linkE = nullptr;
        linkD = nullptr;
    }

    void connect(cell *c)
    {
        if (c != nullptr)
        {
            this->linkD = c;
        }
    }

    void connectE(cell *c)
    {
        if (c != nullptr)
        {
            this->linkE = c;
        }
    }

    void printCell()
    {
        cell *ptr = this;
        cell *ptrE = linkE;
        while (ptr != nullptr)
        {
            cout << ptr->valor << endl;
            ptr = ptr->linkD;
            if(ptr != nullptr)
            {
                ptrE = ptr->linkE;
            }
        }

        while (ptrE != nullptr)
        {
            cout << ptrE->valor << endl;
            ptrE = ptrE->linkE;
        }
    }
};

int main()
{
    cell *c0 = new cell(0);
    cell *c1 = new cell(1);
    cell *c2 = new cell(2);

    c0->connect(c1);
    c1->connect(c2);

    c2->connectE(c1);
    c1->connectE(c0);

    c0->printCell();
}
*/
#include <iostream>

typedef struct celula celula;
struct celula
{
    long int conteudo;
    celula *prox;
};

int main(void)
{
    celula cell;
    printf("sizeof (celula) = %zu\n, sizeof (conteudo) = %zu\n, sizeof (celula *prox) = %zu\n\n\n",  sizeof(cell), sizeof(cell.conteudo), sizeof(cell.prox));
    printf("\n");
    printf("sizeof(long int): %i\n", sizeof(long int));
    printf("sizeof(long long int): %i\n", sizeof(long long int));
    printf("Tamanho de ponteiro: %d bytes\n", sizeof(void*));

    return EXIT_SUCCESS;
}
