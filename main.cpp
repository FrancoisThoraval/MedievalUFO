#include <stdlib.h>
#include "Game/game.hpp"
int main()
{
     srand (time(NULL));
     Game g(800,600);
     g.start();

     return 0;
}
