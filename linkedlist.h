#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct LinkedList;

LinkedList* create();

void add(LinkedList* list, void* element);

void remove(LinkedList* list, int index);

void clear(LinkedList* list);

void* get(LinkedList* list, int index);

int indexOf(LinkedList* list, void* pointer);

#endif
