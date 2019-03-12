#ifndef LINKED_LIST_H
#define LINKED_LIST_H


#define INVALID_POS -1

template <class T2>
struct Node
{
	T2 val;
	Node *next;
};

template <class T1>
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(T1 x, int pos=-1);
	T1 remove(int pos, bool &success);

	int find(T1 x);
	T1 get(int pos, bool &success);
	
	int first();
	int next(int pos);
	
	bool empty();
	void purge_list();

	void create_list(T1 N[], int arr_size);
	void print_list();
	void delete_list();
	bool is_pos_valid(int pos);
	
private:
	Node<T1> *head;
	int num_of_items;
};


#include "LinkedList.cpp"

#endif