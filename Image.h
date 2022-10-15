#pragma once

class Image
{
    unsigned char *width;
    unsigned char *height;
    unsigned char *pixelData;
    unsigned char *imageData;
public:
    Image(unsigned char *imageData);

    unsigned char* getImageData();
    unsigned char* getPixelData();
    unsigned char getWidth();
    unsigned char getHeight();

    void setImageData(unsigned char *newData);

};