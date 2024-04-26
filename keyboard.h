
#include "fild.h"

#ifndef KEYBOARD_H
#define KEYBOARD_H


class Keyboard:public fild
{
public:
    Keyboard();

    // fild interface
protected:
    virtual void _init_Cels_() override;
public:
    bool highlight_Key();
};

#endif // KEYBOARD_H
