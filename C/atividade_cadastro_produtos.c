
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


typedef struct{

char nome[20];//variavel nome do produto
char descricao_produto[100];
float preco;
int qtd_estoque;

}produto;

//-------------DECLARÇÃO DAS FUNÇOES-----------------//
void adiciona_novo_produto(produto *p);
void descrever_produto(produto *p);
void calcular_valor_estoque_produto(produto *p);

int main(void)
{
produto *produtos=malloc(sizeof(produto*));
int produtos_usados=0,command;

do{
//Pegar o commando
printf("1-Adicionar produto | 2-Listar Produtos | 3-Valor Estoque | 4-Sair:");
scanf("%d",&command);

switch(command){
    case 1://Caso comando seja 1 adicionar novo produto
      produtos=(produto*)realloc(produtos,sizeof(produtos));
	    adiciona_novo_produto(&produtos[produtos_usados]);
      produtos_usados++;
	break;
    case 2://Caso comando seja 2 descrever todos os produtos armazenados no ponteiro prod
	      for(int i=0;i<produtos_usados;i++)descrever_produto(&produtos[i]);
        printf("\n");
	    break;
    case 3://Caso comando seja 3 calcular valor estoque todos os produtos armazenados no ponteiro prod
        for(int i=0;i<produtos_usados;i++)calcular_valor_estoque_produto(&produtos[i]);
        printf("\n");
	    break;
}

}while(command!=4);

free(produtos);//Liberar o ponteiro produtos da memoria
return 0;
}

//-------------DESENVOLVIMENTO DAS FUNÇOES-----------------//

//Função para adiciona um novo produto
void adiciona_novo_produto(produto *p){

//Pedir NOME do produto
const char simbolos_invalidos[]="!@#$&[]{}*()";
bool letra_invalido;

getchar();//Para não pular o nome
do{
  letra_invalido=false;
  //Pegar o Nome
  printf("Digite Nome do produto:");
  gets(p->nome);

  //validar se as letras do nome são validas
  for(int i=0;i<20;i++){
    for(int j=0;j<12;j++){
      if(p->nome[i]==simbolos_invalidos[j])letra_invalido=true;//caso algumas letra seja invalido
    }
  }
}while(letra_invalido);

//Pegar descrição do produto
printf("Descricao:");
gets(p->descricao_produto);

//Pegar PREÇO do produto
do{
  printf("Digite Preco do produto:");
  scanf("%f",&p->preco);
}while(p->preco <= 0);

//Pegar QUANTIDADE DE ESTOQUE do produto
do{
  printf("Digite Quantidade de produto no estoque:");
  scanf("%d",&p->qtd_estoque);
}while(p->qtd_estoque <= 0);
 
//finalizar função
return;
}

//-----------Função para descrever o produto----------// 
void descrever_produto(produto *p){
printf("NOME:%s\nPRECO:%.2f\nQuantidade:%d\n",p->nome,p->preco,p->qtd_estoque);
printf("DECRICAO:%s\n",p->descricao_produto);
return;
}

//-----------Função para valor estoque dos produto----------// 
void calcular_valor_estoque_produto(produto *p){
printf("PRODUTO:%s\n",p->nome);
printf("Valor em estoque:%.2f\n",(float)p->preco*p->qtd_estoque);
return;
}
