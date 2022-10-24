#pragma once

#include <string>
using namespace std;

class Cow
{
    public:
        Cow(const string& _name);
        string& getName();
        string& getImage();
        virtual void setImage(const string &_image);
        
        string name;
        string image;
};