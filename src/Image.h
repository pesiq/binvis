#include <vector>
#include <string>

class Color{
    float r, g, b;
public:
    Color();
    Color(float r, float g, float b);
    ~Color();
};

class Image{
private:
    size_t width;
    size_t height;

    std::vector<Color> data;

public:
    Image(size_t width, size_t height);
    Image();
    ~Image();

    Color getColor(size_t x, size_t y);
    void setColor(size_t x, size_t y, const Color& col);

    void Export(const std::string path);

};

