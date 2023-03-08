//linkedlist.h
//Chris Bowman
//Created 8 Mar 2023
#ifndef LINKEDLIST_H
    #define LINKEDLIST_H
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
    };
#endif