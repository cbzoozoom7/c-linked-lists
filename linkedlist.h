//linkedlist.h
//Chris Bowman
//Created 8 Mar 2023
#ifndef LINKEDLIST_H
    #define LINKEDLIST_H
    #include <iostream>
    #include "data.h"
    class LinkedList {
        public:
            LinkedList();
            ~LinkedList();
            bool addNode(int, string*);
            bool deleteNode(int);
            bool getNode(int, Data*);
            void printList(bool = false);
            int getCount();
            bool clearList();
            bool exists(int);
        private:
            Node *head;
            void printData(Data*);//prints the id & data of the provided Data on one line.
            Node *findNode(int);//returns a pointer to the Node with the given id.
            bool setNode(Node*, Data*);//makes a new node with the given data & links it in, given a pointer to the previous node. Assumes that the provided Data is valid.
    };
#endif