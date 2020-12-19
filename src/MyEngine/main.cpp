#include "game_app.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    GameApp app("My game");
    app.init();
    app.run();
}
