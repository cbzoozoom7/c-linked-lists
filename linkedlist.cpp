//linkedlist.cpp
//Chris Bowman
//Created 8 Mar 2023
#include "linkedlist.h"
LinkedList::LinkedList() {
    //head = NULL;
    head = new Node;
    Node *current = head;
    current->next = nullptr;
    current->data.id = 0;
    current->data.data = "0";
    for (int i = 0; i < DUMMY_LENGTH-1; i++) {
        Node *newNode = new Node;
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        current->next = NULL;
        current->data.id = i + 1;
        current->data.data = std::to_string(i + 1);
    }
}
void LinkedList::printData(Data *d) {
    std::cout << d->id << ": \t\"" << d->data << "\"" << std::endl;
}
void LinkedList::printList(bool backward) {
    Node *current = head;
    if (!backward) {
        while (current) {
            printData(&current->data);
            current = current->next;
        }
    }
    if (backward && current) {//getTail()?
        while (current->next) {
            current = current->next;
        }
        while (current) {
            printData(&current->data);
            current = current->prev;
        }
    }
}
bool LinkedList::addHead(Data *d) {
    Node *newNode = new Node;
    newNode->data = *d;
    newNode->next = head;
    if (head) {
        head->prev = newNode;
    }
    head = newNode;
    return true;
}
bool LinkedList::addNode(int id, string *data) {
    bool added = false;
    if (id > 0 && *data != "") {
        Data input;
        input.id = id;
        input.data = *data;
        Node *current = head;
        if (!current) {//empty list
            added = addHead(&input);
        } else if (id < current->data.id) {//new head
            added = addHead(&input);
        } else {
            while (id > current->data.id && current->next) {
                current = current->next;
            }
            if (id != current->data.id) {
                if (id < current->data.id) {//allows me to use the same code for middle & tail
                    current = current->prev;
                }
                Node* newNode = new Node;
                newNode->data = input;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next) {
                    current->next->prev = newNode;
                }
                current->next = newNode;
                added = true;
            }
        }
        
    }
    return added;
}
bool LinkedList::deleteNode(int id) {
    return false;
}
bool LinkedList::getNode(int id, Data *out) {
    return false;
}
int LinkedList::getCount() {
    return -1;
}
bool LinkedList::clearList() {
    return false;
}
LinkedList::~LinkedList() {
    clearList();
}
bool LinkedList::exists(int id) {
    return false;
}