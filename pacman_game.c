#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include "map.h"

MAPA m;
POSITION hero;

int finish(){
    return 0;
}

void move(char direction){

    if(
        direction !='a' &&
        direction !='w' &&
        direction !='s' &&
        direction !='d'){
            return;
        }

    m.matrix[hero.x][hero.y] = '.';

    switch(direction){
        case 'a':
            m.matrix[hero.x][hero.y-1] = '@';
            hero.y--;
            break;
        case 'w':
            m.matrix[hero.x-1][hero.y] = '@';
            hero.x--;
            break;
        case 's':
            m.matrix[hero.x+1][hero.y] = '@';
            hero.x++;
            break;
        case 'd':
            m.matrix[hero.x][hero.y+1] = '@';
            hero.y++;
            break;
    }
}

int main(){

    seemap(&m);

    findmap(&m, &hero, '@');

    do{
        printmap(&m);

        char user_command;
        scanf(" %c", &user_command);
        move(user_command);
    }
    while(!finish());

    freemap(&m);
}
