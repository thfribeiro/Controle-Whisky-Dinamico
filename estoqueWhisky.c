#include "estoqueWhisky.h"


void menu(){
puts("Estoque MEC");
puts("Deseja ordenar os produtos de que forma?");
puts("1 - Idade \t 2 - Quantidade \t 3 - Pais");
}

void inicializar(LISTA *l){
l->inicio=NULL;
}

void exibirEstoque(LISTA *l){
PONT aux= l->inicio;

while(aux!=NULL){
    printf("Nome:%s - Preco de venda:%.2lf - Idade:%i - Pais:%s - Codigo:%i - Quantidade em estoque:%i\n\n", aux->reg.nome,aux->reg.preco,aux->reg.idade,aux->reg.pais,aux->reg.codigo,aux->reg.quantidade);
    aux=aux->prox;
}
}

void reinicializar(LISTA *l){
PONT aux=l->inicio;

while(aux!=NULL){
    l->inicio=l->inicio->prox;
    free(aux);
    aux=l->inicio;
}
}

void inserirOrdIdade(LISTA *l, REGISTRO elem){

PONT atual = NULL;
PONT novo = NULL;
PONT ant = NULL;
novo = (PONT) malloc(sizeof(ELEMENTO));

if(novo==NULL){
    puts("\nNao inserido\n");
}

novo->reg=elem;
novo->prox=NULL;

atual=l->inicio;

while(atual!=NULL && atual->reg.idade<elem.idade){
    ant=atual;
    atual = atual->prox;
}
novo->prox=atual;

if(ant==NULL){
    l->inicio=novo;
}
else{
    ant->prox=novo;
}
}

void inserirOrdQuantidade(LISTA *l, REGISTRO elem){

PONT atual = NULL;
PONT novo = NULL;
PONT ant = NULL;
novo = (PONT) malloc(sizeof(ELEMENTO));

if(novo==NULL){
    puts("\nNao inserido\n");
}

novo->reg=elem;
novo->prox=NULL;

atual=l->inicio;

while(atual!=NULL && atual->reg.quantidade<elem.quantidade){
    ant=atual;
    atual = atual->prox;
}
novo->prox=atual;

if(ant==NULL){
    l->inicio=novo;
}
else{
    ant->prox=novo;
}
}

void inserirOrdPais(LISTA *l, REGISTRO elem){

PONT atual = NULL;
PONT novo = NULL;
PONT ant = NULL;
novo = (PONT) malloc(sizeof(ELEMENTO));

if(novo==NULL){
    puts("\nNao inserido\n");
}

novo->reg=elem;
novo->prox=NULL;

atual=l->inicio;

while(atual!=NULL && strcmp(atual->reg.pais,elem.pais)<0){
    ant=atual;
    atual = atual->prox;
}
novo->prox=atual;

if(ant==NULL){
    l->inicio=novo;
}
else{
    ant->prox=novo;
}
}

PONT buscaWhiskyCodigo(LISTA *l, int codeBusca){


PONT aux= l->inicio;

while(aux!=NULL && aux->reg.codigo<codeBusca){
    aux=aux->prox;

}
if(aux!=NULL && aux->reg.codigo==codeBusca){

    return aux;
}
else{
    return NULL;
}
}

void exlcuirWhiskyCode(LISTA *l, int codeExclusao){
PONT atual= l->inicio;
PONT ant=NULL;

while(atual!=NULL && atual->reg.codigo<codeExclusao){
    ant = atual;
    atual = atual->prox;
}
if(atual==NULL){
    puts("\nO produto nao foi excluido pois seu codigo nao se encontra cadastrado no estoque\n");
}
else{
    if(atual->reg.codigo!=codeExclusao){
        puts("\nO produto nao foi excluido pois seu codigo nao se encontra cadastrado no estoque\n");
    }
    else{
        if(ant==NULL){
            l->inicio=atual->prox;
        }
        else{
                ant->prox=atual->prox;
        }

        free(atual);
        printf("\nO produto do codigo %d e todos os seus dados foram excluidos \n", codeExclusao);
    }
}
}
