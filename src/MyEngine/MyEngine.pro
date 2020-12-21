TEMPLATE = app
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= console
CONFIG -= qt
CONFIG += file_copies

TARGET = MyEngine

VERSION = 0.1

DEFINES += APP_VERSION=\\\"$$VERSION\\\"
DEFINES += APP_NAME=\\\"$$TARGET\\\"


Debug:DESTDIR = $$OUT_PWD/debug/bin
Release:DESTDIR = $$OUT_PWD/release/bin

reses.files = $$files(resources/*)
reses.path = $$DESTDIR/resources/

deps.files = $$files(deps/*)
deps.path = $$DESTDIR/

COPIES += deps
COPIES += reses

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
    core/shader.h

DISTFILES += \
    core/default.frag \
    core/default.vert \
    resources/shaders/default.frag \
    resources/shaders/default.vert
