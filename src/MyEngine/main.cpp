#include "core/app.h"
#include "core/scene.h"

char* FILE_PATH;

int main(int argc, char* argv[])
{
    FILE_PATH = argv[0];

    core::App app;
    app.init();

    const core::Size size(728, 546);
    auto window = app.createWindow(size, "Back2Back");
    window->setIcon("resources/app_icon.png");

    auto scene = new core::Scene(size);
    app.setScene(scene);

    app.run();
    return 0;
}
