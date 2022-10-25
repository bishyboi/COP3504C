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
        if( !((strcmp(argv[2], "heifer")==0) || (strcmp(argv[2], "kitteh")==0) || (strcmp(argv[2], "dragon")==0) || (strcmp(argv[2], "ice-dragon")==0)))  
        {
            cout<< "Couldn't find " << argv[2] << " cow!";
            
        }else{

            for (int i=3; i<argc; i++)
            {
                cout<< argv[i] << " ";
            }

            if(strcmp(argv[2], "heifer")==0)
            {
                cout<<cows[0]->getImage();
            } else if( strcmp(argv[2], "kitteh")==0)
            {
                cout<<cows[1]->getImage();
            } else if( strcmp(argv[2], "dragon")==0)
            {
                cout<<cows[2]->getImage();
                cout<<endl<<"This dragon can breathe fire.";
            } else if( strcmp(argv[2], "ice-dragon")==0)
            {
                cout<<cows[3]->getImage();
                cout<<endl<<"This dragon cannot breathe fire.";
            }
        }
    }
    else{
        for (int i=1; i<argc; i++)
        {
            cout<< argv[i] << " ";
        }
        cout<< std::endl<< cows[0]->getImage();
    }
    cout<< endl;
    return 0;
}