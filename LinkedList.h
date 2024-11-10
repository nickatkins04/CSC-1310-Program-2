#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "userData.h"

//List node class declaration
class UserNode
{
    private:
        UserData value;
        UserNode* next; //Points to next node

    public:
        // Constructor
        UserNode(UserData userValue)
        {
            value = userValue;
			next = NULL;
        }

        //Setters
        void setValue(UserData userValue)
        {
            value = userValue;
        }

        void setNext(UserNode* nextNode)
        {
            next = nextNode;
        }

        //Getters
        UserData getValue() const
        {
            return value;
        }

        UserNode* getNext() const
        {
            return next;
        }
};

//Linked list class declaration, stores user data in list
class UserStorage
{
    private:
        UserNode* head; //Head pointer
        UserNode* tail; //Tail pointer

    public:
        //Constructor
        UserStorage()
        {
            head = NULL;
            tail = NULL;
        }

        //Destructor
        ~UserStorage();

        //Linked List operations
        bool isEmpty();
		int getLength();
		int search(UserData);
        UserData getNodeValue(int);
		void displayNodeValue(int);
		void appendNode(UserData);
		void insertNode(int, UserData);
		void removeNode(UserData);
		void displayList() const;

        //Sorting Functions
        void quickSortUp(int, int);
        void quickSortDown(int, int);
        int partitionUp(int, int);
        int partitionDown(int, int);
        void swap(int, int);
};

#endif