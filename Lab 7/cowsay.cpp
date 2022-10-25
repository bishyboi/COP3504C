#include <iostream>
#include <vector>
#include "HeiferGenerator.h"
#include "Cow.h"
#include "Dragon.h"
#include "IceDragon.h"
#include "string.h"
using namespace std;

int main(int argc, char* argv[])
{
    HeiferGenerator hg;
    vector<Cow*> cows = hg.getCows();

    if(strcmp(argv[1], "-l") ==0)
    {
        cout<< "Cows available: ";
        for (Cow *cow: cows)
        {
            cout<<cow->getName()<< " ";
        }
    }

    else if(strcmp(argv[1], "-n")==0)
    {
        if(strcmp(argv[2], "heifer")==0)
        {
            cows[0]->getImage();
        } else if( strcmp(argv[2], "kitteh")==0)
        {
            cows[1]->getImage();
        } else if( strcmp(argv[2], "dragon")==0)
        {
            cows[2]->getImage();
        } else if( strcmp(argv[2], "ice-dragon")==0)
        {
            cows[3]->getImage();
        }else{
            cout<< "Couldn't find " << argv[2] << " cow!";
            break;
        }

        for (int i=3; i<argc; i++)
        {
            cout<< argv[i] << " ";
        }
    }
    else{

    }
    return 0;
}