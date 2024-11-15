#include "LinkedList.h"
#include <iostream>

using namespace std;

// edit function implementation after adding template to header

//Function that returns true or false for if the funcion is empty
template<typename T>
bool UserStorage<T>::isEmpty()
{
	if(!head)
		return true;
	else
		return false;
}

//Function that returns the number of nodes(users) in the list
template<typename T>
int UserStorage<T>::getLength()
{
	int counter = 0;
	UserNode<T>* nodePtr; //To point to a new node
	
	//Start nodePtr at head of list
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->getNext();
		if (nodePtr == tail)
			counter++;
	}
	return counter;
}

//Function that searches for a specific user and returns their position
template<typename T>
int UserStorage<T>::search(UserData user)
{
	UserNode<T>* nodePtr; //To point to a new node
    int position;

	//Start nodePtr at head of list
	nodePtr = head;
	position = 0;

	//While nodePtr points to a node, continue through list
	while(nodePtr)
	{
		if(nodePtr->getValue() == user)
			return position;
		
		position++;
		nodePtr = nodePtr->getNext();
	}
	return -1;
}

//Function that returns a user's node value given the position of their node
template<typename T>
UserData UserStorage<T>::getNodeValue(int position)
{
	UserNode<T> *nodePtr; //To point to a new node
	
	if(position == 0)
		return head->getValue();

	//Start nodePtr at head of list
	nodePtr = head;
	int currentPos = 0;

	//While nodePtr points to a node, continue through list
	while(nodePtr)
	{
		if(position == currentPos)
			return nodePtr->getValue();
		currentPos++;
		nodePtr = nodePtr->getNext();
	}
}

//Function that displays a user's information given the position of their node
template<typename T>
void UserStorage<T>::displayNodeValue(int position)
{
	UserNode<T>* nodePtr; //To point to a new node

	//Ends function if list is empty
	if(!head)
    {
		cout << "This is not a position in the list\n\n";
        return;
    }
	else
	{
		if(position == 0)
        {
			cout << head->getValue(); //Displays first user's info
        }

		//Start nodePtr at head of list
		nodePtr = head;
		int currentPos = 0;
		while(nodePtr != NULL && position >= currentPos)
		{
			if(position == currentPos)
				cout << nodePtr->getValue(); //Outputs user's info in the current node
			nodePtr = nodePtr->getNext();				
		}
	}
    cout << "This is not a position"; //Bad input protection
	return;
}

//Function that adds a user to the list
template<typename T>
void UserStorage<T>::appendNode(UserData user)
{
	UserNode<T>* newNode; //To point to a new node

	//Creates new node to store the new user
	newNode = new UserNode<T>();

	//If there are no nodes in the list, makes the neww node the first node.
	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  //If not, add new node at the end
	{
		tail->setNext(newNode);
		
		tail = newNode;
	}
}

//Function that adds a user in a specific location given a position
template<typename T>
void UserStorage<T>::insertNode(int position, UserData user)
{
	UserNode<T>* nodePtr; //To point to a new node
	UserNode<T>* newNode;

	//Creates new node to store the new user
	newNode = new UserNode<T>(user);
	
	//Checks if list is empty
	if(!head)
	{
		//Prevents adding to empty list at any other position than 0
		if(position != 0)
		{
			cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
		}
		head = newNode;
		tail = newNode;
	}
	else
	{
		//Start nodePtr at head of list
		nodePtr = head;
		int nodeCount = 0;
		//Makes new node head
		if(position == 0)
		{
			newNode->setNext(head->getNext());
			head = newNode;
		}
		while(nodePtr != tail && nodeCount < position)
		{
			nodeCount++;
			if(nodeCount == position)
				break;
			nodePtr = nodePtr->getNext();
		}
		
		if(nodePtr->getNext() == NULL)
			
		newNode->setNext(nodePtr->getNext());
		nodePtr->setNext(newNode);
		
	}
	
}

//Function that removes a user from the list given their value
template<typename T>
void UserStorage<T>::removeNode(UserData user)
{
	UserNode<T>* nodePtr;       //To point to a new node
	UserNode<T>* previousNode;  //To point to the previous node

	//Ends function if list is empty
	if (!head)
		return;

	//Checks the first node for user value
	if (head->getValue() == user)
	{
		nodePtr = head->getNext();
		delete head;
		head = nodePtr;
	}
	else
	{
		//Start nodePtr at head of list
		nodePtr = head;

		//Searches for user
		while (nodePtr != NULL && nodePtr->getValue() != user)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->getNext();
		}

		
		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->setNext(nodePtr->getNext());
			delete nodePtr;
		}
	}
}

//Function that displays the list of users
template<typename T>
void UserStorage<T>::displayList() const
{
	UserNode<T>* nodePtr; //To point to a new node

	if(head != NULL)
	{
		// Start nodePtr at head of list
		nodePtr = head;
		// While nodePtr points to a node, continue through list
		while (nodePtr)
		{
			// Display the value in this node.
			cout << nodePtr->getValue() << endl; //Need to output user and user info

			// Move to the next node.
			nodePtr = nodePtr->getNext();
		}
	}
	else
		cout << "\nThere are no nodes in the list.\n\n";
}

//Quicksort that sorts the users by age in ascending order
template<typename T>
void UserStorage<T>::quickSortUp(int low, int high)
{
	int pivotLocation = 0;

	//List is already sorted if there is no or only one user
	if(!head)
		return;
	if(head == tail)
		return;
	
	pivotLocation = partitionUp(low, high);

	//Uses recursion to break the list down further
	quickSortUp(low, pivotLocation); //Sorts bottom section
	quickSortUp(pivotLocation + 1, high); //Sorts top section

}

//Function that creates the partitioning of the ascending list
template<typename T>
int UserStorage<T>::partitionUp(int left, int right)
{
	UserData pivot, temp;

	pivot = getNodeValue(left);
	int l = left-1;
	int r = right+1;
	while(l<r)
	{
		//Decrements r to pivot
		do{
			r--;
		}while(getNodeValue(r) > pivot);

		//Increments l to pivot
		do{
		   l++;
	   }while(getNodeValue(l) < pivot);
	   
	   if(l < r)
		swap(l, r);
	}

	return r;
}

//Quicksort that sorts the users by age in descending order
template<typename T>
void UserStorage<T>::quickSortDown(int low, int high)
{
	int pivotLocation = 0;

	//List is already sorted if there is no or only one user
	if(!head)
		return;
	if(head == tail)
		return;
	
	pivotLocation = partitionDown(low, high);

	//Uses recursion to break the list down further
	quickSortDown(low, pivotLocation); //Sorts bottom section
	quickSortDown(pivotLocation + 1, high); //Sorts top section

}

//Function that creates the partitioning of the descending list
template<typename T>
int UserStorage<T>::partitionDown(int left, int right)
{
	UserData pivot, temp;

	pivot = getNodeValue(left);
	int l = left-1;
	int r = right+1;
	while(l<r)
	{
		//Decrements r to pivot
		do{
			r--;
		}while(getNodeValue(r) < pivot);

		//Increments l to pivot
		do{
		   l++;
	   }while(getNodeValue(l) > pivot);
	   
	   if(l < r)
		swap(l, r);
	}

	return r;
}

//Function that swaps two nodes in list
template<typename T>
void UserStorage<T>::swap(int one, int two)
{
	UserNode<T>* nodePtr1=NULL;
	UserNode<T>* nodePtr2=NULL;
	UserData tempValue;

	nodePtr1 = head;

	int curPos = 0;
	while(nodePtr1 != NULL && one != curPos)
	{
		//Traverse to next node
		nodePtr1 = nodePtr1->getNext();
		curPos++;
	}
	//NodePtr1 is pointing to one 
	nodePtr2 = head;
	curPos = 0;
	while(nodePtr2 != NULL && two != curPos)
	{
		//Traverse to next node
		nodePtr2 = nodePtr2->getNext();
		curPos++;
	}	
	//NodePtr2 is pointing to two 	

	tempValue = nodePtr1->getValue();
	nodePtr1->setValue(nodePtr2->getValue());
	nodePtr2->setValue(tempValue);
}

template<typename T>
UserStorage<T>::~UserStorage()
{
	UserNode<T>* nodePtr; //To point to a new node
	UserNode<T>* nextNode; //To point to the next node

	//Start nodePtr at head of list.
	nodePtr = head;

	while (nodePtr != NULL)
	{
		nextNode = nodePtr->getNext();
		
		cout << "\nDeleting the node with value " << nodePtr->getValue();
		
		//Delete the current node.
		delete nodePtr;

		//Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	cout << endl << endl;
}