#include "LinkedList.h"

template<typename T>
int LinkedList<T>::get_size()
{
	return _size;
}

template<typename T>
void LinkedList<T>::push_back(T data)
{
	Node<T>* node = new Node<T>(data);
	node->next_node = nullptr;

	if (_head == nullptr)
	{
		_head = node;
		_tail = node;
	}
	else
	{
		_tail->next_node = node;
		_tail = node;
	}
	_size++;
}

template<typename T>
T& LinkedList<T>::operator[](int index)
{
	Node<T>* cursor = _head;
	for (int i = 0; i < index; i++)
	{
		cursor = cursor->next_node;
	}

	return cursor->_data;
}
