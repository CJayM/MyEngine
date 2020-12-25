#ifndef CORE_KEY_CONSTANTS_H
#define CORE_KEY_CONSTANTS_H

struct KeyConstats {
    enum MOUSE_CLICK {
        MOUSE_LEFT = 0,
        MOUSE_RIGHT = 1,
        MOUSE_MIDDLE = 2
    };

    enum PRESS_MODE {
        PRESS_UP = 0,
        PRESS_DOWN = 1,
        PRESS_HOLD
    };

    enum KEY_CONSTANTS {
        ARROW_RIGHT = 262,
        ARROW_LEFT = 263,
        ARROW_DOWN = 264,
        ARROW_UP = 265,

        NUM_MINUS = 333,
        NUM_PLUS = 334,
    };
};

#endif // CORE_KEY_CONSTANTS_H
