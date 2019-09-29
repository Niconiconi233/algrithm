//
// Created by soft01 on 19-7-14.
//
#include <thread>
#include <functional>
#include <pthread.h>
#include <future>
#include <chrono>
#include "tools.h"

int global = 10;

void somefunc(const int& x, int* heap)
{
    //x += 200;
    *heap += 300;
    global += 200;
}

void* func(void* arg)
{
    int* tmp = static_cast<int*>(arg);
    *tmp += 100;
    global += 100;
    return NULL;
}

void function(std::promise<std::string>& promise_)
{
    auto time = std::chrono::seconds(5);
    std::this_thread::sleep_for(time);
    cout<<"do some and will set value"<<endl;
    promise_.set_value("fuck you mother fucker");
}



int main()
{
    /*int local = 10;
    int* heap = static_cast<int*>(malloc(sizeof(int)));
    *heap = 0;
    cout<<"before global:"<<global<<" local:"<<local<<" heap:"<<*heap<<endl;
    std::thread thObj(somefunc, local, heap);
    thObj.join();
    //pthread_t tid;
    //pthread_create(&tid, NULL, func, &local);
    //pthread_join(tid, NULL);
    cout<<"after global:"<<global<<" local:"<<local<<" heap:"<<*heap<<endl;
    free(heap);*/
    /*std::promise<std::string> promise_;
    std::future<std::string> futrue_ = promise_.get_future();
    std::thread th(function, std::ref(promise_));
    cout<<"getting..."<<endl;
    auto str = futrue_.get();
    cout<<str<<endl;
    th.join();*/

    return 0;
}

