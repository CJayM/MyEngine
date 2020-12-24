#include "core/app.h"
#include "core/scene.h"

char* FILE_PATH;

int main(int argc, char* argv[])
{
    FILE_PATH = argv[0];

    core::App app;
    app.init();

    const int width = 728;
    const int height = 546;

    auto window = app.createWindow(width, height, "Back2Back");
    window->setIcon("resources/app_icon.png");

    auto scene = new core::Scene(width, height);
    app.setScene(scene);

    app.run();
    return 0;
}
