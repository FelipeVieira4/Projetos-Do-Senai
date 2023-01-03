/*
ULTIMA ATUALIZAÇÃO:03/01/2022
*/
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

#define PRECO_PAINEL_SOLAR 456.23
#define PRECO_PECAS 390.75
#define PRECO_ALUGUEL 900

typedef struct 
{
    /* data */
    int qtd_painesSolares,qtd_pecas_vendidas;

    float custo_energia;
}dados_empresa;

//Funçoes
void entrada_de_dados(dados_empresa *dados);//Escrever os dados no terminal lucro e despezas
void salva_dados(FILE *arq,dados_empresa *dados);//Salvar os dados em um arquivos
void carregar_dados(void);

#endif