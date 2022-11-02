#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string filename= "turtle";
    ifstream inFile ("cows\\" + filename + ".cow");
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

    cout<< image;
    return 0;
}