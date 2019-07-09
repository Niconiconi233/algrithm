//
// Created by soft01 on 19-7-9.
//
/*
 * 基于霍夫曼编码的压缩软件
 */

#ifndef TEST_CONPRESS_H
#define TEST_CONPRESS_H

#include "tools.h"

#include <map>


class conpress{
public:
    conpress(const std::string in, const std::string out);

    void getFrequency();

    void buildHuffman();

    void fileConpress();


private:
    int arr_[257]{0};
    std::string inFileName_;
    std::string outFileName_;
    size_t count_;
    std::map<unsigned char, std::string> huffmanCode_;

};


#endif //TEST_CONPRESS_H
