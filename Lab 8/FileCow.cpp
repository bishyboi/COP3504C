#include "FileCow.h"

FileCow::FileCow(const string& _name, const string& filename) : Cow(_name)
{
    this->filename = filename;
}

void FileCow::setImage()
{
    throw std::runtime_error("Cannot reset FileCow Image");
}