#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

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

    for (int i = 0; i < argc; i++){
        std::cout << argv[i] << std::endl;
    }



    std::string filePath = argv[1];

    Image pic;

    pic.Export(filePath);

    return 0;
}