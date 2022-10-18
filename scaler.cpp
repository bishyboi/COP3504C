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
    std::cout << std::endl
              << "Select a Menu Option: ";
    std::cin >> selection;

    switch (selection)
    {
    case 0:
    {
        return false;
    }
    case 1:
    {
        std::string fileName;

        std::cout << "Enter name of file to load: ";
        std::cin >> fileName;
        std::cout << std::endl;

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
            std::cout << "Error: no image loaded";
        else
        {
            cg->displayImage(image.getImageData());
        }
        break;
    }
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
    case 5:
    {
        int order;
        std::cout << "Enter orders of magnitude for reduction: ";
        std::cin >> order;
        order *= -1;
        std::cout << std::endl;

        scaledImage(image.getImageData(), order);

        std::cout << "Image reduced!" << std::endl;
        break;
    }
    case 6:
    {
        std::cout << "Image Dimensions: (" << int(image.getWidth()) << ", " << int(image.getHeight()) << ")" << std::endl;
        break;
    }
    }

    return true;

}

unsigned char *scaledImage(unsigned char *imageData, int order)
{
    // Stores the original image
    Image image = Image(imageData);

    // Stores the height of the original image
    int imageHeight = int(image.getHeight());
    // Stores the width of the original image
    int imageWidth = int(image.getWidth());

    int adjustedOrder = order;
    int scaleFactor = std::pow(2, adjustedOrder);

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

    /*Iterate through all pixels and multiply them by the scale factor. When we scale an image
     * x4, we create x4 of the total pixels; therefore, x4 of each individual pixel*/

    // Stores all the scaled Image data (including width and height)
    unsigned char *scaledImageData = new unsigned char[imageHeight * imageWidth * scaleFactor * scaleFactor + 2];
    
    // Add two to the size so that the first and second indices hold the height and width of the image
    scaledImageData[0] = (unsigned char)(scaleFactor * imageWidth);
    scaledImageData[1] = (unsigned char)(scaleFactor * imageHeight);

    // needs to repeat for each row, so iterates for the height of the image
    for (int i = 0; i < imageHeight; i++) 
    {
        for (int j = 0; j < imageWidth; j++)
        {
            // FIXME: I really doubt this works

            /*
            Store the original pixel value scaleFactor times 
            Ex: scaleFactor=2, then there should be two of each pixel in each row, as well as two
            duplicates of the new scaled row 'stacked' on top of each other
            */

            //k corresponds to the height of the scaled pixel
            for (int k=0; k<scaleFactor; k++)
            {
                //l corresponds to the width of the scaled pixel
                for (int l=0; l<scaleFactor; l++)
                {
                    //+2 to account for the first two indices storing height and width
                    scaledImageData[(scaleFactor*i) +(i*scaleFactor*(j+l))+2 + k] = *(image.getPixelData() + imageHeight*i + j);
                }
            }
        }
    }
    return scaledImageData;
}