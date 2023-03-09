//linkedlist.cpp
//Chris Bowman
//Created 8 Mar 2023
#include "linkedlist.h"
LinkedList::LinkedList() {
    //head = nullptr;
    head = new Node;
    Node *current = head;
    current->next = nullptr;
    current->data.id = 0;
    current->data.data = "0";
    for (int i = 0; i < DUMMY_LENGTH; i++) {
        Node *newNode = new Node;
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
        current->next = nullptr;
        current->data.id = i + 1;
        current->data.data = std::to_string(i + 1);
    }
}
LinkedList::~LinkedList() {
    clearList();
}
bool LinkedList::addNode(int id, string *data) {
    return false;
}
bool LinkedList::deleteNode(int id) {
    return false;
}
bool LinkedList::getNode(int id, Data *out) {
    return false;
}
void LinkedList::printList(bool backward) {
    Node *current = head;
    while (current){
        std::cout << current->data.id << ": \t\"" << current->data.data << "\"" << std::endl;
        current = current->next;
    }
}
int LinkedList::getCount() {
    return -1;
}
bool LinkedList::clearList() {
    return false;
}
bool LinkedList::exists(int id) {
    return false;
}