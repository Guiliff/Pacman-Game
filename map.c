#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map.h"

int parede(MAPA* m, int x, int y){
    return m->matrix[x][y] == VERTICAL_WALL ||
        m->matrix[x][y] == HORIZONTAL_WALL;
}

int ehpersonagem(MAPA* m, char personagem, int x, int y){
    return m->matrix[x][y] == personagem;
}

int podeandar(MAPA* m, char personagem, int x, int y){
    return
        valid(m, x, y) &&
        !parede(m, x, y) &&
        !ehpersonagem(m, personagem, x, y);
}

void copymap(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem->colunas;

    dynamic_allocation(destino);
    for(int i=0; i<origem->linhas; i++){
        strcpy(destino->matrix[i], origem->matrix[i]);
    }
}

int movemap(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino){
    char character = m->matrix [xorigem] [yorigem];
    m->matrix[xdestino] [ydestino] = character;
    m->matrix [xorigem] [yorigem] = EMPTY;
}

int valid(MAPA* m, int x, int y){
    if (x >= m->linhas)
        return 0;
    if (y >= m->colunas)
        return 0;
    return 1;
}

int isempty (MAPA* m, int x, int y){
    return m->matrix[x][y] == EMPTY;
}

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

int findmap(MAPA* m, POSITION* p, char c){
        //Acha a posição do usuário
    for(int i=0; i<m->linhas; i++){
        for (int j=0; j<m->colunas; j++){
            if(m->matrix[i][j] == c){
                p-> x = i;
                p-> y = j;
                return 1;
            }
        }
    }
    return 0;
}
