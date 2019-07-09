//
// Created by soft01 on 19-7-9.
//

#include "unconpress.h"

#include <fstream>
#include <vector>
#include <sstream>

unconpress::unconpress(const std::string in, const std::string out)
    :inFileName_(in),
    outFileName_(out),
    huffman_(),
    count_(0)
{
    getFrequency();
}

void unconpress::getFrequency()
{
    std::ifstream input(inFileName_.c_str(), std::ios::in | std::ios::binary);
    if(!input.is_open())
    {
        std::cerr<<"failed to open file " << strerror(errno)<<std::endl;
        return ;
    }
    int cnt = 0;
    input.read((char*)&cnt, sizeof(int));//读取信息一
    input.read((char*)&count_, sizeof(int));//读取信息二
    std::vector<std::pair<unsigned char, int>> vector_;
    for(int i = 0; i < cnt; ++i)
    {
        unsigned char c = 0;
        int weight = 0;
        input.read((char*)&c, sizeof(char));
        input.read((char*)&weight, sizeof(int));
        vector_.emplace_back(c, weight);
    }
    //input.close();
    huffman_.makeHuffMan(vector_);
    fileUnconpress(input);
}

void unconpress::fileUnconpress(std::ifstream& input)
{
    huffman<unsigned char>::iterator iter = huffman_.getRoot();
    huffman<unsigned char>::iterator cur = iter;
    std::ofstream output(outFileName_.c_str(), std::ios::out | std::ios::trunc);
    if(!output.is_open())
    {
        std::cerr<<"failed to create file " << strerror(errno)<<std::endl;
        input.close();
        return ;
    }
    unsigned char c = 0;
    std::ostringstream os;
    while(count_ > 0)
    {
        c = input.get();
        for(int i = 0; i < 8; ++i)
        {
            if(c & 128)
            {
                if(cur->right)
                    cur = cur->right;
            }
            else
                if(cur->left)
                    cur = cur->left;
            if(cur->left == NULL && cur->right == NULL)//叶节点
            {
                os<<cur->val;
                if(--count_ == 0)
                    break;
                cur = iter;
            }
            c <<= 1;
        }
    }
    {
        std::string str = os.str();
        os.clear();
        output.write(str.c_str(), str.length());
        output.flush();
        output.close();
    }
    cout<<"unconpress done"<<endl;
}



