#include "Dragon.h"

Dragon::Dragon(const string &_name, const string &_image): Cow(_name)
{
    this->name = _name;
    this->image= _image;
}

bool Dragon::canBreatheFire()
{
    return true;
}