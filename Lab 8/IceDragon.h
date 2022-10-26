#pragma once
#include <string>
#include "Cow.h"
#include "Dragon.h"
using namespace std;
class IceDragon : public Dragon
{
public:
    IceDragon(const string &_name, const string &_image);
    virtual void setImage(const string &_image);
    virtual bool canBreatheFire();
};