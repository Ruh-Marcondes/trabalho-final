#include "BIBLIOTECA.h"
#include <locale.h>

void cadastrarLivro(Livro *livros, int *totalLivros);
void emprestarLivro(Livro *livros, int totalLivros);
void devolverLivro(Livro *livros, int totalLivros);
void listarEmprestados(Livro *livros, int totalLivros);
void listarTodososLivros(Livro *livros, int totalLivros);

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;

    carregarDados(&biblioteca, &totalLivros);

    do
    {
        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastrarLivro(biblioteca, &totalLivros);
            break;
        case 2:
            emprestarLivro(biblioteca, totalLivros);
            break;
        case 3:
            devolverLivro(biblioteca, totalLivros);
            break;
        case 4:
            listarEmprestados(biblioteca, totalLivros);
            break;
        case 5:
            listarTodososLivros(biblioteca, totalLivros);
            break;
        case 0:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Op��o  Inv�lida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void menu()
{
    printf("\nMenu:\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Emprestar Livro\n");
    printf("3. Devolver Livro\n");
    printf("4. Listar Livros Emprestados\n");
    printf("5. Listar todos os Livros\n");
    printf("0. Sair\n");

    printf("Escolha uma op��o: ");
}
void cadastrarLivro(Livro *livros, int *totalLivros)
{printf("Cadastrar Livro:\n");

    // Calcular o pr�ximo c�digo como o total atual de livros mais 1
    livros[*totalLivros].codigo = *totalLivros + 1;

    printf("ISBN: ");
    scanf(" %d", &livros[*totalLivros].isbn);

    printf("T�tulo: ");
    scanf(" %[^\n]", livros[*totalLivros].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livros[*totalLivros].autor);

    livros[*totalLivros].emprestado = 0; // Inicializa como dispon�vel
    (*totalLivros)++;
    salvarDados(livros, *totalLivros);
    printf("Livro cadastrado com sucesso!\n");
}

void emprestarLivro(Livro *livros, int totalLivros)
{
    // mudar a val do emprestado pra 1 e precisa verificar se já não está emprestado;

    printf("Escolha o met�do de buscas:");
    printf("1. ISBN\n");
    printf("2. Autor\n");
    printf("3. Titulo\n");

    int opcBusca = 0;
    // int encontrado = 0;
    scanf("%d", &opcBusca);

    switch (opcBusca)
    {
    case 1:
        printf("\nDigite o ISBN: ");
        int isbnn;
        scanf("%d", &isbnn);

        for (int i = 0; i < totalLivros; i++)
        {
            if (livros[i].isbn == isbnn)
            {
                printf("\nLivro encontrado!!\n");

                if (livros[i].emprestado == 1)
                {
                    printf("\nPor�m n�o est� disponivel");
                }
                break;
                // Até aqui ok
            }
        }

        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    default:
        printf("\n Op��o Inv�lida\n ");
        break;
    }

    // if (encontrado==1 && livros->emprestado==0)
    // {
    //      printf("ISBN: %d \nTítulo: %s, \n Autor: %s \n", livros[i].isbn, livros[i].titulo, livros[i].autor);
    // }
}

void devolverLivro(Livro *livros, int totalLivros)
{
    // mudar a val do emprestado pra 0
    printf("Escolha o m�todo de buscas:");
    printf("1. ISBN\n");
    printf("2. Autor\n");
    printf("3. T�tulo\n");

    int opcBusca = 0;
    int isbnn;
    int encontrado = 0;
    int posicao;

    scanf("%d", &opcBusca);

    switch (opcBusca)
    {
    case 1:
        printf("\nDigite o ISBN: ");

        scanf("%d", &isbnn);

        for (int i = 0; i < totalLivros; i++)
        {
            if (livros[i].isbn == isbnn)
            {
                printf("\nLivro encontrado!!\n");
                encontrado = 1;
                posicao = i;
                break;
                // Até aqui ok
            }
        }

        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    default:
        printf("\n Op��o Inv�lida\n");
        break;
    }

    if (encontrado == 1)
    {
        printf("ISBN: %d \nT�tulo: %s, \n Autor: %s \n", livros[posicao].isbn, livros[posicao].titulo, livros[posicao].autor);
    }
}

void listarEmprestados(Livro *livros, int totalLivros)
{

    printf("\n==============================================\n");
    printf("\n\n----Todos os Livros Emprestados----\n\n");
    // mostrar os livros de val emprestado = 1
    for (int i = 0; i < totalLivros; i++)
    {
        if (livros[i].emprestado == 1)

            printf("ISBN: %d \nT�tulo: %s, \n Autor: %s \n", livros[i].isbn, livros[i].titulo, livros[i].autor);
        printf("\n\n\n");
    }
    printf("\n==============================================\n");
}

void listarTodososLivros(Livro *livros, int totalLivros)
{
    // mostra todos os livros
    printf("\n==============================================\n");
    printf("\n\n----Todos os Livros----\n\n");
    for (int i = 0; i < totalLivros; i++)
    {
        printf("ISBN: %d, \nT�tulo: %s, \n Autor: %s,\n Emprestado: %s\n", livros[i].isbn, livros[i].titulo, livros[i].autor, (livros[i].emprestado == 1) ? "Sim" : "N�o");
        printf("\n\n\n");
    }
    printf("\n==============================================\n");
}
void salvarDados(Livro *livros, int totalLivros)
{
    FILE *fp = fopen("todosOsLivros.txt", "w");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    for (int i = 1; i < totalLivros; i++)
    {
        fprintf(fp, "%d;%d;%s;%s;%d\n", livros[i].codigo, livros[i].isbn, livros[i].titulo, livros[i].autor, livros[i].emprestado);
    }

    fclose(fp);
}

void carregarDados(Livro *livros, int *totalLivros)
{
    FILE *fp = fopen("todosOsLivros.txt", "r");
    if (fp == NULL)
    {
        printf("Arquivo de dados n�o encontrado. Criando novo arquivo.\n");
        fp = fopen("todosOsLivros.txt", "w");
        if (fp == NULL)
        {
            printf("Erro ao criar o arquivo.\n");
            exit(1);
        }
        fclose(fp);
        return;
    }

    // Limpa o array antes de carregar os dados
    *totalLivros = 0;

    while (fscanf(fp, "%d;%d;%[^;];%[^;];%d\n", &livros[*totalLivros].codigo, &livros[*totalLivros].isbn, livros[*totalLivros].titulo, livros[*totalLivros].autor, &livros[*totalLivros].emprestado) == 5)
    {
        (*totalLivros)++;
    }

    fclose(fp);

    // Adicione mensagens de depuração
    printf("Dados carregados com sucesso. Total de livros: %d\n", *totalLivros);
}