#include "tools.h"
#include "min_heap.hpp"
#include "insertionSort.h"

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

    std::map<T, std::string> getHuffManCode()
    {
        return getHuffManCode_();
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
                cout<<ptr->val<<":"<<ptr->weight<<" ";
            first_(ptr->left);
            first_(ptr->right);
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

int main()
{
    huffman<char> tree;
    std::vector<std::pair<char, int>> item;
    item.push_back(std::pair<char, int>('f', 5));
    item.push_back(std::pair<char, int>('e', 9));
    item.push_back(std::pair<char, int>('c', 12));
    item.push_back(std::pair<char, int>('b', 13));
    item.push_back(std::pair<char, int>('d', 16));
    item.push_back(std::pair<char, int>('a', 45));
    tree.makeHuffMan(item);
    tree.first();
    cout<<endl;
    auto map = tree.getHuffManCode();
    for(auto i : map)
        cout<<i.first<<" "<<i.second<<endl;

    return 0;


}



