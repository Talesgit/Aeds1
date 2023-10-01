-testei criar um contador dentro da struct no exercicio5, e tentei incrementa-lo dentro da função acessando dessa forma: "variavel.contador++", 
e nos testes com o printf estava mostrando lixo, só funcionou quando coloquei um contador dentro da função, por que isso acontece??

-   char nome[100];
    printf("Qual arquivo tester: "); // POR QUE NAO FUNCIONOU COM IO_READSTRING?, erro "expression must be an modifiable value"
    scanf("%s", nome);

-No exercicio07, tentei colocar um while para ir escaneando ate o fim do arquivo e fazer um contador para testar a quantidade de numeros existente na matriz(no arquivo)
para criar o vetor com tamanho contador e não deu certo, dentro do loop para popular o vetor deu comportamento indefinido,
a parte que conta os numeros do arquivo está comentada, e entrei com o tamanho do do teclado depois, pode conferir? Qual seria a solução pra isso? calcular o tamanho do arquivo para uma condição de parada
E na linha 413, o exercicio07, o printf esta mostrando lixo junto com os dados do vetor.

-Algo parecido no exercicio08, a unica forma de colocar a condição de parada para leitura do arquivo, é indicando a quantidade pelo teclado? Testei no 7 um contador e deu errado

-Como faço para testar se os tamanhos são compatíveis? Estou colocando sempre o tamanho pelo teclado

-No ex9, na linhas de:  dados.matriz2[i] = (int**)malloc(dados.cols1 * sizeof(int));, no sinal de '=', esta mostrando um warning: assignment from incompatible pointer type . O que seria?

-Confira a saida do Extra2 por favor?
