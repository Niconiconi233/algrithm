//
// Created by soft01 on 2019/9/26.
//
#include <iostream>
using namespace std;

#include <string.h>

#include "linux_list.h"

struct t{
    double a;//0
    int b;//8
    double c;//16
    char d;//24
};

struct person
{
    int age;
    char name[20];
    list_head list;
};

int main()
{
//    t tt;
//    cout<<offsetof(t, a)<<endl;
//    cout<<offsetof(t, b)<<endl;
//    cout<<offsetof(t, c)<<endl;
//    cout<<offsetof(t, d)<<endl;
//    cout<<sizeof(t)<<endl;

//    cout<<(void*)&tt<<endl;
//    cout<<container_of(&tt.d, t, d)<<endl;

    person person_head;
    person *ptr;
    list_head *pos, *n;
    INIT_LIST_HEAD(&person_head.list);

    for(int i = 0; i < 5; ++i)
    {
        ptr = (person*)malloc(sizeof(person));
        ptr->age = 1;
        snprintf(ptr->name, 20, "fuckyou");
        list_add_tail(&(ptr->list), &(person_head.list));
    }

    list_for_each(pos, &person_head.list)
    {
        ptr = list_entry(pos, person, list);//获取整个结构体地址
        cout<<ptr->age<<" "<<ptr->name<<endl;
    }

    list_for_each_safe(pos, n, &person_head.list)
    {
        ptr = list_entry(pos, person, list);
        if(ptr->age == 20)
        {
            list_del(pos);
            free(ptr);
        }
    }

    list_for_each(pos, &person_head.list)
    {
        ptr = list_entry(pos, person, list);
        cout<<ptr->age<<" "<<ptr->name<<endl;
    }

    list_for_each_safe(pos, n, &person_head.list)
    {
        ptr = list_entry(pos, person, list);
        list_del_init(pos);
        free(ptr);
    }

}