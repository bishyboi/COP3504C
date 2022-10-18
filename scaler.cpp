#include <iostream>
#include <cmath>
#include "Image.h"
#include "ConsoleGfx.h"

ConsoleGfx *cg = ConsoleGfx::getInstance();
Image image = Image(nullptr);

bool menu();
unsigned char* scaledImage(unsigned char *imageData, int order);

int main()
{
    std::cout << "Welcome to the Image Scaler!" << std::endl << std::endl;
    std::cout << "Displaying Spectrum Image:" << std::endl;
    cg->displayImage(cg->testRainbow);

    bool run = true;
    while(run)
    {
        run = menu();
    }

    return 0;
}

bool menu()
{
    std::cout<< std::endl;
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
    std::cout<< std::endl<< "Select a Menu Option: ";
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
        case 4:
        {
            int order;
            std::cout<<"Enter orders of magnitude for enlargement: ";
            std::cin>> order;
            std::cout<<std::endl;

            scaledImage(image.getImageData(), order);

            std::cout<<"Image enlarged!"<< std::endl;
        }
        case 5:
        {
            int order;
            std::cout<<"Enter orders of magnitude for reduction: ";
            std::cin>> order;
            order *=-1;
            std::cout<<std::endl;

            scaledImage(image.getImageData(), order);

            std::cout<<"Image reduced!"<< std::endl;
        }
        case 6:
        {
            std::cout<<"Image Dimensions: (" << int(image.getWidth())<<", "<<int(image.getHeight())<< ")"<<std::endl;
        }
    }
    
    return true;
}

unsigned char* scaledImage(unsigned char *imageData, int order)
{
    unsigned char *scaledImageData = nullptr;

    Image *image = new Image(imageData);
    int adjustedOrder = order;
    int scaleFactor = std::pow(2,adjustedOrder);

    //Checking to see if scaling the image will exceed the boundaries where 1<height or width <256
    while ((scaleFactor * int(image->getHeight()) > 256) || (scaleFactor * int(image->getWidth()) > 256) || (scaleFactor * int(image->getHeight()) < 1) || (scaleFactor * int(image->getWidth()) < 1))
    {
        if ((scaleFactor * int(image->getHeight()) > 256) || (scaleFactor * int(image->getWidth()) > 256))
        {
            adjustedOrder--; //If the scale factor is too large, decrease it
        }else{
            adjustedOrder++; //If the scale factor is too small, increase it
        }

        scaleFactor = std::pow(2,adjustedOrder);
    }

    
    return scaledImageData;
}