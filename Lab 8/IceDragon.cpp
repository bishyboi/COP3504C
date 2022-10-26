#include "IceDragon.h"

IceDragon::IceDragon(const string &_name, const string &_image) : Dragon(_name, _image)
{
    this->name = _name;
    this->image = _image;
}

void IceDragon::setImage(const string &_image)
{
    this->image = _image;
}

bool IceDragon::canBreatheFire()
{
    return false;
}