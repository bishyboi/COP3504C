#include <iostream>
#include <vector>
#include "HeiferGenerator.h"
#include "Cow.h"
#include "Dragon.h"
#include "IceDragon.h"
using namespace std;

int main(int argc, char** argv)
{
    HeiferGenerator hg;
    vector<Cow*> cows = hg.getCows();

    switch (*argv[1])
        case ("-l"):
        {
            cout<< "Cows available: ";
            for (Cow *cow: cows)
            {
                cow->getName();
            }
        }
    return 0;
}