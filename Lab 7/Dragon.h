#pragma once
#include "Cow.h"

class Dragon: public Cow
{
    public:
        Dragon(const string &_name, const string &_image);
        virtual bool canBreatheFire();
};