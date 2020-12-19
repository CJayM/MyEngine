TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= console
CONFIG -= qt

#INCLUDEPATH += ../../libs/freeglut/include
#LIBS += -L"../../libs/freeglut/bin/x64" -lfreeglut

INCLUDEPATH += ../../libs/glfw/include
LIBS += -L"../../libs/glfw/lib-mingw-w64" -lglfw3 -lgdi32 -lopengl32

#INCLUDEPATH += ../../libs/glew/include
#LIBS += -L"../../libs/glew/lib/Release/x64" -lglew32



SOURCES +=          \
    core/camera.cpp \
    core/app.cpp \
    core/geom.cpp \
    core/matrices.cpp \
    core/model.cpp \
    core/simple_shader.cpp \
    game_app.cpp \
    main.cpp

HEADERS += \
    core/camera.h \
    core/matrices.h \
    core\app.h \
    core\geom.h \
    core\model.h \
    core\shaders_src.h \
    core\simple_shader.h \
    game_app.h


INCLUDEPATH += ../../libs/glad/include
SOURCES += ../../libs/glad/src/gl.c
