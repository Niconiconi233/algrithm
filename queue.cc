#include "tools.h"



template<typename T>
class Queue
{
public: 
    Queue(int init = 128)
    {
        arr_ = static_cast<T*>(malloc(sizeof(T) * init));
        beg_ = arr_;
        curr_ = beg_;
        end_ = arr_ + init;
        size_ = init;
    }

    ~Queue()
    {
        delete arr_;
    }

    void enQueue(const T& val)
    {
        if(curr_ != end_)
            *curr_++ = val;
        else
        {
            makeSpace();
            *curr_++ = val;
        }     
    }

    T DeQueue()
    {
        T val = *beg_++;
        if(beg_ == curr_)
        {
            beg_ = arr_;
            curr_ = beg_;
        }
        if(curr_ - beg_ < size_ / 2)
        {
            size_t len = curr_ - beg_;
            memmove(arr_, beg_, len* sizeof(T));
            beg_ = arr_;
            curr_ = beg_ + len;
        }
        return val;
    }

    size_t size()
    {
        return curr_ - beg_;
    }

private: 
    T* arr_;
    T *beg_, *curr_, *end_;
    size_t size_;

    void makeSpace()
    {
        T* tmp = static_cast<T*>(malloc(sizeof(T) * (size_ * 2)));
        assert(tmp);
        memcpy(tmp, beg_, sizeof(T) * size());
        size_ *= 2;
        size_t len = curr_ - beg_;
        delete arr_;
        arr_ = tmp;
        beg_ = arr_;
        end_ = beg_ + size_;
        curr_ = beg_ + len;
    }
};


int main(int argc, char const *argv[])
{
    Queue<int> queue;
    for(int i = 0; i < 1000; ++i)
        queue.enQueue(i);
    for(int i = 0; i < 600; ++i)
        cout<<queue.DeQueue()<<" ";
    cout<<endl;
    for(int i = 0; i < 1000; ++i)
        queue.enQueue(i);
    for(int i = 0; i < 1400; ++i)
        cout<<queue.DeQueue()<<" ";
    cout<<endl;
    return 0;
}

