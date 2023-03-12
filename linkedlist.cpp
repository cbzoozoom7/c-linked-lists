//linkedlist.cpp
//Chris Bowman
//Created 8 Mar 2023
#include "linkedlist.h"
LinkedList::LinkedList() {
    head = NULL;
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
    if (backward && current) {
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
    newNode->prev = NULL;
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
Node *LinkedList::findNode(int id) {
    Node *current = head;
    if (current) {
        while (current->next && id > current->data.id) {
            current = current->next;
        }
        if (id != current->data.id) {
            current = NULL;
        }
    }
    return current;
}
bool LinkedList::deleteNode(int id) {
    bool deleted = false;
    Node *target = findNode(id);
    if (target) {
        if (target->prev) {
            target->prev->next = target->next;
        } else if (target == head) {
            head = target->next;
        }
        if (target->next) {
            target->next->prev = target->prev;
        }
        delete target;
        deleted = true;
    }
    return deleted;
}
bool LinkedList::getNode(int id, Data *out) {
    Node *gotten = findNode(id);
    if (gotten) {
        out->id = gotten->data.id;
        out->data = gotten->data.data;
    } else {
        out->id = -1;
        out->data = "";
    }
    return gotten;
}
int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
    if (current) {
        count++;
        while (current->next) {
            current = current->next;
            count++;
        }
    }
    return count;
}
bool LinkedList::clearList() {
    bool cleared = false;
    Node *current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = NULL;
    cleared = true;
    return cleared;
}
LinkedList::~LinkedList() {
    clearList();
}
bool LinkedList::exists(int id) {
    return false;
}