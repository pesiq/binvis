#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Color{
public:
    unsigned char r, g, b;

    Color();
    Color(unsigned char r, unsigned char g, unsigned char b);
    ~Color();
};

class Image{
private:
    size_t width;
    size_t height;

    std::vector<Color> data;

public:
    Image(size_t width, size_t height);
    ~Image();

    Color getColor(size_t x, size_t y);
    void setColor(size_t x, size_t y, const Color& col);

    void Export(const std::string path);

};

