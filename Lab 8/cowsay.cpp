#include <iostream>
#include <vector>
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

    // Only runs the program if there are cmd-line args, otherwise a Segmentation Fault will
    if (argc > 1)
    {
        // Checks if the first cmd-line argument is looking for a list of cow names
        if (strcmp(argv[1], "-l") == 0)
        {
            cout << "Cows available: ";
            string message;

            // Iterates through the types of cows and returns their name
            for (Cow *cow : cows)
            {
                message.append(cow->getName());
                message.append(" ");
            }
            message.pop_back();
            cout << message << endl;
        }

        // Checks if the first cmd-line argument is naming a specific cow
        else if (strcmp(argv[1], "-n") == 0)
        {
            // Checks if the name is valid
            if (!((strcmp(argv[2], "heifer") == 0) || (strcmp(argv[2], "kitteh") == 0) || (strcmp(argv[2], "dragon") == 0) || (strcmp(argv[2], "ice-dragon") == 0)))
            {
                cout << "Could not find " << argv[2] << " cow!" << endl;
            }
            else
            {
                cout << endl;

                // Grabs the message after the name of the cow
                string s;
                for (int i = 3; i < argc; i++)
                {
                    s.append(argv[i]);
                    s.append(" ");
                }
                s.pop_back();
                cout << s << endl;

                // Gets the image of the cow
                if (strcmp(argv[2], "heifer") == 0)
                {
                    cout << cows[0]->getImage();
                }
                else if (strcmp(argv[2], "kitteh") == 0)
                {
                    cout << cows[1]->getImage();
                }
                else if (strcmp(argv[2], "dragon") == 0)
                {
                    cout << cows[2]->getImage();
                    cout << endl
                         << "This dragon can breathe fire." << endl;
                }
                else if (strcmp(argv[2], "ice-dragon") == 0)
                {
                    cout << cows[3]->getImage();
                    cout << endl
                         << "This dragon cannot breathe fire." << endl;
                }
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