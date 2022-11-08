#pragma once

#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Cow.h"

class FileCow : public Cow
{
public:
    FileCow(const string &_name, const string &filename);
    void setImage();
    string readFile(const string &filename);

};