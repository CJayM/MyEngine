TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= console
CONFIG -= qt

INCLUDEPATH += ../../libs/glfw/include
LIBS += -L"../../libs/glfw/lib-mingw-w64" -lglfw3 -lgdi32 -lopengl32

INCLUDEPATH += ../../libs/glew/include
LIBS += -L"../../libs/glew/lib/Release/x64" -lglew32


SOURCES +=  main.cpp \
    core/app.cpp \
    core/camera.cpp \
    core/geom.cpp \
    core/matrices.cpp \
    core/model.cpp \
    core/shader.cpp \
    game_app.cpp

HEADERS += \
    core/app.h \
    core/camera.h \
    core/geom.h \
    core/gl_headers.h \
    core/matrices.h \
    core/model.h \
    core/shader.h \
    core/shaders_src.h
