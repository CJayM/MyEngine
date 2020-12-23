#include "core/app.h"

char* FILE_PATH;

int main(int argc, char * argv[])
{
    FILE_PATH = argv[0];

    core::App app;
    app.init();

    auto window = app.createWindow(800, 600, "Back2Back");
    window->setIcon("resources/app_icon.png");

    app.run();
    return 0;
}
