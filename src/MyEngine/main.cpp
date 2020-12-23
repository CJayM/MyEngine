#include "core/app.h"
#include "core/scene.h"

char* FILE_PATH;

int main(int argc, char * argv[])
{
    FILE_PATH = argv[0];

    core::App app;
    app.init();

    auto window = app.createWindow(800, 600, "Back2Back");
    window->setIcon("resources/app_icon.png");

    auto scene = new core::Scene();
    app.setScene(scene);

    app.run();
    return 0;
}
