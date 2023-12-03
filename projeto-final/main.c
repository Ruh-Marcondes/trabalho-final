#include "BIBLIOTECA.h"

int main()
{

    Livro biblioteca[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;
    carregarDados(biblioteca, &totalLivros);

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
            case 6:
            listarNaoEmprestados(biblioteca,totalLivros);
            break;
        case 0:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Opção  Inválida. Tente novamente.\n");
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
    printf("6.Listar Livors não Emprestados\n");
    printf("0. Sair\n");

    printf("Escolha uma opção: ");
}
void cadastrarLivro(Livro *livros, int *totalLivros)
{
    printf("Cadastrar Livro:\n");

    // Calcular o próximo código como o total atual de livros mais 1
    livros[*totalLivros].codigo = *totalLivros + 1;

    printf("ISBN: ");
    limparBufferEntrada();
    scanf(" %[^\n]", livros[*totalLivros].isbn);

    printf("Título: ");
    limparBufferEntrada();
    scanf(" %[^\n]", livros[*totalLivros].titulo);

    printf("Autor: ");
    limparBufferEntrada();
    scanf(" %[^\n]", livros[*totalLivros].autor);

    livros[*totalLivros].emprestado = 0; // Inicializa como disponível
    salvarDados(livros, *totalLivros + 1);
    (*totalLivros)++;
    printf("Livro cadastrado com sucesso!\n");
}

void emprestarLivro(Livro *livros, int totalLivros)
{
    //@JuhManuh2004 está desenvolvendo
     listarNaoEmprestados(livros, totalLivros);
    int indiceLivro = 0;
    printf("\n\nEscolha o livro que deseja pegar emprestado pelo codigo dele: ");
    scanf("%d", &indiceLivro);

    livros[indiceLivro - 1].emprestado = 1;
    salvarDados(livros, totalLivros);
    printf("\n\nLivro Emprestado!");
}
void listarNaoEmprestados(Livro *livros, int *totalLivros){
   
    int emprestados = 0;

    printf("\n==============================================\n");
    printf("\n\n----Todos os Livros Emprestados----\n\n");

    for (int i = 0; i < totalLivros; i++)
    {
        if (livros[i].emprestado == 0)
        {
            printf("\n\n%d°. Livro", ++emprestados);
            printf("\n Codigo de cadastro do livro: %d \n", livros[i].codigo);
            printf("ISBN: %s \nTítulo: %s, \nAutor: %s \n", livros[i].isbn, livros[i].titulo, livros[i].autor);
        }
        printf("\n\n\n");
    }
    printf("\n==============================================\n");
}
void devolverLivro(Livro *livros, int totalLivros)
{
    // mudar a val do emprestado pra 0

    listarEmprestados(livros, totalLivros);
    int indiceLivro = 0;
    printf("\n\nEscolha o livro que deseja devolver pelo codigo dele: ");
    scanf("%d", &indiceLivro);

    livros[indiceLivro - 1].emprestado = 0;
    salvarDados(livros, totalLivros);
    printf("\n\nLivro Devolvido!");
}

void listarEmprestados(Livro *livros, int totalLivros)
{

    int emprestados = 0;

    printf("\n==============================================\n");
    printf("\n\n----Todos os Livros Emprestados----\n\n");

    for (int i = 0; i < totalLivros; i++)
    {
        if (livros[i].emprestado == 1)
        {
            printf("\n\n%d°. Livro", ++emprestados);
            printf("\n Codigo de cadastro do livro: %d \n", livros[i].codigo);
            printf("ISBN: %s \nTítulo: %s, \nAutor: %s \n", livros[i].isbn, livros[i].titulo, livros[i].autor);
        }
        printf("\n\n\n");
    }
    printf("\n==============================================\n");
}

void listarTodososLivros(Livro *livros, int totalLivros)
{

    printf("\n==============================================\n");
    printf("\n\n----Todos os Livros----\n\n");
    for (int i = 0; i < totalLivros; i++)
    {
        printf("\n%d°. Livro\n", i + 1);
        printf("ISBN: %s, \nTítulo: %s, \n Autor: %s,\n Emprestado: %s\n", livros[i].isbn, livros[i].titulo, livros[i].autor, (livros[i].emprestado == 1) ? "Sim" : "Não");
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

    for (int i = 0; i < totalLivros; i++)
    {
        fprintf(fp, "%d;", livros[i].codigo);
        fputs(livros[i].isbn, fp);
        fputs(";", fp);
        fputs(livros[i].titulo, fp);
        fputs(";", fp);
        fputs(livros[i].autor, fp);
        fprintf(fp, ";%d\n", livros[i].emprestado);
    }

    fclose(fp);
}

void carregarDados(Livro *livros, int *totalLivros)
{
    FILE *fp = fopen("todosOsLivros.txt", "r");
    if (fp == NULL)
    {
        printf("Arquivo de dados não encontrado. Criando novo arquivo.\n");
        fp = fopen("todosOsLivros.txt", "w");
        if (fp == NULL)
        {
            printf("Erro ao criar o arquivo.\n");
            exit(1);
        }
        fclose(fp);
        return;
    }

    *totalLivros = 0;

    while (fscanf(fp, "%d;%[^;];%[^;];%[^;];%d\n", &livros[*totalLivros].codigo, &livros[*totalLivros].isbn, livros[*totalLivros].titulo, livros[*totalLivros].autor, &livros[*totalLivros].emprestado) == 5)
    {
        (*totalLivros)++;
    }

    fclose(fp);

    printf("Dados carregados com sucesso. Total de livros: %d\n", *totalLivros);
}

void limparBufferEntrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}