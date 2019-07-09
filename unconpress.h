//
// Created by soft01 on 19-7-9.
//
/*
 * 基于霍夫曼编码的解压软件
 */

#ifndef TEST_UNCONPRESS_H
#define TEST_UNCONPRESS_H

#include "tools.h"
#include "huffman.hpp"

#include <map>


class unconpress{
public:
    unconpress(const std::string in, const std::string out);

    void getFrequency();

    void buildHuffman();

    void fileUnconpress(std::ifstream& input);




private:
    std::string inFileName_;
    std::string outFileName_;
    huffman<unsigned char> huffman_;
    int count_;
    //std::map<unsigned char, std::string> huffmanCode_;

};


#endif //TEST_UNCONPRESS_H
