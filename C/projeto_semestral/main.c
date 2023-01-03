#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#include"system.h"

int main(void){

    float ganhos=0.0f;
    float despezas=0.0f;

    dados_empresa Dados;
    FILE *arquivo;

    carregar_dados();

    do{

    entrada_de_dados(&Dados);

    printf("Continuar?(S/n)");
    getchar();
    }while(getchar()=='S');
    salva_dados(arquivo,&Dados);
    ganhos+=(PRECO_PAINEL_SOLAR*Dados.qtd_painesSolares)+(PRECO_PECAS*Dados.qtd_pecas_vendidas);

    printf("GANHO:%.2f\n",ganhos);
    return 0;
}