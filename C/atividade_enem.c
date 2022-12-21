/*
Por:Felipe Vieira
Ultima Atualização:23/11/2022
*/

#include<stdio.h>
#include<stdlib.h>

#define NUMERO_CANDIDATOS 100//Total de candidatos
#define NUMERO_QUESTOES 90//Total de questões

//Estrutura para o candidato
typedef struct{

char nome[16];//Nome do candidato
int acertos;//Número de acerto do candidato
int codigo;//Codigo do candidato

}Candidato;//Estrutura para armazenar informaçoes dos candidatos

int main(void)
{
    //Entrada
    const char respostas_corretas[NUMERO_QUESTOES]={"CEDBDDDCACCBDAEBADCBDCDAAECEDDDECDDCBDDAEDCCAEBCCCCCACCDABCCABCABCABCBAECEDBBDBEEEDBBACCDA"};
    Candidato candidatos[NUMERO_CANDIDATOS];//Array de candidatos
    
    //Limpar variavel acertos dos candidatos
    for(int num=0;num<NUMERO_CANDIDATOS;num++)candidatos[num].acertos=0;

    printf("\tSISTEMA ENEM\n\t\tpor:Felipe Vieira\n");

    //SETA INFORMAÇÃO DOS CANDIDATOS
    for(int p=0;p<NUMERO_CANDIDATOS;p++){
        //Escrever nome candidato
        printf("Digite Nome Candidato[%d]:",p);
        gets(candidatos[p].nome);

        do{
        //Escrever codigo candidato
        printf("Digite Codigo Candidato:");
        scanf("%d",&candidatos[p].codigo);
        }while(candidatos[p].codigo>=1000);

        //Loop para Pedir as respostas do candidato
        printf("Digite Questoes Candidato:");
        for(int x=0;x<NUMERO_QUESTOES;x++){
            char res;
            scanf(" %c",&res);
            if(res==respostas_corretas[x])//comparar resposta
                candidatos[p].acertos++;
        }
        system("cls");//Limpar tela
        getchar();
    }


    //numero de Questões a 0
    for(int x=NUMERO_QUESTOES;x>=0;x--){
        //LOOP pegar variavel "acertos" de todos os candidatos
        for(int p=0;p<NUMERO_CANDIDATOS;p++){
                //comparar acertos Candidato[p] com o valor da variavel x(que é o número de questões)
                if(candidatos[p].acertos==x){// si acertos Candidato[p] for igual x escreva informaçoes candidato p
                    printf("Nome:%s\n",candidatos[p].nome);
                    printf("acerto(s):%d\n",candidatos[p].acertos);
                    printf("codigo(s):%d\n",candidatos[p].codigo);
                    printf("porcentagem:%.2f\n",(float)(candidatos[p].acertos*100)/NUMERO_QUESTOES);
                }
        }
    }
    return 0;
}