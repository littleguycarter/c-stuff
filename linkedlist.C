#include<stdlib.h>
#include<stdio.h>
#include "linkedlist.h"

struct Node {
    void* item;
    Node* nextNode;
};

struct LinkedList {
    int size;
    Node* head;
};

LinkedList* create() {
    LinkedList* listPointer = (LinkedList*) malloc(sizeof(LinkedList));
    listPointer->head = (Node*) malloc(sizeof(Node));
    listPointer->size = 0;
    listPointer->head->nextNode = NULL;
    listPointer->head->item = NULL;
    return listPointer;
}

void add(LinkedList* list, void* element) {
    Node* node = list->head;

    while (true) {
        if (node->nextNode == NULL) {
            break;
        }

        node = node->nextNode;
    }

    Node* next = (Node*) malloc(sizeof(Node));
    next->nextNode = NULL;
    next->item = NULL;
    node->nextNode = next;
    node->item = element;
    list->size += 1;
}

void remove(LinkedList* list, int index) {
    Node* previous = list->head;

    for (int i = 1; i < index; i++) {
        previous = previous->nextNode;
    }

    previous->nextNode = previous->nextNode->nextNode;
    free(previous->nextNode);
    list->size -= 1;
}

void clear(LinkedList* list) {
    Node* node = list->head;

    while (true) {
        if (node == NULL) {
            return;
        }

        Node* freeing = node;
        node = node->nextNode;
        free(freeing);
    }

    list->size = 0;
}

void* get(LinkedList* list, int index) {
    Node* current = list->head;

    for (int i = 0; i < index; i++) {
        current = current->nextNode;
    }

    return current->item;
}

int indexOf(LinkedList* list, void* pointer) {
    Node* current = list->head;

    for (int i = 0; i < list->size; i++) {
        if (current->item == pointer) {
            return i;
        }

        current = current->nextNode;
    }

    return -1;
}
