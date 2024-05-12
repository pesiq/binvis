#include <fstream>
#include <iostream>

#include "./Image.h"

#define FILE_HEADER_SIZE 12
#define INFO_HEADER_SIZE 40

/////////////////////////////////////////////////////////////////

Color::Color() : r(0), g(0), b(0) {}
Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}
Color::~Color(){}

/////////////////////////////////////////////////////////////////

Image::Image(size_t width, size_t height)
    : width(width), height(height), data(std::vector<Color>(width * height)) {}

Image::Image() : width(0), height (0), data(NULL) {}

Image::~Image(){}

Color Image::getColor(size_t x, size_t y){
    return data[y * width + x];
}

void Image::setColor(size_t x, size_t y, const Color &col){
    data[y * width + x] = col;
}

void Image::Export(const std::string path){
    std::ofstream file (path, std::ios::out | std::ios::binary);

    if(!file.is_open()){
        std::cout << "Unable to open file" << std::endl;
        return;
    }

    const int padding = (4 - (width * 3) % 4) % 4;
    const int paddingAmount = ((width * 3) + padding) * height;
    const int fileSize = FILE_HEADER_SIZE + INFO_HEADER_SIZE + width * height * 3 + paddingAmount;

    char BM[2] = {'B', 'M'}; 
    unsigned int fileHeader[FILE_HEADER_SIZE / 2];
    unsigned int infoHeader[INFO_HEADER_SIZE / 4];

    //filling file header
    //BM is not included here
    fileHeader[0] = fileSize; //fileSize
    fileHeader[1] = 0; //reserved bits (unused)
    fileHeader[2] = FILE_HEADER_SIZE + INFO_HEADER_SIZE + 2; //offset size (+2 for BM)

    //filling bmp header
    infoHeader[0] = INFO_HEADER_SIZE; // size of header
    infoHeader[1] = width;
    infoHeader[2] = height;

    unsigned short planes = 1; // number of planes =1
    unsigned short bpp = 24; //bits per pixel 24 for full RGB

    unsigned int concat = (planes << 16) + bpp;

    infoHeader[3] = concat;

    infoHeader[4] = 0; //compression; 0 = no compression
    infoHeader[5] = 0; //ImageSize; 0 if no compression

    infoHeader[6] = 0; //horizontal resolution: Pixels/meter; 0 = not specified
    infoHeader[7] = 0; //vertical resolution: Pixels/meter; = 0 not specified

    infoHeader[8] = 0; // color palette; 0 = not used
    infoHeader[9] = 0; //important colors; 0 = all

    //headers done, now write them to file

    file.write(BM, 2);
    file.write((char *)fileHeader, FILE_HEADER_SIZE);
    file.write((char *)infoHeader, INFO_HEADER_SIZE);

    // now write actual data
    // image data is written from bottom to top
    // and colors are written as (b, r, g)
    for(int y = height - 1; y >= 0; y--){
        for(int x = 0; x < width; x++){

        }
    }

}
