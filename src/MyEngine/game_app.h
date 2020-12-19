#ifndef GAMEAPP_H
#define GAMEAPP_H

#include <string>

#include "core/app.h"

class GameApp: public core::App
{
public:
    GameApp(std::string title="Core App");
};

#endif // GAMEAPP_H
