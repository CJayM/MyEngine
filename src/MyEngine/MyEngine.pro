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

shaders.files = $$files(resources/shaders/*)
shaders.path = $$DESTDIR/resources/shaders/

images.files = $$files(resources/images/*)
images.path = $$DESTDIR/resources/images/

sprites.files = $$files(resources/sprites/*)
sprites.path = $$DESTDIR/resources/sprites/

spritesheets.files = $$files(resources/spritesheets/*)
spritesheets.path = $$DESTDIR/resources/spritesheets/

reses.files = $$files(resources/*.png)
reses.path = $$DESTDIR/resources/

deps.files = $$files(deps/*)
deps.path = $$DESTDIR/

COPIES += deps
COPIES += reses shaders images sprites spritesheets

INCLUDEPATH += ../../libs/glfw/include
LIBS += -L"../../libs/glfw/lib-mingw-w64" -lglfw3 -lgdi32 -lopengl32

INCLUDEPATH += ../../libs/glew/include
LIBS += -L"../../libs/glew/lib/Release/x64" -lglew32

#INCLUDEPATH += other/

win32:RC_ICONS += my_engine.ico

SOURCES +=  main.cpp \
    core/app.cpp \
    core/camera.cpp \
    core/geom.cpp \
    core/material.cpp \
    core/matrices.cpp \
    core/mesh.cpp \
    core/models/plane.cpp \
    core/sprites/sprite.cpp \
    core/models/sprite_sheet.cpp \
    core/scene.cpp \
    core/shader.cpp \
    core/texture.cpp \
    core/window.cpp \
    core/iapp.cpp

HEADERS += \
    core/app.h \
    core/camera.h \
    core/geom.h \
    core/gl_headers.h \
    core/key_constants.h \
    core/material.h \
    core/matrices.h \
    core/mesh.h \
    core/models/plane.h \
    core/sprites/sprite.h \
    core/models/sprite_sheet.h \
    core/scene.h \
    core/shader.h \
    core/texture.h \
    core/window.h \
    core/iapp.h \
    other/stb_image.h

DISTFILES += \
    resources/shaders/default.frag \
    resources/shaders/default.vert \
    resources/shaders/sprite.frag \
    resources/shaders/sprite.vert
