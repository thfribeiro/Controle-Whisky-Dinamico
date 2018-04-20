#ifndef ESTOQUEWHISKY_H_INCLUDED
#define ESTOQUEWHISKY_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct whisky{
char nome[50];
double preco;
int idade;
char pais[50];
int codigo;
int quantidade;
}REGISTRO;

typedef struct aux{
    REGISTRO reg;
    struct whisky *prox ;
}ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct{
    PONT inicio;
}LISTA;


//PROTÓTIPOS
void menu();
void inicializar(LISTA *l);
void exibirEstoque(LISTA *l);
void reinicializar(LISTA *l);
void inserirOrdIdade(LISTA *l, REGISTRO elem);
void inserirOrdQuantidade(LISTA *l, REGISTRO elem);
void inserirOrdPais(LISTA *l, REGISTRO elem);
PONT buscaWhiskyCodigo(LISTA *l, int codeBusca);
void exlcuirWhiskyCode(LISTA *l, int codeExclusao);

#endif // ESTOQUEWHISKY_H_INCLUDED
