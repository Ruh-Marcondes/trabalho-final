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
    salvarDados(livros, *totalLivros+1);
    (*totalLivros)++;
    printf("Livro cadastrado com sucesso!\n");
}

//Verificar livro cadastrado
int verificarLivroCadastrado(Livro *livros, int totalLivros, int isbn) {
    for (int i = 0; i < totalLivros; i++) {
        if (livros[i].isbn == isbn) {
            return i; // Retorna o índice do livro se estiver cadastrado
        }
    }
    return -1; // Retorna -1 se o livro não estiver cadastrado
}

void emprestarLivro(Livro *livros, int totalLivros){
   printf("Escolha o metódo de buscas:");
    printf("1. ISBN\n");
    printf("2. Autor\n");
    printf("3. Titulo\n");

    int opcBusca = 0;
    int encontrado =0;
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
                    printf("\nPorém não está disponivel");
                }
                break; 
                
            }
        } 
}
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
                    printf("\nPorém não está disponivel");
                }
                break; 
                //Até aqui ok
            }
        }

        case 2:
    printf("\nDigite o nome do autor: ");
    char autorBusca[250];
    scanf(" %[^\n]", autorBusca);

    for (int i = 0; i < totalLivros; i++)
    {
        if (strcmp(livros[i].autor, autorBusca) == 0)
        {
            printf("\nLivro encontrado pelo autor!!\n");

            if (livros[i].emprestado == 1)
            {
                printf("\nMas está indisponível.");
            }
            break; // Finaliza a busca após encontrar o livro
        }
    }
    case 3:
    printf("\nDigite o título do livro: ");
    char tituloBusca[250];
    scanf(" %[^\n]", tituloBusca);

    for (int i = 0; i < totalLivros; i++)
    {
        if (strcmp(livros[i].titulo, tituloBusca) == 0)
        {
            printf("\nLivro encontrado pelo título!!\n");

            if (livros[i].emprestado == 1)
            {
                printf("\nMas está indisponível.");
            }
            break; // Finaliza a busca após encontrar o livro
        }
    }
    break;
            
void devolverLivro(Livro *livros, int totalLivros)
{
    // mudar a val do emprestado pra 0

    listarEmprestados(livros,totalLivros);
    int indiceLivro=0; 
    printf("\n\nEscolha o livro que deseja devolver pelo codigo dele: ");
    scanf("%d",&indiceLivro);
    
    livros[indiceLivro-1].emprestado = 0;
    salvarDados(livros,totalLivros);
    printf("\n\nLivro Devolvido!");
}

void listarEmprestados(Livro *livros, int totalLivros)
{

int emprestados =0;

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

//mostrar os dados baseados no autor é no nome do livro completa

case 2:
    printf("\nDigite o nome do autor: ");
    char autorBusca[250];
    scanf(" %[^\n]", autorBusca);

    for (int i = 0; i < totalLivros; i++)
    {
        if (strcmp(livros[i].autor, autorBusca) == 0)
        {
            printf("\nLivro encontrado pelo autor!!\n");

            if (livros[i].emprestado == 1)
            {
                printf("\nMas está indisponível.");
            }
            break; // Finaliza a busca após encontrar o livro
        }
    }
    break;


case 3:
    printf("\nDigite o título do livro: ");
    char tituloBusca[250];
    scanf(" %[^\n]", tituloBusca);

    for (int i = 0; i < totalLivros; i++)
    {
        if (strcmp(livros[i].titulo, tituloBusca) == 0)
        {
            printf("\nLivro encontrado pelo título!!\n");

            if (livros[i].emprestado == 1)
            {
                printf("\nMas está indisponível.");
            }
            break; // Finaliza a busca após encontrar o livro
        }
    }
    break;

//opção de escolher o livro para pegar emprestado

const int MAX_LIVROS = 100;

typedef struct
{
    int codigo;
    int isbn;
    char titulo[250];
    char autor[250];
    int emprestado;
} Livro;

// ... (código anterior)

void listarLivrosDisponiveis(Livro *livros, int totalLivros);
void emprestarLivroEscolhido(Livro *livros, int totalLivros, int indiceLivro);

// ... (código anterior)

void emprestarLivro(Livro *livros, int totalLivros)
{
    printf("Livros disponíveis para empréstimo:\n");
    listarLivrosDisponiveis(livros, totalLivros);

    printf("Digite o número do livro para empréstimo: ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha >= 1 && escolha <= totalLivros)
    {
        emprestarLivroEscolhido(livros, totalLivros, escolha - 1);
    }
    else
    {
        printf("Escolha inválida.\n");
    }
}

void listarLivrosDisponiveis(Livro *livros, int totalLivros)
{
    for (int i = 0; i < totalLivros; i++)
    {
        if (livros[i].emprestado == 0)
        {
            printf("%d. ISBN: %d, Título: %s, Autor: %s\n", i + 1, livros[i].isbn, livros[i].titulo, livros[i].autor);
        }
    }
}

void emprestarLivroEscolhido(Livro *livros, int totalLivros, int indiceLivro)
{
    if (livros[indiceLivro].emprestado == 1)
    {
        printf("Livro indisponível para empréstimo.\n");
    }
    else
    {
        livros[indiceLivro].emprestado = 1;
        printf("Livro emprestado com sucesso!\n");
        salvarDados(livros, totalLivros);
    }
}

//escolher um dos livros baseado em livros já cadastrados: 

const int MAX_LIVROS = 100;

typedef struct {
    int livroCadastrado;
} Livro;

void listarLivros(Livro *livros, int totalLivros) {
    printf("Livros cadastrados:\n");
    for (int i = 0; i < totalLivros; i++) {
        printf("%d. ISBN: %d, Título: %s, Autor: %s\n", i + 1, livros[i].isbn, livros[i].titulo, livros[i].autor);
    }
}

int escolherLivro(Livro *livros, int totalLivros) {
    listarLivros(livros, totalLivros);

    printf("\nEscolha um dos livros acima: ");
    int escolha;
    scanf("%d", &escolha);

    if (escolha >= 1 && escolha <= totalLivros) {
        return escolha - 1; // Retorna o índice escolhido
    } else {
        printf("Escolha inválida.\n");
        return -1; // Retorna -1 para indicar uma escolha inválida
    }
}

    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Achou! Alugue já seu livro: \n");
        printf("2. Não está entre os cadastrado! \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            int indiceLivro = escolherLivro(biblioteca, totalLivros);
                if (indiceLivro != -1) {
                    // Realize as operações de empréstimo aqui
                    printf("Você escolheu emprestar o livro: %s\n", biblioteca[indiceLivro].titulo);
                }
                break;
            }
            case 2:
                listarLivros(biblioteca, totalLivros); // Listar todos os livros
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
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
    while ((c = getchar()) != '\n' && c != EOF);
}
