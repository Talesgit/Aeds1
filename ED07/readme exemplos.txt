Por que a necessidade de tentar ler o primeiro antes?
como "// tentar ler o primeiro
         strcpy ( linha, IO_freadln ( arquivo ) );" ??
testei comentar a linha e a primeira palavra continuou a ser impressa, mas apareceu "lixo", simbolos estranhos.

- strcpy(linha, IO_readln("")); - Neste caso, está sendo copiado para "linha" o dado lido com o readln??
- No exemplo7 experimentei colocar um printf para imprimir as linhas dentro do while, e no fim apareceu um simbolo estranho, por que?

-while (!feof(entrada))
    {
        // contar linha lida
        contador = contador + 1;
        // gravar no destino,
        // EXCEPCIONALMENTE sem a ultima linha, nesse caso

        if (strcmp("PARAR", linha) != 0)
        { // COPIA A LINHA ATE "PARAR"
            IO_fprintln(saida, linha);
        } // fim se

        // ler da origem
        strcpy(linha, IO_freadln(entrada));
        printf("%s\n", linha);
    } // fim repetir

Como a leitura passa para a próxima palavra? exemplo: tales , após ter lido"tales" como o loop passa para ler e copiar a palavra debaixo?
                                                      aluno

