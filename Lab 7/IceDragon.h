#pragma once
#include "Dragon.h"
class IceDragon: public Dragon
{
    public:
        IceDragon(const string &_name, const string &_image);
        bool canBreatheFire();
};