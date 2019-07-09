//
// Created by soft01 on 19-7-9.
//
/*
 * 霍夫曼树
 */

#ifndef TEST_HUFFMAN_HPP
#define TEST_HUFFMAN_HPP

#include "tools.h"
#include "min_heap.hpp"
#include "insertion_sort.h"

#include <map>
#include <stack>

template<typename T>
class huffmanNode
{
public:
    huffmanNode* left;
    huffmanNode* right;
    huffmanNode* parent;
    T val;
    int weight;
    huffmanNode(const T val, int weight)
            :left(nullptr),
             right(nullptr),
             parent(nullptr),
             val(val),
             weight(weight)
    {}
};

template<typename T>
bool compare(const huffmanNode<T>* lhs, const huffmanNode<T>* rhs)
{
    return lhs->weight < rhs->weight;
}

template<typename T>
class huffman
{
    using node = huffmanNode<T>;
public:
    using iterator = node*;
    huffman():root(nullptr){}

    ~huffman()
    {
        delete_(root);
    }

    void makeHuffMan(const std::pair<T, int>* arr, size_t n) {
        if (n <= 0)
            return;
        makeFuffMan_(arr, n);
    }

    void makeHuffMan(const std::vector<std::pair<T, int>> arr)
    {
        if(arr.size() <= 0)
            return;
        makeFuffMan_(arr.data(), arr.size());
    }

    /*
     * 前序遍历
     */
    void first()
    {
        first_(root);
    }

    void mid()
    {
        mid_(root);
    }

    void last()
    {
        last_(root);
    }

    std::map<T, std::string> getHuffManCode()
    {
        return getHuffManCode_();
    }

    const iterator getRoot()
    {
        assert(root != NULL);
        return root;
    }



private:
    void first_(iterator ptr)
    {
        if(ptr)
        {
            //cout<<ptr->val<<":"<<ptr->weight<<" ";
            if(ptr->val == T())
            {
                cout<<"NULL:"<<ptr->weight<<" ";
            }else
                cout<< static_cast<T>(ptr->val)<<":"<<ptr->weight<<" ";
            first_(ptr->left);
            first_(ptr->right);
        }
    }

    void mid_(iterator it)
    {
        std::stack<iterator> stack_;
        iterator iter = it;
        while(iter != NULL || !stack_.empty())
        {
            while(iter != NULL)
            {
                stack_.push(iter);
                iter = iter->left;
            }
            if(!stack_.empty())
            {
                iter = stack_.top();
                stack_.pop();
                if(iter->val != T())
                    cout<<iter->val<<":"<<iter->weight<<" ";
                else
                    cout<<"NULL:"<<iter->weight<<" ";
                iter = iter->right;
            }
        }
    }

    void last_(iterator it)
    {
        std::stack<iterator> stack1_;
        std::stack<iterator> stack2_;
        iterator iter = it;
        while(iter != NULL || !stack1_.empty())
        {
            if(iter)
            {
                stack1_.push(iter);
                stack2_.push(iter);
                iter = iter->right;
            }else
            {
                iter = stack1_.top();
                stack1_.pop();
                iter = iter->left;
            }
        }
        while(!stack2_.empty())
        {
            iter = stack2_.top();
            stack2_.pop();
            if(iter->val != T())
                cout<<iter->val<<":"<<iter->weight<<" ";
            else
                cout<<"NULL:"<<iter->weight<<" ";
        }
    }

    void makeFuffMan_(const std::pair<T, int>* arr, size_t len)
    {
        MinHeap<iterator> heap(std::bind(&compare<T>, std::placeholders::_1, std::placeholders::_2));
        for(int i = 0; i < len; ++i)
        {
            iterator tmp = new node(arr[i].first, arr[i].second);
            heap.insert(tmp);
        }

        while(heap.size() > 1)
        {
            iterator left = heap.top();
            heap.pop();
            iterator right = heap.top();
            heap.pop();
            iterator parent = new node(T(), left->weight + right->weight);
            parent->left = left;
            parent->right = right;
            left->parent = parent;
            right->parent = parent;
            heap.insert(parent);
        }
        root = heap.top();
        heap.pop();
    }

    std::map<T, std::string> getHuffManCode_()
    {
        std::stack<std::pair<iterator, std::string>> stack_;
        std::map<T, std::string> res;
        iterator iter = root;
        std::string str;
        while(iter != NULL || !stack_.empty()) {
            while (iter != NULL) {
                stack_.push(std::pair<iterator, std::string>(iter, str));
                if(iter->val != T())
                    res[iter->val] = str;
                iter = iter->left;
                if(iter)
                    str += "0";
            }
            if(!stack_.empty())
            {
                auto item = stack_.top();
                stack_.pop();
                iter = item.first;
                item.second += "1";
                str = item.second;
                iter = iter->right;
            }
        }
        return res;
    };

    void delete_(iterator iter)
    {
        if(iter)
        {
            delete_(iter->left);
            delete_(iter->right);
            delete iter;
        }
    }

private:
    node* root;
};

#endif //TEST_HUFFMAN_HPP
