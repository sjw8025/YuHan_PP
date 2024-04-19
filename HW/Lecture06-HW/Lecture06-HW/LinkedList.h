#pragma once

template<typename T>
class Node
{
public:
	Node() {};
	Node(T data) { _data = data; }
	~Node() {};

	T _data;
	Node* next_node;
};

template<typename T>
class LinkedList
{
public:
	LinkedList() {};
	~LinkedList() {};

	int get_size();
	void push_back(T data);
	T& operator[] (int index);

private:
	Node<T>* _head;
	Node<T>* _tail;
	int _size;
};

