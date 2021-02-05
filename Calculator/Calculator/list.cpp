#include "list.h"

template <typename T>
Node<T>::Node(T data)
{
	this->data = data;
	this->next = NULL;
}

template <typename T>
List<T>::List() {};

template <typename T>
List<T>::~List() {};

template <typename T>
void List<T>::push(T c)
{
	Node<T> *item = new Node<T>(c);
	if (root)
	{
		item->next = root;
		root = item;
	}
	else
		root = item;
}

template <typename T>
T List<T>::top()
{
	if (!root)
		return ('\0');
	return (root->data);
}

template <typename T>
T List<T>::pop()
{
	T data = root->data;
	Node<T> *temp = root->next;
	delete root;
	root = temp;
	return (data);
}

template <typename T>
int List<T>::get_size()
{
	int size = 0;
	Node<T> *temp = root;
	if (!root)
		return (0);
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}

template <typename T>
void List<T>::free()
{
	Node<T> *temp;

	while (root)
	{
		temp = root->next;
		delete root;
		root = temp;
	}
}