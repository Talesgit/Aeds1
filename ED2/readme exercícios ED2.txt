No exercício 7, "Exemplo0217.c", para o segundo valor coloquei a condição :
if ( y % 2 == 1 && y > 0)
{
    printf("O segundo valor e positivo\n");
}
else if ( y % 2 == 1 && y < 0)
{
    printf("O segundo valor e impar porem negativo\n");
}
else
{
    printf("O segundo valor nao e impar\n");
}
Houve um problema de que, ao inserir exemplo o número -15, ele printava "O segundo valor nao e impar", ao invés de printar o else if, que seria a condição correta dele: impar porem negativo.
Ele só considerou impar os positivos.