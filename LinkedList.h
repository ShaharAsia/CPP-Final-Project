#ifndef _LINKEDLIST_
#define _LINKEDLIST_
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node* next;
	T value;
};


template <class T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(LinkedList& other);
	void addNode(T value);
	bool deleteNode(T value);
	void print();
	friend ostream& operator<<(ostream& os, const LinkedList& ls)
	{
		Node<T>* myNode = ls.first;
		while (myNode)
		{
			os << myNode->value<< "--------" << endl;
			myNode = myNode->next;
		}
		return os;
	}

private:
	Node<T>* first, * last;
};

template<class T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr)
{
}
template<class T>
 LinkedList<T>::LinkedList(LinkedList& other)
{
	 cout << "In c'tor" << endl;
	 if (nullptr != other.first)
	 {
		 this->first->value = other.first->value;
		 this->last->value = other.last->value;
	 }
	 Node<T>* current = other.first->next;
	 while (nullptr != current)
	 {
		 this->addNode(current->value);
		 current = current->next();
	 }
}

template<class T>
void LinkedList<T>::addNode(T value)
{
	Node<T>* newNode = new Node<T>() ;
	newNode->value = value;
	if (this->first == NULL) //first node
	{
		this->first = newNode;
		this->last = first;
	}
	else
	{
		this->last->next = newNode;
		this->last = newNode;
	}
}
template<class T>
bool LinkedList<T>::deleteNode(T value)
{
	if (this->first == NULL) return false; //empty list
	else if (this->first == this->last) //One node list
	{
		if (this->first->value == value)
		{
			this->first = nullptr;
			this->last = nullptr;
			delete this->first;
			return true;
		}
		else return false;
	}
	else // 2 or more nodes
	{
		if (this->first->value == value)
		{
			Node<T>* tmp = this->first->next;
			delete this->first;
			this->first = tmp;
			return true;
		}
		else
		{
			Node<T>* beforeNode = this->first;
			Node<T>* currentNode = this->first->next;
			while (currentNode)
			{
				if (currentNode->value == value) //id value found
				{
					if (currentNode == this->last)
					{
						this->last = beforeNode;
						beforeNode->next = nullptr;
					}
					else 
					{
						beforeNode->next = currentNode->next;
					}
					delete currentNode;
					return true;
				}
				else //value still not found
				{
					beforeNode = currentNode;
					currentNode = currentNode->next;
				}
			}
			return false;
		}
	}
}
template<class T>
void LinkedList<T>::print()
{
	Node<T>* myNode = this->first;
	while (myNode)
	{
		cout << "value = " << myNode->value << endl;
		myNode = myNode->next;
	}
}

#endif

