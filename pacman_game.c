#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "map.h"
#include <time.h>

MAPA m;
POSITION hero;
int tempilula = 0;

int positionghost(int xatual, int yatual, int* xdestino, int*ydestino){
    int opcoes[4][2] = {
        {xatual, yatual +1},
        {xatual +1, yatual},
        {xatual, yatual -1},
        {xatual -1, yatual}
    };
    srand(time(0));
    for (int i = 0; i<10; i++){
        int posicao = rand() %4;

        if(podeandar(&m, GHOST, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void ghost(){
    MAPA copy;

    copymap(&copy, &m);

    for(int i = 0; i<m.linhas; i++){
        for (int j=0; j<m.colunas;j++){
            if(copy.matrix[i][j] == GHOST){

                int xdestino;
                int ydestino;

                int encontrou = positionghost(i, j, &xdestino, &ydestino);

                if (encontrou){
                    movemap(&m, i, j, xdestino, ydestino);
                }
            }
        }
    }
    freemap(&copy);
}

int finish(){
    POSITION pos;
    int fogefogenomapa = findmap(&m, &pos, HERO);
    return !fogefogenomapa;
}

int intdirection(char direction){

        return direction =='a' ||
        direction =='w' ||
        direction =='s' ||
        direction =='d';
}

void move(char direction){

    if(!intdirection(direction))
        return;

    int proximox = hero.x;
    int proximoy = hero.y;

    switch(direction){
        case LEFT:
            proximoy--;
            break;
        case UP:
            proximox--;
            break;
        case DOWN:
            proximox++;
            break;
        case RIGHT:
            proximoy++;
            break;
    }

    if(!podeandar(&m, HERO, proximox, proximoy))
        return;

    if(ehpersonagem(&m, PILULA, proximox, proximoy))
        tempilula = 1;;

    movemap(&m, hero.x, hero.y, proximox, proximoy);
    hero.x = proximox;
    hero.y = proximoy;

}

void explodepilula(){
    printf("explodiu");
}

int main(){

    seemap(&m);

    findmap(&m, &hero, HERO);

    do{

        printf("Tem pilula: %s\n", (tempilula ? "SIM" : "NAO"));
        
        printmap(&m);

        char user_command;
        scanf(" %c", &user_command);
        move(user_command);
        if (user_command == BOMBA) explodepilula();

        ghost();
    }
    while(!finish());

    freemap(&m);
}
