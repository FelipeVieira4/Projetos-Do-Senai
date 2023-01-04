#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#include"system.h"

int main(void){

    float resultado=0.0f;

    dados_empresa Dados;
    FILE *arquivo;

    carregar_dados();
    do{

    entrada_de_dados(&Dados);

    printf("Continuar?(S/n)");
    getchar();
    }while(getchar()=='S');

    salva_dados(arquivo,&Dados);
    resultado+=(PRECO_PAINEL_SOLAR*Dados.qtd_painesSolares)+(PRECO_PECAS*Dados.qtd_pecasVendidas);

    printf("GANHO:%.2f\n",resultado);
    return 0;
}