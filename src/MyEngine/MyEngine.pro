TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= console
CONFIG -= qt

#INCLUDEPATH += ../../libs/freeglut/include
#LIBS += -L"../../libs/freeglut/bin/x64" -lfreeglut

INCLUDEPATH += ../../libs/glad/include
SOURCES += ../../libs/glad/src/gl.c \
    app.cpp \
    geom.cpp \
    model.cpp \
    simple_shader.cpp

INCLUDEPATH += ../../libs/glfw/include
LIBS += -L"../../libs/glfw/lib-mingw-w64" -lglfw3 -lgdi32 -lopengl32

#INCLUDEPATH += ../../libs/glew/include
#LIBS += -L"../../libs/glew/lib/Release/x64" -lglew32



SOURCES += \        
        main.cpp

HEADERS += \
    app.h \
    geom.h \
    model.h \
    shaders_src.h \
    simple_shader.h
