#include <iostream>
#include <vector>
#include "HeiferGenerator.h"
#include "Cow.h"
#include "Dragon.h"
#include "IceDragon.h"
using namespace std;

int main(int argc, char* argv[])
{
    HeiferGenerator hg;
    vector<Cow*> cows = hg.getCows();
    string args = *argv;

    cout<<args[2];
    // if(args[1]).compare("-l"))
    // {
    //     cout<< "Cows available: ";
    //     for (Cow *cow: cows)
    //     {
    //         cow->getName();
    //     }
    // }
    return 0;
}