//
// Created by soft01 on 2019/9/26.
//

#ifndef TEST_LINUX_LIST_H
#define TEST_LINUX_LIST_H

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE*)0)->MEMBER)

#define container_of(ptr, type, member) ({          \
const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
(type *)( (char *)__mptr - offsetof(type,member) );})

struct list_head
{
    list_head *next, *prev;
};

#define LIST_HEAD_INIT(name) {&(name), &(name)}

#define LIST_HEAD(name)\
    list_head name = LIST_HEAD_INIT(name)

static inline void INIT_LIST_HEAD(list_head* list)
{
        list->next = list;
        list->prev = list;
}

static inline void __list_add(list_head *n, list_head *prev, list_head *next)
{
        next->prev = n;
        prev->next = n;
        n->prev = prev;
        n->next = next;
}

static inline void list_add(list_head *n, list_head *head)
{
        __list_add(n, head, head->next);
}

static inline void list_add_tail(list_head *n, list_head *head)
{
        __list_add(n, head->prev, head);
}

static inline void __list_del(list_head *prev, list_head *next)
{
        next->prev = prev;
        prev->next = next;
}

static inline void list_del(list_head *entry)
{
        __list_del(entry->prev, entry->next);
}

static inline void __list_del_entry(list_head *entry)
{
        __list_del(entry->prev, entry->next);
}

static inline void list_del_init(list_head *entry)
{
        __list_del_entry(entry);
        INIT_LIST_HEAD(entry);
}

static inline void list_replace(list_head *old, list_head *n)
{
        n->next = old->next;
        n->next->prev = n;
        n->prev->next = n;
        n->prev = old->prev;
}

static inline int list_empty(list_head* head)
{
        return head->next == head;
}

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)

#define list_for_each(pos, head)    \
    for (pos = (head)->next; pos != (head); pos = pos->next)

//双指针
#define list_for_each_safe(pos, n, head)    \
    for(pos = (head)->next, n = pos->next; pos != (head);   \
    pos = n, n = pos->next)

#endif //TEST_LINUX_LIST_H
