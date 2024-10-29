#ifndef USERS_H
#define USERS_H

#include "userData.h"
#include <string>

using namespace std;

class UserStorage
{
    private:
        //Declare structure for linked list
        struct UserNode
        {
            UserData value;
            UserNode* next; //Points to next node
        };

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
		UserData getNodeValue(UserData);
		void appendNode(UserData);
		void insertNode(int, UserData);
		void removeNode(UserData);
		void displayList() const;
        void sortList();
};

#endif