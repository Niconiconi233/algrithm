#include "tools.h"
#include "min_heap.hpp"
#include "insertionSort.h"

template<typename T>
class huffmanNode
{
public:
    huffmanNode* left;
    huffmanNode* right;
    huffmanNode* parent;
    //T val;
    int weight;
    huffmanNode(int weight)
        :left(nullptr),
        right(nullptr),
        parent(nullptr),
        //val(val),
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
public:
    huffman():root(nullptr){}
    void makeHuffMan(const T* arr, size_t n) {
        if (n <= 0)
            return;
        MinHeap<node*> heap(std::bind(&compare<T>, std::placeholders::_1, std::placeholders::_2));
        for(int i = 0; i < n; ++i)
        {
            node* tmp = new node(arr[i]);
            heap.insert(tmp);
        }
        while (heap.size() > 1)
        {
            node* left = heap.top();
            heap.pop();
            node* right = heap.top();
            heap.pop();
            node* parent = new node(left->weight + right->weight);
            parent->left = left;
            parent->right = right;
            left->parent = parent;
            right->parent = parent;
            heap.insert(parent);
        }
        root = heap.top();
        heap.pop();
    }

    void first()
    {
        first_(root);
    }

private:
    void first_(huffmanNode<T>* ptr)
    {
        if(ptr)
        {
            cout<<ptr->weight<<" ";
            first_(ptr->left);
            first_(ptr->right);
        }
    }



private:
    using node = huffmanNode<T>;
    node* root;
};

int main()
{
    huffman<int> tree;
    int a[] = {5, 9, 12, 13, 16, 45};
    tree.makeHuffMan(a, sizeof(a)/sizeof(a[0]));
    tree.first();

    return 0;


}



