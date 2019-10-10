//
// Created by soft01 on 2019/10/9.
//
#include <set>
#include <iostream>
using namespace std;

using MinHeap = set<int>;
using MaxHeap = set<int, greater<int> >;

class DynamicArray
{
public:
    void insert(int value)
    {
        if(((minHeap_.size() + maxHeap_.size()) & 1) == 0)//偶数 插入到最小堆
        {
            //保证最小堆中每个数都比最大堆大
            if(maxHeap_.size() > 0 && value < *maxHeap_.begin())
            {
                maxHeap_.emplace(value);
                value = *maxHeap_.begin();
                maxHeap_.erase(maxHeap_.begin());
                //minHeap_.emplace(tmp);
            }
            minHeap_.emplace(value);
        }else
        {
            if(minHeap_.size() > 0 && value > *minHeap_.begin())
            {
                minHeap_.emplace(value);
                value = *minHeap_.begin();
                minHeap_.erase(minHeap_.begin());
            }
            maxHeap_.emplace(value);
        }
    }

    int getMedian()
    {
        int size = minHeap_.size() + maxHeap_.size();
        if(size == 0)
            return 0;
        if(size & 1 == 0)
            return (*minHeap_.begin() + *maxHeap_.begin()) / 2;
        else
            return *minHeap_.begin();
    }


private:
    MinHeap minHeap_;
    MaxHeap maxHeap_;
};

int main()
{
    DynamicArray arr;
    arr.insert(1);
    arr.insert(2);
    arr.insert(4);
    arr.insert(5);
    arr.insert(8);
    arr.insert(9);
    arr.insert(50);
    arr.insert(52);
    arr.insert(230);
    arr.insert(44);
    arr.insert(43);
    arr.insert(333);
    arr.insert(555);
    cout<<arr.getMedian();
    return 0;
}

