//
// Created by soft01 on 19-7-12.
//

#include "tools.h"
#include "Base64.h"
#include <fstream>

int main()
{
    std::ifstream input("/home/soft01/下载/sci_fi_science_space_fantasy_art_artwork_artistic_futuristic_8000x4500.jpg", std::ios::in | std::ios::binary);
    if(!input.is_open())
        return -1;
    char* file = static_cast<char*>(malloc(1024 * 1024 * 10));
    input.seekg(0, std::ios::end);
    size_t size = input.tellg();
    input.seekg(0, std::ios::beg);
    input.read(file, size);
    input.close();
    std::string en(base64_encode(file, size));
    std::cout<<en;
    //std::ofstream out("1.jpg", std::ios::out | std::ios::binary);
    //std::string de(base64_decode(en));
    //out.write(de.c_str(), de.length());
    free(file);
    return 0;


}

