#include "./Image.h"


std::vector<std::byte> &readFile(std::string path){
    std::ifstream file (path);
    auto buffer = new std::vector<std::byte>;
    char s;
    while (file.get(s)){
        buffer->push_back(std::byte(s));
    }
    return *buffer;
}

int main (int argc, char *argv[]) {

    if (argc < 2){
        std::cout << "no args" << std::endl;
        return 0;
    }

    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }



    std::string filePath = argv[1];

    const size_t width = 2000;
    const size_t height = 2000;
    Image pic(width, height);

    for(size_t x = 0; x < width; x++){
        for(size_t y = 0; y < height; y++){
            pic.setColor(x, y, Color(x, y, x+y));
        }
    }

    pic.Export(filePath);
    pic.Dump("Dump.bmp");
    

    return 0;
}