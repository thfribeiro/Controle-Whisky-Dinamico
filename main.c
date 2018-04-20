#include "estoqueWhisky.h"

int main()
{

LISTA estoque;
REGISTRO elem;
PONT aux = NULL;
int opt=0;


inicializar(&estoque);

menu();
scanf("%i", &opt);

if(opt!=1 && opt!= 2 && opt!=3){
    puts("Escolha uma opcao correta");
    system("cls");
    return main();
}

elem = (const REGISTRO){"The John Walker",15000.00,25,"Escocia",1,5};
if(opt==1) inserirOrdIdade(&estoque, elem);
else if(opt==2) inserirOrdQuantidade(&estoque, elem);
else if(opt==3) inserirOrdPais(&estoque, elem);


elem = (const REGISTRO){"Double Black",150.00,5,"Escocia",5,15};
if(opt==1) inserirOrdIdade(&estoque, elem);
else if(opt==2) inserirOrdQuantidade(&estoque, elem);
else if(opt==3) inserirOrdPais(&estoque, elem);

elem = (const REGISTRO){"Blue Label",2500.00,10,"Reino Unido",3,25};
if(opt==1) inserirOrdIdade(&estoque, elem);
else if(opt==2) inserirOrdQuantidade(&estoque, elem);
else if(opt==3) inserirOrdPais(&estoque, elem);

elem = (const REGISTRO){"Sinatra Century",2500.00,15,"Estados Unidos",6,40};
if(opt==1) inserirOrdIdade(&estoque, elem);
else if(opt==2) inserirOrdQuantidade(&estoque, elem);
else if(opt==3) inserirOrdPais(&estoque, elem);


system("cls");
if(opt==1) puts("Estoque ordenado por Idade:\n");
else if(opt==2) puts("Estoque ordenado por Quantidade no estoque:\n");
else if(opt==3) puts("Estoque ordenado por Pais:\n");
exibirEstoque(&estoque);

puts("-------------------------------------------------------------------------------------------------------------\n");
aux = buscaWhiskyCodigo(&estoque, elem.codigo);

if(buscaWhiskyCodigo(&estoque, elem.codigo)!=NULL){
    printf("Busca por codigo:\n\nO elemento esta na lista:\n\n");
    printf("Nome:%s - Preco de venda:%.2lf - Idade:%i - Pais:%s - Codigo:%i - Quantidade em estoque:%i\n\n", aux->reg.nome,aux->reg.preco,aux->reg.idade,aux->reg.pais,aux->reg.codigo,aux->reg.quantidade);
}
else{
    printf("O elemento %d nao esta na lista\n", elem.codigo);
}

puts("-------------------------------------------------------------------------------------------------------------\n");
printf("Exclusao por codigo:\n\n");
exlcuirWhiskyCode(&estoque, elem.codigo=5);

puts("-------------------------------------------------------------------------------------------------------------\n");
printf("Reexibicao do estoque:\n\n");
if(opt==1) puts("Estoque ordenado por Idade:\n");
else if(opt==2) puts("Estoque ordenado por Quantidade no estoque:\n");
else if(opt==3) puts("Estoque ordenado por Pais:\n");
exibirEstoque(&estoque);

reinicializar(&estoque);

}
