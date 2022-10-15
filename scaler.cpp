#include <iostream>
#include "Image.h"
#include "ConsoleGfx.h"

ConsoleGfx *cg = ConsoleGfx::getInstance();
Image image = Image(nullptr);
bool menu()
{
    std::cout<< std::endl << std::endl;
    std::cout<< "Scaler Menu" << std::endl;
    std::cout<< "-----------" << std::endl;
    std::cout<< "0. Exit"     << std::endl;
    std::cout<< "1. Load File"<< std::endl;
    std::cout<< "2. Load Test Image"<< std::endl;
    std::cout<< "3. Display Image"<< std:: endl;
    std::cout<< "4. Enlarge Image"<< std::endl;
    std::cout<< "5. Shrink Image"<< std::endl;
    std::cout<< "6. Show Image Properties" << std::endl;

    int selection;
    std::cout<< "Select a menu option: ";
    std::cin>> selection;

    switch (selection)
    {
        case 0:
        {
            return false;
        }
        case 1:
        {
            std::string fileName;

            std::cout<< "Enter name of file to load: ";
            std::cin>> fileName;
            std::cout<<std::endl;
            
            image.setImageData(cg->loadFile(fileName));
            break;
        }
        case 2:
        {
            image.setImageData(cg->testImage);
            break;
        }
        case 3:
        {   
            if (image.getImageData() == nullptr)
                std::cout<< "Error: no image loaded";
            else{
                cg->displayImage(image.getImageData());
            
            }
            break;
        }
    }
    
    return true;
}

int main()
{
    std::cout << "Welcome to the Image Scaler!" << std::endl;
    std::cout << "Displaying Spectrum Image:" << std::endl;
    cg->displayImage(cg->testRainbow);

    bool run = true;
    while(run)
    {
        run = menu();
    }

    return 0;
}