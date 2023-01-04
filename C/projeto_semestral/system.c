#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#include"system.h"

//Funçoes
void entrada_de_dados(dados_empresa *dados){
    //Pegar valor de saido do scanf
    int scanf_code;

    do{
    printf("Informa valor de Paineis Vendidos:");
    scanf_code=scanf("%d",&dados->qtd_painesSolares);
    gets();
    }while(scanf_code!=1);

    do{
    printf("Informa valor de Peças Vendidos:");
    scanf_code=scanf("%d",&dados->qtd_pecasVendidas);
    gets();
    }while(scanf_code!=1);

    do{
    printf("Informa Garantia Extendidas:");
    scanf_code=scanf("%d",&dados->vds_GarantiaExten);
    gets();
    }while(scanf_code!=1);

    return;
}

void checkar_arquivos(char patch[13]){

    int arquivos_livre=0;
    char patch_file[13];
    FILE *test;

    do{
        sprintf(patch_file,"dados_%d.txt",arquivos_livre);//dados_0.txt
        if((test=fopen(patch_file,"r"))!=0){
            arquivos_livre++;//arquivos_existentes+=1
        }
        else break;
        fclose(test);
    }while(1);
    strcpy(patch,patch_file);//copy array of "patch_file" to "patch"
    return;
}


void salva_dados(FILE *arq,dados_empresa *dados){
    char patch[13];

    checkar_arquivos(patch);

    arq=fopen(patch,"w");
    fprintf(arq,"%d\n",dados->qtd_painesSolares);
    fprintf(arq,"%d\n",dados->qtd_pecasVendidas);
    fprintf(arq,"%d\n",dados->vds_GarantiaExten);
    fclose(arq);
    return;
}

void carregar_dados(void){
    FILE *arq;
    dados_empresa dados;
    
    arq=fopen("dados_0.txt","r");
    fscanf(arq,"%d",&dados.qtd_painesSolares);
    fscanf(arq,"%d\n",&dados.qtd_pecasVendidas);
    fscanf(arq,"%d\n",&dados.vds_GarantiaExten);


    printf("PAINEIS VENDIDOS:%d\nPECAS VENDIDOS:%d\nGARANTIA EXTENDIDAS:%d\n",
    dados.qtd_painesSolares,
    dados.qtd_pecasVendidas,
    dados.vds_GarantiaExten);

    return;
}