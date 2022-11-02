#include "FileCow.h"

FileCow::FileCow(const string &_name, const string &filename) : Cow(_name)
{
    this->image = FileCow::readFile(filename);
}

// Code from https://documents.uow.edu.au/~lukes/TEXTBOOK/notes-cpp/io/readtextfile.html and https://www.udacity.com/blog/2021/05/how-to-read-from-a-file-in-cpp.html
// Accessed on 11/02/2022

// Reads a text file and returns the entire text file, including all whitespace and new lines.
string FileCow::readFile(const string &filename)
{
    ifstream inFile ("cows\\" + filename);
    string image;

    if(inFile)
    {
        string line;
        while(inFile)
        {
            getline(inFile,line);
            image.append(line+"\n");
        }
    } else
    {
        cerr << "MOOOO!!!";
    }

    return image;
}

void FileCow::setImage()
{
    throw std::runtime_error("Cannot reset FileCow Image");
}