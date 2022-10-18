#include "Image.h"

Image::Image(unsigned char *imageData)
{
    this->imageData = imageData;
    this->width = imageData; 
    this->height= imageData+1;
    this->pixelData = imageData+2;
}

unsigned char* Image::getImageData()
{
    return imageData;
}

unsigned char* Image::getPixelData()
{
    return pixelData;
}

unsigned char Image::getWidth()
{
    return *width;
}

unsigned char Image::getHeight()
{
    return *height;
}

void Image::setImageData(unsigned char *newData)
{
    //Deallocating the memory stored in original Image
    delete this->pixelData;
    delete this->height;
    delete this->width;
    delete this->imageData;

    this->imageData = newData;
    this->width = newData; 
    this->height= newData+1;
    this->pixelData = newData+2;
}