#include <stdio.h>
#include <iostream>

class celula
{
private:
    int valor = 0;
    celula *link;
    celula *linka;

public:
    celula(int valor)
    {
        this->valor = valor;
        link = nullptr;
        linka = nullptr;
    }

    void printCell()
    {
        celula *ptr = this;
        celula *ptra = linka;

        while (ptr != nullptr)
        {
            printf("%d\n", ptr->valor);
            ptr = ptr->link;
            if(ptr != nullptr) ptra = ptr->linka;
        }

        while (ptra != nullptr)
        {
            printf("%d\n", ptra->valor);
            ptra = ptra->linka;
        }
    }

    void connect(celula *c)
    {
        if (c != nullptr)
        {
            this->link = c;
            c->linka = this;
        }
    }
};

int main()
{
    celula* c1 = new celula(1);
    celula* c2 = new celula(2);
    celula* c3 = new celula(3);

    c1->connect(c2);
    c2->connect(c3);
    c1->printCell();
}

