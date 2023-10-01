struct extra1
{
    int *arranjo;
    int tamanho;
};

void ordenarArranjo(char *arquivo, struct extra1 data)
{
    FILE *arq = fopen(arquivo, "rt");
    int controle = 0;

    data.arranjo = (int *)malloc(data.tamanho * sizeof(int));

    printf("Anterior: \n");
    while (controle < data.tamanho)
    {
        fscanf(arq, "%d", &data.arranjo[controle]);
        printf("%d\n", data.arranjo[controle]);
        controle++;
    }
    fclose(arq);
    printf("\n");

    // ordenar
    for (int j = 0; j < data.tamanho - 1; j++)
    {
        for (int i = 0; i < data.tamanho - j - 1; i++)
        {

            if (data.arranjo[i] > data.arranjo[i + 1])
            {
                int aux = data.arranjo[i];
                data.arranjo[i] = data.arranjo[i + 1];
                data.arranjo[i + 1] = aux;
            }
        }
    }

    printf("Ordenado: \n");
    for (int i = 0; i < data.tamanho; i++)
    {
        printf("%d\n", data.arranjo[i]);
    }
}

int main()
{
    struct extra1 man;
    char nome[80];

    printf("Qual o arquivo pegar o vetor? ");
    scanf("%s", nome);
    printf("\nQuantidade de numeros no arquivo: ");
    scanf("%d", &man.tamanho);

    ordenarArranjo(nome, man);

    getchar();
}