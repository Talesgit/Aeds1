#include <stdio.h>
#include <iostream>
/*
int main(int argc, char *argv[])
{
    int valorA = 0, valor = 0;
    valorA = (int)argv[1];
    valor = (int)argv[2];

    int mul = valor * valorA;

    printf("%d\n", mul);
}*/

/*
typedef
struct celula
{
    int valor;
    struct celula* link;
}cell;

void set_cellNULL(struct celula obj)
{
    obj.valor = 0;
    obj.link = NULL;
}

void connectAB(struct celula obj1, struct celula obj2)
{
    obj1.link = obj2.link;
    obj2.link = obj1.link;
}

void printCell(cell ob)
{
    while(ob.link != NULL)
    {
        printf("%d\n", ob.valor);
    }

}

int main()
{
    cell c1;
    c1.valor = 1;
    cell c2;
    c2.valor = 2;
    cell c3;
    c3.valor = 3;

    set_cellNULL(c1);
    connectAB(c1, c2);
    connectAB(c2, c3);
    printCell(c1);
}*/

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

