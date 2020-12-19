#include <stdio.h>
#include <stdlib.h>

#include "shaders_src.h"

#include "app.h"

int main(void)
{
    App app;
    app.init();
    app.setShaders(VERTEX_SHADER_SRC, FRAGMENT_SHADER_SRC);
    app.run();
}
