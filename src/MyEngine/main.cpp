#include "game_app.h"

char* FILE_PATH;

int main(int argc, char * argv[])
{
    FILE_PATH = argv[0];

    GameApp app("My game");
    app.init();
    app.run();
    return 0;
}
