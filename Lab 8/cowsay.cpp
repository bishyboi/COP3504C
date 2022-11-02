#include <iostream>
#include <vector>
#include <cstring>
#include "HeiferGenerator.h"
#include "Cow.h"
#include "Dragon.h"
#include "IceDragon.h"
#include "string.h"
using namespace std;

int main(int argc, char *argv[])
{
    // Importing the different types of cows and the generator
    HeiferGenerator hg;
    vector<Cow *> cows = hg.getCows();
    vector<Cow *> fileCows = hg.getFileCows();

    // Only runs the program if there are cmd-line args, otherwise a Segmentation Fault will occur
    if (argc > 1)
    {
        // Checks if the first cmd-line argument is looking for a list of cow names
        if (strcmp(argv[1], "-l") == 0)
        {
            cout << "Regular cows available: ";

            // Iterates through the types of cows and returns their name
            for (int i = 0; i < cows.size(); i++)
            {
                if (i < cows.size() - 1)
                    cout << cows[i]->getName() << " ";
                else
                    cout << cows[i]->getName();
            }

            cout << endl
                 << "File cows available: ";

            for (int i = 0; i < fileCows.size(); i++)
            {
                if (i < fileCows.size() - 1)
                    cout << fileCows[i]->getName() << " ";
                else
                    cout << fileCows[i]->getName();
            }
        }

        // Checks if the first cmd-line argument is naming a regular cow
        else if (strcmp(argv[1], "-n") == 0)
        {
            bool cowFound = false;
            for (Cow *cow : cows)
            {
                // Searches through all cows to see if the name is valid
                if (cow->getName() == argv[2])
                {
                    cowFound = true;

                    // Prints message after the cow name
                    for (int i = 3; i < argc; i++)
                    {
                        if (i < argc)
                        {
                            cout << argv[i] << " ";
                        }
                        else
                        {
                            cout << argv[i];
                        }
                    }

                    // Displays the cow image
                    cout << endl
                         << cow->getImage();

                    // Code from https://dev-notes.eu/2019/05/Conditional-Printing-in-C-and-C++-Using-a-Ternary-Statement/ and 
                    // https://www.bogotobogo.com/cplusplus/upcasting_downcasting.php 
                    // Accessed 11/02/2022
                    if (typeid(*cow) == typeid(Dragon) || typeid(*cow) == typeid(IceDragon)) //Determines if the cow is a dragon
                    {
                        // Downcasts the cow to a dragon to determine whether or not it breathes fire
                        cout << "This dragon " << ((dynamic_cast<Dragon *>(cow)->canBreatheFire()) ? "can" : "cannot") << " breathe fire.";
                    }
                }
            }

            if (cowFound == false)
            {
                cout << "Could not find " << argv[2] << " cow!" << endl;
            }
        }

        // If a file cow cmd-line argument is entered
        else if (strcmp(argv[1], "-f") == 0)
        {
            bool cowFound = false;

            for (Cow *cow : fileCows)
            {
                // Iterates through all cows to determine if the name is valid
                if (cow->getName() == argv[2])
                {
                    cowFound = true;

                    // Prints the message after the fileCow name
                    for (int i = 3; i < argc; i++)
                    {
                        if (i < argc)
                        {
                            cout << argv[i] << " ";
                        }
                        else
                        {
                            cout << argv[i];
                        }
                    }

                    cout << endl
                         << cow->getImage();
                }
            }

            if (cowFound == false)
            {
                cout << "Could not find " << argv[2] << " cow!" << endl;
            }
        }
        // If only a message was entered as the cmd-line argument
        else
        {
            cout << endl;

            // Reads in cmd-line arguments
            string s;
            for (int i = 1; i < argc; i++)
            {
                s.append(argv[i]);
                s.append(" ");
            }
            s.pop_back();
            cout << s;

            // Grabs the Heifer image as the default
            cout << endl
                 << cows[0]->getImage();
        }
        cout << endl;
    }

    return 0;
}