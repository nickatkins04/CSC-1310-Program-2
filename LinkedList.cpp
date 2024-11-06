#include "LinkedList.h"
#include <iostream>

using namespace std;

//Function that returns true or false for if the funcion is empty
bool UserStorage::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

//Function that returns the number of nodes in the list
int UserStorage::getLength()
{
	int counter = 0;
	UserNode* nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

//Searches for a specific user and returns their position
int UserStorage::search(UserData user)
{
	UserNode* nodePtr;
    int position;

	// Start nodePtr at head of list
	nodePtr = head;
	position = 0;

	// While nodePtr points to a node, continue through list
	while (nodePtr)
	{
		if(nodePtr->value == user)
			return position;
		
		position++;
		nodePtr = nodePtr->next;
	}
	return -1;
}

void UserStorage::getNodeValue(int position)
{
	UserNode* nodePtr;
	if(!head)
    {
		cout << "This is not a position in the list\n\n";
        return;
    }
	else
	{
		if(position == 0)
        {
			cout << head->value; //need to output a user and info
        }
		nodePtr = head;
		int currentPos = 0;
		while(nodePtr != NULL && position >= currentPos)
		{
			if(position == currentPos)
				cout << nodePtr->value; //need to output a user and info
			currentPos++;
			nodePtr = nodePtr->next;				
		}
	}
    cout << "This is not a position";
	return;
}

void UserStorage::appendNode(UserData user)
{
	UserNode* newNode;  // To point to a new node

	// Allocate a new node and store num there.
	newNode = new UserNode;
	newNode->value = user;
	newNode->next = NULL;

	// If there are no nodes in the list make newNode the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  // Otherwise, insert newNode at end.
	{
		//set the current last node's next pointer to the new node
		tail->next = newNode;
		
		//now the tail is the new node
		tail = newNode;
	}
}

void UserStorage::insertNode(int position, UserData user)
{
	UserNode* nodePtr;
	UserNode* newNode;
	
	newNode = new UserNode;
	newNode->value = user;
	
	if(!head)
	{
		if(position != 0)
		{
			//can't insert node at position (>0) if there is not already a node
			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newNode->next = head->next;
			head = newNode;
		}
		while(nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->next;
		}
		
		//now nodePtr is positioned 1 node BEFORE the node we want to insert
		if(nodePtr->next == NULL) //we are appending this node to the end
			tail = newNode;
			
		newNode->next = nodePtr->next;
		nodePtr->next = newNode;
		
	}
	
}

void UserStorage::removeNode(UserData user)
{
	UserNode* nodePtr;       // To traverse the list
	UserNode* previousNode;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head)
		return;

	// Determine if the first node is the one.
	if (head->value == user)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != NULL && nodePtr->value != user)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}

void UserStorage::displayList() const
{
	UserNode* nodePtr;  // To move through the list

	if(head != NULL)
	{
		// Position nodePtr at the head of the list.
		nodePtr = head;
		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->value << endl; //Need to output user and user info

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

void UserStorage::sortList()


UserStorage::~UserStorage()
{
	UserNode* nodePtr;   // To traverse the list
	UserNode*nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;
		
		cout << "\nDeleting the node with value " << nodePtr->value;
		
		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	cout << endl << endl;
}