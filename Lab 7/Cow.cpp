#include "Cow.h"

Cow::Cow(const string &_name)
{
    this->name = _name;
}

string& Cow::getName()
{
    return this->name;
}

string& Cow::getImage()
{
    return this->image;
}

void Cow::setImage(const string &_image)
{
    this->image = _image;
}