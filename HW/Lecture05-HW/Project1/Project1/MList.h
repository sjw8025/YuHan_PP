#pragma once
template <typename T>
class MList
{
	MNode<T> head;
	MNode<T> tail;
	int size

		MList();
	~MList();

	void push_back(T value);
	int get_size(T);
private:
	int _size();
};

template <typename T>
class MNode
{
public:
	T data;
	MNode<t>* next;

	Mnode(T value)
};


template<typename T>
int MList<T>

