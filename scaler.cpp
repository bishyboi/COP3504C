#include <iostream>
#include <cmath>
#include "Image.h"
#include "ConsoleGfx.h"

ConsoleGfx *cg = ConsoleGfx::getInstance();
Image image = Image(nullptr);

bool menu();
unsigned char *scaledImage(unsigned char *imageData, int order);

int main()
{
    std::cout << "Welcome to the Image Scaler!" << std::endl
              << std::endl;
    std::cout << "Displaying Spectrum Image:" << std::endl;
    cg->displayImage(cg->testRainbow);

    bool run = true;
    while (run)
    {
        run = menu();
    }

    return 0;
}

bool menu()
{
    std::cout << std::endl;
    std::cout << "Scaler Menu" << std::endl;
    std::cout << "-----------" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "1. Load File" << std::endl;
    std::cout << "2. Load Test Image" << std::endl;
    std::cout << "3. Display Image" << std::endl;
    std::cout << "4. Enlarge Image" << std::endl;
    std::cout << "5. Shrink Image" << std::endl;
    std::cout << "6. Show Image Properties" << std::endl;

    int selection;
    std::cout << std::endl << "Select a Menu Option: ";
    std::cin >> selection;

    switch (selection)
    {
        //Exit
        case 0:
        {
            return false;
        }
        //Load File
        case 1:
        {
            std::string fileName;

            std::cout << "Enter name of file to load: ";
            std::cin >> fileName;
            std::cout << std::endl;

            image.setImageData(cg->loadFile(fileName));
            break;
        }
        //Load Test Image
        case 2:
        {
            image.setImageData(cg->testImage);
            break;
        }
        //Display Image
        case 3:
        {
            if (image.getImageData() == nullptr)
                std::cout << "Error: no image loaded";
            else
            {
                cg->displayImage(image.getImageData());
            }
            break;
        }
        //Enlarge Image
        case 4:
        {
            int order;
            std::cout << "Enter orders of magnitude for enlargement: ";
            std::cin >> order;
            std::cout << std::endl;

            image.setImageData(scaledImage(image.getImageData(), order));

            std::cout << "Image enlarged!" << std::endl;
            break;
        }
        //Shrink Image
        case 5:
        {
            int order;
            std::cout << "Enter orders of magnitude for reduction: ";
            std::cin >> order;
            order *= -1; //Makes order negative because it will be a negative exponent
            std::cout << std::endl;

            image.setImageData(scaledImage(image.getImageData(), order));

            std::cout << "Image reduced!" << std::endl;
            break;
        }
        //Show Image Properties
        case 6:
        {
            std::cout << "Image Dimensions: (" << int(image.getWidth()) << ", " << int(image.getHeight()) << ")" << std::endl;
            break;
        }
    }

    return true;
}

unsigned char* scaledImage(unsigned char *imageData, int order)
{
    // Stores the original image
    Image image = Image(imageData);

    int adjustedOrder = order;
    // Stores the height of the original image
    int imageHeight = int(image.getHeight());
    // Stores the width of the original image
    int imageWidth = int(image.getWidth());
    int area = imageHeight*imageWidth;
    int scaleFactor = order;

    // Checking to see if scaling the image will exceed the boundaries where 1<height or width <256
    while ((scaleFactor * imageHeight > 256) || (scaleFactor * imageWidth > 256) 
            || (scaleFactor * imageHeight < 1) || (scaleFactor * imageWidth < 1))
    {
        if ((scaleFactor * imageHeight > 256) || (scaleFactor * imageWidth > 256))
        {
            adjustedOrder--; // If the scale factor is too large, decrease it
        }
        else
        {
            adjustedOrder++; // If the scale factor is too small, increase it
        }

        scaleFactor = std::pow(2, adjustedOrder);
    }
    scaleFactor = std::pow(2, adjustedOrder);

    int scaledHeight = imageHeight*scaleFactor;
    int scaledWidth = imageWidth*scaleFactor;
    int scaledArea = scaledHeight*scaledWidth;

    /*Iterate through all pixels and multiply them by the scale factor. When we scale an image
     * x4, we create x4 of the total pixels; therefore, x4 of each individual pixel*/

    // Stores all the scaled Image data (including width and height)
    unsigned char *scaledImageData = new unsigned char[scaledArea + 2];
    
    //Matches formatting of image data in Image.cpp
    scaledImageData[0] = (scaleFactor * imageWidth);
    scaledImageData[1] = (scaleFactor * imageHeight);

    std::cout<<int(scaledImageData[0])<< ", "<< int(scaledImageData[1])<<std::endl;

    for (int x=0; x<imageWidth; x++)
    {
        for (int y=0; y<imageHeight; y++)
        {
            for (int i=0; i<scaleFactor; i++)
            {
                for (int j=0; j<scaleFactor; j++)
                {
                    int pixelIdx = x + y*imageWidth; //Converts 2-D coordinate on original image to 1-D coordinate
                    int scaledPixelIdx = (scaleFactor*x + i) + (scaleFactor*y + j)*(scaledWidth); //Converts 2-D scaled coordinate to 1-D scaled coordinate
                    scaledImageData[scaledPixelIdx + 2] = imageData[pixelIdx+2]; // Add two to account for [0] and [1] storing image width and height
                }
            }
        }
    }

    return scaledImageData;
}