#ifndef BIBLIOTECA_H

#define BIBLIOTECA_H

//  includes necessários
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições de constantes globais
#define MAX_LIVROS 100
#define MAX_CARACTERE 250

// Definição da estrutura Livro
typedef struct
{
    int codigo;
    char isbn[MAX_CARACTERE];
    char titulo[MAX_CARACTERE];
    char autor[MAX_CARACTERE];
    int emprestado; // 0 para disponível, 1 para emprestado
} Livro;


// Protótipos das funções

/**
 * Função cadastrarLivro(Livro *livros, int *totalLivros)
 * Recebe os dados a ser salvos no arquivo de testo "todosOsLivros.txt"
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void cadastrarLivro(Livro *livros, int *totalLivros);


/**
 * Função emprestarLivro(Livro *livros, int *totalLivros)
 * Essa função muda o valor de Enmprestado  de livros, para emprestar um livro no arquivo "todosOsLivros.txt"
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void emprestarLivro(Livro *livros, int totalLivros);


/**
 * Função devolverLivro(Livro *livros, int *totalLivros)
 * Essa função muda o valor de Enmprestado  de livros, para devolver um livro no arquivo "todosOsLivros.txt"
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void devolverLivro(Livro *livros, int totalLivros);


/**
 * Função listarEmprestados(Livro *livros, int *totalLivros)
 * Essa função Lista os livros emprestados.
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void listarEmprestados(Livro *livros, int totalLivros);


/**
 * Função listarTodososLivros(Livro *livros, int *totalLivros)
 * Essa função Lista os todos livros.
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void listarTodososLivros(Livro *livros, int totalLivros);


/**
 * Função salvarDados(Livro *livros, int *totalLivros)
 * Essa função salva os dados recebidos na função cadastrarLivro(Livro *livros, int *totalLivros);
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void salvarDados(Livro *livros, int totalLivros);


/**
 * Função carregarDados(Livro *livros, int *totalLivros)
 Essa função é a primira chamada no main(), ela carrega o valor de total livros e os livros no arquivo "todosOsLivros.txt"
 *    @param livros Um ponteiro para o array de livros
 *    @param totalLivros um ponteiro para o total de livros
 **/
void carregarDados(Livro *livros, int *totalLivros);


/**
 * Função menu() constroi o menu de o opções na tela
 **/
void menu(void);


/**
 * Função limparBufferEntrada() Limpa o Buffer 
 **/
void limparBufferEntrada(void);

#endif // BIBLIOTECA_H
