#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#include"system.h"

void entrada_de_dados(dados_empresa *dados){
    printf("Informa valor de Paineis Vendidos:");
    scanf("%d",&dados->qtd_painesSolares);

    printf("Informa valor de Peças Vendidos:");
    scanf("%d",&dados->qtd_pecas_vendidas);
}

void salva_dados(FILE *arq,dados_empresa *dados){
    arq=fopen("Dados/dado_1.txt","w");
    fprintf(arq,"%d\n",dados->qtd_painesSolares);
    fclose(arq);
    return;
}

void carregar_dados(void){
    FILE *arq;
    dados_empresa dados;
    arq=fopen("Dados/dado_1.txt","r");
    fscanf(arq,"%d",&dados.qtd_painesSolares);

    printf("PAINEIS VENDIDOS:%d\n",dados.qtd_painesSolares);

    return;
}