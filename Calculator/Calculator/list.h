#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# pragma warning (disable : 4996)

template <typename T>
class Node {
public:
	T data;
	Node *next;

	Node<T>(T data);
};

template <typename T>
class List {
public:
	Node<T> *root;

	List();
	~List();
	void push(T c);
	T top();
	T pop();
	int get_size();
	void free();
};

#endif
