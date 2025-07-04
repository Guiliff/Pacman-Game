#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "map.h"

MAPA m;
POSITION hero;

void ghost(){
    MAPA copy;

    copymap(&copy, &m);

    for(int i = 0; i<m.linhas; i++){
        for (int j=0; j<m.colunas;j++){
            if(copy.matrix[i][j] == GHOST){
                if (valid(&m, i, j+1) && isempty(&m, i, j+1)){
                    movemap(&m, i, j, i, j+1);
                }
            }
        }
    }
    freemap(&copy);
}

int finish(){
    return 0;
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

    if(!valid(&m, proximox, proximoy))
        return;

    if (!isempty(&m, proximox, proximoy))
        return;

    movemap(&m, hero.x, hero.y, proximox, proximoy);
    hero.x = proximox;
    hero.y = proximoy;

}

int main(){

    seemap(&m);

    findmap(&m, &hero, HERO);

    do{
        printmap(&m);

        char user_command;
        scanf(" %c", &user_command);
        move(user_command);
        ghost();
    }
    while(!finish());

    freemap(&m);
}
