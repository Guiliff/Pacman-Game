#define HERO '@'
#define GHOST '#'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'

//Criando uma estrutura para manter o mapa, facilitando caso venha a expandir o código com mais mapas
struct map{
    char** matrix; //Ponteiro de ponteiro
    int linhas;
    int colunas;
};
typedef struct map MAPA;

struct position{
    int x;
    int y;
};
typedef struct position POSITION;

void dynamic_allocation(MAPA* m);
void seemap(MAPA* m);
void freemap(MAPA* m);
void printmap(MAPA* m);
void findmap(MAPA* m, POSITION* p, char c);
int valid(MAPA* m, int x, int y);
int isempty (MAPA* m, int x, int y);
int movemap(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copymap(MAPA* destino, MAPA* origem);
