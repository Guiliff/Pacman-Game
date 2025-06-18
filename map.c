#include <stdio.h>
#include <stdlib.h>
#include "map.h"

void dynamic_allocation(MAPA* m){
    //Alocando o mapa com memória e tamanho dinamicamente
    m->matrix = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i<m->linhas; i++){
        m->matrix[i] = malloc(sizeof(char) * (m->colunas + 1));
    }
}

void seemap(MAPA* m){
    FILE* f;
    f = fopen("map_1.txt", "r");
    if(f==0){
        printf("Erro na leitura do mapa\n"); //Aviso caso de erro no programa
        exit(1);
    }

    fscanf(f, "%d %d", &m->linhas, &m->colunas);

    dynamic_allocation(m);

    for(int i=0; i<5; i++){
        fscanf(f, "%s", m->matrix[i]);
    }
    fclose(f);
}

void freemap(MAPA* m){
    for(int i=0; i<m->linhas; i++){
        free(m->matrix[i]);
    }
    free(m->matrix);
}

void printmap(MAPA* m){
    for (int i = 0; i<5; i++){
        printf("%s\n", m->matrix[i]);
    }    
}

void findmap(MAPA* m, POSITION* p, char c){
        //Acha a posição do usuário
    for(int i=0; i<m->linhas; i++){
        for (int j=0; j<m->colunas; j++){
            if(m->matrix[i][j] == c){
                p-> x = i;
                p-> y = j;
                break;
            }
        }
    }
}