//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_LIST_HPP
#define TEST_LIST_HPP


#include "tools.h"


template<typename T>
class node
{
public:
    node(const T& val):val(val), next(NULL){}
    T val;
    node* next;
};

template<typename T>
class List
{
public:
    List()
    {
        head_ = NULL;
        end_ = NULL;
        size_ = 0;
    }
    ~List()
    {
        node<T>* ptr = head_;
        while(head_ != NULL)
        {
            ptr = ptr->next;
            delete head_;
            head_ = ptr;
        }
        head_ = NULL;
        end_ = NULL;
    }
    void push_back(const T& val)
    {
        node<T>* tmp = new node<T>(val);
        if(head_ == NULL)
        {
            head_ = tmp;
            end_ = tmp;
            ++size_;
            return ;
        }
        end_->next = tmp;
        end_ = tmp;
        ++size_;
    }
    bool insert(const T& val, size_t pos)
    {
        if(pos > size_)
            return false;
        if(pos == size_)
        {
            push_back(val);
            return true;
        }
        node<T>* tmp = new node<T>(val);
        node<T>* ptr = head_;
        for(size_t i = 0; i < pos - 1; ++i)
        {
            ptr = ptr->next;
            if(ptr == NULL)
            {
                delete tmp;
                return false;
            }
        }
        node<T>* ptr1 = ptr->next;
        ptr->next = tmp;
        tmp->next = ptr1;
        ++size_;
        return true;
    }

    bool erase(size_t pos)
    {
        if(pos > size_)
            return false;
        if(pos == size_)
        {
            node<T>* ptr = head_;
            while(ptr->next != end_)
            {
                ptr = ptr->next;
            }
            delete end_;
            end_ = ptr;
        }
        node<T>* ptr = head_;
        for(size_t i = 0; i < pos - 1; ++i)
        {
            ptr = ptr->next;
            if(ptr == NULL)
                return false;
        }
        node<T>* ptr1 = ptr->next->next;
        delete ptr->next;
        ptr->next = ptr1;
        --size_;
        return true;
    }

    size_t find(const T& val)
    {
        if(size_ == 0)
            return -1;
        node<T>* ptr = head_;
        size_t i = 0;
        while(ptr != NULL)
        {
            if(ptr->val == val)
                return i;
            ++i;
            ptr = ptr->next;
        }
        return -1;
    }

    size_t size() const
    {
        return size_;
    }

    T operator[](size_t idx)
    {
        if(head_ == NULL)
            return T();
        node<T>* ptr = head_;
        for(int i = 0; i < idx; ++i)
        {
            ptr = ptr->next;
            assert(ptr);
        }
        return ptr->val;
    }

    void pr()
    {
        node<T>* ptr = head_;
        while(ptr != NULL)
        {
            cout<<ptr->val<<" ";
            ptr = ptr->next;
        }
        cout<<endl;
    }

private:
    node<T>* head_;
    node<T>* end_;
    size_t size_;

};
#endif //TEST_LIST_HPP
