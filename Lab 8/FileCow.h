#pragma once

#include <filesystem>
#include <stdexcept>
#include <Cow.h>

class FileCow : public Cow
{
public:
    string filename;
    FileCow(const string& _name, const string& filename);
    void setImage();

};