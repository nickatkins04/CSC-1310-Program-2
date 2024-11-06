#ifndef USERS_H
#define USERS_H

#include "userData.h"

//List node class declaration
class UserNode
{
    UserData value;
    UserNode* next; //Points to next node
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
		void getNodeValue(int);
		void appendNode(UserData);
		void insertNode(int, UserData);
		void removeNode(UserData);
		void displayList() const;
        void sortList();
};

#endif