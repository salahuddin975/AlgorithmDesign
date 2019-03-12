#include "LinkedList.h"
#include <iostream>


template <class T1>
LinkedList<T1>::LinkedList() : num_of_items(0) { }

template <class T1>
LinkedList<T1>::~LinkedList()
{
	if (head != nullptr){
		delete_list();
	}
}

template <class T1>
void LinkedList<T1>::create_list(T1 N[], int arr_size)
{
	Node<T1> *item = new Node<T1>;
	item->val = N[0];
	item->next = nullptr;

	head = item;
	num_of_items = arr_size;

	for (int i = 1; i < arr_size; i++){
		Node<T1> *newItem = new Node<T1>;
		newItem->val = N[i];
		newItem->next = nullptr;

		item->next = newItem;
		item = newItem;
	}
}

template <class T1>
void LinkedList<T1>::print_list()
{
	if (head == nullptr){
		std::cout << "no items in the list!" << std::endl;
		return;
	}

	Node<T1> *item = head;
	while (item->next != nullptr){
		std::cout << item->val << ", ";
		item = item->next;
	}

	std::cout << item->val << std::endl;
}

template <class T1>
bool LinkedList<T1>::is_pos_valid(int pos)
{
	if (pos < 0 || pos >= num_of_items){
		return false;
	}
	return true;
}

template <class T1>
void LinkedList<T1>::add(T1 x, int pos)
{
	if (pos == -1){        
		pos = num_of_items;
	}

	if (pos != 0 && is_pos_valid(pos-1) == false){
		return;
	}

	Node<T1> *newItem = new Node<T1>();
	newItem->val = x;
	newItem->next = nullptr;

	if (pos == 0){
		newItem->next = head;
		head = newItem;
		num_of_items++;
		return;
	}

	Node<T1> *item = head;
	while (--pos){
		item = item->next;
	}

	newItem->next = item->next;
	item->next = newItem;

	num_of_items = num_of_items + 1;
}

template <class T1>
T1 LinkedList<T1>::remove(int pos, bool &success)
{
	if (is_pos_valid(pos) == false){
		success = false;
		return INVALID_POS;
	}

	T1 x;
	Node<T1> *item = head;

	if (pos == 0){
		head = item->next;
		x = item->val;
		delete item;
		return x;
	}

	pos--;
	while (pos--){
		item = item->next;
	}

	x = item->next->val;
	Node<T1> *delItem = item->next;
	item->next = delItem->next;

	delete delItem;
	success = true;
	num_of_items = num_of_items - 1;

	return x;
}

template <class T1>
int LinkedList<T1>::find(T1 x)
{
	if (head == nullptr){
		return INVALID_POS;
	}

	int pos = 0;
	Node<T1> *item = head;
	while (item != nullptr){
		if (x == item->val)
			return pos;

		item = item->next;
		pos++;
	}

	return INVALID_POS;
}

template <class T1>
T1 LinkedList<T1>::get(int pos, bool &success)
{
	if (is_pos_valid(pos) == false){
		success = false;
		return INVALID_POS;
	}

	Node<T1> *item = head;
	success = true;

	while (pos) {
		item = item->next;
		pos--;
	}
	return item->val;
}

template <class T1>
int LinkedList<T1>::next(int pos)
{
	if (is_pos_valid(pos) == false){
		return INVALID_POS;
	}

	return pos + 1;
}

template <class T1>
int LinkedList<T1>::first()
{
	if (head == nullptr){
		return INVALID_POS;
	}

	return 0;
}

template <class T1>
bool LinkedList<T1>::empty()
{
	if (head == nullptr)
		return true;
	else
		return false;
}

template <class T1>
void LinkedList<T1>::delete_list()
{
	if (head == nullptr)
		return;

	Node<T1> *item = head;
	while (item->next != nullptr){
		Node<T1> *nxtItem = item->next;
		delete item;
		item = nxtItem;
	}

	head = nullptr;
}


template <class T1>
void LinkedList<T1>::purge_list()
{
	if (head == nullptr)
		return;

	bool success;
	int pos=0, pos1;
	Node<T1> *item = head;

	while (item->next != nullptr)
	{
		Node<T1> *prevItem = item;
		Node<T1> *checkingItem = item->next;
		pos1 = pos+1;

		while (checkingItem != nullptr)
		{
			if (item->val == checkingItem->val){
				remove(pos1, success);
				checkingItem = prevItem;
				pos1 = pos1 - 1;
			}
			prevItem = checkingItem;
			if (checkingItem != nullptr){
				checkingItem = checkingItem->next;
			}
			pos1 = pos1 + 1;
		}
		item = item->next;
		pos = pos + 1;

		if (item == nullptr)
			break;
	}
}
