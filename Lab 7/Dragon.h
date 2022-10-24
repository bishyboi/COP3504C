#pragma once
#include <string>
#include "Cow.h"
using namespace std;
class Dragon: public Cow
{
    public:
        Dragon(const string &_name, const string &_image);
        virtual void setImage(const string &_image);
        virtual bool canBreatheFire();
};