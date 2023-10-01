!!!!!-Qual a diferença do "x = numero[x]" para "numero[x] = x" ?

A ordem da expressão vai alterar o que?

Testei mudar essa ordem de cima no ex 7 no codigo antes do if, e só entrou no if o ultimo valor indicado para x do vetor, por que?

Neste caso abaixo, o printf vai se repetir toda vez que o numero entrar no if e ele for dado como verdadeiro por causa do loop do for: 

if ( ( x % 3 == 0) && ( x >= inferior && x <= superior  ) ) //verficar IF x e multiplo de 3 e, se x esta no intervalo
    {
        printf("\nE multiplo de 3, e esta no intervalo entre lim superior e inferior o valor que esta na posicao %d: %d",y, x );
        contador++;// contador para mostrar quantos dos valores lidos passaram no teste de condicao
    }
   
O que quero saber é se há uma maneira de de não repetir o printf dentro do if no for, mostrar todos os números que satisfazem o if dentro do mesmo.


!!!!-Caso os elementos dentro do meu vetor forem double ou float, o vetor deve ser declarado como double ou float? Não pode ser inteiro? 

