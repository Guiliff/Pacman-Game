#define UP 'w'
#define RIGHT 'd'
#define LEFT 'a'
#define DOWN 's'
#define BOMBA 'b'

void move(char direction);
int finish();

int intdirection(char direction);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtd);
void ghost();
