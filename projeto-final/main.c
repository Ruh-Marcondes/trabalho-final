#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int codigo;
    char titulo[100];
    char autor[50];
    int emprestado; // 0 para disponível, 1 para emprestado
} Livro;

void cadastrarLivro(Livro* livros, int* totalLivros);
void emprestarLivro(Livro* livros, int totalLivros);
void devolverLivro(Livro* livros, int totalLivros);
void listarEmprestados(Livro* livros, int totalLivros);
void salvarDados(Livro* livros, int totalLivros);
void carregarDados(Livro* livros, int* totalLivros);
void listarTodososLivros(Livro* livros,int totalLivros);
void menu(void);

int main() {
    Livro biblioteca[100]; // Assumindo um máximo de 100 livros na biblioteca
    int totalLivros = 0;
    int opcao;

    carregarDados(biblioteca, &totalLivros); // Carregar dados do arquivo

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
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
                listarTodososLivros(biblioteca,totalLivros);
                break;
            case 0:

                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void menu(){
    printf("\nMenu:\n");
    printf("1. Cadastrar Livro\n");
    printf("2. Emprestar Livro\n");
    printf("3. Devolver Livro\n");
    printf("4. Listar Livros Emprestados\n");
    printf("5. Listar todos os Livros\n");
    printf("0. Sair\n");

    printf("Escolha uma opcao: ");
}
void cadastrarLivro(Livro* livros, int* totalLivros) {
    printf("Cadastrar Livro:\n");

    printf("Codigo: ");
    scanf("%d", &livros[*totalLivros].codigo);

    printf("Titulo: ");
    scanf(" %[^\n]", livros[*totalLivros].titulo);

    printf("Autor: ");
    scanf(" %[^\n]", livros[*totalLivros].autor);

    livros[*totalLivros].emprestado = 0; // Inicializa como disponível
    (*totalLivros)++;
    salvarDados(livros, *totalLivros); //
    printf("Livro cadastrado com sucesso!\n");
}

void emprestarLivro(Livro* livros, int totalLivros) {
//mudar a val do emprestado pra 1
}

void devolverLivro(Livro* livros, int totalLivros) {
//mudar a val do emprestado pra 0
}

void listarEmprestados(Livro* livros, int totalLivros) {
// mostrar os livros de val emprestado = 1
}

void listarTodososLivros(Livro* livros,int totalLivros){
// mostra todos os livros
}
void salvarDados(Livro* livros, int totalLivros) {
    FILE *fp = fopen("projeto-final\\output\\todosOsLivros.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        exit(1);
    }

    for (int i = 0; i < totalLivros; i++) {
        fprintf(fp, "%d;%s;%s;%d\n", livros[i].codigo, livros[i].titulo, livros[i].autor, livros[i].emprestado);
    }

    fclose(fp);
}

void carregarDados(Livro* livros, int* totalLivros) {
    FILE *fp = fopen("projeto-final\\output\\todosOsLivros.txt", "r");
    if (fp == NULL) {
        printf("Arquivo de dados nao encontrado. Criando novo arquivo.\n");
        return;
    }

    while (fscanf(fp, "%d;%[^;];%[^;];%d\n", &livros[*totalLivros].codigo, livros[*totalLivros].titulo, livros[*totalLivros].autor, &livros[*totalLivros].emprestado) == 4) {
        (*totalLivros)++;
    }

    fclose(fp);
}