typedef struct
{
    char codigo[10];
    char titulo[50];
    char secao[20];
    char tipo[10];
} Figurinha;

typedef struct
{
    Figurinha *fig_coladas;
    Figurinha *fig_faltantes;
    Figurinha *fig_repetidas_ou_nao_coladas;
    Figurinha *fig_disponiveis;
    int quant_fig;
    int posicao_no_album;
    int posicao_repetidas_ou_nao_coladas;
    int posicao_faltantes;
    float porcentagem_do_album;
    char proprietario[50];
    float dinheiro_gasto;
    char proprietario[50];
    int quant_n_colada;
    int quant_colada;
    int quant_repetida;
    float porcentagem_do_album;
    float dinheiro_gasto;
    int contador_figurinha;
} Album;

void comprar_envelope(Figurinha *figurinha, Album album)
{
    srand(time(NULL));

    // se colocar mais de um album temos q fazer um if e switch pra escolher o album
    printf("\n");
    printf("Vamos comprar pacotes de figurinhas! Lembrando que cada pacote possui 5 figurinhas :)\n");
    // printf("Para qual album voce deseja comprar figurinhas? ");

    printf("Neste pacote voce obteve:\n");

    for (int i = 0; i < 5; i++)
    {
        char opcao;
        int aux = 0;
        int num = rand() % 10; // gerar um numero de 0 a 9
        printf("FIGURINHA %d:\n", i + 1);
        printf("| Codigo | Titulo           | Secao       | Tipo       |\n");
        printf("| %-6s | %-16s | %-11s | %-10s |\n", figurinha[num].codigo, figurinha[num].titulo, figurinha[num].secao, figurinha[num].tipo);

        // tenho q fazer o strcomp pra ver se ta no album antes de perguntar se quer colar ou nao

        if (album.posicao_no_album == 0)
        {
            album.fig_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album.fig_repetidas_ou_nao_coladas = (Figurinha *)calloc(1, sizeof(Figurinha));
            album.fig_faltantes = (Figurinha *)calloc(1, sizeof(Figurinha));
        }
        else
        {

            // realocar a relacao de figurinhas coladas, repetidas/nao coladas e faltantes
            if (album.posicao_no_album > 0)
            {
                for (int l = 1; l <= album.posicao_no_album; l++)
                {
                    album.fig_coladas = realloc(album.fig_coladas, (album.posicao_no_album + 1) * sizeof(Figurinha));
                }
            }
            if (album.posicao_repetidas_ou_nao_coladas > 0)
            {
                for (int l = 1; l <= album.posicao_repetidas_ou_nao_coladas; l++)
                {
                    album.fig_repetidas_ou_nao_coladas = realloc(album.fig_repetidas_ou_nao_coladas, (album.posicao_repetidas_ou_nao_coladas + 1) * sizeof(Figurinha));
                }
            }

            if (album.posicao_faltantes > 0)
            {
                for (int l = 1; l <= album.posicao_faltantes; l++)
                {
                    album.fig_faltantes = realloc(album.fig_faltantes, (album.posicao_faltantes + 1) * sizeof(Figurinha));
                }
            }
        }

        for (int j = 0; j <= album.quant_fig; j++)
        {
            if (strcasecmp(figurinha[num].codigo, album.fig_coladas[j].codigo) == 0)
            {
                aux++;
                break;
            }
        }

        if (aux == 1)
        {
            printf("Voce ja possui esta figurinha no seu album! Parabens :)\nAgora, esta figurinha esta salva na relacao de figurinhas repetidas/nao coladas.\n");
            album.fig_repetidas_ou_nao_coladas[album.posicao_repetidas_ou_nao_coladas] = figurinha[num];
            album.posicao_repetidas_ou_nao_coladas++;
        }
        else
        {
            setbuf(stdin, NULL);
            printf("Voce nao possui esta figurinha em seu album. Deseja cola-la?\nS para sim e N para nao. ");
            scanf("%c", &opcao);
            setbuf(stdin, NULL);

            if (opcao == 'S' || opcao == 's')
            {

                album.fig_coladas[album.posicao_no_album] = figurinha[num];
                album.posicao_no_album++;

                album.porcentagem_do_album = ((100.0 * album.posicao_no_album) / 678);
            }

            if (opcao == 'N' || opcao == 'n')
            {
                printf("Tudo bem, voce ainda tem a chance de obte-la novamente!\nEsta figurinha foi salva na relacao de figurinhas nao coladas/repetidas.\n");
                album.fig_repetidas_ou_nao_coladas[album.posicao_repetidas_ou_nao_coladas] = figurinha[num];
                album.posicao_repetidas_ou_nao_coladas++;
            }
        }
        setbuf(stdin, NULL);
        printf("\n");
        printf("Porcentagem concluida deste album: %.2f\n\n", album.porcentagem_do_album);
    }
}
