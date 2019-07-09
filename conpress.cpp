//
// Created by soft01 on 19-7-9.
//

#include "conpress.h"
#include "tools.h"
#include "huffman.hpp"

#include <fstream>
#include <vector>
#include <cerrno>

conpress::conpress(const std::string in, const std::string out)
    :inFileName_(in),
    outFileName_(out),
    count_(0)
{
    //memset(&arr_, 0, sizeof(arr_)/ sizeof(arr_[0]));
    getFrequency();
}

void conpress::getFrequency()
{
    std::ifstream input(inFileName_.c_str(), std::ios::in | std::ios::binary);
    //input.open(fileName_.c_str(), std::ios::in | std::ios::binary);
    if(!input.is_open())
    {
        std::cerr<<"failed to open file "<< strerror(errno)<<std::endl;
        return ;
    }
    while(true)
    {
        unsigned char c = input.get();
        if(input.eof())
            break;
        ++arr_[c];
        ++count_;
    }
    count_ -= 1;//忽略掉文件末尾的\n
    input.close();
}

void conpress::buildHuffman()
{
    std::vector<std::pair<unsigned char, int>> vector_;
    huffman<unsigned char> huffman_;
    for(int i = 0; i < 257; ++i)
    {
        if(arr_[i] != 0)
        {
            vector_.emplace_back(i, arr_[i]);
        }
    }
    huffman_.makeHuffMan(vector_);
    auto map = huffman_.getHuffManCode();
    huffmanCode_ = map;
}
/*
 * 写入3种文件信息
 * 1.int 字符种类数量
 * 2.int 字符数量
 * 3.char int 字符及其频率
 * 4.char 字符对应的霍夫曼码
 */

void conpress::fileConpress()
{
    buildHuffman();
    unsigned char tmp = 0;
    std::ofstream output(outFileName_.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
    std::ifstream input(inFileName_.c_str(), std::ios::in | std::ios::binary);
    if(!input.is_open())
    {
        std::cerr<<"failed to open file "<< strerror(errno)<<std::endl;
        return ;
    }
    if(!output.is_open())
    {
        std::cerr<<"fialed to create file " << strerror(errno)<<std::endl;
        input.close();
        return ;
    }
    {
        int cnt = 0;
        for(int i = 0; i < 257; ++i)
            if(arr_[i] != 0)
                ++cnt;
        output.write((char*)&cnt, sizeof(int));//信息一
        output.write((char*)&count_, sizeof(int));//信息二
    }
    for(size_t i = 0; i < 257; ++i)//信息三
    {
        if(arr_[i] != 0)
        {
            output.write((char*)&i, sizeof(char));
            output.write((char*)&arr_[i], sizeof(int));
        }
    }
    std::string str;
    size_t cnt = 0;
    while(true)
    {
        unsigned char c = input.get();
        if(input.eof())
            break;
        str += huffmanCode_[c];//拼接二进制吗
        ++cnt;
        while(str.length() >= 8)//处理霍夫曼码大于等与8位的
        {
            tmp = 0;
            for(int i = 0; i < 8; ++i)//写入前8位
            {
                tmp <<= 1;
                if(str[i] == '1')
                    tmp |= 1;
            }
            auto it = str.begin();
            str.erase(it, it + 8);
            output.write((char*)&tmp, sizeof(unsigned char));
        }
    }
    input.close();
    if(str.length() > 0)
    {
        tmp = 0;
        for(size_t i = 0; i < str.length(); ++i)
        {
            tmp <<= 1;
            if(str[i] == 1)
                tmp |= 1;
        }
        for(size_t i = 0; i < (8 - str.length()); ++i)
            tmp <<= 1;
        output.write((char*)&tmp, sizeof(unsigned char));
    }
    output.flush();
    output.close();
    cout<<"conpress done"<<endl;
}


